# GAS 学习笔记 · Day 02

> 日期：2026-04-28  
> 工程：`D:\UnrealProjects\MyProject`  
> 主题：**GameplayCue** —— 把表现层从 Ability 里解耦出去  
> 对应总纲：第 7 章（表现层 · GameplayCue）

---

## 一、今日速查表

| # | 问题 / 场景 | 记住这条 |
|---|------------|---------|
| 1 | 想在命中时放特效 | 不要在 Ability / Projectile 里 SpawnEmitter，用 Cue |
| 2 | Cue Tag 命名 | **必须以 `GameplayCue.` 开头**，否则 CueManager 不扫描 |
| 3 | 一次性 vs 持续性 | Burst → `ExecuteGameplayCue`；Looping → `Add/RemoveGameplayCue` |
| 4 | Static vs Actor Notify | Burst 用 Static（不生 Actor，省性能）；Looping 必须 Actor |
| 5 | 后加入的客户端看不到光环 | `OnActive` 和 `WhileActive` 都要处理 |
| 6 | 客户端喊 AddCue 别人看不到 | 只有服务器或 LocalPredicted Ability 才能广播 |
| 7 | 改了 Notify 没生效 | 重启 PIE，或 `RefreshGameplayCueNotifyData()` |
| 8 | Cue 打不出又不报错 | `AbilitySystem.GameplayCue.PrintWarning 1` 打开警告 |
| 9 | 没 ASC 的墙也要爆炸 | 走 `GameplayCueManager::HandleGameplayCue` 静态入口 |
| 10 | GE Apply 时自动带声光 | GE 资产 `Display → GameplayCues` 里挂一条 Tag |

---

## 二、核心知识卡片

### 💎 卡片 1：Cue 的两种节奏

| 触发方式 | ASC API | 生命周期 | 典型用途 |
|---------|---------|---------|---------|
| **Burst** | `ExecuteGameplayCue` | 一瞬间 | 爆炸、命中闪光、治疗弹字 |
| **Looping** | `AddGameplayCue` / `RemoveGameplayCue` | 从 Add 到 Remove | 蓄力环、中毒烟雾、护盾球 |

> 💡 Add 和 Remove **必须成对**，否则 Actor 泄漏。Ability 的 `EndAbility` / `CancelAbility` / 中断路径都要 Remove。

---

### 💎 卡片 2：两种 Notify 资产

| 资产基类 | 生成 Actor | 主回调 | 何时用 |
|---------|-----------|-------|-------|
| `UGameplayCueNotify_Static` | ❌ | `OnExecute_Implementation` | Burst、轻量 |
| `AGameplayCueNotify_Actor` | ✅ | `OnActive` / `WhileActive` / `OnRemove` / `OnExecute` | Looping、需要持续跟随 |

**Actor 版关键字段**：
- `bAutoDestroyOnRemove = true`：Remove 后自毁
- `AutoDestroyDelay`：允许尾焰淡出

**⚠️ 后进客户端坑**：
```
OnActive   → 本地首次 Add 时
WhileActive → 晚加入的客户端"同步过来"时首次看到
```
只写 `OnActive` 会让后进玩家看不到蓄力光环。两个回调都要处理，或抽成公共函数。

---

### 💎 卡片 3：三条触发通路

**A. 代码直调**：
```cpp
// Burst
FGameplayCueParameters P;
P.Location = Hit.ImpactPoint;
P.Normal   = Hit.ImpactNormal;
TargetASC->ExecuteGameplayCue(GASTags::Cue_Fireball_Explode, P);

// Looping
ASC->AddGameplayCue(GASTags::Cue_Fireball_Charging);
ASC->RemoveGameplayCue(GASTags::Cue_Fireball_Charging);
```

**B. 挂在 GE 上（最推荐）**：  
GE 资产 → `Display` → `Gameplay Cues` → 加 Tag。  
GE Apply 时自动 Execute（Instant）或 Add/Remove（Duration/Infinite）。  
→ **零胶水代码**，所有伤害自动飘红闪光。

**C. 无 ASC 目标（墙壁）**：
```cpp
UGameplayCueManager* Mgr = UAbilitySystemGlobals::Get().GetGameplayCueManager();
Mgr->HandleGameplayCue(Target, CueTag, EGameplayCueEvent::Executed, Params);
```

