# GAS 学习笔记 · Day 03

> 日期：2026-05-06  
> 工程：`D:\UnrealProjects\MyProject`  
> 主题：**MMC / ExecCalc** —— 把伤害做厚（暴击 / 护甲 / 吸血 / 等级缩放）  
> 对应总纲：第 2.2 节（Magnitude 计算公式）扩展

---

## 一、为什么需要 MMC / ExecCalc

到 Day02 为止，伤害是这样算的：

```
ApplyGE_Damage20(Spec) → SetByCaller(Data.Damage, 20) → Modifier 把 20 写进 Damage Meta
```

数字写死，加不了暴击、加不了护甲、加不了吸血。要扩展就有两条路：

| 方案 | 适合什么 | 给什么 |
|------|---------|--------|
| **MMC**（ModifierMagnitudeCalculation） | **单个 Modifier** 的数值需要"按公式算"，但不改其他属性 | `float CalculateBaseMagnitude_Implementation(Spec)` 返回一个数 |
| **ExecCalc**（GameplayEffectExecutionCalculation） | 需要**同时输出多个 Modifier**（伤害+生命偷取+护甲穿透），或读多个属性、写多个属性 | 一个函数里手动塞 `OutExecutionOutput` 多条 Modifier |

**一句话区分**：

> **MMC 是"我算一个数"，ExecCalc 是"我算一组结果"。**

⚠️ 还有人会问：那 SetByCaller / AttributeBased 不是也能算吗？区别在 **能读 `EvaluateParameters` 拿到 Source/Target 的所有属性 + Tag + Spec 等级**——MMC/ExecCalc 才有完整上下文。

---

## 二、今日速查表

| # | 现象 / 场景 | 记住这条 |
|---|------------|---------|
| 1 | 想加暴击 | 用 ExecCalc，一次算"是否暴击 + 最终伤害" |
| 2 | 想做"攻击 - 护甲" | 简单的 MMC 就够（只算一个数） |
| 3 | 想做"造成伤害的 30% 吸血" | ExecCalc 同时输出 Damage 和 Healing 两条 Modifier |
| 4 | 公式要按等级缩放 | `Spec.GetLevel()` 在 MMC/ExecCalc 都可用 |
| 5 | 想读 Source 的 AttackPower、Target 的 Armor | `RelevantAttributesToCapture` 登记 → `GetCapturedAttributeMagnitude` 读 |
| 6 | 暴击时给"暴击事件" Tag | `OutExecutionOutput.MarkGameplayCuesHandledManually()` + `AddOutputModifier` 之外，可以用 `Spec.AddDynamicAssetTag` 或 `OutExecutionOutput.MarkConditionalGameplayEffectsToTrigger` |
| 7 | ExecCalc 跑了但属性没变 | 没 `AddOutputModifier`，或者 Modifier 用错了 Op |
| 8 | 改了 ExecCalc 不重新编译 | C++ 类必须**实编译**，蓝图子类靠 C++ 父类执行 |
| 9 | Backing Attribute（捕获的属性）总是 0 | 没在构造函数 `RelevantAttributesToCapture.Add(Def)`，或 `Def.AttributeToCapture` 没初始化 |
| 10 | Source 是谁？Target 是谁？ | 发起方 = Source（攻击者 ASC），承受方 = Target（受击 ASC）。`MakeOutgoingSpec` 时 Source 自动定，`ApplyTo(Target)` 时 Target 自动定 |

---

## 三、知识卡片

### 💎 卡片 1：Attribute Capture（属性捕获）

ExecCalc/MMC 要读外部属性必须先"捕获"。

**捕获定义**：

