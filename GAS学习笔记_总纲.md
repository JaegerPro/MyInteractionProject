# GAS 学习笔记 · 总纲（体系化梳理）

> 创建日期：2026-04-28　修订：2026-05-06  
> 工程：`D:\UnrealProjects\MyProject`  
> 目的：把散落在 Day 笔记里的 GAS 知识点按**主线脉络**串成一张地图。  
> 配套：`GAS学习笔记_DayXX.md`（速查 / 踩坑），本文件（体系 / 心智图）。

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
   │         │            │           │           │ Montage    │
   └─────────┘            └───────────┘           └───────────┘
        │                       │                       │
        │   ◄─── GameplayTag 贯穿三层（粘合剂） ───►    │
        │                       │                       │
        └───────────────┬───────┴───────────────────────┘
                        │
                  ┌─────▼──────┐
                  │  网络层     │
                  │Replication │
                  │Prediction  │
                  └────────────┘
```

**记忆口诀**：**数据是底，行为是骨，表现是皮，网络是血，Tag 是脉络**。

> ⚠️ **关于 Tag**：GameplayTag 不是单独的"一层"，而是**跨层连接线**——属性、效果、技能、动画、Cue 都靠它对话。所以下文每个章节都会出现 Tag 相关字段，本文不再单设"Tag 层"。

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

⚠️ 不要在构造函数里 `InitHealth(100)` 然后以为就有 100 血——那只是赋默认值，**不走 GE 流水线**，无法被监听、无法被复制。

### 1.3 Meta Attribute 模式（伤害最佳实践）

```
Damage(Meta)  ──PostGameplayEffectExecute──▶  Health -= Damage
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

⚠️ `PreAttributeChange` 里读 `MaxHealth` 时，如果它正在被同一个 GE 修改，可能读到旧值。

---

## 2. 行为层：GameplayEffect (GE)

### 2.1 GE 的三种 Duration

| 类型 | 行为 | 典型用途 |
|------|------|----------|
| `Instant` | 立刻改 BaseValue，不留 Modifier | 伤害、回血、初始化属性 |
| `Duration` | 持续 N 秒，期间挂 Modifier | Buff、Debuff |
| `Infinite` | 永久挂 Modifier，直到手动移除 | 装备加成、光环 |
| + `Period` | 每隔 X 秒触发一次 Instant | DOT、HOT |

### 2.2 Magnitude 计算公式

```
Final = (CoefficientBase + PreMul) * Coefficient + PostMul
```

四种 Magnitude 类型：
- **ScalableFloat**：曲线表，按等级缩放
- **AttributeBased**：基于其他属性算（攻击力 × 1.5）
- **CustomCalculation**：自定义类（**MMC** / **ExecCalc**，详见 Day03）
- **SetByCaller**（最常用）：运行时塞数值

### 2.3 SetByCaller 三步走

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

### 2.4 GE 上的 Tag（Tag 在 GE 里的含义）

| 字段 | 作用 |
|------|------|
| `Asset Tags` | 标识 GE 自己（用于"我有没有这条 GE" 查询） |
| `Granted Tags` | GE 激活期间，Owner 自动获得这些 Tag（自动复制） |
| `Ongoing Tag Requirements` | Target 必须有/不能有的 Tag，否则 Modifier 不生效 |
| `Application Tag Requirements` | Apply 时的准入条件 |
| `Removal Tag Requirements` | 被强制移除的条件 |

> 💡 实战常用：用 Infinite GE 的 `Granted Tags` 表达"阶段状态"（Day02 补丁 A 方案 B）——Tag 自动同步、自动清理。

---

## 3. 行为层：GameplayAbility (GA)

### 3.1 生命周期

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

### 3.2 InstancingPolicy（实例策略）

| 策略 | 说明 | 典型 |
|------|------|------|
| `NonInstanced` | 全局共享一个 CDO | 极简、无状态技能 |
| `InstancedPerActor` ⭐ | 每个 Actor 一个实例 | **大多数情况** |
| `InstancedPerExecution` | 每次激活一个实例 | 多次并发释放 |