---

### 💎 卡片 4：多人同步规则

| 触发方式 | 同步行为 |
|---------|---------|
| GE 自带的 Cue | 服务器 Apply 时，客户端自动收到 |
| `ExecuteGameplayCue`（服务器调） | 多播给所有相关客户端 |
| `AddGameplayCue`（服务器调） | 复制状态，**后来加入的客户端走 `WhileActive`** |
| `LocalPredicted` Ability 里调 | 本地立刻播 + 服务器广播给别人（表现零延迟） |
| 客户端在普通逻辑里调 | **只自己看得到**，别人看不到 |

**避坑**：
1. `LocalOnly` Ability 里的 Cue 不走网络
2. 纯客户端调 `AddGameplayCue` 不会同步
3. `FGameplayCueParameters.Location/Normal/Instigator` 会被复制；自定义数据用 `RawMagnitude`

---

### 💎 卡片 5：Cue Tag 命名规范

```
GameplayCue.<大类>.<小类>[.<变体>]
```

示例：
| Tag | 含义 |
|-----|------|
| `GameplayCue.Character.Hit` | 通用受击闪红 |
| `GameplayCue.Character.Death` | 死亡特效 |
| `GameplayCue.Fireball.Charging` | 火球蓄力环（Looping） |
| `GameplayCue.Fireball.Explode` | 火球爆炸（Burst） |
| `GameplayCue.Buff.Burning` | 灼烧状态 |

> ⚠️ 硬性规则：**前缀必须是 `GameplayCue.`**，否则 CueManager 不扫描。拼错静默失败。

---

### 💎 卡片 6：调试三板斧

| 现象 | 方法 |
|-----|------|
| Cue 没反应 | 控制台 `showdebug abilitysystem`，翻到 GameplayCue 页 |
| 想看静默失败 | `AbilitySystem.GameplayCue.PrintWarning 1` |
| 改了资产不生效 | 重启 PIE；或 `UGameplayCueManager::RefreshGameplayCueNotifyData()` |
| 预加载 Cue 资产 | `AbilitySystemGlobals.ini` 里配 `GameplayCueNotifyPaths` |

---

## 三、本日改造步骤（Fireball 升级）

### Step 1：在 `GASLearnGameplayTags.h` 增加 Cue Tag

```cpp
// Cue
UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cue_Fireball_Charging);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cue_Fireball_Explode);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cue_Character_Hit);
```

`.cpp`：
```cpp
UE_DEFINE_GAMEPLAY_TAG(Cue_Fireball_Charging, "GameplayCue.Fireball.Charging");
UE_DEFINE_GAMEPLAY_TAG(Cue_Fireball_Explode,  "GameplayCue.Fireball.Explode");
UE_DEFINE_GAMEPLAY_TAG(Cue_Character_Hit,     "GameplayCue.Character.Hit");
```

### Step 2：`UGA_Fireball::ActivateAbility` 蓄力时加 Cue

```cpp
if (UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get())
{
    ASC->AddGameplayCue(GASTags::Cue_Fireball_Charging);
}
```

在 `EndAbility` / `OnChargeInterrupted` / `OnMontageInterrupted` **所有出口**里：
```cpp
if (UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get())
{
    ASC->RemoveGameplayCue(GASTags::Cue_Fireball_Charging);
}
```

> ⚠️ **重要**：Ability 的所有收尾路径都要 Remove，否则 Cue Actor 泄漏。如果怕漏，考虑把 Remove 放在 `EndAbility` 统一处理。

### Step 3：`AFireballProjectile::OnHit` 爆炸 Cue

```cpp
FGameplayCueParameters Params;
Params.Location   = Hit.ImpactPoint;
Params.Normal     = Hit.ImpactNormal;
Params.Instigator = GetInstigator();
Params.EffectCauser = this;

if (UAbilitySystemComponent* TargetASC =
        UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor))
{
    TargetASC->ExecuteGameplayCue(GASTags::Cue_Fireball_Explode, Params);
}
else // 墙壁、非 ASC 目标
{
    UGameplayCueManager* Mgr = UAbilitySystemGlobals::Get().GetGameplayCueManager();
    Mgr->HandleGameplayCue(OtherActor, GASTags::Cue_Fireball_Explode,
                           EGameplayCueEvent::Executed, Params);
}
```