```cpp
// 在 ExecCalc/MMC 类里
struct FDamageStatics
{
    // 1. 声明 Capture 定义
    DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);   // Source 端
    DECLARE_ATTRIBUTE_CAPTUREDEF(Armor);         // Target 端
    DECLARE_ATTRIBUTE_CAPTUREDEF(CritChance);    // Source 端
    DECLARE_ATTRIBUTE_CAPTUREDEF(CritDamage);    // Source 端

    FDamageStatics()
    {
        // 2. 绑定到属性集 + 指定来源 + 是否快照
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, AttackPower, Source, true);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, Armor,       Target, false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, CritChance,  Source, true);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, CritDamage,  Source, true);
    }
};

static const FDamageStatics& DamageStatics()
{
    static FDamageStatics S;
    return S;
}
```

**两个关键参数**：

| 参数 | 含义 |
|------|------|
| `Source / Target` | 这个属性从攻击者读还是从受击者读 |
| `bSnapshot`（最后那个 bool） | **`true`**：MakeSpec 时拍快照（推荐用于 Source 攻击力，避免施法过程被改变）；**`false`**：Apply 时实时读（推荐用于 Target 护甲、HP，能反映当前状态） |

**构造函数里登记**（让框架知道要捕获）：

```cpp
UGEExec_Damage::UGEExec_Damage()
{
    RelevantAttributesToCapture.Add(DamageStatics().AttackPowerDef);
    RelevantAttributesToCapture.Add(DamageStatics().ArmorDef);
    RelevantAttributesToCapture.Add(DamageStatics().CritChanceDef);
    RelevantAttributesToCapture.Add(DamageStatics().CritDamageDef);
}
```

**读取**：

```cpp
const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
FAggregatorEvaluateParameters EvalParams;
EvalParams.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
EvalParams.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

float AttackPower = 0.f;
ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
    DamageStatics().AttackPowerDef, EvalParams, AttackPower);

float Armor = 0.f;
ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
    DamageStatics().ArmorDef, EvalParams, Armor);
```

> ⚠️ `AttemptCalculate...` 的两个返回方式：成员函数返回 bool（成功/失败）+ 通过 out 参数拿值。失败一般是因为**没 Capture**。

---

### 💎 卡片 2：MMC 写法（最简单的"一个数"）

适合："攻击 - 护甲 × 0.5"这种**单一输出**公式。

**`UMMC_BasicDamage.h`**：

```cpp
#pragma once
#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "UMMC_BasicDamage.generated.h"

UCLASS()
class MYPROJECT_API UMMC_BasicDamage : public UGameplayModMagnitudeCalculation
{
    GENERATED_BODY()
public:
    UMMC_BasicDamage();
    virtual float CalculateBaseMagnitude_Implementation(
        const FGameplayEffectSpec& Spec) const override;

private:
    FGameplayEffectAttributeCaptureDefinition AttackPowerDef;
    FGameplayEffectAttributeCaptureDefinition ArmorDef;
};
```

**`UMMC_BasicDamage.cpp`**：

```cpp
#include "UMMC_BasicDamage.h"
#include "GAS/GASLearnAttributeSet.h"

UMMC_BasicDamage::UMMC_BasicDamage()
{
    AttackPowerDef.AttributeToCapture = UGASLearnAttributeSet::GetAttackPowerAttribute();
    AttackPowerDef.AttributeSource    = EGameplayEffectAttributeCaptureSource::Source;
    AttackPowerDef.bSnapshot          = true;

    ArmorDef.AttributeToCapture = UGASLearnAttributeSet::GetArmorAttribute();
    ArmorDef.AttributeSource    = EGameplayEffectAttributeCaptureSource::Target;
    ArmorDef.bSnapshot          = false;

    RelevantAttributesToCapture.Add(AttackPowerDef);
    RelevantAttributesToCapture.Add(ArmorDef);
}

float UMMC_BasicDamage::CalculateBaseMagnitude_Implementation(
    const FGameplayEffectSpec& Spec) const
{
    FAggregatorEvaluateParameters Eval;
    Eval.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    Eval.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

    float Atk = 0.f, Armor = 0.f;
    GetCapturedAttributeMagnitude(AttackPowerDef, Spec, Eval, Atk);
    GetCapturedAttributeMagnitude(ArmorDef,       Spec, Eval, Armor);

    const float Level = Spec.GetLevel();           // 等级缩放
    const float Base  = Atk * (1.f + 0.1f * Level); // 攻击 ×（1 + 等级×10%）

    return FMath::Max(Base - Armor * 0.5f, 1.f);   // 护甲减伤，至少 1
}
```

