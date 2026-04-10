// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PersistBaseComponent.h"

#ifdef MYPROJECT_PersistBaseComponent_generated_h
#error "PersistBaseComponent.generated.h already included, missing '#pragma once' in PersistBaseComponent.h"
#endif
#define MYPROJECT_PersistBaseComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UClass;
class UPersistBaseComponent;
class UPersistEffectBase;

// ********** Begin Class UPersistBaseComponent ****************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetNetOwnerActor); \
	DECLARE_FUNCTION(execUnApplyPersistEffectData); \
	DECLARE_FUNCTION(execApplyPersistEffect); \
	DECLARE_FUNCTION(execCreatePersistEffectDataByClass); \
	DECLARE_FUNCTION(execApplyPersistEffectDataByClass); \
	DECLARE_FUNCTION(execApplyPersistEffectData);


struct Z_Construct_UClass_UPersistBaseComponent_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_UPersistBaseComponent_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPersistBaseComponent(); \
	friend struct ::Z_Construct_UClass_UPersistBaseComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_UPersistBaseComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPersistBaseComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UPersistBaseComponent_NoRegister) \
	DECLARE_SERIALIZER(UPersistBaseComponent)


#define FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPersistBaseComponent(UPersistBaseComponent&&) = delete; \
	UPersistBaseComponent(const UPersistBaseComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPersistBaseComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPersistBaseComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPersistBaseComponent) \
	NO_API virtual ~UPersistBaseComponent();


#define FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h_9_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h_12_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPersistBaseComponent;

// ********** End Class UPersistBaseComponent ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