### Step 4：编辑器里建两个 Notify 资产

| 资产 | 基类 | Tag | 说明 |
|-----|------|-----|------|
| `BP_GCN_FireballExplode` | `GameplayCueNotify_Static` | `GameplayCue.Fireball.Explode` | `OnExecute` → SpawnEmitterAtLocation + PlaySoundAtLocation + CameraShake |
| `BP_GCN_FireballCharging` | `GameplayCueNotify_Actor` | `GameplayCue.Fireball.Charging` | `OnActive` + `WhileActive` Spawn 粒子；`OnRemove` Destroy；`bAutoDestroyOnRemove = true` |

### Step 5：`GE_Damage20` 挂通用受击 Cue

打开 GE 资产 → `Display` → `Gameplay Cues` → Add → `GameplayCue.Character.Hit`。  
→ 从此**任何**伤害源打**任何**目标都自动闪红飘字，0 额外代码。

### Step 6：测试矩阵

- [ ] 单机：蓄力光环出现 → 松手消失
- [ ] 单机：击中假人 → 爆炸粒子 + 假人闪红
- [ ] 双人 PIE（Number of Players = 2）：A 蓄力，B 能看到 A 手里的光环
- [ ] A 打 B：B 屏幕也出现爆炸
- [ ] **后加入测试**：A 先蓄力，B 再连进来 → B 应该也能看到光环（`WhileActive` 生效）

---

## 四、本次会话关键新增文件

| 文件 | 作用 |
|------|------|
| `Source/MyProject/GAS/GASLearnGameplayTags.h/cpp` | 新增 3 个 Cue Tag |
| `Source/MyProject/GAS/UGA_Fireball.cpp` | 蓄力 Add / 结束 Remove |
| `Source/MyProject/CustomActor/AFireballProjectile.cpp` | OnHit Execute Cue |
| Content / `BP_GCN_FireballCharging.uasset`（待建） | Actor 型 Notify |
| Content / `BP_GCN_FireballExplode.uasset`（待建） | Static 型 Notify |
| Content / `GE_Damage20.uasset`（待改） | 挂 `GameplayCue.Character.Hit` |

---

## 五、补丁 A：阶段 Tag vs Ability Tag（今日踩坑）

### 踩坑实录

最初把 `State.Charging` 挂在 `ActivationOwnedTags` 上：

```cpp
UGA_Fireball::UGA_Fireball()
{
    ActivationOwnedTags.AddTag(GASTags::State_Charging); // ❌ 从头挂到尾
}
```

**问题**：Ability 的生命周期不是只有蓄力一段。完整时间轴是：

```
ActivateAbility ─────────────────────────────────────── EndAbility
       ├──[A: 蓄力中]──┤                                       │
       │   WaitInputRelease                                    │
       │                ├──[B: 释放动画]──┤                    │
       │                │   PlayMontage + WaitGameplayEvent    │
       │                │                  ├──[C: 余韵]──────┤
```

`ActivationOwnedTags` 在 A/B/C 三段**全程挂着** → 释放动画期间角色还在做蓄力姿势、蓄力光环不消失、AnimBP 状态机退不出 Charging 状态。

### 核心原则

| 粒度 | 工具 | 例子 |
|------|------|------|
| 整个 Ability 活着 | `ActivationOwnedTags` | `State.Casting.Fireball`（广义"正在放火球"） |
| Ability **内某个阶段** | 手动 `AddLooseGameplayTag` / `AddReplicatedLooseGameplayTag` / GE 包裹 | `State.Charging`（具体"正在蓄力中"） |

> ⚠️ **`ActivationOwnedTags` 是粗粒度开关，粒度 = 整个 Ability**。  
> 拿它表达"阶段"相当于用总闸当客厅灯开关——能亮，但语义错位。

### 修正模板（方案 A：最小改动）