### 3.3 NetExecutionPolicy（网络策略）

| 策略 | 含义 | 场景 |
|------|------|------|
| `LocalOnly` | 仅本地 | UI、纯表现 |
| `LocalPredicted` ⭐ | 客户端预测 + 服务器校验 | 大多数主动技能 |
| `ServerInitiated` | 服务器发起 | 被动触发 |
| `ServerOnly` | 仅服务器 | 扣血、给 Buff |

⚠️ `BlueprintAuthorityOnly` 节点在 `LocalPredicted` 客户端会静默失败，扣血走标准 ASC 接口。

### 3.4 Cost / Cooldown 也是 GE

- **Cost GE**：Instant，扣蓝
- **Cooldown GE**：Duration，给一个 `Cooldown.XXX` Tag，CanActivate 检查这个 Tag

### 3.5 GA 上的 Tag（Tag 在 GA 里的含义）

| 字段 | 作用 |
|------|------|
| `AbilityTags` | 标识技能本身（"我是火球术"） |
| `ActivationOwnedTags` | 激活期间 Owner 获得的 Tag（自动加/自动移） |
| `ActivationBlockedTags` | Owner 有这些 Tag 时不能释放（眩晕、沉默） |
| `ActivationRequiredTags` | Owner 必须有这些 Tag 才能释放 |
| `BlockAbilitiesWithTag` | 激活期间，屏蔽其他带这些 Tag 的技能 |
| `CancelAbilitiesWithTag` | 激活时，取消其他带这些 Tag 的技能 |
| `SourceRequired/BlockedTags` | 来源 Actor 的 Tag 准入 |
| `TargetRequired/BlockedTags` | 目标 Actor 的 Tag 准入 |

⚠️ **CDO 覆盖坑**：C++ 里设了 `ActivationOwnedTags`，蓝图子类的 Class Defaults 面板会**覆盖**它，要么蓝图里也加一遍，要么走 Loose Tag。

⚠️ **粒度错位坑**（Day02 补丁 A）：`ActivationOwnedTags` 是"整个 Ability 活着"的粗粒度开关。表达"蓄力中→释放中→余韵"这种**阶段**要用 `AddLooseGameplayTag` 或 Infinite GE 包裹。

### 3.6 Native Tag 推荐写法

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

## 4. 行为层：AbilityTask

### 4.1 常用 Task

| Task | 作用 |
|------|------|
| `WaitInputPress / Release` | 等输入（蓄力松手） |
| `WaitGameplayEvent` | 等事件（动画通知触发） |
| `PlayMontageAndWait` | 播 Montage 监听结束 |
| `WaitDelay` | 等时间 |
| `WaitTargetData` | 等目标选择（点选、AOE） |
| `WaitGameplayTagAdded/Removed` | 等 Tag 变化 |
| `WaitAttributeChange` | 等属性变化（HP < 30% 触发） |

### 4.2 Task 黄金法则

> **一个 Ability 同一时刻只挂一个主线 Task**，`OnCompleted / OnCancelled / OnInterrupted` 三个出口都要接到 `EndAbility`，否则 Ability 会卡死。

### 4.3 PlayMontageAndWait 不能循环

详见 Day01 卡片 4：循环动画走 **Tag 驱动 AnimBP 状态机**，不要走 Montage。

---

## 5. 表现层（一）：Animation 联动

### 5.1 三种动画驱动方式

| 方式 | 适用 | 特点 |
|------|------|------|
| **Montage**（一次性） | 攻击、施法动作 | 用 `PlayMontageAndWait`，监听 `OnCompleted` |
| **Tag 驱动状态机** ⭐ | 蓄力、奔跑、霸体 | "状态"语义，不是"动作" |
| **AnimNotify → GameplayEvent** | 动画关键帧触发逻辑 | 比如挥剑到一半时生成判定盒 |

### 5.2 Tag → AnimBP 桥接

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

