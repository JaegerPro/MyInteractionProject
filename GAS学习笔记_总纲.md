# GAS 学习笔记 · 总纲（体系化梳理）

> 创建日期：2026-04-28　修订：2026-05-12  
> 工程：`D:\UnrealProjects\MyProject`  
> 目的：把散落在 Day 笔记里的 GAS 知识点按**主线脉络**串成一张地图。  
> 配套：`GAS学习笔记_DayXX.md`（速查 / 踩坑），本文件（体系 / 心智图）。

> 🤖 **给 AI 的接课须知**（节省 token）：新会话接课时，**只读本总纲即可**，  
> 不要主动打开 `GAS学习笔记_DayXX.md` 任何一篇——每日笔记是人类复习用的，  
> 接课需要的所有状态（进度、已掌握结论、下一步、踩坑）本总纲都已沉淀。  
> 详见 §14。

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

> 📌 阶段切换（2026-05-12）：**GAS 主干学习已结束，转入面试场景化演练**。  
> 当前判断：剩余 GAS 知识点（Tag 互斥、动画阶段化等）均为 API 级组合，  
> 机制级理解已通过 Day06（PredictionKey）/ Day03（ExecCalc）/ Day05（TargetData）覆盖。  
> 继续补 GAS 知识点对面试 / 工作的边际收益已经很低。

```
✅ 已学（详细结论见对应每日笔记）：
   ├─ Day01: AttributeSet / GE 三种类型 / Ability 生命周期 / AbilityTask / Tag 驱动 AnimBP / Native Tag   → `GAS学习笔记_Day01.md`
   ├─ Day02: GameplayCue（Burst / Looping） / 阶段 Tag vs Ability Tag / Looping Cue 跟随玩家              → `GAS学习笔记_Day02.md`
   ├─ Day03: MMC / ExecCalc（暴击、护甲、吸血） / Attribute Capture / Period GE + Snapshot               → `GAS学习笔记_Day03.md`
   ├─ Day04: Buff/Debuff 实战（Burn / Stun） / GE Tag Requirements / Immunity / 属性联动 CMC            → `GAS学习笔记_Day04.md`
   ├─ Day05: TargetData + GroundTrace 地面选点火球                                                        → `GAS学习笔记_Day05.md`
   ├─ Day06: PredictionKey 深啃（理论 + 日志实验）                                                        → `GAS学习笔记_Day06.md`
   ├─ Day07: GA 生命周期 + GE 数据流 双串讲（纯理解篇，未改代码）                                         → `GAS学习笔记_Day07.md`
   └─ Day08: Cooldown 正式化（Duration GE + Cooldown Tag 组合，无新机制）                                  ← 2026-05-12 早

⏭️ 评估后跳过（不是"待学"，是"主动放弃"）：
   ├─ Day09  Tag 互斥规则
   │         理由：ActivationBlockedTags / BlockAbilitiesWithTag / CancelAbilitiesWithTag
   │         本质是字段组合，API 级。机制理解已通过 Day06 PredictionKey 覆盖，
   │         回头学性价比低。
   │
   └─ Day10  动画阶段化（Montage 三段 + AnimNotify 关键帧）
             理由：(1) 缺合适的动画资源，硬学就是看文档背 API；
                   (2) 火球代码里其实已经做了 Charge.Active Tag + Cue 跟随，
                       要系统化也只是命名 + 模板抽取，没有新机制；
                   (3) API 级组合，对面试边际收益低。

🔄 备选方向（如果将来想拓展，但不是当前重心）：
   ├─ A. 网络预测进阶（ScopedPrediction 小 demo / 回滚可视化）
   ├─ B. AbilitySet 资产化
   ├─ C. UE5 TargetingSystem 插件
   └─ D. AI 怪物接 GAS

⏸ 明确暂不做：
   ├─ 多人网络深挖（Prediction 源码级）
   ├─ GameFeature Plugin 化
   └─ 大型项目框架重构（AbilitySet + 装备驱动整套）
```

