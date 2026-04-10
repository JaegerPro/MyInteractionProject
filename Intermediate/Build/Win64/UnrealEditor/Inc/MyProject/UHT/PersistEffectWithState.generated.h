// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PersistEffectWithState.h"

#ifdef MYPROJECT_PersistEffectWithState_generated_h
#error "PersistEffectWithState.generated.h already included, missing '#pragma once' in PersistEffectWithState.h"
#endif
#define MYPROJECT_PersistEffectWithState_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FActivityStateRep;

// ********** Begin Class UPersistEffectWithState **************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execJumpToState); \
	DECLARE_FUNCTION(execGetCurrentStateName); \
	DECLARE_FUNCTION(execOnRep_CurrentStateIndexInfo);


struct Z_Construct_UClass_UPersistEffectWithState_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_UPersistEffectWithState_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPersistEffectWithState(); \
	friend struct ::Z_Construct_UClass_UPersistEffectWithState_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_UPersistEffectWithState_NoRegister(); \
public: \
	DECLARE_CLASS2(UPersistEffectWithState, UPersistEffectBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UPersistEffectWithState_NoRegister) \
	DECLARE_SERIALIZER(UPersistEffectWithState) \
	virtual UObject* _getUObject() const override { return const_cast<UPersistEffectWithState*>(this); } \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentIndex=NETFIELD_REP_START, \
		NETFIELD_REP_END=CurrentIndex	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPersistEffectWithState(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPersistEffectWithState(UPersistEffectWithState&&) = delete; \
	UPersistEffectWithState(const UPersistEffectWithState&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPersistEffectWithState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPersistEffectWithState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPersistEffectWithState) \
	NO_API virtual ~UPersistEffectWithState();


#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h_14_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h_17_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPersistEffectWithState;

// ********** End Class UPersistEffectWithState ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
