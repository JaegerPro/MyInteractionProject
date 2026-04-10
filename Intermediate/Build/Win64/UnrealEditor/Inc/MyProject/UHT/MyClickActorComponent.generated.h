// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyClickActorComponent.h"

#ifdef MYPROJECT_MyClickActorComponent_generated_h
#error "MyClickActorComponent.generated.h already included, missing '#pragma once' in MyClickActorComponent.h"
#endif
#define MYPROJECT_MyClickActorComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FClick_ValidInfo;
struct FClickUIInfo;
struct FHitResult;

// ********** Begin ScriptStruct FClick_PassInfo ***************************************************
struct Z_Construct_UScriptStruct_FClick_PassInfo_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_19_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FClick_PassInfo_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FClick_PassInfo;
// ********** End ScriptStruct FClick_PassInfo *****************************************************

// ********** Begin ScriptStruct FClick_ValidInfo **************************************************
struct Z_Construct_UScriptStruct_FClick_ValidInfo_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_57_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FClick_ValidInfo_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FClick_ValidInfo;
// ********** End ScriptStruct FClick_ValidInfo ****************************************************

// ********** Begin ScriptStruct FClickUIInfo ******************************************************
struct Z_Construct_UScriptStruct_FClickUIInfo_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_84_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FClickUIInfo_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FClickUIInfo;
// ********** End ScriptStruct FClickUIInfo ********************************************************

// ********** Begin ScriptStruct FClick_Param ******************************************************
struct Z_Construct_UScriptStruct_FClick_Param_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_143_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FClick_Param_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FClick_Param;
// ********** End ScriptStruct FClick_Param ********************************************************

// ********** Begin ScriptStruct FClick_CheckFunctionName ******************************************
struct Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_155_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FClick_CheckFunctionName;
// ********** End ScriptStruct FClick_CheckFunctionName ********************************************

// ********** Begin ScriptStruct FClick_ExecuteFunctionName ****************************************
struct Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_171_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FClick_ExecuteFunctionName;
// ********** End ScriptStruct FClick_ExecuteFunctionName ******************************************

// ********** Begin ScriptStruct FClickInfo ********************************************************
struct Z_Construct_UScriptStruct_FClickInfo_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_186_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FClickInfo_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FClickInfo;
// ********** End ScriptStruct FClickInfo **********************************************************

// ********** Begin ScriptStruct FClick_ValidInfo_Rep **********************************************
struct Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics;
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_215_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics; \
	MYPROJECT_API static class UScriptStruct* StaticStruct();


struct FClick_ValidInfo_Rep;
// ********** End ScriptStruct FClick_ValidInfo_Rep ************************************************

// ********** Begin Interface UClickActorPCInterface ***********************************************
struct Z_Construct_UClass_UClickActorPCInterface_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_UClickActorPCInterface_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_236_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UClickActorPCInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UClickActorPCInterface(UClickActorPCInterface&&) = delete; \
	UClickActorPCInterface(const UClickActorPCInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UClickActorPCInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UClickActorPCInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UClickActorPCInterface) \
	virtual ~UClickActorPCInterface() = default;


#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_236_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUClickActorPCInterface(); \
	friend struct ::Z_Construct_UClass_UClickActorPCInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_UClickActorPCInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UClickActorPCInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UClickActorPCInterface_NoRegister) \
	DECLARE_SERIALIZER(UClickActorPCInterface)


#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_236_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_236_GENERATED_UINTERFACE_BODY() \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_236_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_236_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IClickActorPCInterface() {} \
public: \
	typedef UClickActorPCInterface UClassType; \
	typedef IClickActorPCInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_233_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_241_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_236_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UClickActorPCInterface;

// ********** End Interface UClickActorPCInterface *************************************************

// ********** Begin Class UMyClickActorComponent ***************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_253_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnEndOverlap); \
	DECLARE_FUNCTION(execOnBeginOverlap); \
	DECLARE_FUNCTION(execOnButtonClick);


struct Z_Construct_UClass_UMyClickActorComponent_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_UMyClickActorComponent_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_253_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyClickActorComponent(); \
	friend struct ::Z_Construct_UClass_UMyClickActorComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_UMyClickActorComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UMyClickActorComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UMyClickActorComponent_NoRegister) \
	DECLARE_SERIALIZER(UMyClickActorComponent)


#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_253_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UMyClickActorComponent(UMyClickActorComponent&&) = delete; \
	UMyClickActorComponent(const UMyClickActorComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyClickActorComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyClickActorComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyClickActorComponent) \
	NO_API virtual ~UMyClickActorComponent();


#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_250_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_253_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_253_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_253_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_253_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UMyClickActorComponent;

// ********** End Class UMyClickActorComponent *****************************************************

// ********** Begin Delegate FOnClickButton ********************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_307_DELEGATE \
MYPROJECT_API void FOnClickButton_DelegateWrapper(const FMulticastScriptDelegate& OnClickButton, FClick_ValidInfo Info);


// ********** End Delegate FOnClickButton **********************************************************

// ********** Begin Class UClickButtonWidget *******************************************************
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_312_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetOwner);


#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_312_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UClickButtonWidget_Statics;
MYPROJECT_API UClass* Z_Construct_UClass_UClickButtonWidget_NoRegister();

#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_312_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUClickButtonWidget(); \
	friend struct ::Z_Construct_UClass_UClickButtonWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* ::Z_Construct_UClass_UClickButtonWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UClickButtonWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UClickButtonWidget_NoRegister) \
	DECLARE_SERIALIZER(UClickButtonWidget)


#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_312_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UClickButtonWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UClickButtonWidget(UClickButtonWidget&&) = delete; \
	UClickButtonWidget(const UClickButtonWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UClickButtonWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UClickButtonWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UClickButtonWidget) \
	NO_API virtual ~UClickButtonWidget();


#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_309_PROLOG
#define FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_312_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_312_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_312_CALLBACK_WRAPPERS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_312_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h_312_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UClickButtonWidget;

// ********** End Class UClickButtonWidget *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
