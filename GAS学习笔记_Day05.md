# GAS 学习笔记 · Day 05

> 日期：2026-05-08  
> 工程：`D:\UnrealProjects\MyProject`  
> 主题：**TargetData + GroundTrace 地面选点火球**  
> 对应总纲：学习路线图 Day05

---

## 一、今天解决了什么（先看结果）

- **从"自动飞向准星"升级为"地面选点"火球**：玩家按键 → 出现地面指示器 → 鼠标点地确认 → 火球从手部飞向落点。
- **走通了 TargetData 完整链路**：`WaitTargetData` Task 创建 → 手动 `BeginSpawningActor` → 配置 TargetActor → `FinishSpawningActor` → `ReadyForActivation` → `ValidData` 回调拿落点。
- **踩穿了 `GroundTrace.StartLocation` 默认坑**：默认是 `LiteralTransform`（世界原点），必须手动设成相机或角色，不然射线从 (0,0,0) 出发完全打不中地面。
- **修了 OnHit 的"打墙不爆炸"**：爆炸 Cue 不能和伤害绑在同一个 if 分支里，否则打无 ASC 物体时视觉缺失。

---

## 二、速查表（一次记住今天的坑）

| # | 现象 / 问题 | 根因 | 建议做法 |
|---|---|---|---|
| 1 | 创建 Task 后地上没出现指示器 | `WaitTargetData` 不会自动 Spawn TargetActor | 必须手动 `BeginSpawningActor → FinishSpawningActor` |
| 2 | GroundTrace 射线方向不对，永远不命中地面 | `StartLocation` 默认 `LiteralTransform`（=世界原点） | 在 `BeginSpawn` 之后、`FinishSpawn` 之前，设成 `ActorTransform` + `PlayerCameraManager` |
| 3 | 鼠标左键点了没反应 | `UserConfirmed` 模式需要走 `LocalInputConfirm` | 用 `K_Confirm` 输入或 `ASC->LocalInputConfirm()` 触发 |
| 4 | `OnTargetDataReady` 没回调 | `ReadyForActivation` 漏调 | Task 配置完一定要 `Task->ReadyForActivation()` |
| 5 | 火球打墙不爆炸（无 Cue） | Cue 调用被放进了"目标有 ASC"的分支里 | Cue 作为视觉表现应**无条件播**，独立于伤害逻辑 |
| 6 | 火球可能命中自己导致一出生就炸 | Spawn 后没忽略 Owner 碰撞 | `Root->IgnoreActorWhenMoving(Avatar, true)` |

---

## 三、TargetData 主链路：从按键到落点

### 1) 整体调用链

```
玩家按键
  → ASC->TryActivateAbility
    → UGA_FireballGround::ActivateAbility
       ├─ 1. WaitTargetData::WaitTargetData(...)        创建 Task（未 Spawn）
       ├─ 2. ValidData / Cancelled 绑回调
       ├─ 3. Task->BeginSpawningActor(...)              开始两段式 Spawn
       ├─ 4. 配置 TargetActor（StartLocation 等）        ← 关键：必须在这一步
       ├─ 5. Task->FinishSpawningActor(...)             TargetActor 进入场景，开始 Targeting
       └─ 6. Task->ReadyForActivation()                 Task 真正开始监听
玩家点鼠标
  → ASC->LocalInputConfirm
    → TargetActor::ConfirmTargeting
      → 产生 FGameplayAbilityTargetDataHandle
        → Task::ValidData 广播
          → UGA_FireballGround::OnTargetDataReady
             ├─ 取落点：GetTargetDataEndPoint(Data, 0)
             ├─ 服务器 Spawn 火球
             └─ EndAbility
```

### 2) 为什么要"两段式 Spawn"

`BeginSpawningActor` / `FinishSpawningActor` 是 UE 的 **Deferred Spawn** 模式：

- `BeginSpawn`：分配出 Actor 但**还没调用 BeginPlay、还没注册到世界**。
- 中间这段时间，你可以安全地配置 Actor 上的 UPROPERTY（比如 `StartLocation`）。
- `FinishSpawn`：正式注册、跑 BeginPlay、TargetActor 内部开始 `StartTargeting`。

**为什么不能用 `SpawnActor` 一步到位？**  
因为如果直接 Spawn，BeginPlay 已经跑完了，TargetActor 内部用的就是默认的 `StartLocation = LiteralTransform`（世界原点），等你再去改已经晚了。

---

## 四、GroundTrace.StartLocation：今天最关键的坑

### 现象
不配 `StartLocation` 时，地上根本没有有效的落点指示器，或者指示器卡在 (0,0,0) 附近。

### 根因
`AGameplayAbilityTargetActor_GroundTrace::StartLocation` 是一个 `FGameplayAbilityTargetingLocationInfo`：

```cpp
struct FGameplayAbilityTargetingLocationInfo
{
    EGameplayAbilityTargetingLocationType::Type LocationType; // 默认 LiteralTransform
    FTransform LiteralTransform;                              // 默认 = Identity = 世界原点
    AActor* SourceActor;                                      // 默认 nullptr
    UMeshComponent* SourceComponent;
    UGameplayAbility* SourceAbility;
};
```

