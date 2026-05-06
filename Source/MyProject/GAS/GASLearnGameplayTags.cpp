// Fill out your copyright notice in the Description page of Project Settings.


#include "GASLearnGameplayTags.h"

namespace GASTags
{
    UE_DEFINE_GAMEPLAY_TAG(Ability_Fireball, "Ability.Fireball");
    UE_DEFINE_GAMEPLAY_TAG(Event_Fireball_Launch, "Ability.Fireball.Launch");

    UE_DEFINE_GAMEPLAY_TAG(State_Dead, "State.Dead");
    UE_DEFINE_GAMEPLAY_TAG(State_Stunned, "State.Stunned");
    UE_DEFINE_GAMEPLAY_TAG(State_Charging, "State.Charging");

    UE_DEFINE_GAMEPLAY_TAG(Cooldown_Fireball, "Cooldown.Fireball");

    UE_DEFINE_GAMEPLAY_TAG(Data_Damage, "Data.Damage");
    UE_DEFINE_GAMEPLAY_TAG(Data_Heal, "Data.Heal");

    UE_DEFINE_GAMEPLAY_TAG(Cue_Fireball_Charging, "GameplayCue.Fireball.Charging");
    UE_DEFINE_GAMEPLAY_TAG(Cue_Fireball_Explode, "GameplayCue.Fireball.Explode");
    UE_DEFINE_GAMEPLAY_TAG(Cue_Character_Hit, "GameplayCue.Character.Hit");
    UE_DEFINE_GAMEPLAY_TAG(Cue_Damage_Critical, "GameplayCue.Damage.Critical");
}