```cpp
// 构造函数：删掉 ActivationOwnedTags.AddTag(State_Charging)

// ActivateAbility：进入阶段 A
ASC->AddLooseGameplayTag(GASTags::State_Charging);
ASC->AddGameplayCue(GASTags::Cue_Fireball_Charging, Params);

// OnInputReleased：离开阶段 A
ASC->RemoveLooseGameplayTag(GASTags::State_Charging);
ASC->RemoveGameplayCue(GASTags::Cue_Fireball_Charging);

// EndAbility：兜底（被眩晕/死亡打断时 OnInputReleased 不会触发）
if (ASC->HasMatchingGameplayTag(GASTags::State_Charging))
{
    ASC->RemoveLooseGameplayTag(GASTags::State_Charging);
    ASC->RemoveGameplayCue(GASTags::Cue_Fireball_Charging);
}
```

**三点成一线**：进入阶段的入口 + 离开阶段的出口 + EndAbility 兜底。缺一个都会漏清。

### Loose Tag 的网络坑

| API | 本地生效 | 同步到其他客户端 |
|-----|---------|------------------|
| `AddLooseGameplayTag` | ✅ | ❌ |
| `AddReplicatedLooseGameplayTag` | ✅ | ✅ |
| `ActivationOwnedTags` | ✅ | ✅（自动） |
| 挂在 Infinite GE 的 `Granted Tags` | ✅ | ✅（GE 复制） |

驱动**本地 AnimBP** 的 Tag 用 `AddLooseGameplayTag` 就够（每个客户端的 LocalPredicted Ability 自己管自己）。要让**别人也看到**（比如敌人 UI 显示"他在蓄力"）必须用 Replicated 版或 GE 包裹。

### 进阶方案（方案 B：GE 包裹阶段）

蓄力阶段 = 一个 Infinite GE 的生命周期。Tag 和 Cue 都挂在 GE 上，引擎自动管理同步。

1. 建 `GE_FireballChargingState`，`Duration Policy = Infinite`
2. `Granted Tags` → `State.Charging`（GE 自动复制）
3. `Display → Gameplay Cues` → `GameplayCue.Fireball.Charging`
4. Ability 里：

```cpp
// ActivateAbility
FGameplayEffectContextHandle Ctx = ASC->MakeEffectContext();
FGameplayEffectSpecHandle Spec = ASC->MakeOutgoingSpec(ChargingStateEffect, 1.f, Ctx);
ChargingStateHandle = ASC->ApplyGameplayEffectSpecToSelf(*Spec.Data.Get());

// OnInputReleased
if (ChargingStateHandle.IsValid())
{
    ASC->RemoveActiveGameplayEffect(ChargingStateHandle);
    ChargingStateHandle.Invalidate();
}
```

**优势**：Tag 自动复制、Cue 零胶水、未来加"蓄力降速 30%"只改资产不改代码。

---

## 六、补丁 B：Cue 跟随玩家的正确姿势（今日踩坑）

### 现象

蓄力光环卡在世界原点 (0,0,0)，玩家移动光环不跟随。

### 根因

```cpp
ASC->AddGameplayCue(GASTags::Cue_Fireball_Charging); // ❌ 没传 Params
```

这个重载内部构造**默认 Params**：
- `Location = FVector::ZeroVector` → (0,0,0)
- `Instigator = nullptr` → Cue Notify Actor 找不到 Attach Target

然后：
- **Static 型 Notify**：`SpawnEmitterAtLocation(Params.Location)` → 粒子生在原点、无父节点、不跟随
- **Actor 型 Notify**：`SetActorLocation(Params.Location)` → Actor 放原点、没 Attach 到玩家

### 选型红线（再强调）

| Cue 类型 | Notify 基类 | 能跟随吗 |
|---------|-------------|---------|
| Burst（一次性爆炸） | `UGameplayCueNotify_Static` | 不需要跟随 |
| Looping（蓄力环、护盾球） | `AGameplayCueNotify_Actor` | **必须 Actor 版 + Attach** |

> 🔑 **Looping 特效不能用 Static 版**。Static 本质是"Spawn 完就扔",无法 Remove、无法跟随。

### 正确姿势（方案 A：Actor 型 + Attach to Owner）

#### 1. Cue Notify 资产设置

