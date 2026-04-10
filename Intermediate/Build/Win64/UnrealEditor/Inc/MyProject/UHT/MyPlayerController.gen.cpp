// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/MyPlayerController.h"
#include "MyProject/MyClickActorComponent.h"
#include "UObject/CoreNet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMyPlayerController() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
MYPROJECT_API UClass* Z_Construct_UClass_AMyPlayerController();
MYPROJECT_API UClass* Z_Construct_UClass_AMyPlayerController_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UClickActorPCInterface_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UMyClickActorComponent_NoRegister();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClick_ValidInfo_Rep();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AMyPlayerController Function ExcuteClientClickRequest ********************
struct MyPlayerController_eventExcuteClientClickRequest_Parms
{
	UMyClickActorComponent* Compoent;
	int32 ID;
};
static FName NAME_AMyPlayerController_ExcuteClientClickRequest = FName(TEXT("ExcuteClientClickRequest"));
void AMyPlayerController::ExcuteClientClickRequest(UMyClickActorComponent* Compoent, int32 ID)
{
	MyPlayerController_eventExcuteClientClickRequest_Parms Parms;
	Parms.Compoent=Compoent;
	Parms.ID=ID;
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ExcuteClientClickRequest);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Compoent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExcuteClientClickRequest constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Compoent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExcuteClientClickRequest constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExcuteClientClickRequest Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::NewProp_Compoent = { "Compoent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayerController_eventExcuteClientClickRequest_Parms, Compoent), Z_Construct_UClass_UMyClickActorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Compoent_MetaData), NewProp_Compoent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayerController_eventExcuteClientClickRequest_Parms, ID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::NewProp_Compoent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::NewProp_ID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::PropPointers) < 2048);
// ********** End Function ExcuteClientClickRequest Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ExcuteClientClickRequest", 	Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::PropPointers), 
sizeof(MyPlayerController_eventExcuteClientClickRequest_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(MyPlayerController_eventExcuteClientClickRequest_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execExcuteClientClickRequest)
{
	P_GET_OBJECT(UMyClickActorComponent,Z_Param_Compoent);
	P_GET_PROPERTY(FIntProperty,Z_Param_ID);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ExcuteClientClickRequest_Validate(Z_Param_Compoent,Z_Param_ID))
	{
		RPC_ValidateFailed(TEXT("ExcuteClientClickRequest_Validate"));
		return;
	}
	P_THIS->ExcuteClientClickRequest_Implementation(Z_Param_Compoent,Z_Param_ID);
	P_NATIVE_END;
}
// ********** End Class AMyPlayerController Function ExcuteClientClickRequest **********************

// ********** Begin Class AMyPlayerController Function OnRep_ClickInfo *****************************
struct Z_Construct_UFunction_AMyPlayerController_OnRep_ClickInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_ClickInfo constinit property declarations ***********************
// ********** End Function OnRep_ClickInfo constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_OnRep_ClickInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "OnRep_ClickInfo", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_OnRep_ClickInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_OnRep_ClickInfo_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AMyPlayerController_OnRep_ClickInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_OnRep_ClickInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execOnRep_ClickInfo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_ClickInfo();
	P_NATIVE_END;
}
// ********** End Class AMyPlayerController Function OnRep_ClickInfo *******************************

// ********** Begin Class AMyPlayerController ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AMyPlayerController;
UClass* AMyPlayerController::GetPrivateStaticClass()
{
	using TClass = AMyPlayerController;
	if (!Z_Registration_Info_UClass_AMyPlayerController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MyPlayerController"),
			Z_Registration_Info_UClass_AMyPlayerController.InnerSingleton,
			StaticRegisterNativesAMyPlayerController,
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
	return Z_Registration_Info_UClass_AMyPlayerController.InnerSingleton;
}
UClass* Z_Construct_UClass_AMyPlayerController_NoRegister()
{
	return AMyPlayerController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AMyPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "MyPlayerController.h" },
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClickRepInfo_MetaData[] = {
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocalClickRepInfo_MetaData[] = {
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AMyPlayerController constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClickRepInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ClickRepInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LocalClickRepInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LocalClickRepInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AMyPlayerController constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ExcuteClientClickRequest"), .Pointer = &AMyPlayerController::execExcuteClientClickRequest },
		{ .NameUTF8 = UTF8TEXT("OnRep_ClickInfo"), .Pointer = &AMyPlayerController::execOnRep_ClickInfo },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyPlayerController_ExcuteClientClickRequest, "ExcuteClientClickRequest" }, // 1778829918
		{ &Z_Construct_UFunction_AMyPlayerController_OnRep_ClickInfo, "OnRep_ClickInfo" }, // 3741698948
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AMyPlayerController_Statics

// ********** Begin Class AMyPlayerController Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyPlayerController_Statics::NewProp_ClickRepInfo_Inner = { "ClickRepInfo", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FClick_ValidInfo_Rep, METADATA_PARAMS(0, nullptr) }; // 439374860
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMyPlayerController_Statics::NewProp_ClickRepInfo = { "ClickRepInfo", "OnRep_ClickInfo", (EPropertyFlags)0x0040008100000020, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayerController, ClickRepInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClickRepInfo_MetaData), NewProp_ClickRepInfo_MetaData) }; // 439374860
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyPlayerController_Statics::NewProp_LocalClickRepInfo_Inner = { "LocalClickRepInfo", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FClick_ValidInfo_Rep, METADATA_PARAMS(0, nullptr) }; // 439374860
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMyPlayerController_Statics::NewProp_LocalClickRepInfo = { "LocalClickRepInfo", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayerController, LocalClickRepInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocalClickRepInfo_MetaData), NewProp_LocalClickRepInfo_MetaData) }; // 439374860
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayerController_Statics::NewProp_ClickRepInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayerController_Statics::NewProp_ClickRepInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayerController_Statics::NewProp_LocalClickRepInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayerController_Statics::NewProp_LocalClickRepInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::PropPointers) < 2048);
// ********** End Class AMyPlayerController Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_AMyPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AMyPlayerController_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UClickActorPCInterface_NoRegister, (int32)VTABLE_OFFSET(AMyPlayerController, IClickActorPCInterface), false },  // 2134406423
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyPlayerController_Statics::ClassParams = {
	&AMyPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMyPlayerController_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyPlayerController_Statics::Class_MetaDataParams)
};
void AMyPlayerController::StaticRegisterNativesAMyPlayerController()
{
	UClass* Class = AMyPlayerController::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AMyPlayerController_Statics::Funcs));
}
UClass* Z_Construct_UClass_AMyPlayerController()
{
	if (!Z_Registration_Info_UClass_AMyPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyPlayerController.OuterSingleton, Z_Construct_UClass_AMyPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyPlayerController.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AMyPlayerController::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_ClickRepInfo(TEXT("ClickRepInfo"));
	const bool bIsValid = true
		&& Name_ClickRepInfo == ClassReps[(int32)ENetFields_Private::ClickRepInfo].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AMyPlayerController"));
}
#endif
AMyPlayerController::AMyPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AMyPlayerController);
AMyPlayerController::~AMyPlayerController() {}
// ********** End Class AMyPlayerController ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h__Script_MyProject_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyPlayerController, AMyPlayerController::StaticClass, TEXT("AMyPlayerController"), &Z_Registration_Info_UClass_AMyPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyPlayerController), 3449027149U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h__Script_MyProject_1113866348{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyPlayerController_h__Script_MyProject_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
