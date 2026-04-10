// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyCharacter.h"

#ifdef MYPROJECT_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define MYPROJECT_MyCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AMyCharacter *************************************************************
struct Z_Construct_UClass_AMyCharacter_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_AMyCharacter_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_MyCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct ::Z_Construct_UClass_AMyCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_AMyCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_AMyCharacter_NoRegister) \
	DECLARE_SERIALIZER(AMyCharacter)


#define FID_UnrealProjects_MyProject_Source_MyProject_MyCharacter_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AMyCharacter(AMyCharacter&&) = delete; \
	AMyCharacter(const AMyCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter) \
	NO_API virtual ~AMyCharacter();


#define FID_UnrealProjects_MyProject_Source_MyProject_MyCharacter_h_9_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_MyCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_MyCharacter_h_12_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AMyCharacter;

// ********** End Class AMyCharacter ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_MyCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
