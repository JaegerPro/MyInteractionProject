// ExecCalc_Damage.cpp
#include "ExecCalc_Damage.h"
#include "GASLearnAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GASLearnGameplayTags.h"
#include <AbilitySystemBlueprintLibrary.h>

// ============================================================
// ① 捕获定义集中放在一个 struct 里（社区惯例）
// ============================================================
struct FDamageStatics
{
    // 用宏批量声明捕获定义（每个对应一个 FGameplayEffectAttributeCaptureDefinition）
    DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
    DECLARE_ATTRIBUTE_CAPTUREDEF(Armor);
    DECLARE_ATTRIBUTE_CAPTUREDEF(CritChance);
    DECLARE_ATTRIBUTE_CAPTUREDEF(CritMultiplier);

    FDamageStatics()
    {
        // DEFINE 宏：(类名, 属性名, Source/Target, bSnapshot)
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, AttackPower, Source, true);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, Armor, Target, false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, CritChance, Source, true);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UGASLearnAttributeSet, CritMultiplier, Source, true);
    }
};

// 全局单例（只构造一次）
static const FDamageStatics& DamageStatics()
{
    static FDamageStatics Statics;
    return Statics;
}

// ============================================================
// ② 构造函数：把所有捕获定义注册进去
// ============================================================
UExecCalc_Damage::UExecCalc_Damage()
{
    RelevantAttributesToCapture.Add(DamageStatics().AttackPowerDef);
    RelevantAttributesToCapture.Add(DamageStatics().ArmorDef);
    RelevantAttributesToCapture.Add(DamageStatics().CritChanceDef);
    RelevantAttributesToCapture.Add(DamageStatics().CritMultiplierDef);
}

// ============================================================
// ③ 主逻辑
// ============================================================
void UExecCalc_Damage::Execute_Implementation(
    const FGameplayEffectCustomExecutionParameters& ExecutionParams,
    FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
    // ─── 拿 Spec ───
    const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

    // ─── 拿 Source / Target ASC（MMC 拿不到的东西，ExecCalc 能拿到）───
    UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();
    UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
    AActor* SourceActor = SourceASC ? SourceASC->GetAvatarActor() : nullptr;
    AActor* TargetActor = TargetASC ? TargetASC->GetAvatarActor() : nullptr;

    // ─── 准备 Tag 评估参数（跟 MMC 一样）───
    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
    FAggregatorEvaluateParameters EvalParams;
    EvalParams.SourceTags = SourceTags;
    EvalParams.TargetTags = TargetTags;

    // ─── 取属性 ───
    float AttackPower = 0.f, Armor = 0.f, CritChance = 0.f, CritMultiplier = 1.f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
        DamageStatics().AttackPowerDef, EvalParams, AttackPower);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
        DamageStatics().ArmorDef, EvalParams, Armor);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
        DamageStatics().CritChanceDef, EvalParams, CritChance);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
        DamageStatics().CritMultiplierDef, EvalParams, CritMultiplier);

    // ─── 算伤害 ───
    float Damage = FMath::Max(0.f, AttackPower - Armor);

    // ─── 暴击 ───
    const bool bIsCrit = (FMath::FRand() < CritChance);
    if (bIsCrit)
    {
        Damage *= CritMultiplier;
    }

    // ─── 吸血（暂时写死 20%，后面会属性化）───
    const float LifeStealRatio = 0.2f;
    const float HealAmount = Damage * LifeStealRatio;

    UE_LOG(LogTemp, Log,
        TEXT("[ExecCalc_Damage] AP=%.1f Armor=%.1f Crit=%s Damage=%.1f Heal=%.1f"),
        AttackPower, Armor, bIsCrit ? TEXT("YES") : TEXT("no"), Damage, HealAmount);

    // ============================================================
    // ④ 把修改塞进 OutExecutionOutput
    //    这才是 ExecCalc 真正"做事"的地方
    // ============================================================

    // 1) 扣 Target 的血
    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(
        UGASLearnAttributeSet::GetHealthAttribute(),
        EGameplayModOp::Additive,
        -Damage));

    // 2) 加 Source 的血（吸血）
// 2) 吸血：必须 Apply 一个独立 GE 给 Source（自我治疗）
    if (HealAmount > 0.f && SourceASC)
    {
        // 用一个 GE_LifeSteal 资产（Instant、Modifier: Health Add SetByCaller）
        if (UClass* LifeStealClass = LifeStealEffectClass)   // 见下文
        {
            FGameplayEffectContextHandle Ctx = SourceASC->MakeEffectContext();
            FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(LifeStealClass, 1.f, Ctx);
            if (SpecHandle.IsValid())
            {
                UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(
                    SpecHandle, GASTags::Data_Heal, HealAmount);
                SourceASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
            }
        }
    }


    // ============================================================
    // ⑤ 暴击 Cue（ExecCalc 能直接干这事，MMC 干不了）
    // ============================================================
    if (bIsCrit && SourceASC && TargetActor)
    {
        FGameplayCueParameters CueParams;
        CueParams.Instigator = SourceActor;
        CueParams.EffectCauser = TargetActor;
        CueParams.Location = TargetActor->GetActorLocation();
        CueParams.RawMagnitude = Damage;   // 把暴击数值传给 Cue，飘字用
        // 调 Target 的 ASC 触发，方便看到血条上方的"暴击!"
        TargetASC->ExecuteGameplayCue(GASTags::Cue_Damage_Critical, CueParams);
    }
}
