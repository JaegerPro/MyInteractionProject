// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CustomActor/CustomTypeDefine.h"

#ifdef MYPROJECT_CustomTypeDefine_generated_h
#error "CustomTypeDefine.generated.h already included, missing '#pragma once' in CustomTypeDefine.h"
#endif
#define MYPROJECT_CustomTypeDefine_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UActorComponent;
struct FActorComponentSelector;

// ********** Begin ScriptStruct FActorComponentSelector *******************************************
struct Z_Construct_UScriptStruct_FActorComponentSelector_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_13_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FActorComponentSelector_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FActorComponentSelector;
// ********** End ScriptStruct FActorComponentSelector *********************************************

// ********** Begin ScriptStruct FShapeComponentSelector *******************************************
struct Z_Construct_UScriptStruct_FShapeComponentSelector_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_22_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FShapeComponentSelector_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct(); \
	typedef FActorComponentSelector Super;


struct FShapeComponentSelector;
// ********** End ScriptStruct FShapeComponentSelector *********************************************

// ********** Begin Class UComponentSelectorStatics ************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetComponentBySelector);


struct Z_Construct_UClass_UComponentSelectorStatics_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_UComponentSelectorStatics_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUComponentSelectorStatics(); \
	friend struct ::Z_Construct_UClass_UComponentSelectorStatics_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_UComponentSelectorStatics_NoRegister(); \
public: \
	DECLARE_CLASS2(UComponentSelectorStatics, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UComponentSelectorStatics_NoRegister) \
	DECLARE_SERIALIZER(UComponentSelectorStatics)


#define FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UComponentSelectorStatics(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UComponentSelectorStatics(UComponentSelectorStatics&&) = delete; \
	UComponentSelectorStatics(const UComponentSelectorStatics&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UComponentSelectorStatics); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UComponentSelectorStatics); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UComponentSelectorStatics) \
	NO_API virtual ~UComponentSelectorStatics();


#define FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_26_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_29_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UComponentSelectorStatics;

// ********** End Class UComponentSelectorStatics **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
