// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/MyActivityActor.h"
#include "MyProject/ActivityStateInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMyActivityActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_AActor();
MYPROJECT_API UClass* Z_Construct_UClass_AMyActivityActor();
MYPROJECT_API UClass* Z_Construct_UClass_AMyActivityActor_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UActivityStateInterface_NoRegister();
MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FActivityState();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FActivityStateRep();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AMyActivityActor Function JumpToState ************************************
struct Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics
{
	struct MyActivityActor_eventJumpToState_Parms
	{
		FName StateName;
		float EnterTime;
		bool bPause;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CPP_Default_bPause", "false" },
		{ "CPP_Default_EnterTime", "0.000000" },
		{ "ModuleRelativePath", "MyActivityActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function JumpToState constinit property declarations ***************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_StateName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnterTime;
	static void NewProp_bPause_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPause;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function JumpToState constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function JumpToState Property Definitions **************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::NewProp_StateName = { "StateName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyActivityActor_eventJumpToState_Parms, StateName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::NewProp_EnterTime = { "EnterTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyActivityActor_eventJumpToState_Parms, EnterTime), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::NewProp_bPause_SetBit(void* Obj)
{
	((MyActivityActor_eventJumpToState_Parms*)Obj)->bPause = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::NewProp_bPause = { "bPause", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MyActivityActor_eventJumpToState_Parms), &Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::NewProp_bPause_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::NewProp_StateName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::NewProp_EnterTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::NewProp_bPause,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::PropPointers) < 2048);
// ********** End Function JumpToState Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMyActivityActor, nullptr, "JumpToState", 	Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::MyActivityActor_eventJumpToState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::MyActivityActor_eventJumpToState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyActivityActor_JumpToState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyActivityActor_JumpToState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyActivityActor::execJumpToState)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_StateName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_EnterTime);
	P_GET_UBOOL(Z_Param_bPause);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->JumpToState(Z_Param_StateName,Z_Param_EnterTime,Z_Param_bPause);
	P_NATIVE_END;
}
// ********** End Class AMyActivityActor Function JumpToState **************************************

// ********** Begin Class AMyActivityActor Function OnRep_CurrentStateIndexInfo ********************
struct Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics
{
	struct MyActivityActor_eventOnRep_CurrentStateIndexInfo_Parms
	{
		FActivityStateRep PreIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyActivityActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_CurrentStateIndexInfo constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnRep_CurrentStateIndexInfo constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnRep_CurrentStateIndexInfo Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::NewProp_PreIndex = { "PreIndex", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyActivityActor_eventOnRep_CurrentStateIndexInfo_Parms, PreIndex), Z_Construct_UScriptStruct_FActivityStateRep, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreIndex_MetaData), NewProp_PreIndex_MetaData) }; // 4003429430
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::NewProp_PreIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::PropPointers) < 2048);
// ********** End Function OnRep_CurrentStateIndexInfo Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMyActivityActor, nullptr, "OnRep_CurrentStateIndexInfo", 	Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::MyActivityActor_eventOnRep_CurrentStateIndexInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::MyActivityActor_eventOnRep_CurrentStateIndexInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyActivityActor::execOnRep_CurrentStateIndexInfo)
{
	P_GET_STRUCT_REF(FActivityStateRep,Z_Param_Out_PreIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentStateIndexInfo(Z_Param_Out_PreIndex);
	P_NATIVE_END;
}
// ********** End Class AMyActivityActor Function OnRep_CurrentStateIndexInfo **********************

// ********** Begin Class AMyActivityActor Function OnRep_CurrentTransform *************************
struct Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentTransform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyActivityActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_CurrentTransform constinit property declarations ****************
// ********** End Function OnRep_CurrentTransform constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMyActivityActor, nullptr, "OnRep_CurrentTransform", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentTransform_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyActivityActor::execOnRep_CurrentTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentTransform();
	P_NATIVE_END;
}
// ********** End Class AMyActivityActor Function OnRep_CurrentTransform ***************************

