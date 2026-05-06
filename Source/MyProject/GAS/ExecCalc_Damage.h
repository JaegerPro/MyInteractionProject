// ExecCalc_Damage.h
#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"   // ExecCalc 基类
#include "ExecCalc_Damage.generated.h"

UCLASS()
class MYPROJECT_API UExecCalc_Damage : public UGameplayEffectExecutionCalculation
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, Category = "Damage")
    TSubclassOf<UGameplayEffect> LifeStealEffectClass;

    UExecCalc_Damage();

    // ExecCalc 的核心入口：注意签名跟 MMC 完全不一样
    virtual void Execute_Implementation(
        const FGameplayEffectCustomExecutionParameters& ExecutionParams,
        FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