**默认 `LocationType = LiteralTransform`，`LiteralTransform = Identity`** —— 意味着射线起点就是 **(0, 0, 0)**。

### 正确做法（已落地代码）
```cpp
if (PC && PC->PlayerCameraManager)
{
    GroundTrace->StartLocation.LocationType =
        EGameplayAbilityTargetingLocationType::ActorTransform;
    GroundTrace->StartLocation.SourceActor = PC->PlayerCameraManager;
}
```

用 `PlayerCameraManager` 当起点，配合 GroundTrace 内部"沿前向射线打到地面"的逻辑，效果接近 **FPS/TPS 鼠标指向**。

### 配置时机
**必须在 `BeginSpawningActor` 之后、`FinishSpawningActor` 之前**。  
原因看上面的"两段式 Spawn"——FinishSpawn 之后 BeginPlay 跑完，TargetActor 已经按错的 StartLocation 在工作了。

---

## 五、Confirm / Cancel 触发链

### `EGameplayTargetingConfirmation::UserConfirmed` 模式
- `ValidData` 广播必须等玩家**主动确认**。
- 主动确认有两种触发方式：
  1. **输入绑定**：在 `DefaultInput.ini` / `EnhancedInput` 里把某个键绑到 `K_Confirm` / `K_Cancel`。
  2. **代码触发**：在按键事件里手动调 `ASC->LocalInputConfirm()` 或 `LocalInputCancel()`。

### 替代模式：`Instant`
- 不等玩家点，TargetActor 一出现就立刻 ConfirmTargeting。
- 适合"按下立刻打"的技能，比如自动锁定的弹道。

### 取消的清理
`OnTargetDataCancelled` 里只做 `EndAbility(..., bWasCancelled=true)` 就够了——TargetActor 自己会被 Task 销毁，不用手动 Destroy。

---

## 六、OnHit 的爆炸 Cue：还没完全干净

### 当前实现的问题
```cpp
if (TargetASC && DamageEffectClass)
{
    if (SourceASC.IsValid())
    {
        SourceASC->ExecuteGameplayCue(GASTags::Cue_Fireball_Explode, CueParams); // ← 在这里
        // ... Spec / Apply ...
    }
}
else
{
    UGameplayCueManager* Mgr = UAbilitySystemGlobals::Get().GetGameplayCueManager();
    Mgr->HandleGameplayCue(...); // ← 兜底
}
```

**两个分支都有 Cue 调用，看似覆盖到了，但语义上 Cue 和伤害是耦合的：**
- 如果某天 `SourceASC.IsValid()` 不成立（角色已死、ASC 被销毁），目标即使有 ASC 也不会播 Cue。
- 命中无 ASC 的物体（墙、岩石）走 else 分支，能播但路径不一致。

### 更干净的写法（备忘，下次重构再改）
```cpp
// 1) Cue 永远播 —— 视觉与伤害解耦
PlayExplosionCue(Hit);

// 2) 伤害单独一段
if (TargetASC && DamageEffectClass && SourceASC.IsValid())
{
    ApplyDamageTo(TargetASC, Hit);
}

// 3) 销毁
Destroy();
```

**核心原则**：**Cue 是表现层，伤害是逻辑层，两者不要写在同一个 if 分支里**。

---

## 七、Day05 最小闭环清单

- [x] 按键能弹出地面指示器
- [x] 鼠标点地能确认落点
- [x] 火球从手部飞向落点
- [x] 命中目标走 GE 扣血
- [x] 命中墙也能播爆炸 Cue（虽然路径不一致）
- [ ] OnHit 的 Cue 与伤害解耦（待 Day06+ 重构）
- [ ] 加 CD / Cost（留到 Day08）

---

## 八、今天的心法

1. **GAS 里很多 TargetActor 是"半成品"**：`WaitTargetData` 只创建 Task，不 Spawn Actor；TargetActor 自己也有一堆默认值需要外部喂。
2. **两段式 Spawn 是 UE 的标准做法，不是 GAS 特有**：凡是涉及"先分配再配置再启动"的对象都可能用到。
3. **看到 `LiteralTransform` 默认值时要警觉**：它意味着"如果你没填，就是 Identity"。
4. **表现层（Cue）和逻辑层（GE）分开**：以后写所有命中事件都要按这个原则。
5. **TargetData 模式（UserConfirmed）依赖 LocalInputConfirm 链**：调不通先查输入是否绑到了 Confirm。

---

## 九、下一步建议（Day06）

不加新功能，回头串讲：

- **基于 `UGA_FireballGround`，把 `TryActivateAbility → ActivateAbility → CommitAbility → EndAbility` 整条 GA 生命周期讲一遍**
- 每一步发生了什么、谁调谁、客户端和服务器各跑了什么
- 产出：一张手画调用链图 + 一段"自己的解释"

跑完 Day06 再决定 Day07 是继续串讲 GE 数据流，还是直接进 Day08 做 Cooldown。
