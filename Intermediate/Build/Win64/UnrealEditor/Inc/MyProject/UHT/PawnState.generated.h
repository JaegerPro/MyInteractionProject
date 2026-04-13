// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PawnState.h"

#ifdef MYPROJECT_PawnState_generated_h
#error "PawnState.generated.h already included, missing '#pragma once' in PawnState.h"
#endif
#define MYPROJECT_PawnState_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EPawnState : uint8;

// ********** Begin ScriptStruct FSimpleBitMask ****************************************************
struct Z_Construct_UScriptStruct_FSimpleBitMask_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h_73_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FSimpleBitMask_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FSimpleBitMask;
// ********** End ScriptStruct FSimpleBitMask ******************************************************

// ********** Begin ScriptStruct FStateCounter *****************************************************
struct Z_Construct_UScriptStruct_FStateCounter_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h_126_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FStateCounter_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FStateCounter;
// ********** End ScriptStruct FStateCounter *******************************************************

// ********** Begin Delegate FOnPawnStateEnter *****************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h_141_DELEGATE \
MYPROJECT_API void FOnPawnStateEnter_DelegateWrapper(const FMulticastScriptDelegate& OnPawnStateEnter, EPawnState State);


// ********** End Delegate FOnPawnStateEnter *******************************************************

// ********** Begin Delegate FOnPawnStateLeave *****************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h_142_DELEGATE \
MYPROJECT_API void FOnPawnStateLeave_DelegateWrapper(const FMulticastScriptDelegate& OnPawnStateLeave, EPawnState State);


// ********** End Delegate FOnPawnStateLeave *******************************************************

// ********** Begin Delegate FOnPawnStateInterrupt *************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h_143_DELEGATE \
MYPROJECT_API void FOnPawnStateInterrupt_DelegateWrapper(const FMulticastScriptDelegate& OnPawnStateInterrupt, EPawnState State, EPawnState InterruptedBy);


// ********** End Delegate FOnPawnStateInterrupt ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_PawnState_h

// ********** Begin Enum EPawnStateRelation ********************************************************
#define FOREACH_ENUM_EPAWNSTATERELATION(op) \
	op(EPawnStateRelation::None) \
	op(EPawnStateRelation::X_) \
	op(EPawnStateRelation::_Y) \
	op(EPawnStateRelation::XY) 

enum class EPawnStateRelation : uint8;
template<> struct TIsUEnumClass<EPawnStateRelation> { enum { Value = true }; };
template<> MYPROJECT_NON_ATTRIBUTED_API UEnum* StaticEnum<EPawnStateRelation>();
// ********** End Enum EPawnStateRelation **********************************************************

// ********** Begin Enum EPawnState ****************************************************************
#define FOREACH_ENUM_EPAWNSTATE(op) \
	op(EPawnState::Move) \
	op(EPawnState::Sprint) \
	op(EPawnState::Jump) \
	op(EPawnState::Crouch) \
	op(EPawnState::Prone) \
	op(EPawnState::Swim) \
	op(EPawnState::Vault) \
	op(EPawnState::GunFire) \
	op(EPawnState::GunReload) \
	op(EPawnState::GunADS) \
	op(EPawnState::MeleeAttack) \
	op(EPawnState::DriveVehicle) \
	op(EPawnState::InVehicle) \
	op(EPawnState::Dying) \
	op(EPawnState::Dead) \
	op(EPawnState::Stun) \
	op(EPawnState::Interacting) \
	op(EPawnState::CastingSkill) \
	op(EPawnState::__MAX) 

enum class EPawnState : uint8;
template<> struct TIsUEnumClass<EPawnState> { enum { Value = true }; };
template<> MYPROJECT_NON_ATTRIBUTED_API UEnum* StaticEnum<EPawnState>();
// ********** End Enum EPawnState ******************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
