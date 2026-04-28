# GAS 学习笔记 · 总纲（体系化梳理）

> 创建日期：2026-04-28  
> 工程：`D:\UnrealProjects\MyProject`  
> 目的：把之前会话里散落的 GAS 知识点按**主线脉络**重新串起来，作为整张"地图"。  
> 配套：`GAS学习笔记_Day01.md`（速查 / 踩坑），本文件（体系 / 心智图）。

---

## 0. 全局心智图（先记这张图）

```
                    ┌─────────────────────────┐
                    │   GameplayAbilitySystem │
                    │      （GAS 总入口）      │
                    └───────────┬─────────────┘
                                │
        ┌───────────────────────┼───────────────────────┐
        │                       │                       │
   ┌────▼────┐            ┌─────▼─────┐           ┌─────▼─────┐
   │ 数据层   │            │ 行为层     │           │ 表现层     │
   │Attribute│            │ Ability   │           │ Cue        │
   │ Effect  │            │ Task      │           │ Animation  │
   │ Tag     │            │           │           │ Montage    │
   └─────────┘            └───────────┘           └───────────┘
        │                       │                       │
        └───────────────┬───────┴───────────────────────┘
                        │
                  ┌─────▼──────┐
                  │  网络层     │
                  │Replication │
                  │Prediction  │
                  └────────────┘
```

**记忆口诀**：**数据是底，行为是骨，表现是皮，网络是血**。

---

## 1. 数据层：Attribute & AttributeSet

### 1.1 三个核心字段（必背）

| 字段 | 含义 | 谁会改它 |
|------|------|----------|
| `BaseValue` | 基础值（持久） | `Instant` / `Periodic` GE |
| `CurrentValue` | 当前值（瞬时） | `Duration` / `Infinite` GE 加 Modifier |
| `Modifier` | 修饰器（叠加层） | Buff / Debuff |

> **关键理解**：`CurrentValue = BaseValue + 所有激活 Modifier 的叠加结果`。  
> Buff 消失 → Modifier 移除 → CurrentValue 自动回落，**不需要你手动减**。

### 1.2 属性初始化的两种方式

| 方式 | 适用场景 | 坑 |
|------|----------|-----|
| **DataTable + InitStats** | 多角色、多等级，数值表配置 | 表头列名要和属性名完全一致 |
| **Instant GE（推荐）** | 通用场景、灵活 | `PossessedBy` 时 Apply 一次 `GE_InitAttributes` |

? 不要在构造函数里 `InitHealth(100)` 然后以为就有 100 血，那只是赋默认值，不走 GE 流水线。

### 1.3 Meta Attribute 模式（伤害最佳实践）

```
Damage(Meta)  ──PostGameplayEffectExecute──?  Health -= Damage
                                              SetDamage(0)
```

**为什么要有 Meta**：
- 解耦伤害计算与血量扣减
- 未来加护盾/暴击/吸血只改 `PostGameplayEffectExecute`
- `Coefficient` 填正数，语义清晰

详见 Day01 卡片 2。

### 1.4 Clamp 的两种位置

| 位置 | 时机 | 适用 |
|------|------|------|
| `PreAttributeChange` | 修改 CurrentValue 前 | 简单 Clamp（HP 不超 MaxHP） |
| `PostGameplayEffectExecute` | GE 实际执行后 | 复杂逻辑（伤害转血量、死亡判定） |

? `PreAttributeChange` 里读 `MaxHealth` 时如果它也在被同一个 GE 改，可能读到旧值。

---

## 2. 数据层：GameplayTag

### 2.1 Tag 是 GAS 的"通用语言"

Tag 串起了所有模块：
- **Ability**：`AbilityTags` / `ActivationOwnedTags` / `BlockedTags` / `RequiredTags`
- **Effect**：`GrantedTags` / `OngoingTagRequirements`
- **AnimBP**：通过 `FGameplayTagBlueprintPropertyMap` 把 Tag 映射成 bool
- **Cue**：`GameplayCue.XXX` 定位特效

### 2.2 三种打 Tag 的方式