**GE 里怎么挂**：

```
GE_Damage_Basic
├─ Modifier: Damage
│  ├─ Op: Add
│  └─ Magnitude Calculation Type: CustomCalculationClass
│      └─ Class: UMMC_BasicDamage
└─ Modifier 公式（Final = (Base + PreMul) * Coeff + PostMul）
   ├─ Coefficient: 1.0
   ├─ PreMul: 0.0
   └─ PostMul: 0.0
```

---

### 💎 卡片 3：ExecCalc 写法（"一组结果"）

适合：暴击 + 护甲 + 吸血 + 减伤标签判断 ……一次性算完。

**`UExec_Damage.h`**：

```cpp
#pragma once
#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "UExec_Damage.generated.h"

UCLASS()
class MYPROJECT_API UExec_Damage : public UGameplayEffectExecutionCalculation
{
    GENERATED_BODY()
public:
    UExec_Damage();
    virtual void Execute_Implementation(
        const FGameplayEffectCustomExecutionParameters& ExecParams,
        FGameplayEffectCustomExecutionOutput& OutOutput) const override;
};
```

**`UExec_Damage.cpp`**：

```cpp
#include "UExec_Damage.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "GAS/GASLearnAttributeSet.h"
#include "GAS/GASLearnGameplayTags.h"

struct FDStatics
{
    DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
    DECLARE_ATTRIBUTE_CAPTUREDEF(Armor);
    DECLARE_ATTRIBUTE_CAPTUREDEF(CritChance);
    DECLARE_ATTRIBUTE_CAPTUREDEF(CritDamage);
    DECLARE_ATTRIBUTE_CAPTUREDEF(LifeSteal);
    FDStatics()
    {
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, AttackPower, Source, true);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, Armor,       Target, false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, CritChance,  Source, true);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, CritDamage,  Source, true);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, LifeSteal,   Source, true);
    }
};
static const FDStatics& Stats() { static FDStatics S; return S; }

UExec_Damage::UExec_Damage()
{
    RelevantAttributesToCapture.Add(Stats().AttackPowerDef);
    RelevantAttributesToCapture.Add(Stats().ArmorDef);
    RelevantAttributesToCapture.Add(Stats().CritChanceDef);
    RelevantAttributesToCapture.Add(Stats().CritDamageDef);
    RelevantAttributesToCapture.Add(Stats().LifeStealDef);
}

void UExec_Damage::Execute_Implementation(
    const FGameplayEffectCustomExecutionParameters& ExecParams,
    FGameplayEffectCustomExecutionOutput& OutOutput) const
{
    const FGameplayEffectSpec& Spec = ExecParams.GetOwningSpec();

    FAggregatorEvaluateParameters Eval;
    Eval.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    Eval.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

    // 1) 读捕获的属性
    float Atk = 0.f, Armor = 0.f, CritC = 0.f, CritD = 1.5f, LifeS = 0.f;
    ExecParams.AttemptCalculateCapturedAttributeMagnitude(Stats().AttackPowerDef, Eval, Atk);
    ExecParams.AttemptCalculateCapturedAttributeMagnitude(Stats().ArmorDef,       Eval, Armor);
    ExecParams.AttemptCalculateCapturedAttributeMagnitude(Stats().CritChanceDef,  Eval, CritC);
    ExecParams.AttemptCalculateCapturedAttributeMagnitude(Stats().CritDamageDef,  Eval, CritD);
    ExecParams.AttemptCalculateCapturedAttributeMagnitude(Stats().LifeStealDef,   Eval, LifeS);

    // 2) 读 SetByCaller 的"基础伤害"（技能强度）
    const float BaseDamage = Spec.GetSetByCallerMagnitude(
        GASTags::Data_Damage, /*WarnIfNotFound=*/false, /*DefaultIfNotFound=*/0.f);

    // 3) 等级缩放
    const float Level = Spec.GetLevel();
    float Damage = (BaseDamage + Atk) * (1.f + 0.08f * (Level - 1.f));

    // 4) 护甲减伤（线性公式，可换成 K/(K+Armor) 这种百分比公式）
    Damage = FMath::Max(Damage - Armor * 0.5f, 1.f);

    // 5) 暴击判定
    const bool bCrit = FMath::FRand() * 100.f < CritC;
    if (bCrit)
    {
        Damage *= FMath::Max(CritD, 1.f);
    }

    // 6) 标签：减伤（目标"格挡中"减 50%）
    if (Eval.TargetTags->HasTag(GASTags::State_Blocking))
    {
        Damage *= 0.5f;
    }

    // 7) 输出 Modifier：扣 Target 的 Damage（Meta），由 PostGameplayEffectExecute 转 Health
    OutOutput.AddOutputModifier(
        FGameplayModifierEvaluatedData(
            UGASLearnAttributeSet::GetDamageAttribute(),
            EGameplayModOp::Additive,
            Damage));

    // 8) 吸血：给 Source 加血（同一个 Exec 里输出第二条 Modifier）
    if (LifeS > KINDA_SMALL_NUMBER)
    {
        const float Heal = Damage * LifeS;
        // 找 Source ASC，单独 Apply 一条治疗 GE 是更干净的做法（见后文"吸血二选一"）
        // 这里演示：直接通过 OutputModifier 的 SourceAttribute 扣回 —— 不能这样写，
        // OutOutput 只能改 Target 属性；吸血必须走"额外 Apply 一条 GE 到 Source"。
    }

    // 9) 暴击事件 Tag → Cue 飘"CRITICAL!"飘字
    if (bCrit)
    {
        FGameplayEffectContextHandle Ctx = Spec.GetEffectContext();
        if (UAbilitySystemComponent* TargetASC =
                ExecParams.GetTargetAbilitySystemComponent())
        {
            FGameplayCueParameters P;
            P.AggregatedSourceTags.AddTag(GASTags::Event_Damage_Crit);
            P.RawMagnitude = Damage;
            TargetASC->ExecuteGameplayCue(GASTags::Cue_Damage_Crit, P);
        }
    }
}
```

