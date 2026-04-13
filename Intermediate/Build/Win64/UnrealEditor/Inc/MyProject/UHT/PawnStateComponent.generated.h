// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PawnStateComponent.h"

#ifdef MYPROJECT_PawnStateComponent_generated_h
#error "PawnStateComponent.generated.h already included, missing '#pragma once' in PawnStateComponent.h"
#endif
#define MYPROJECT_PawnStateComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USimpleStateConfig;
enum class EPawnState : uint8;
enum class EPawnStateRelation : uint8;
struct FSimpleBitMask;

// ********** Begin ScriptStruct FStateRelationConfig **********************************************
struct Z_Construct_UScriptStruct_FStateRelationConfig_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_16_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FStateRelationConfig_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FStateRelationConfig;
// ********** End ScriptStruct FStateRelationConfig ************************************************

// ********** Begin Class USimpleStateConfig *******************************************************
struct Z_Construct_UClass_USimpleStateConfig_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_USimpleStateConfig_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSimpleStateConfig(); \
	friend struct ::Z_Construct_UClass_USimpleStateConfig_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_USimpleStateConfig_NoRegister(); \
public: \
	DECLARE_CLASS2(USimpleStateConfig, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_USimpleStateConfig_NoRegister) \
	DECLARE_SERIALIZER(USimpleStateConfig)


#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_37_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USimpleStateConfig(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USimpleStateConfig(USimpleStateConfig&&) = delete; \
	USimpleStateConfig(const USimpleStateConfig&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USimpleStateConfig); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USimpleStateConfig); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USimpleStateConfig) \
	NO_API virtual ~USimpleStateConfig();


#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_34_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_37_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USimpleStateConfig;

// ********** End Class USimpleStateConfig *********************************************************

// ********** Begin Class UPawnStateComponent ******************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_CurrentStates); \
	DECLARE_FUNCTION(execGetStateDebugString); \
	DECLARE_FUNCTION(execClearStateRelations); \
	DECLARE_FUNCTION(execAddStateRelation); \
	DECLARE_FUNCTION(execSetStateConfig); \
	DECLARE_FUNCTION(execResetStateDisabled); \
	DECLARE_FUNCTION(execIsStateDisabled); \
	DECLARE_FUNCTION(execSetStateDisabled); \
	DECLARE_FUNCTION(execLeaveAllStates); \
	DECLARE_FUNCTION(execLeaveState); \
	DECLARE_FUNCTION(execEnterState); \
	DECLARE_FUNCTION(execCanEnterState); \
	DECLARE_FUNCTION(execGetCurrentStatesBits); \
	DECLARE_FUNCTION(execGetActiveStates); \
	DECLARE_FUNCTION(execOnlyHasStates); \
	DECLARE_FUNCTION(execHasAllStates); \
	DECLARE_FUNCTION(execHasAnyStates); \
	DECLARE_FUNCTION(execHasState);


struct Z_Construct_UClass_UPawnStateComponent_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_UPawnStateComponent_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_56_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPawnStateComponent(); \
	friend struct ::Z_Construct_UClass_UPawnStateComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_UPawnStateComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPawnStateComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UPawnStateComponent_NoRegister) \
	DECLARE_SERIALIZER(UPawnStateComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentStates=NETFIELD_REP_START, \
		NETFIELD_REP_END=CurrentStates	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_56_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPawnStateComponent(UPawnStateComponent&&) = delete; \
	UPawnStateComponent(const UPawnStateComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPawnStateComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPawnStateComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPawnStateComponent) \
	NO_API virtual ~UPawnStateComponent();


#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_53_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_56_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_56_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h_56_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPawnStateComponent;

// ********** End Class UPawnStateComponent ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