💡 如果想绕过 PropertyMap，状态机 Transition 里用**纯函数版**：
```
AbilitySystemBlueprintLibrary::HasMatchingGameplayTag(ASC, State.Charging)
```

### 5.3 状态机 Transition 单/双向

- 一条线只能单向，需要双向画两条
- 多入多出用 **Conduit 节点**（菱形）

### 5.4 AnimNotify → GameplayEvent

动画关键帧（挥剑到一半）触发 Ability 内逻辑：

```cpp
// Ability 内
UAbilityTask_WaitGameplayEvent* Task =
    UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(this, GASTags::Event_Montage_Hit);
Task->EventReceived.AddDynamic(this, &UMyAbility::OnHitFrame);
Task->ReadyForActivation();
```

动画里加 `AnimNotify_PlayMontageNotify` 或自定义 Notify 调 `SendGameplayEventToActor`。

---

## 6. 表现层（二）：GameplayCue

> 详见 Day02 全篇。

### 6.1 核心思想

把 VFX/SFX 从 Ability 里解耦出去，Ability 只负责"喊一声"，由 CueManager 决定播什么。

### 6.2 四种触发方式

| 触发方式 | API | 在 Notify 里的回调 | 用途 |
|---------|-----|------------------|------|
| **Execute**（一次性） | `ExecuteGameplayCue` | `OnExecute` | 爆炸、命中闪光、飘字 |
| **Active**（首次激活） | `AddGameplayCue`（首次）| `OnActive` | Looping Cue 第一次出现 |
| **WhileActive**（同步在线） | `AddGameplayCue`（已激活）| `WhileActive` | **后加入客户端**首次看到 |
| **Remove**（结束） | `RemoveGameplayCue` | `OnRemove` | Looping 结束清理 |

⚠️ Looping Cue 必须**同时实现 `OnActive` 和 `WhileActive`**，否则后进玩家看不到。

### 6.3 三条触发通路

| 通路 | 适用 |
|------|------|
| **代码直调**（`ExecuteGameplayCue`） | 临时表现 |
| **挂在 GE 上**（GE 资产 → Display → Gameplay Cues）⭐ | 推荐：零胶水 |
| **GameplayCueManager 静态入口** | 无 ASC 目标（墙壁） |

### 6.4 Cue Tag 命名规范

```
GameplayCue.<大类>.<小类>[.<变体>]
```

⚠️ 前缀**必须是** `GameplayCue.`，否则 CueManager 不扫描。

### 6.5 跟随玩家的关键

Looping Cue 要跟随玩家：
1. Notify 父类必须是 **`GameplayCueNotify_Actor`**（不是 Static）
2. `Attach to Owner = true`
3. 调用时传 `Params.Instigator = Avatar`

详见 Day02 补丁 B。

---

## 7. 网络层：Replication & Prediction

### 7.1 ASC 在哪里

| 角色 | ASC 挂在哪 |
|------|-----------|
| **玩家角色** | `PlayerState`（推荐，重生不丢） |
| **AI / 怪物** | `Pawn` / `Character` |

`MyCharacter` 实现 `IAbilitySystemInterface::GetAbilitySystemComponent()` 让框架找到。

### 7.2 属性 Replication

```cpp
UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health)
FGameplayAttributeData Health;

void OnRep_Health(const FGameplayAttributeData& Old)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGASLearnAttributeSet, Health, Old);
}
```

`GetLifetimeReplicatedProps` 里也要登记。

### 7.3 Prediction（普通预测）

- `LocalPredicted` Ability 自带预测
- 客户端立刻播动画 / 扣本地血
- 服务器校验后，错了会"回滚"
- **预测窗口**：`CommitAbility` 之前
- **不可预测的事**：随机数、依赖服务器状态的判定

### 7.4 Scoped Prediction（作用域预测）⭐

普通 Prediction 解决"客户端先动手"的问题，**Scoped Prediction** 解决"客户端发起的副作用如何被服务器认可、且能在校验失败时整体回滚"。

