// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/PersistEffectWithState.h"
#include "MyProject/ActivityStateInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePersistEffectWithState() {}

// ********** Begin Cross Module References ********************************************************
MYPROJECT_API UClass* Z_Construct_UClass_UActivityStateInterface_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UPersistEffectBase();
MYPROJECT_API UClass* Z_Construct_UClass_UPersistEffectWithState();
MYPROJECT_API UClass* Z_Construct_UClass_UPersistEffectWithState_NoRegister();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FActivityState();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FActivityStateRep();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPersistEffectWithState Function GetCurrentStateName *********************
struct Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics
{
	struct PersistEffectWithState_eventGetCurrentStateName_Parms
	{
		FName ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistEffectWithState.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentStateName constinit property declarations *******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentStateName constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentStateName Property Definitions ******************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectWithState_eventGetCurrentStateName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentStateName Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectWithState, nullptr, "GetCurrentStateName", 	Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::PersistEffectWithState_eventGetCurrentStateName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::PersistEffectWithState_eventGetCurrentStateName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistEffectWithState::execGetCurrentStateName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FName*)Z_Param__Result=P_THIS->GetCurrentStateName();
	P_NATIVE_END;
}
// ********** End Class UPersistEffectWithState Function GetCurrentStateName ***********************

// ********** Begin Class UPersistEffectWithState Function JumpToState *****************************
struct Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics
{
	struct PersistEffectWithState_eventJumpToState_Parms
	{
		FName StateName;
		float EnterTime;
		bool bPause;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CPP_Default_bPause", "false" },
		{ "CPP_Default_EnterTime", "0.000000" },
		{ "ModuleRelativePath", "PersistEffectWithState.h" },
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
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::NewProp_StateName = { "StateName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectWithState_eventJumpToState_Parms, StateName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::NewProp_EnterTime = { "EnterTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectWithState_eventJumpToState_Parms, EnterTime), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::NewProp_bPause_SetBit(void* Obj)
{
	((PersistEffectWithState_eventJumpToState_Parms*)Obj)->bPause = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::NewProp_bPause = { "bPause", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PersistEffectWithState_eventJumpToState_Parms), &Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::NewProp_bPause_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::NewProp_StateName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::NewProp_EnterTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::NewProp_bPause,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::PropPointers) < 2048);
// ********** End Function JumpToState Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectWithState, nullptr, "JumpToState", 	Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::PersistEffectWithState_eventJumpToState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::PersistEffectWithState_eventJumpToState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectWithState_JumpToState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectWithState_JumpToState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistEffectWithState::execJumpToState)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_StateName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_EnterTime);
	P_GET_UBOOL(Z_Param_bPause);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->JumpToState(Z_Param_StateName,Z_Param_EnterTime,Z_Param_bPause);
	P_NATIVE_END;
}
// ********** End Class UPersistEffectWithState Function JumpToState *******************************

