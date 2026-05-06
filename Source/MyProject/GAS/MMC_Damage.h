// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_Damage.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMMC_Damage : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
    UMMC_Damage();

    // 这个函数是 MMC 的"主入口"，GE 会在命中瞬间调用它
    virtual float CalculateBaseMagnitude_Implementation(
        const FGameplayEffectSpec& Spec) const override;

private:
    // ─── 要捕获的属性定义（在构造函数里填写）───
    // FGameplayEffectAttributeCaptureDefinition 就是"我要哪个属性 + 从谁身上取 + 是否快照"的三合一结构体
    FGameplayEffectAttributeCaptureDefinition AttackPowerDef;
    FGameplayEffectAttributeCaptureDefinition ArmorDef;
    FGameplayEffectAttributeCaptureDefinition CritChanceDef;       // 新增
    FGameplayEffectAttributeCaptureDefinition CritMultiplierDef;   // 新增

};