| 概念 | 解释 |
|------|------|
| `FPredictionKey` | 预测会话的"票号"，标识一段预测窗口 |
| `ScopedPredictionWindow` | C++ 里 RAII 风格的作用域，作用域内 Apply 的 GE / 加的 Tag 都被这把 Key 管 |
| **回滚** | 服务器拒绝 → 整个 Scope 内的副作用全部撤销 |

**典型场景**：技能 A 在客户端预测里 `Apply GE_Slow → Slow Buff 立刻生效 → 服务器算了一遍发现 A 早就死了 → Slow Buff 自动撤销**，不需要写一行回滚代码**。

**写法（在 GA 里）**：
```cpp
// 在 ActivateAbility 内
FScopedPredictionWindow PredictionWindow(GetAbilitySystemComponentFromActorInfo(),
                                         CurrentActivationInfo.GetActivationPredictionKey());
// 这一段里 Apply 的 GE 都被 Key 管
```

⚠️ **可预测的副作用**：Apply GE、加 Tag、生成预测 Spawn Actor。  
⚠️ **不可预测**：随机数、读服务器状态判定、永久 Spawn。

### 7.5 GA 之间的 Prediction 协作

- GA-A `LocalPredicted`，里面用 `WaitGameplayEvent` 触发 GA-B → GA-B 也会自动获得 A 的 Prediction Key
- 跨 GA 传 Key：`SendGameplayEvent` 时附带 `EventData.PredictionKey`

---

## 8. 整体数据流（一次完整伤害的旅程）

```
玩家按下 1 键
   │
   ▼
[Input] → AbilitySystemComponent::TryActivateAbility
   │
   ▼
[Client]  GA_Fireball::ActivateAbility   ◄── LocalPredicted
   │      ├─ AddLooseGameplayTag(State.Charging)（阶段 Tag）
   │      ├─ AddGameplayCue(Cue.Fireball.Charging, Params)（蓄力光环）
   │      ├─ AnimBP 检测到 Tag → 进入蓄力状态机
   │      └─ AbilityTask::WaitInputRelease
   │
   ▼ (松手)
   ├─ RemoveLooseGameplayTag(State.Charging)
   ├─ RemoveGameplayCue(Cue.Fireball.Charging)
   ├─ CommitAbility（扣蓝、CD）
   ├─ SpawnActor(FireballProjectile)
   └─ EndAbility
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
[Target ASC] ExecCalc 计算（攻击 × 系数 - 护甲，含暴击）
             ↓
             PreAttributeChange(Damage)
             ↓
             PostGameplayEffectExecute:
                Health -= Damage
                SetDamage(0)
   │
   ▼