| 方式 | 何时加 / 移 | 网络同步 |
|------|-------------|----------|
| `ActivationOwnedTags`（C++ 默认值） | Ability 激活/结束自动 | ? 自动 |
| `AddLooseGameplayTag` | 手动控制 | ? 不同步 |
| `AddReplicatedLooseGameplayTag` | 手动控制 | ? 同步 |

?? **CDO 覆盖坑**：C++ 里设了 `ActivationOwnedTags`，蓝图子类的 Class Defaults 面板会**覆盖**它，要么蓝图里也加一遍，要么走 Loose Tag。

### 2.3 Native Tag 推荐写法

```cpp
// GASLearnGameplayTags.h
namespace GASTags
{
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Charging);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Data_Damage);
}

// .cpp
namespace GASTags
{
    UE_DEFINE_GAMEPLAY_TAG(State_Charging, "State.Charging");
    UE_DEFINE_GAMEPLAY_TAG(Data_Damage, "Data.Damage");
}
```

好处：编译期检查、IDE 跳转、不怕拼错。

---

## 3. 行为层：GameplayEffect (GE)

### 3.1 GE 的三种 Duration

| 类型 | 行为 | 典型用途 |
|------|------|----------|
| `Instant` | 立刻改 BaseValue，不留 Modifier | 伤害、回血、初始化属性 |
| `Duration` | 持续 N 秒，期间挂 Modifier | Buff、Debuff |
| `Infinite` | 永久挂 Modifier，直到手动移除 | 装备加成、光环 |
| + `Period` | 每隔 X 秒触发一次 Instant | DOT、HOT |

### 3.2 Magnitude 计算公式

```
Final = (CoefficientBase + PreMul) * Coefficient + PostMul
```

四种 Magnitude 类型：
- **ScalableFloat**：曲线表，按等级缩放
- **AttributeBased**：基于其他属性算（攻击力 × 1.5）
- **CustomCalculation**：自定义类（MMC/ExecCalc）
- **SetByCaller** ?：运行时塞数值（最常用）

### 3.3 SetByCaller 三步走

```cpp
// 1. 拿到 SpecHandle
FGameplayEffectSpecHandle Spec =
    Source->MakeOutgoingSpec(DamageGE, 1.f, Source->MakeEffectContext());

// 2. 塞数值
UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(
    Spec, GASTags::Data_Damage, DamageAmount);

// 3. Apply
Source->ApplyGameplayEffectSpecToTarget(*Spec.Data.Get(), Target);
```

GE 资产里 Modifier 配：`Magnitude Calculation Type = SetByCaller`，`Data Tag = Data.Damage`。

---

## 4. 行为层：GameplayAbility (GA)

### 4.1 生命周期

```
CanActivate → ActivateAbility → [AbilityTask 等待] → CommitAbility → EndAbility
                     ↓                                                  ↑
                  失败 / 取消 ──────────────────────────────────────────┘
```

| 钩子 | 用途 |
|------|------|
| `CanActivateAbility` | 自定义释放条件 |
| `ActivateAbility` | 主逻辑入口 |
| `CommitAbility` | 真正扣 Cost / 启动 CD |
| `EndAbility` | 清理（移 Tag、停 Task） |
| `CancelAbility` | 被中断 |

### 4.2 InstancingPolicy（实例策略）

| 策略 | 说明 | 典型 |
|------|------|------|
| `NonInstanced` | 全局共享一个 CDO | 极简、无状态技能 |
| `InstancedPerActor` ? | 每个 Actor 一个实例 | **大多数情况** |
| `InstancedPerExecution` | 每次激活一个实例 | 多次并发释放 |

### 4.3 NetExecutionPolicy（网络策略）

| 策略 | 含义 | 场景 |
|------|------|------|
| `LocalOnly` | 仅本地 | UI、纯表现 |
| `LocalPredicted` ? | 客户端预测 + 服务器校验 | 大多数主动技能 |
| `ServerInitiated` | 服务器发起 | 被动触发 |
| `ServerOnly` | 仅服务器 | 扣血、给 Buff |

