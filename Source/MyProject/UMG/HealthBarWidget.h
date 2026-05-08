// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UHealthBarWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    // 蓝图里实现：把 Percent 赋值给 ProgressBar
    // 用 BlueprintImplementableEvent 最灵活，蓝图美术自己画
    UFUNCTION(BlueprintImplementableEvent, Category = "HealthBar")
    void OnHealthPercentChanged(float NewPercent);

    // C++ 统一入口，内部会调上面的 BIE
    UFUNCTION(BlueprintCallable, Category = "HealthBar")
    void SetHealthPercent(float CurrentHealth, float MaxHealth);
    UFUNCTION(BlueprintImplementableEvent, Category = "Debuff")
    void OnBurnChanged(int32 StackCount, float RemainingTime);

    UFUNCTION(BlueprintCallable, Category = "Debuff")
    void SetBurnInfo(int32 StackCount, float RemainingTime);
};