**重点**：
- `OutOutput.AddOutputModifier` 是 ExecCalc 的"输出口"。**它只能写 Target 的属性**。
- 想给 Source 加血？走"再 Apply 一条 GE_LifeSteal 到 Source"，详见卡片 4。
- 暴击/格挡这种"事件性"的东西，走 GameplayCue 反馈到表现层。

---

### 💎 卡片 4：吸血的两种实现

**方案 A：ExecCalc 内部 Apply 一条治疗 GE 到 Source**（推荐）

```cpp
// 在 Execute_Implementation 末尾
if (LifeS > KINDA_SMALL_NUMBER && Damage > 0.f && LifeStealHealEffect)
{
    UAbilitySystemComponent* SourceASC = ExecParams.GetSourceAbilitySystemComponent();
    if (SourceASC)
    {
        FGameplayEffectContextHandle Ctx = SourceASC->MakeEffectContext();
        FGameplayEffectSpecHandle HealSpec =
            SourceASC->MakeOutgoingSpec(LifeStealHealEffect, Spec.GetLevel(), Ctx);

        UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(
            HealSpec, GASTags::Data_Heal, Damage * LifeS);

        SourceASC->ApplyGameplayEffectSpecToSelf(*HealSpec.Data.Get());
    }
}
```

`LifeStealHealEffect` 在 ExecCalc 里 `UPROPERTY(EditDefaultsOnly) TSubclassOf<UGameplayEffect>`，蓝图配。

**方案 B：在 GE_Damage 上直接挂一条"Conditional GE"**（更优雅）

