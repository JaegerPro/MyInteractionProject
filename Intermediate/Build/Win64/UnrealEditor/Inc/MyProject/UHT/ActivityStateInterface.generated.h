// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ActivityStateInterface.h"

#ifdef MYPROJECT_ActivityStateInterface_generated_h
#error "ActivityStateInterface.generated.h already included, missing '#pragma once' in ActivityStateInterface.h"
#endif
#define MYPROJECT_ActivityStateInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Delegate FActivityChangeState **************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_21_DELEGATE \
MYPROJECT_API void FActivityChangeState_DelegateWrapper(const FMulticastScriptDelegate& ActivityChangeState, FName const& LeaveState, FName const& EnterState);


// ********** End Delegate FActivityChangeState ****************************************************

// ********** Begin ScriptStruct FActivityLink *****************************************************
struct Z_Construct_UScriptStruct_FActivityLink_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_25_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FActivityLink_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FActivityLink;
// ********** End ScriptStruct FActivityLink *******************************************************

// ********** Begin ScriptStruct FActivityState ****************************************************
struct Z_Construct_UScriptStruct_FActivityState_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_50_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FActivityState_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FActivityState;
// ********** End ScriptStruct FActivityState ******************************************************

// ********** Begin ScriptStruct FActivityStateRep *************************************************
struct Z_Construct_UScriptStruct_FActivityStateRep_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_109_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FActivityStateRep_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FActivityStateRep;
// ********** End ScriptStruct FActivityStateRep ***************************************************

// ********** Begin Interface UActivityStateInterface **********************************************
struct Z_Construct_UClass_UActivityStateInterface_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_UActivityStateInterface_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_136_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UActivityStateInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UActivityStateInterface(UActivityStateInterface&&) = delete; \
	UActivityStateInterface(const UActivityStateInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UActivityStateInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UActivityStateInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UActivityStateInterface) \
	virtual ~UActivityStateInterface() = default;


#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_136_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUActivityStateInterface(); \
	friend struct ::Z_Construct_UClass_UActivityStateInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_UActivityStateInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UActivityStateInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UActivityStateInterface_NoRegister) \
	DECLARE_SERIALIZER(UActivityStateInterface)


#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_136_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_136_GENERATED_UINTERFACE_BODY() \
	FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_136_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_136_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IActivityStateInterface() {} \
public: \
	typedef UActivityStateInterface UClassType; \
	typedef IActivityStateInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_133_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_144_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h_136_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UActivityStateInterface;

// ********** End Interface UActivityStateInterface ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h

// ********** Begin Enum ESequenceBindingType ******************************************************
#define FOREACH_ENUM_ESEQUENCEBINDINGTYPE(op) \
	op(ESequenceBindingType::None) \
	op(ESequenceBindingType::GenerateActorSequence) \
	op(ESequenceBindingType::BindingActorSequence) \
	op(ESequenceBindingType::BindingLevelSequence) \
	op(ESequenceBindingType::BindingSoftLevelSequence) \
	op(ESequenceBindingType::GenerateSkillSequence) 

enum class ESequenceBindingType : uint8;
template<> struct TIsUEnumClass<ESequenceBindingType> { enum { Value = true }; };
template<> MYPROJECT_NON_ATTRIBUTED_API UEnum* StaticEnum<ESequenceBindingType>();
// ********** End Enum ESequenceBindingType ********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