### 11.1 阶段总结（给未来的自己 / 下次接课的 AI 看）

Day01~Day08 已完成 GAS 核心闭环：
- **数据层**：Attribute / AttributeSet / Meta Attribute / Clamp 两种位置
- **行为层**：GE 三种 Duration / SetByCaller / GA 生命周期 / Cost & Cooldown / AbilityTask 黄金法则
- **表现层**：Tag 驱动 AnimBP / Montage / GameplayCue 四种触发方式 / Looping Cue 跟随
- **网络层**：Replication / Prediction / **ScopedPrediction（机制级，不是 API 级）**
- **数值计算**：MMC / ExecCalc / Attribute Capture / Period GE + Snapshot
- **目标系统**：TargetData / GroundTrace / 两段式 Spawn

**没学但已主动评估放弃的**：Day09 Tag 互斥、Day10 动画阶段化。理由见上。

**这个状态不是"GAS 没学完"，是"GAS 主干学透了，转入下一阶段"。**  
未来回看本笔记如果又焦虑"是不是还有什么没学"——回到这一节读一遍。

---

## 12. 接下来做什么（面试演练阶段）

> 📌 当前阶段（2026-05-12 起）：**不再补 GAS 知识点，转入"把已掌握的东西讲出来"**。

### 12.1 主线：「卡 + 图」面试演练

**形式**：每张卡一个 GAS 主题，正面是面试官的问法，背面是 60 秒口述版本 + 一张机制图。
AI 出题 → 用户答 → AI 打分 + 给改进点。

**优先出题方向**（按"面试出现频率 × 用户素材充足度"排）：

| 序号 | 主题 | 素材所在 | 难度 |
|------|------|----------|------|
| 1 | GameplayCue 怎么用、为什么要分 Burst / Looping | Day02 + UGA_Fireball | 中 |
| 2 | GAS 网络预测怎么理解（PredictionKey / ScopedPrediction） | Day06 | 高（用户最强项） |
| 3 | 伤害怎么算（MMC / ExecCalc / Meta Attribute） | Day03 + ExecCalc_Damage | 中 |
| 4 | TargetData 流程 / 为什么要两段式 Spawn | Day05 + UGA_FireballGround | 中 |
| 5 | GA 的 Commit 机制 / Cost 和 Cooldown 为什么是 GE | Day08 + UGA_Fireball | 低 |
| 6 | Ability 之间怎么协作 / Ability 怎么取消 | 综合 | 低 |
| 7 | GAS 适合什么项目 / 不适合什么 | 综合 + PawnState 对比 | 高（差异化加分点） |

### 12.2 次线：「读代码方」讲法定调

用户工作中读过但**未参与设计**的项目代码：
- `PawnState / PawnStateComponent`：uint64 位掩码 + 互斥矩阵 + 引用计数 disable
- `PersistEffectBase / PersistEffectWithState`：网络复制的"持久效果"系统（轻量级 GE 替代品）
- `FakePossessComponent / FakePossessInterface`：伪 Possess 系统
- `MyClickActorComponent / MyActivityActor`：交互系统

**讲法原则**：
- **不能**说"我自己写了一套 X"——会被追问设计决策时穿帮
- **应该**说"项目里有这套 X，我作为交互物开发需要用到，所以读懂了它的实现 + 和 GAS 做过横向对比"
- **加分点**：读代码方 + 横向对比 = "能读懂复杂系统 + 有技术判断力"，比"会用 GAS"稀缺

具体每套系统的"60 秒讲法模板"在演练阶段按需产出，不预先全写。

### 12.3 不做什么

- ❌ 不再按"补 GAS 知识点"的思路推进（Day09 / Day10 已评估放弃）
- ❌ 不写长篇背诵稿（用户风格抗拒长背书，走"机制图 + 短口述"路线）
- ❌ 不主动让用户写"项目外资产"的故事（PawnState 不是用户写的，硬讲会穿帮）