GE 资产 → `Display` → `Conditional Gameplay Effects` → 满足某 Tag 时自动 Apply。  
配合 Tag `Source.HasTag(Buff.LifeSteal)` 触发。

---

### 💎 卡片 5：MMC vs ExecCalc 选型

| 需求 | MMC | ExecCalc |
|------|-----|---------|
| 算一个数（攻击 - 护甲） | ⭐ | 可以但杀鸡用牛刀 |
| 算多个属性（伤害 + 吸血 + 破甲） | ❌ | ⭐ |
| 想读 Source/Target 多个属性 | ✅ | ✅ |
| 想根据 Tag 改公式 | ✅ | ✅ |
| 想"伤害 + 触发暴击 Cue + 吸血 GE" | ❌ 单一输出 | ⭐ |
| 复杂度成本 | 低 | 中 |

**经验法则**：能用 MMC 就用 MMC，否则上 ExecCalc。

---

### 💎 卡片 6：等级缩放（按角色等级 / 技能等级）

**两种"等级"来源**：

| 来源 | 怎么读 | 含义 |
|------|-------|------|
| **Spec 等级** | `Spec.GetLevel()` | `MakeOutgoingSpec(GE, Level, Ctx)` 里传的等级，常用作"技能等级" |
| **Source 角色等级** | 通过 Capture 一个 `CharacterLevel` 属性读 | 角色身上的等级属性 |

**ScalableFloat（曲线表）**：在不写代码的前提下做等级缩放：

```
GE 资产 → Modifier → Magnitude:
   ScalableFloat
   ├─ Value: 10
   └─ Curve Table Row: DT_DamageByLevel.Fireball  ← 关联曲线
```

曲线 X 轴 = 等级，Y 轴 = 倍率。运行时 `Final = Value * Curve(Level)`。

**MMC 里**：
```cpp
const float Lv = Spec.GetLevel();
return Base * Lv;
```

---

### 💎 卡片 7：Backing Attribute（让 Modifier 自动跟着属性变）

如果你写的是 Duration GE（Buff），**Backing Attribute** 可以让"伤害随攻击力实时变化"。

GE 资产 → Modifier → Magnitude:
```
AttributeBased
├─ Backing Attribute:
│   └─ Source.AttackPower（指定来源）
├─ Coefficient: 1.0
├─ Pre Add: 0
└─ Post Add: 0
```

实现的就是：Buff 持续期间，攻击力被另一条 Buff 加成 → 这条 Buff 的伤害也跟着涨。

⚠️ **MMC/ExecCalc 算的是 BaseValue（Instant）或一次性快照（Duration）**，不会自动跟随。要"实时跟"必须用 AttributeBased。

---

## 四、本日改造步骤（火球升级到 1.0 → 暴击/护甲/吸血）

### Step 0：先扩 AttributeSet

在 `GASLearnAttributeSet.h` 里新增：

```cpp
// === 战斗属性 ===
UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_AttackPower)
FGameplayAttributeData AttackPower;
ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, AttackPower)

UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Armor)
FGameplayAttributeData Armor;
ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, Armor)

UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CritChance)
FGameplayAttributeData CritChance;          // 0~100，百分比
ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, CritChance)

UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CritDamage)
FGameplayAttributeData CritDamage;          // 倍率，1.5 = +50%
ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, CritDamage)

UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_LifeSteal)
FGameplayAttributeData LifeSteal;           // 0~1
ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, LifeSteal)
```

OnRep / GetLifetimeReplicatedProps 一并补上。

`GE_InitAttributes` 里给默认值（AP=10, Armor=2, CritC=10, CritD=1.5, LifeS=0）。

### Step 1：新增 Tag

`GASLearnGameplayTags.h/cpp`：

