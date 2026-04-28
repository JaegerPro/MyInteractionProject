# GAS 学习笔记 · Day 01

> 日期：2026-04-28  
> 工程：`D:\UnrealProjects\MyProject`  
> 主题：GAS 入门 —— 属性 / 效果 / 技能 / 动画联动 / Tag 驱动状态机

---

## 一、今日踩坑速查表（先扫一眼，以后忘了来这里找）

| # | 现象 | 根因 | 正确做法 |
|---|------|------|----------|
| 1 | HP 显示为 1 | `InitHealth(1)` + `DefaultAttributesEffect` 没配 | 用 `GE_InitAttributes` 初始化，Clamp 顺序要对 |
| 2 | 打一下反而加血 | Modifier 用了正数 `Coefficient` | 改成 `-1`，或走 Damage Meta Attribute |
| 3 | Montage 勾了 Loop 还是不循环 | `PlayMontageAndWait` 不支持循环 | Tag 驱动 AnimBP 状态机 |
| 4 | `HasMatchingGameplayTag` 不能连 Transition | 它不是纯函数 | 用 `AbilitySystemBlueprintLibrary::HasMatchingGameplayTag`（纯函数版本） |
| 5 | `.generated.h must appear at the top` | 文件名 `MyAnimInstance .h` 里有空格 | 重命名文件 + 删 `Intermediate/` 重新生成 |
| 6 | AnimBP 报"尚不支持双向传输" | 一条 Transition 不能双向 | 画两条独立单向线，或用 Conduit 节点 |
| 7 | `ActivationOwnedTags` 不生效 | 蓝图 CDO 覆盖了 C++ 默认值 | 在 `BP_GA_Fireball` 的 Class Defaults 里手动加 Tag |
| 8 | `BlueprintAuthorityOnly` 客户端调用无效 | 该节点只在服务端执行 | 走 Ability 的 `NetExecutionPolicy=LocalPredicted` |

---

## 二、核心知识卡片

### ? 卡片 1：AttributeSet 初始化三件套

```cpp
// .h
UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health)
FGameplayAttributeData Health;
ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, Health)
```

**初始化坑点**：  
- ? 不要在构造函数里 `InitHealth(100)` 然后以为就有 100 血  
- ? 用 `GE_InitAttributes`（Instant 型 GE）在 `PossessedBy` 时 Apply 一次

**PreAttributeChange 里 Clamp 的正确顺序**：
```cpp
if (Attribute == GetHealthAttribute())
{
    NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth()); // 先读 MaxHealth
}
```
?? 如果 `MaxHealth` 也在被同一个 GE 修改，可能读到旧值 —— 这时走 `PostGameplayEffectExecute` 更稳。

---

### ? 卡片 2：Damage Meta Attribute 模式（最佳实践）

> Meta Attribute = 中转站，不持久化，只是"本次伤害多少"的临时变量。

```cpp
// 1. 在 AttributeSet 里声明 Damage（Meta，不 Replicate）
UPROPERTY(BlueprintReadOnly)
FGameplayAttributeData Damage;

// 2. PostGameplayEffectExecute 里转成 Health 扣减
if (Data.EvaluatedData.Attribute == GetDamageAttribute())
{
    const float LocalDamage = GetDamage();
    SetDamage(0.f);                              // 用完清零
    SetHealth(FMath::Max(GetHealth() - LocalDamage, 0.f));
}
```

**好处**：  
- 伤害流程和血量解耦，未来加护盾、暴击、吸血只改 `PostGameplayEffectExecute`  
- `Coefficient` 正常填 **正数**，语义清晰

---

### ? 卡片 3：SetByCaller 动态伤害

**GE 配置**：Modifier → Magnitude Calculation Type = `SetByCaller` → Data Tag = `Data.Damage`

**C++ 触发**：
```cpp
FGameplayEffectSpecHandle SpecHandle =
    Source->MakeOutgoingSpec(DamageGE, 1.f, Source->MakeEffectContext());

UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(
    SpecHandle, GASTags::Data_Damage, DamageAmount); // 正数即可

Source->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), Target);
```

**公式记忆**：`Final = (Value + PreMul) * Coefficient + PostMul`

---

### ? 卡片 4：Tag 驱动 AnimBP（替代 Montage 循环）

**为什么不用 Montage 循环**：  
- `PlayMontageAndWait` 监听 OnCompleted，循环时永远不完成 → Ability 卡死  
- Montage 本质是"一次性动作"，不是"状态"

**正确方案 —— 三步走**：

1. **Ability 端**：进入蓄力时打 Tag
```cpp
// 方案 A（推荐）：ActivationOwnedTags（自动加 / 自动移）
// 构造函数里
ActivationOwnedTags.AddTag(GASTags::State_Charging);
```
?? **坑**：如果蓝图子类 `BP_GA_Fireball` 的 Class Defaults 面板里 `ActivationOwnedTags` 是空的，蓝图 CDO 会**覆盖** C++ 默认值 → 需要**在蓝图面板里也加一次**，或者走方案 B：

