// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

// 用命名空间组织，避免污染全局
namespace GASTags
{
    // Ability
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ability_Fireball);

    // State
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Dead);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Stunned);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Charging);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Debuff_Stun);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Debuff_Burn);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(State_Immune_Control);


    // Cooldown
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cooldown_Fireball);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Event_Fireball_Launch);

    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Data_Damage);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Data_Heal);
    
    //Cue
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cue_Fireball_Charging);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cue_Fireball_Explode);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cue_Character_Hit);
    UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cue_Damage_Critical);
}