// ********** Begin Class UPersistEffectWithState Function OnRep_CurrentStateIndexInfo *************
struct Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics
{
	struct PersistEffectWithState_eventOnRep_CurrentStateIndexInfo_Parms
	{
		FActivityStateRep PreIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistEffectWithState.h" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::NewProp_PreIndex = { "PreIndex", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectWithState_eventOnRep_CurrentStateIndexInfo_Parms, PreIndex), Z_Construct_UScriptStruct_FActivityStateRep, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreIndex_MetaData), NewProp_PreIndex_MetaData) }; // 4003429430
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::NewProp_PreIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::PropPointers) < 2048);
// ********** End Function OnRep_CurrentStateIndexInfo Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectWithState, nullptr, "OnRep_CurrentStateIndexInfo", 	Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::PersistEffectWithState_eventOnRep_CurrentStateIndexInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::PersistEffectWithState_eventOnRep_CurrentStateIndexInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistEffectWithState::execOnRep_CurrentStateIndexInfo)
{
	P_GET_STRUCT_REF(FActivityStateRep,Z_Param_Out_PreIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentStateIndexInfo(Z_Param_Out_PreIndex);
	P_NATIVE_END;
}
// ********** End Class UPersistEffectWithState Function OnRep_CurrentStateIndexInfo ***************

// ********** Begin Class UPersistEffectWithState **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPersistEffectWithState;
UClass* UPersistEffectWithState::GetPrivateStaticClass()
{
	using TClass = UPersistEffectWithState;
	if (!Z_Registration_Info_UClass_UPersistEffectWithState.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PersistEffectWithState"),
			Z_Registration_Info_UClass_UPersistEffectWithState.InnerSingleton,
			StaticRegisterNativesUPersistEffectWithState,
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
	return Z_Registration_Info_UClass_UPersistEffectWithState.InnerSingleton;
}
UClass* Z_Construct_UClass_UPersistEffectWithState_NoRegister()
{
	return UPersistEffectWithState::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPersistEffectWithState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "PersistEffectWithState.h" },
		{ "ModuleRelativePath", "PersistEffectWithState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateMachineInfo_MetaData[] = {
		{ "Category", "SkillConfig" },
		{ "ModuleRelativePath", "PersistEffectWithState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentIndex_MetaData[] = {
		{ "ModuleRelativePath", "PersistEffectWithState.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPersistEffectWithState constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_StateMachineInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StateMachineInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPersistEffectWithState constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetCurrentStateName"), .Pointer = &UPersistEffectWithState::execGetCurrentStateName },
		{ .NameUTF8 = UTF8TEXT("JumpToState"), .Pointer = &UPersistEffectWithState::execJumpToState },
		{ .NameUTF8 = UTF8TEXT("OnRep_CurrentStateIndexInfo"), .Pointer = &UPersistEffectWithState::execOnRep_CurrentStateIndexInfo },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPersistEffectWithState_GetCurrentStateName, "GetCurrentStateName" }, // 260019220
		{ &Z_Construct_UFunction_UPersistEffectWithState_JumpToState, "JumpToState" }, // 3393762317
		{ &Z_Construct_UFunction_UPersistEffectWithState_OnRep_CurrentStateIndexInfo, "OnRep_CurrentStateIndexInfo" }, // 2490104440
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPersistEffectWithState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPersistEffectWithState_Statics

// ********** Begin Class UPersistEffectWithState Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPersistEffectWithState_Statics::NewProp_StateMachineInfo_Inner = { "StateMachineInfo", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FActivityState, METADATA_PARAMS(0, nullptr) }; // 4017843703
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPersistEffectWithState_Statics::NewProp_StateMachineInfo = { "StateMachineInfo", nullptr, (EPropertyFlags)0x0020088000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistEffectWithState, StateMachineInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateMachineInfo_MetaData), NewProp_StateMachineInfo_MetaData) }; // 4017843703
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPersistEffectWithState_Statics::NewProp_CurrentIndex = { "CurrentIndex", "OnRep_CurrentStateIndexInfo", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistEffectWithState, CurrentIndex), Z_Construct_UScriptStruct_FActivityStateRep, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentIndex_MetaData), NewProp_CurrentIndex_MetaData) }; // 4003429430
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPersistEffectWithState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistEffectWithState_Statics::NewProp_StateMachineInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistEffectWithState_Statics::NewProp_StateMachineInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistEffectWithState_Statics::NewProp_CurrentIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistEffectWithState_Statics::PropPointers) < 2048);
// ********** End Class UPersistEffectWithState Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UPersistEffectWithState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPersistEffectBase,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistEffectWithState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UPersistEffectWithState_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UActivityStateInterface_NoRegister, (int32)VTABLE_OFFSET(UPersistEffectWithState, IActivityStateInterface), false },  // 209411951
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPersistEffectWithState_Statics::ClassParams = {
	&UPersistEffectWithState::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPersistEffectWithState_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPersistEffectWithState_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistEffectWithState_Statics::Class_MetaDataParams), Z_Construct_UClass_UPersistEffectWithState_Statics::Class_MetaDataParams)
};
void UPersistEffectWithState::StaticRegisterNativesUPersistEffectWithState()
{
	UClass* Class = UPersistEffectWithState::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPersistEffectWithState_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPersistEffectWithState()
{
	if (!Z_Registration_Info_UClass_UPersistEffectWithState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPersistEffectWithState.OuterSingleton, Z_Construct_UClass_UPersistEffectWithState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPersistEffectWithState.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UPersistEffectWithState::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_CurrentIndex(TEXT("CurrentIndex"));
	const bool bIsValid = true
		&& Name_CurrentIndex == ClassReps[(int32)ENetFields_Private::CurrentIndex].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UPersistEffectWithState"));
}
#endif
UPersistEffectWithState::UPersistEffectWithState() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPersistEffectWithState);
UPersistEffectWithState::~UPersistEffectWithState() {}
// ********** End Class UPersistEffectWithState ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h__Script_MyProject_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPersistEffectWithState, UPersistEffectWithState::StaticClass, TEXT("UPersistEffectWithState"), &Z_Registration_Info_UClass_UPersistEffectWithState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPersistEffectWithState), 103880376U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h__Script_MyProject_2806965154{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffectWithState_h__Script_MyProject_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