---

## 13. 关键文件索引

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

## 14. 使用说明（怎么让笔记越记越连贯）

**笔记三层结构**：

```
GAS学习笔记_总纲.md       ← 本文件，体系地图 + 进度状态（每节课后追加/修订）
GAS学习笔记_DayXX.md      ← 每日笔记（速查 + 踩坑 + 自检），人类复习用
```

### 14.1 🤖 AI 接课规则（省 token 的关键）

**新会话开窗口后，AI 应当遵守**：

1. **只读本总纲，不要主动打开任何 `GAS学习笔记_DayXX.md`**。  
   每日笔记是写给人类复习用的，里面有大量口语化复述和例题，AI 接课不需要。  
   接课需要的所有信息（进度、已掌握结论、下一步、关键踩坑）本总纲都已沉淀——  
   §11 路线图看进度，§12 看下一步做什么，§0~§10 看体系，§13 看代码文件索引。

2. **需要读源码时，直接按 §13 索引读**，不要靠翻每日笔记来定位文件。

3. **用户主动提到"Day05 那里怎么做的"之类具体问题**，再按需打开对应 `GAS学习笔记_DayXX.md`。  
   没明确指向时不要预防性翻阅。

4. **课后只更新总纲的"进度指针"，不要往总纲塞知识点**。  
   每讲完一节课，只改两处：  
   （a）§11 "已学"列表追加一行 `Day0X: 主题简述 → GAS学习笔记_Day0X.md`  
   （b）§11 "后续路线" 把 `◄── 下一节` 标记挪到下一个 Day  
   具体知识点、踩坑、代码片段**一律写进每日笔记**，不写进总纲。  
   每日笔记由用户自己写（手写过程本身就是学习），AI 不代劳。  
   > ⚠️ 反例：把"PredictionKey 两种生成时机"、"ctor 不能碰 ASC"这种细节塞进 §11——  
   > 总纲会越长越难读，违背"只作为体系地图 + 接课指引"的定位。

5. **总纲里的体系章节（§0~§10）只在发现错误/不精确时才改**，不要每节课都追加。  
   如果某节课学到的新东西和 §0~§10 某条结论冲突，直接修订那条；  
   否则不要扩写（要扩写也先问用户是否同意）。

6. **用户说"继续上课"时的标准动作**：
   - ⚠️ **先看 §11 顶部的"阶段切换"——2026-05-12 起已经不是"上课"阶段，是面试演练阶段**
   - 如果用户说"继续"、"接着来"之类——默认是要继续 §12 的面试演练，不是要上新 Day 的课
   - 只有用户**明确**说"想学 X 知识点"才开新课

7. **关于"下一节讲啥"的判断**：
   - Day08 之后**没有 Day09**（见 §11，评估后跳过）
   - 如果用户问"接下来学什么"——不要默认回答"Day09"，要按 §12 的方向回答（面试演练 / 读代码方讲法）
   - 这个笔记体系已经从"补知识"切换到"整理输出"，AI 要识别这个阶段切换

8. **关于用户的学习风格（重要）**：
   - 抗拒长篇背诵稿——走"机制图 + 短口述（60 秒内）"路线
   - 喜欢自己推导 + 踩坑复盘，不喜欢被直接喂答案
   - 能区分"API 级"和"机制级"，不要用 API 级内容充数
   - 项目里 `PawnState / PersistEffect / FakePossess` 等代码**不是用户写的**，是工作里读过学习的——不要当作"用户的自研作品"讲

### 14.2 用户自己的使用方法

- 每节课结束后写一篇 `GAS学习笔记_DayXX.md`，结构建议：一句话速记 / 自己重新讲一遍 / 自检题答案 / 与此前内容的串联。
- 写笔记这件事**不要让 AI 代劳**——用自己的话重新组织一遍，才是学习发生的那一刻。
- 写完笔记后，如果发现总纲里哪条结论不对 / 不够精确，直接让 AI 改总纲。