? `BlueprintAuthorityOnly` 节点在 `LocalPredicted` 客户端会静默失败，扣血走标准 ASC 接口。

### 4.4 Cost / Cooldown 也是 GE

- **Cost GE**：Instant，扣蓝
- **Cooldown GE**：Duration，给一个 `Cooldown.XXX` Tag，CanActivate 检查这个 Tag

---

## 5. 行为层：AbilityTask

### 5.1 常用 Task

| Task | 作用 |
|------|------|
| `WaitInputPress / Release` | 等输入（蓄力松手） |
| `WaitGameplayEvent` | 等事件（动画通知触发） |
| `PlayMontageAndWait` | 播 Montage 监听结束 |
| `WaitDelay` | 等时间 |
| `WaitTargetData` | 等目标选择 |
| `WaitGameplayTagAdded/Removed` | 等 Tag 变化 |

### 5.2 Task 黄金法则

> **一个 Ability 同一时刻只挂一个主线 Task**，`OnCompleted / OnCancelled / OnInterrupted` 三个出口都要接到 `EndAbility`，否则 Ability 会卡死。

### 5.3 PlayMontageAndWait 不能循环

详见 Day01 卡片 4：循环动画走 **Tag 驱动 AnimBP 状态机**，不要走 Montage。

---

## 6. 表现层：Animation 联动

### 6.1 三种动画驱动方式

| 方式 | 适用 | 特点 |
|------|------|------|
| **Montage**（一次性） | 攻击、施法动作 | 用 `PlayMontageAndWait`，监听 `OnCompleted` |
| **Tag 驱动状态机** ? | 蓄力、奔跑、霸体 | "状态"语义，不是"动作" |
| **AnimNotify → GameplayEvent** | 动画关键帧触发逻辑 | 比如挥剑到一半时生成判定盒 |

### 6.2 Tag → AnimBP 桥接（重要）

```cpp
// AnimInstance.h
UPROPERTY(EditDefaultsOnly)
FGameplayTagBlueprintPropertyMap TagMap;

// AnimInstance.cpp NativeInitializeAnimation
if (auto* ASI = Cast<IAbilitySystemInterface>(TryGetPawnOwner()))
{
    TagMap.Initialize(this, ASI->GetAbilitySystemComponent());
}
```

然后在 AnimBP Class Defaults 里把 `State.Charging` 映射到 bool 变量 `bIsCharging`，状态机 Transition 直接用这个 bool。

? 如果想绕过 PropertyMap，状态机 Transition 里用**纯函数版**：
```
AbilitySystemBlueprintLibrary::HasMatchingGameplayTag(ASC, State.Charging)
```

### 6.3 状态机 Transition 单/双向

- 一条线只能单向，需要双向画两条
- 多入多出用 **Conduit 节点**（菱形）

---

## 7. 表现层：GameplayCue（待学）

> Day01 末尾的"明日可选方向 B"。

**核心思想**：把 VFX/SFX 从 Ability 里解耦出去，Ability 只负责"喊一声"，由 CueManager 决定播什么。

```cpp
// Ability 里
ASC->ExecuteGameplayCue(GASTags::Cue_Fireball_Hit, Context); // 一次性
ASC->AddGameplayCue(GASTags::Cue_Buff_Burning, Context);     // 持续
ASC->RemoveGameplayCue(GASTags::Cue_Buff_Burning);
```

Cue Notify 资产挂在 `GameplayCue.XXX` Tag 上，自动响应。

---

## 8. 网络层：Replication & Prediction

### 8.1 ASC 在哪里

| 角色 | ASC 挂在哪 |
|------|-----------|
| **玩家角色** | `PlayerState`（推荐，重生不丢） |
| **AI / 怪物** | `Pawn` / `Character` |

`MyCharacter` 实现 `IAbilitySystemInterface::GetAbilitySystemComponent()` 让框架找到。

### 8.2 属性 Replication

```cpp
UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health)
FGameplayAttributeData Health;

void OnRep_Health(const FGameplayAttributeData& Old)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGASLearnAttributeSet, Health, Old);
}
```

