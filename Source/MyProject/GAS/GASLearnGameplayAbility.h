// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GASLearnAbilityInputID.h"
#include "GASLearnGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UGASLearnGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UGASLearnGameplayAbility();
	// 绑定到哪个 InputID（Q=Ability1 等）
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input")
	EGASLearnAbilityInputID AbilityInputID = EGASLearnAbilityInputID::None;
};