OnRep_Health → UI 刷新血条
GE 自带的 Cue.Character.Hit → 闪红飘字（零胶水）
```

把这张图印在脑子里，所有 GAS 问题都能定位到"是哪一段出问题"。

---

## 9. ASC 高频 API 速查

| API | 用途 |
|-----|------|
| `GetGameplayAttributeValue(Attr, bFound)` | 读属性 CurrentValue |
| `GetNumericAttribute(Attr)` | 读 BaseValue（不走 Modifier） |
| `HasMatchingGameplayTag(Tag)` | 是否拥有某 Tag |
| `HasAnyMatchingGameplayTags(Container)` | 是否拥有任意 |
| `HasAllMatchingGameplayTags(Container)` | 是否全部拥有 |
| `AddLooseGameplayTag / Remove...` | 手动 Tag（本地） |
| `AddReplicatedLooseGameplayTag / Remove...` | 手动 Tag（同步） |
| `TryActivateAbilityByTag / ByClass` | 手动激活技能 |
| `CancelAbilities(WithTags, WithoutTags, Ignore)` | 批量取消 |
| `MakeOutgoingSpec(GE, Level, Context)` | 构造 GE Spec |
| `ApplyGameplayEffectSpecToSelf / ToTarget` | 应用 GE |
| `RemoveActiveGameplayEffect(Handle)` | 按 Handle 移除 |
| `GetActiveEffectsTimeRemaining(Query)` | 查 GE 剩余时间（CD UI） |
| `ExecuteGameplayCue / Add / Remove` | Cue 触发 |

---

## 10. 调试工具箱

| 工具 / 命令 | 作用 |
|------------|------|
| `showdebug abilitysystem` | 在 PIE 里叠加 ASC 状态（属性、激活的 GE、Tag、Cue） |
| `AbilitySystem.DebugAbilityTags 1` | Tag 变化打 Log |
| `AbilitySystem.GameplayCue.PrintWarning 1` | Cue 静默失败时打 Warning |
| `gas dumpasc` *(部分版本)* | 把 ASC 状态 dump 到 Log |
| `AbilitySystem.AlwaysConvertGESpecToGCParams 1` | Cue 调试 |
| 编辑器 → Window → Developer Tools → **Gameplay Debugger** | F1 打开，可视化技能/Cue/Tag |
| `RefreshGameplayCueNotifyData()` | 改完 Cue Notify 不重启 PIE 也能生效 |
| 断点 `UAbilitySystemComponent::ApplyGameplayEffectSpecToSelf` | 看每条 GE 进入流程 |

---

## 11. 学习路线图

```
✅ 已学：
   ├─ AttributeSet 基础（Health/MaxHealth/Damage）
   ├─ GE 三种类型 + SetByCaller
   ├─ Ability 生命周期 + LocalPredicted
   ├─ AbilityTask（PlayMontageAndWait / WaitInputRelease）
   ├─ Tag 驱动 AnimBP（蓄力状态机）
   ├─ Native Tag
   ├─ GameplayCue（Burst / Looping，Day02）
   └─ 阶段 Tag vs Ability Tag（Day02 补丁 A）

🔜 进行中（Day03）：
   └─ MMC / ExecCalc：暴击、护甲、吸血、等级缩放

📋 下一步（按优先级）：
   1. MMC / ExecCalc（伤害公式是大多数游戏的刚需）   ← Day03
   2. TargetData（AOE、扇形、目标筛选）
   3. AbilitySet / Loadout（技能装配系统）
   4. 多人网络专题（Prediction Key、Scoped、回滚、RPC）
   5. 高级主题：DA 数据驱动 / GE 资产合并 / 调试工具深挖
```

---

## 12. 关键文件索引

| 文件 | 作用 |
|------|------|
| `Source/MyProject/GAS/GASLearnAttributeSet.h/cpp` | 属性集，HP/MaxHealth/Damage |
| `Source/MyProject/GAS/UGA_Fireball.h/cpp` | 火球技能（含蓄力） |
| `Source/MyProject/CustomActor/AFireballProjectile.cpp` | 弹道，调 SetByCaller |
| `Source/MyProject/MyCharacter.h/cpp` | 实现 IAbilitySystemInterface |
| `Source/MyProject/MyAnimInstance.h/cpp` | AnimBP C++ 基类 |
| `Source/MyProject/GAS/GASLearnGameplayTags.h/cpp` | Native Tag |
| `Source/MyProject/MyProject.Build.cs` | 模块依赖 |

---

## 13. 使用说明（怎么让笔记越记越连贯）

**笔记三层结构**：

```
GAS学习笔记_总纲.md       ← 本文件，体系地图（少改，新主题学完追加章节）
GAS学习笔记_Day01.md      ← 当天速查 + 踩坑（每天一份）
GAS学习笔记_Day02.md      ← ...
GAS学习笔记_Day03.md      ← MMC / ExecCalc
```

**新会话开头给 AI 的"最小上下文"**：
1. `GAS学习笔记_总纲.md` 的 **0/8/11 节**（心智图 + 数据流 + 路线图）
2. 上一份 Day 笔记的 **踩坑速查表 + 关键文件索引**
3. 今天想学/想解决的问题

这样既不丢上下文，又不会塞爆 token。