`GetLifetimeReplicatedProps` 里也要登记。

### 8.3 Prediction（预测）

- `LocalPredicted` Ability 自带预测
- 客户端立刻播动画 / 扣本地血
- 服务器校验后，错了会"回滚"
- **预测窗口**：`CommitAbility` 之前
- **不可预测的事**：随机数、依赖服务器状态的判定

---

## 9. 整体数据流（一次完整伤害的旅程）

```
玩家按下 1 键
   │
   ▼
[Input] → AbilitySystemComponent::TryActivateAbility
   │
   ▼
[Client]  GA_Fireball::ActivateAbility   ?── LocalPredicted
   │      ├─ 加 ActivationOwnedTags(State.Charging)
   │      ├─ AnimBP 检测到 Tag → 进入蓄力状态机
   │      └─ AbilityTask::WaitInputRelease
   │
   ▼ (松手)
   ├─ CommitAbility（扣蓝、CD）
   ├─ SpawnActor(FireballProjectile)
   └─ EndAbility → 移除 State.Charging Tag
   │
   ▼
[Projectile] OnHit
   │
   ▼
MakeOutgoingSpec(GE_Damage) + AssignSetByCaller(Data.Damage, 50)
   │
   ▼
ApplyGameplayEffectSpecToTarget
   │
   ▼
[Target ASC] PreAttributeChange(Damage)
             ↓
             PostGameplayEffectExecute:
                Health -= Damage
                SetDamage(0)
   │
   ▼
OnRep_Health → UI 刷新血条
ExecuteGameplayCue(Cue.Fireball.Hit) → VFX/SFX
```

把这张图印在脑子里，所有 GAS 问题都能定位到"是哪一段出问题"。

---

## 10. 学习路线图

```
? 已学：
   ├─ AttributeSet 基础（Health/MaxHealth/Damage）
   ├─ GE 三种类型 + SetByCaller
   ├─ Ability 生命周期 + LocalPredicted
   ├─ AbilityTask（PlayMontageAndWait / WaitInputRelease）
   ├─ Tag 驱动 AnimBP（蓄力状态机）
   └─ Native Tag

? 进行中：
   ├─ ActivationOwnedTags CDO 覆盖排查
   └─ AnimBP 状态机精修

? 下一步建议（按优先级）：
   1. GameplayCue（表现层解耦）
   2. MMC / ExecCalc（复杂伤害公式：暴击/护甲/吸血）
   3. 多人网络专题（Prediction Key、回滚、RPC）
   4. TargetData（AOE、目标筛选）
   5. AbilitySet / Loadout（技能装配系统）
```

---

## 11. 关键文件索引（与 Day01 同步）

| 文件 | 作用 |
|------|------|
| `Source/MyProject/GASLearnAttributeSet.h/cpp` | 属性集，HP/MaxHealth/Damage |
| `Source/MyProject/UGA_Fireball.h/cpp` | 火球技能（含蓄力） |
| `Source/MyProject/AFireballProjectile.cpp` | 弹道，调 SetByCaller |
| `Source/MyProject/MyCharacter.h/cpp` | 实现 IAbilitySystemInterface |
| `Source/MyProject/MyAnimInstance.h/cpp` | AnimBP C++ 基类 |
| `Source/MyProject/GASLearnGameplayTags.h/cpp` | Native Tag |
| `Source/MyProject/MyProject.Build.cs` | 模块依赖 |

---

## 12. 使用说明（怎么让笔记越记越连贯）

**笔记三层结构**：

```
GAS学习笔记_总纲.md       ← 本文件，体系地图（很少改，新主题学完追加章节）
GAS学习笔记_Day01.md      ← 当天速查 + 踩坑（每天一份）
GAS学习笔记_Day02.md      ← ...
```

**新会话开头给 AI 的"最小上下文"**：
1. `GAS学习笔记_总纲.md` 的 **0/9/10 节**（心智图 + 数据流 + 路线图）
2. 上一份 Day 笔记的 **踩坑速查表 + 关键文件索引**
3. 今天想学/想解决的问题

这样既不丢上下文，又不会塞爆 token。
