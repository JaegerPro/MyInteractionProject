// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PersistEffect.h"

#ifdef MYPROJECT_PersistEffect_generated_h
#error "PersistEffect.generated.h already included, missing '#pragma once' in PersistEffect.h"
#endif
#define MYPROJECT_PersistEffect_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "Net/Core/PushModel/PushModelMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPersistBaseComponent;

// ********** Begin Class UPersistEffectBase *******************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool CanApply_BP_Implementation(AActor* Character); \
	DECLARE_FUNCTION(execCanApply_BP); \
	DECLARE_FUNCTION(execGetOwnerSafety); \
	DECLARE_FUNCTION(execGetNetOwnerActor); \
	DECLARE_FUNCTION(execHasAuthority); \
	DECLARE_FUNCTION(execCanApply);


#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_15_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UPersistEffectBase_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_UPersistEffectBase_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPersistEffectBase(); \
	friend struct ::Z_Construct_UClass_UPersistEffectBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_UPersistEffectBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UPersistEffectBase, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UPersistEffectBase_NoRegister) \
	DECLARE_SERIALIZER(UPersistEffectBase) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Owner=NETFIELD_REP_START, \
		NETFIELD_REP_END=Owner	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API) \
private: \
	REPLICATED_BASE_CLASS(UPersistEffectBase) \
public:


#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPersistEffectBase(UPersistEffectBase&&) = delete; \
	UPersistEffectBase(const UPersistEffectBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPersistEffectBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPersistEffectBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPersistEffectBase) \
	NO_API virtual ~UPersistEffectBase();


#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_12_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_15_CALLBACK_WRAPPERS \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPersistEffectBase;

// ********** End Class UPersistEffectBase *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
