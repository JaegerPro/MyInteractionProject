// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyActivityActor.h"

#ifdef MYPROJECT_MyActivityActor_generated_h
#error "MyActivityActor.generated.h already included, missing '#pragma once' in MyActivityActor.h"
#endif
#define MYPROJECT_MyActivityActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FActivityStateRep;

// ********** Begin Class AMyActivityActor *********************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execJumpToState); \
	DECLARE_FUNCTION(execOnRep_CurrentStateIndexInfo); \
	DECLARE_FUNCTION(execOnRep_CurrentTransform);


struct Z_Construct_UClass_AMyActivityActor_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_AMyActivityActor_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyActivityActor(); \
	friend struct ::Z_Construct_UClass_AMyActivityActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_AMyActivityActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AMyActivityActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_AMyActivityActor_NoRegister) \
	DECLARE_SERIALIZER(AMyActivityActor) \
	virtual UObject* _getUObject() const override { return const_cast<AMyActivityActor*>(this); } \
	NO_API void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentTransform=NETFIELD_REP_START, \
		CurrentIndex, \
		NETFIELD_REP_END=CurrentIndex	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AMyActivityActor(AMyActivityActor&&) = delete; \
	AMyActivityActor(const AMyActivityActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyActivityActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyActivityActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyActivityActor) \
	NO_API virtual ~AMyActivityActor();


#define FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h_10_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h_13_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AMyActivityActor;

// ********** End Class AMyActivityActor ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
