// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Tools/MyProjectEditorTool.h"

#ifdef MYPROJECTEDITOR_MyProjectEditorTool_generated_h
#error "MyProjectEditorTool.generated.h already included, missing '#pragma once' in MyProjectEditorTool.h"
#endif
#define MYPROJECTEDITOR_MyProjectEditorTool_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UMyProjectEditorTool *****************************************************
#define FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetSelectedActorCount); \
	DECLARE_FUNCTION(execAddTagToSelectedActors); \
	DECLARE_FUNCTION(execBatchMoveActors); \
	DECLARE_FUNCTION(execBatchRenameActors);


struct Z_Construct_UClass_UMyProjectEditorTool_Statics;
MYPROJECTEDITOR_API UClass* Z_Construct_UClass_UMyProjectEditorTool_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyProjectEditorTool(); \
	friend struct ::Z_Construct_UClass_UMyProjectEditorTool_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECTEDITOR_API UClass* ::Z_Construct_UClass_UMyProjectEditorTool_NoRegister(); \
public: \
	DECLARE_CLASS2(UMyProjectEditorTool, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProjectEditor"), Z_Construct_UClass_UMyProjectEditorTool_NoRegister) \
	DECLARE_SERIALIZER(UMyProjectEditorTool)


#define FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyProjectEditorTool(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMyProjectEditorTool(UMyProjectEditorTool&&) = delete; \
	UMyProjectEditorTool(const UMyProjectEditorTool&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyProjectEditorTool); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyProjectEditorTool); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyProjectEditorTool) \
	NO_API virtual ~UMyProjectEditorTool();


#define FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h_13_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h_16_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMyProjectEditorTool;

// ********** End Class UMyProjectEditorTool *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
