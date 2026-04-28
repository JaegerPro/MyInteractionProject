// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GASLearnAbilityInputID.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGASLearnAbilityInputID : uint8
{
    None            UMETA(DisplayName = "None"),
    Confirm         UMETA(DisplayName = "Confirm"),
    Cancel          UMETA(DisplayName = "Cancel"),
    Ability1        UMETA(DisplayName = "Ability1"),   // Q 键 → 火球
    Ability2        UMETA(DisplayName = "Ability2"),   // E 键 → 治疗（下节课用）
    Ability3        UMETA(DisplayName = "Ability3"),   // R 键 → 终极
    Ability4        UMETA(DisplayName = "Ability4")
};