```cpp
// 方案 B：手动打 Tag
ASC->AddLooseGameplayTag(GASTags::State_Charging);
// EndAbility 里
ASC->RemoveLooseGameplayTag(GASTags::State_Charging);
```
?? Loose Tag 不同步到客户端，多人要用 `AddReplicatedLooseGameplayTag`。

2. **AnimBP 端**：在 `AnimInstance` 里绑定 Tag → Bool
```cpp
// .h
UPROPERTY(EditDefaultsOnly)
FGameplayTagBlueprintPropertyMap TagMap; // 来自 GameplayEffectTypes.h

// .cpp NativeInitializeAnimation
if (IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(TryGetPawnOwner()))
{
    TagMap.Initialize(this, ASI->GetAbilitySystemComponent());
}
```

3. **状态机 Transition**：用纯函数版本
```
AbilitySystemBlueprintLibrary::HasMatchingGameplayTag(ASC, State.Charging) == true
```

---

### ? 卡片 5：AnimBP 状态机双向 Transition

**错误**："尚不支持双向传输 Idle → Charging"

**原因**：一条连线只能单向。

**解法**：
- ? 画两条独立箭头：Idle → Charging 一条，Charging → Idle 一条
- ? 复杂分支用 **Conduit 节点**（菱形）作为中转，多入多出

---

### ? 卡片 6：Ability 网络模式

| NetExecutionPolicy | 含义 | 使用场景 |
|--------------------|------|----------|
| `LocalOnly` | 只在本地跑 | 纯表现、UI |
| `LocalPredicted` ? | 客户端预测 + 服务器校验 | **大多数主动技能** |
| `ServerInitiated` | 服务端发起 | 被动触发 |
| `ServerOnly` | 只服务端 | 扣血、给 Buff |

**`BlueprintAuthorityOnly` 节点的坑**：  
这类节点只在服务端执行，客户端调用会静默失败。如果你的 Ability 是 `LocalPredicted`，**扣血 / 应用 GE 要走 ASC 的标准接口**（`ApplyGameplayEffectToSelf` 等），它们内部已经处理了预测 + 同步。

---

### ? 卡片 7：`.generated.h` 文件名坑

**错误**：`The given include must appear at the top of the header following all other includes: '#include "MyAnimInstance .generated.h"'`

**根因**：头文件名是 `MyAnimInstance .h`（**末尾有空格**），UHT 生成的 `MyAnimInstance .generated.h` 和你代码里 `#include "MyAnimInstance.generated.h"` 对不上。

**修复步骤**：
1. 在资源管理器里重命名文件，去掉空格 → `MyAnimInstance.h`
2. 同步改 `.cpp` 里的 `#include "MyAnimInstance.h"`
3. 关闭编辑器，**删除 `Intermediate/` 和 `Binaries/`**
4. 右键 `.uproject` → `Generate Visual Studio project files`
5. 重新编译

---

## 三、GAS 四象限学习法（你后续学习的罗盘）

```
            ┌─────────────────────────────┐
            │         表现层（Cue）         │
            │  GameplayCue / Anim / VFX    │
            └─────────────────────────────┘
                        ▲
                        │
┌───────────────┐       │       ┌───────────────┐
│  数据层         │ ?─────┼─────? │  行为层         │
│ AttributeSet  │       │       │ Ability / GE   │
│ GameplayTag   │       │       │ AbilityTask    │
└───────────────┘       │       └───────────────┘
                        ▼
            ┌─────────────────────────────┐
            │         网络层                │
            │ NetExecutionPolicy / Predict │
            │ Replication / RPC            │
            └─────────────────────────────┘
```

**学习顺序建议**：数据 → 行为 → 表现 → 网络，每个象限吃透再往下。

---

## 四、明日可选方向（二选一，别贪多）

- **A. 继续深挖**：`ActivationOwnedTags` 没生效 → 专题排查（CDO 覆盖 / 生命周期 / 客户端同步）
- **B. 推进新主题**：`GameplayCue` 表现层（把 VFX / SFX 从 Ability 里解耦出去）

---

## 五、本次会话关键文件索引

| 文件 | 作用 |
|------|------|
| `Source/MyProject/GASLearnAttributeSet.h/cpp` | 属性集，HP/MaxHealth/Damage |
| `Source/MyProject/UGA_Fireball.h/cpp` | 火球技能，含蓄力逻辑 |
| `Source/MyProject/AFireballProjectile.cpp` | 弹道，调用 SetByCaller 伤害 |
| `Source/MyProject/MyCharacter.h/cpp` | 实现 `IAbilitySystemInterface` |
| `Source/MyProject/MyAnimInstance.h` | AnimBP C++ 基类（注意曾经带空格） |
| `Source/MyProject/GASLearnGameplayTags.h/cpp` | Native Tag 定义 |
| `Source/MyProject/MyProject.Build.cs` | 已含 GameplayAbilities/Tags/Tasks |

---

> ? **使用建议**：以后每天一份 `GAS学习笔记_DayXX.md`，新会话开头只把**上一份笔记的"踩坑速查表"和"关键文件索引"**喂给 AI，不用把完整对话历史都带上，上下文立刻清爽。