```cpp
UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Blocking);     // 格挡中
UE_DECLARE_GAMEPLAY_TAG_EXTERN(Data_Heal);          // SetByCaller heal
UE_DECLARE_GAMEPLAY_TAG_EXTERN(Event_Damage_Crit);  // 暴击事件
UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cue_Damage_Crit);    // 暴击飘字 Cue

UE_DEFINE_GAMEPLAY_TAG(State_Blocking,    "State.Blocking");
UE_DEFINE_GAMEPLAY_TAG(Data_Heal,         "Data.Heal");
UE_DEFINE_GAMEPLAY_TAG(Event_Damage_Crit, "Event.Damage.Crit");
UE_DEFINE_GAMEPLAY_TAG(Cue_Damage_Crit,   "GameplayCue.Damage.Crit");
```

### Step 2：写 ExecCalc（卡片 3 的代码）

新建 `Source/MyProject/GAS/UExec_Damage.h/cpp`，照抄即可。

### Step 3：写 LifeSteal 治疗 GE

新建 `GE_LifeStealHeal`（蓝图资产）：
- Duration Policy: Instant
- Modifier: Health, Add, SetByCaller(`Data.Heal`)

### Step 4：改 `GE_Damage`

打开 `GE_Damage` 资产：
- 删掉原来的"Damage Modifier (SetByCaller)"
- `Executions` → Add → `Calculation Class = UExec_Damage`
- `Display → Gameplay Cues` 保留 `GameplayCue.Character.Hit`

⚠️ 注意：GE 同时配 Modifier 和 Execution 时，**Execution 跑完以后 Modifier 才跑**，顺序要想清楚。这一版我们把所有计算都丢给 ExecCalc。

### Step 5：暴击 Cue Notify

建 `BP_GCN_DamageCrit`：
- 父类 `GameplayCueNotify_Static`
- Tag `GameplayCue.Damage.Crit`
- `OnExecute` → 在 `Params.Location` 处 SpawnEmitter（黄色十字）+ `PrintString("CRITICAL " + RawMagnitude)` 演示

### Step 6：测试矩阵

- [ ] 普通命中：飘红+扣血公式正确（Atk × 系数 - Armor×0.5）
- [ ] 暴击：屏幕飘 "CRITICAL"、伤害 ≈ 普通 × CritDamage
- [ ] 给 Source 加 LifeSteal=0.3：每次命中 Source HP 回血 = 伤害 × 30%
- [ ] 给 Target 加 `State.Blocking` Tag（用 Loose Tag 控制台测）：伤害减半
- [ ] 提升 Spec 等级（`MakeOutgoingSpec(GE, 5, Ctx)`）：伤害随等级线性增

---

## 五、排查清单

| # | 现象 | 怎么定位 |
|---|------|---------|
| 1 | ExecCalc 没跑 | 在 `Execute_Implementation` 第一行 `UE_LOG`，不打印就是 GE 资产没挂 Execution 类 |
| 2 | 跑了但属性不变 | 没 `AddOutputModifier`，或 `EGameplayModOp` 用错（Override 会顶替不是叠加） |
| 3 | 捕获的属性是 0 | 三个原因：①没 `RelevantAttributesToCapture.Add` ②`AttributeToCapture` 没初始化 ③Source/Target 写反 |
| 4 | 暴击概率每次都 100% 或 0% | `FMath::FRand()` 返回 0~1，比的应该是 `*100 < CritC` 或者 `< CritC*0.01` |
| 5 | 等级缩放无效 | `Spec.GetLevel()` 在 `MakeOutgoingSpec(GE, Level, ...)` 时确认传了非 1 的值 |
| 6 | 吸血没回血 | OutputModifier 只改 Target，吸血必须**额外 Apply 一条 GE 到 Source**（卡片 4 方案 A） |
| 7 | 暴击 Cue 不飘字 | 优先用 `ExecuteGameplayCue` 而不是 `Add`，Burst 用 Static Notify |
| 8 | 蓝图改 ExecCalc 默认值不生效 | C++ `UPROPERTY(EditDefaultsOnly)` 才能在蓝图子类暴露 |
| 9 | 多次命中数值跳变 | Source 端属性 `bSnapshot=false` 时会实时读，可能被中间 Buff 改了；改成 `true` 用快照 |
| 10 | `AttemptCalculateCapturedAttributeMagnitude` 返回 false | Spec 没捕获这个 Attribute（Source/Target 没生效），重启编辑器试试，C++ 改了 Capture 必须重编 |