// ********** Begin Class AMyActivityActor *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AMyActivityActor;
UClass* AMyActivityActor::GetPrivateStaticClass()
{
	using TClass = AMyActivityActor;
	if (!Z_Registration_Info_UClass_AMyActivityActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MyActivityActor"),
			Z_Registration_Info_UClass_AMyActivityActor.InnerSingleton,
			StaticRegisterNativesAMyActivityActor,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AMyActivityActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AMyActivityActor_NoRegister()
{
	return AMyActivityActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AMyActivityActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyActivityActor.h" },
		{ "ModuleRelativePath", "MyActivityActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateMachineInfo_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "MyActivityActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTransform_MetaData[] = {
		{ "ModuleRelativePath", "MyActivityActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentIndex_MetaData[] = {
		{ "ModuleRelativePath", "MyActivityActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnActivityActorChangeState_MetaData[] = {
		{ "ModuleRelativePath", "MyActivityActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AMyActivityActor constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_StateMachineInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StateMachineInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentIndex;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActivityActorChangeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AMyActivityActor constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("JumpToState"), .Pointer = &AMyActivityActor::execJumpToState },
		{ .NameUTF8 = UTF8TEXT("OnRep_CurrentStateIndexInfo"), .Pointer = &AMyActivityActor::execOnRep_CurrentStateIndexInfo },
		{ .NameUTF8 = UTF8TEXT("OnRep_CurrentTransform"), .Pointer = &AMyActivityActor::execOnRep_CurrentTransform },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyActivityActor_JumpToState, "JumpToState" }, // 1155359767
		{ &Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentStateIndexInfo, "OnRep_CurrentStateIndexInfo" }, // 691789004
		{ &Z_Construct_UFunction_AMyActivityActor_OnRep_CurrentTransform, "OnRep_CurrentTransform" }, // 3585198904
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyActivityActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AMyActivityActor_Statics

// ********** Begin Class AMyActivityActor Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyActivityActor_Statics::NewProp_StateMachineInfo_Inner = { "StateMachineInfo", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FActivityState, METADATA_PARAMS(0, nullptr) }; // 4017843703
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMyActivityActor_Statics::NewProp_StateMachineInfo = { "StateMachineInfo", nullptr, (EPropertyFlags)0x0020088000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyActivityActor, StateMachineInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateMachineInfo_MetaData), NewProp_StateMachineInfo_MetaData) }; // 4017843703
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyActivityActor_Statics::NewProp_CurrentTransform = { "CurrentTransform", "OnRep_CurrentTransform", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyActivityActor, CurrentTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTransform_MetaData), NewProp_CurrentTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyActivityActor_Statics::NewProp_CurrentIndex = { "CurrentIndex", "OnRep_CurrentStateIndexInfo", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyActivityActor, CurrentIndex), Z_Construct_UScriptStruct_FActivityStateRep, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentIndex_MetaData), NewProp_CurrentIndex_MetaData) }; // 4003429430
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AMyActivityActor_Statics::NewProp_OnActivityActorChangeState = { "OnActivityActorChangeState", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyActivityActor, OnActivityActorChangeState), Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnActivityActorChangeState_MetaData), NewProp_OnActivityActorChangeState_MetaData) }; // 3952287915
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyActivityActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActivityActor_Statics::NewProp_StateMachineInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActivityActor_Statics::NewProp_StateMachineInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActivityActor_Statics::NewProp_CurrentTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActivityActor_Statics::NewProp_CurrentIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActivityActor_Statics::NewProp_OnActivityActorChangeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyActivityActor_Statics::PropPointers) < 2048);
// ********** End Class AMyActivityActor Property Definitions **************************************
UObject* (*const Z_Construct_UClass_AMyActivityActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyActivityActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AMyActivityActor_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UActivityStateInterface_NoRegister, (int32)VTABLE_OFFSET(AMyActivityActor, IActivityStateInterface), false },  // 209411951
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyActivityActor_Statics::ClassParams = {
	&AMyActivityActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMyActivityActor_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyActivityActor_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyActivityActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyActivityActor_Statics::Class_MetaDataParams)
};
void AMyActivityActor::StaticRegisterNativesAMyActivityActor()
{
	UClass* Class = AMyActivityActor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AMyActivityActor_Statics::Funcs));
}
UClass* Z_Construct_UClass_AMyActivityActor()
{
	if (!Z_Registration_Info_UClass_AMyActivityActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyActivityActor.OuterSingleton, Z_Construct_UClass_AMyActivityActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyActivityActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AMyActivityActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_CurrentTransform(TEXT("CurrentTransform"));
	static FName Name_CurrentIndex(TEXT("CurrentIndex"));
	const bool bIsValid = true
		&& Name_CurrentTransform == ClassReps[(int32)ENetFields_Private::CurrentTransform].Property->GetFName()
		&& Name_CurrentIndex == ClassReps[(int32)ENetFields_Private::CurrentIndex].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AMyActivityActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AMyActivityActor);
AMyActivityActor::~AMyActivityActor() {}
// ********** End Class AMyActivityActor ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h__Script_MyProject_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyActivityActor, AMyActivityActor::StaticClass, TEXT("AMyActivityActor"), &Z_Registration_Info_UClass_AMyActivityActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyActivityActor), 551941244U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h__Script_MyProject_859755403{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyActivityActor_h__Script_MyProject_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
