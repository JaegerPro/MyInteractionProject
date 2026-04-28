// Fill out your copyright notice in the Description page of Project Settings.

#include "GASLearnGameplayAbility.h"

UGASLearnGameplayAbility::UGASLearnGameplayAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	bReplicateInputDirectly = false;
}