---

## 六、概念脉络图（把今天的串起来）

```
                    [玩家释放火球]
                          │
                          ▼
        MakeOutgoingSpec(GE_Damage, Level, Ctx)
        SetByCaller(Data.Damage, 50)
                          │
                          ▼
            ApplyGameplayEffectSpecToTarget
                          │
                          ▼
              ┌──────── Execution 阶段 ────────┐
              │  UExec_Damage::Execute         │
              │  ├─ Capture(AttackPower, Armor,│
              │  │   CritC, CritD, LifeS)      │
              │  ├─ Damage 公式                │
              │  ├─ 暴击判定                    │
              │  ├─ 标签减伤                    │
              │  ├─ AddOutputModifier(Damage)  │
              │  ├─ ApplySpec(GE_LifeStealHeal)│
              │  └─ ExecuteGameplayCue(Crit)   │
              └────────────────────────────────┘
                          │
                          ▼
              ┌──────── Modifier 阶段 ─────────┐
              │  写 Damage Meta（OutputMod）   │
              └────────────────────────────────┘
                          │
                          ▼
       PostGameplayEffectExecute（卡片 2 老代码）
       Health -= Damage; SetDamage(0)
                          │
                          ▼
       OnRep_Health → UI 刷新
       GE 自带 Cue.Character.Hit → 闪红
```

---

## 七、关键文件索引（本日新增）

| 文件 | 作用 |
|------|------|
| `Source/MyProject/GAS/GASLearnAttributeSet.h/cpp` | **新增**: AttackPower / Armor / CritChance / CritDamage / LifeSteal |
| `Source/MyProject/GAS/UExec_Damage.h/cpp` | **新增**: 伤害 ExecCalc |
| `Source/MyProject/GAS/UMMC_BasicDamage.h/cpp` | （可选）简化版 MMC 示例 |
| `Source/MyProject/GAS/GASLearnGameplayTags.h/cpp` | **新增**: State_Blocking / Data_Heal / Event_Damage_Crit / Cue_Damage_Crit |
| Content / `GE_Damage.uasset` | **改**: 移除 SetByCaller Modifier，改挂 Execution = `UExec_Damage` |
| Content / `GE_LifeStealHeal.uasset` | **新建**: Instant 治疗 GE，SetByCaller(Data.Heal) |
| Content / `BP_GCN_DamageCrit.uasset` | **新建**: 暴击飘字 Static Cue |
| Content / `GE_InitAttributes.uasset` | **改**: 给新属性默认值 |

---

## 八、心法

1. **MMC = 算一个数；ExecCalc = 算一组结果**
2. **Source 端属性常用快照（`bSnapshot=true`），Target 端常用实时（`bSnapshot=false`）**
3. **OutputModifier 只能改 Target；改 Source 走"再 Apply 一条 GE"**
4. **暴击/格挡这种"事件"用 Cue 表达，不要硬塞进数值流程**
5. **公式抽到 ExecCalc 后，新加伤害类型只配 GE 不写代码**

---

## 九、明日方向（Day04 候选）

- **A. TargetData**：AOE / 锥形 / 多目标筛选（`UAbilityTask_WaitTargetData` + `UGameplayAbilityTargetActor`）
- **B. AbilitySet / Loadout**：技能装配系统的标准做法（DA + GrantAbility 表）
- **C. 多人网络专题**：Prediction Key、Scoped Prediction、回滚演示

> 推荐顺序：A → B → C。先把"打到谁"做好，再做"装备什么技能"，最后深挖网络细节。

> 📌 新会话开头喂给 AI：**总纲 0/8/11 节 + Day03 速查表 + 关键文件索引**。
