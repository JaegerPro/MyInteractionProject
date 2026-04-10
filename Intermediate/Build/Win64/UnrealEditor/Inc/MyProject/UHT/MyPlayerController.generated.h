// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyPlayerController.h"

#ifdef MYPROJECT_MyPlayerController_generated_h
#error "MyPlayerController.generated.h already included, missing '#pragma once' in MyPlayerController.h"
#endif
#define MYPROJECT_MyPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMyClickActorComponent;

// ********** Begin Class AMyPlayerController ******************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ExcuteClientClickRequest_Validate(UMyClickActorComponent* , int32 ); \
	virtual void ExcuteClientClickRequest_Implementation(UMyClickActorComponent* Compoent, int32 ID); \
	DECLARE_FUNCTION(execOnRep_ClickInfo); \
	DECLARE_FUNCTION(execExcuteClientClickRequest);


#define FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_16_CALLBACK_WRAPPERS
struct Z_Construct_UClass_AMyPlayerController_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_AMyPlayerController_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyPlayerController(); \
	friend struct ::Z_Construct_UClass_AMyPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_AMyPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AMyPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_AMyPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AMyPlayerController) \
	virtual UObject* _getUObject() const override { return const_cast<AMyPlayerController*>(this); } \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ClickRepInfo=NETFIELD_REP_START, \
		NETFIELD_REP_END=ClickRepInfo	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AMyPlayerController(AMyPlayerController&&) = delete; \
	AMyPlayerController(const AMyPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyPlayerController) \
	NO_API virtual ~AMyPlayerController();


#define FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_13_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_16_CALLBACK_WRAPPERS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_16_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AMyPlayerController;

// ********** End Class AMyPlayerController ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
