// MMC_Damage.cpp
#include "MMC_Damage.h"
#include "GASLearnAttributeSet.h"

UMMC_Damage::UMMC_Damage()
{
    // ─── ① 定义要捕获的属性 ───

    // 攻击力：从"施法者（Source）"身上取
    AttackPowerDef.AttributeToCapture = UGASLearnAttributeSet::GetAttackPowerAttribute();
    AttackPowerDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
    AttackPowerDef.bSnapshot = true;   // 快照：施法那一刻的攻击力

    // 护甲：从"目标（Target）"身上取
    ArmorDef.AttributeToCapture = UGASLearnAttributeSet::GetArmorAttribute();
    ArmorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
    ArmorDef.bSnapshot = false;        // 实时：命中那一刻的护甲

    // 暴击率：从施法者身上取，快照（按施法时刻）
    CritChanceDef.AttributeToCapture = UGASLearnAttributeSet::GetCritChanceAttribute();
    CritChanceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
    CritChanceDef.bSnapshot = true;

    // 暴击倍率：从施法者身上取，快照
    CritMultiplierDef.AttributeToCapture = UGASLearnAttributeSet::GetCritMultiplierAttribute();
    CritMultiplierDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
    CritMultiplierDef.bSnapshot = true;
    // ─── ② 把捕获定义注册到"要捕获属性列表"里 ───
    RelevantAttributesToCapture.Add(AttackPowerDef);
    RelevantAttributesToCapture.Add(ArmorDef);
    RelevantAttributesToCapture.Add(CritChanceDef);
    RelevantAttributesToCapture.Add(CritMultiplierDef);
}

float UMMC_Damage::CalculateBaseMagnitude_Implementation(
    const FGameplayEffectSpec& Spec) const
{
    // ─── Tag 准备（不变）───
    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
    FAggregatorEvaluateParameters EvalParams;
    EvalParams.SourceTags = SourceTags;
    EvalParams.TargetTags = TargetTags;

    // ─── 取属性 ───
    float AttackPower = 0.f, Armor = 0.f, CritChance = 0.f, CritMultiplier = 1.f;
    GetCapturedAttributeMagnitude(AttackPowerDef, Spec, EvalParams, AttackPower);
    GetCapturedAttributeMagnitude(ArmorDef, Spec, EvalParams, Armor);
    GetCapturedAttributeMagnitude(CritChanceDef, Spec, EvalParams, CritChance);
    GetCapturedAttributeMagnitude(CritMultiplierDef, Spec, EvalParams, CritMultiplier);

    // ─── 基础公式 ───
    float Damage = FMath::Max(0.f, AttackPower - Armor);

    // ─── 掷骰子 ───
    const bool bIsCrit = (FMath::FRand() < CritChance);
    if (bIsCrit)
    {
        Damage *= CritMultiplier;
    }

    UE_LOG(LogTemp, Log, TEXT("[MMC_Damage] AP=%.1f Armor=%.1f Crit=%s(%.0f%%×%.1f) → Damage=%.1f"),
        AttackPower, Armor,
        bIsCrit ? TEXT("YES") : TEXT("no"),
        CritChance * 100.f, CritMultiplier,
        Damage);

    return Damage;
}