`BP_GCN_FireballCharging` 父类必须是 `GameplayCueNotify_Actor`：

| 字段 | 值 | 作用 |
|------|-----|------|
| `GameplayCueTag` | `GameplayCue.Fireball.Charging` | 匹配 Tag |
| `Attach to Owner` / `bAutoAttachToOwner` | ✅ | Attach 到 Target |
| `Attach Point` | `hand_r`（或法阵想贴的 Socket） | 挂点 |
| `bAutoDestroyOnRemove` | ✅ | Remove 自毁 |

`OnActive` 和 `WhileActive` 都 Spawn 粒子 Attach 到 `self`（Notify Actor 已经被 Attach 到玩家了）。

#### 2. 调用时传 Params

```cpp
FGameplayCueParameters Params;
AActor* Avatar = ActorInfo->AvatarActor.Get();
Params.Instigator   = Avatar;     // Cue Notify Actor 从这里取 Attach Target
Params.EffectCauser = Avatar;
Params.SourceObject = Avatar;
if (Avatar)
{
    Params.Location = Avatar->GetActorLocation();  // 出生位置兜底
}
ASC->AddGameplayCue(GASTags::Cue_Fireball_Charging, Params);
```

### 方案 B（老版本 UE 或想完全代码控制）：手动 Attach

在 Cue Notify C++ 父类的 `OnActive_Implementation` 里：

```cpp
bool AGCN_FireballCharging::OnActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& P)
{
    AActor* AttachTarget = MyTarget ? MyTarget : P.Instigator.Get();
    if (!AttachTarget) return false;
    USkeletalMeshComponent* Mesh = AttachTarget->FindComponentByClass<USkeletalMeshComponent>();
    ChargingFX = UNiagaraFunctionLibrary::SpawnSystemAttached(
        ChargingNiagara, Mesh, TEXT("hand_r"),
        FVector::ZeroVector, FRotator::ZeroRotator,
        EAttachLocation::SnapToTarget, /*bAutoDestroy=*/false);
    return true;
}

// ⚠️ 别忘了 WhileActive，给后加入客户端看
bool AGCN_FireballCharging::WhileActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& P)
{
    return OnActive_Implementation(MyTarget, P);
}
```

> 💡 **`MyTarget` 就是 Cue 挂载目标**，GAS 自动传进来，比从 Params 里挖更直接。

### 排查清单（逐项核对）

| # | 检查点 | 怎么验 |
|---|-------|-------|
| 1 | Notify 父类是 `_Actor` 不是 `_Static` | Class Settings → Parent Class |
| 2 | `GameplayCueTag` = `GameplayCue.Fireball.Charging` | Class Defaults |
| 3 | `Attach to Owner` = true | 同上 |
| 4 | `Attach Point` 的 Socket 真实存在 | Skeleton 编辑器搜索 |
| 5 | `AddGameplayCue` 传了 `Params.Instigator = Avatar` | 源码 |
| 6 | `showdebug abilitysystem` → Cue 页看是否激活 | PIE |
| 7 | `AbilitySystem.GameplayCue.PrintWarning 1` 看静默失败 | PIE |

### 一句心法

> **Cue 的"位置/跟随"全靠 `FGameplayCueParameters` + Notify Actor 的 Attach 配置。`Add/ExecuteGameplayCue` 不传 Params 就等于告诉引擎"生在原点、谁也不跟"。Looping 型必须 Actor 版 + Attach to Owner。**

---

## 七、明日方向：MMC / ExecCalc（已选定 → Day03）

把火球做厚：暴击、护甲减伤、吸血、属性加成。  
详见 `GAS学习笔记_Day03.md`。

---

## 六、今日心法总结

1. **Ability 是导演，Cue 是演员，Tag 是台本**
2. **能挂在 GE 上就挂在 GE 上**，少写胶水代码
3. **Burst 用 Static，Looping 用 Actor**
4. **Add 必须成对 Remove**，所有出口都要清
5. **Cue Tag 前缀雷打不动是 `GameplayCue.`**

> 📌 明天开新会话时，把**总纲 0/9/10 节 + 本文件的速查表和心法** 喂给 AI，就能无缝接上。
