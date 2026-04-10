// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/CustomActor/CustomTypeDefine.h"
#include "Components/ActorComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCustomTypeDefine() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
MYPROJECT_API UClass* Z_Construct_UClass_UComponentSelectorStatics();
MYPROJECT_API UClass* Z_Construct_UClass_UComponentSelectorStatics_NoRegister();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FActorComponentSelector();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FShapeComponentSelector();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FActorComponentSelector *******************************************
struct Z_Construct_UScriptStruct_FActorComponentSelector_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FActorComponentSelector); }
	static inline consteval int16 GetStructAlignment() { return alignof(FActorComponentSelector); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "CustomActor/CustomTypeDefine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComponentName_MetaData[] = {
		{ "Category", "ActorComponentSelector" },
		{ "ModuleRelativePath", "CustomActor/CustomTypeDefine.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FActorComponentSelector constinit property declarations ***********
	static const UECodeGen_Private::FNamePropertyParams NewProp_ComponentName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FActorComponentSelector constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActorComponentSelector>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FActorComponentSelector_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FActorComponentSelector;
class UScriptStruct* FActorComponentSelector::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FActorComponentSelector.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FActorComponentSelector.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActorComponentSelector, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("ActorComponentSelector"));
	}
	return Z_Registration_Info_UScriptStruct_FActorComponentSelector.OuterSingleton;
	}

// ********** Begin ScriptStruct FActorComponentSelector Property Definitions **********************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FActorComponentSelector_Statics::NewProp_ComponentName = { "ComponentName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActorComponentSelector, ComponentName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComponentName_MetaData), NewProp_ComponentName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActorComponentSelector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorComponentSelector_Statics::NewProp_ComponentName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentSelector_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FActorComponentSelector Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActorComponentSelector_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"ActorComponentSelector",
	Z_Construct_UScriptStruct_FActorComponentSelector_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentSelector_Statics::PropPointers),
	sizeof(FActorComponentSelector),
	alignof(FActorComponentSelector),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentSelector_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FActorComponentSelector_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FActorComponentSelector()
{
	if (!Z_Registration_Info_UScriptStruct_FActorComponentSelector.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FActorComponentSelector.InnerSingleton, Z_Construct_UScriptStruct_FActorComponentSelector_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FActorComponentSelector.InnerSingleton);
}
// ********** End ScriptStruct FActorComponentSelector *********************************************

// ********** Begin ScriptStruct FShapeComponentSelector *******************************************
struct Z_Construct_UScriptStruct_FShapeComponentSelector_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FShapeComponentSelector); }
	static inline consteval int16 GetStructAlignment() { return alignof(FShapeComponentSelector); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ComponentSelectorClassFilter", "/Script/Engine.ShapeComponent" },
		{ "ModuleRelativePath", "CustomActor/CustomTypeDefine.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FShapeComponentSelector constinit property declarations ***********
// ********** End ScriptStruct FShapeComponentSelector constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FShapeComponentSelector>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FShapeComponentSelector_Statics
static_assert(std::is_polymorphic<FShapeComponentSelector>() == std::is_polymorphic<FActorComponentSelector>(), "USTRUCT FShapeComponentSelector cannot be polymorphic unless super FActorComponentSelector is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FShapeComponentSelector;
class UScriptStruct* FShapeComponentSelector::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FShapeComponentSelector.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FShapeComponentSelector.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FShapeComponentSelector, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("ShapeComponentSelector"));
	}
	return Z_Registration_Info_UScriptStruct_FShapeComponentSelector.OuterSingleton;
	}
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FShapeComponentSelector_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	Z_Construct_UScriptStruct_FActorComponentSelector,
	&NewStructOps,
	"ShapeComponentSelector",
	nullptr,
	0,
	sizeof(FShapeComponentSelector),
	alignof(FShapeComponentSelector),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FShapeComponentSelector_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FShapeComponentSelector_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FShapeComponentSelector()
{
	if (!Z_Registration_Info_UScriptStruct_FShapeComponentSelector.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FShapeComponentSelector.InnerSingleton, Z_Construct_UScriptStruct_FShapeComponentSelector_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FShapeComponentSelector.InnerSingleton);
}
// ********** End ScriptStruct FShapeComponentSelector *********************************************

// ********** Begin Class UComponentSelectorStatics Function GetComponentBySelector ****************
struct Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics
{
	struct ComponentSelectorStatics_eventGetComponentBySelector_Parms
	{
		const AActor* OwnerActor;
		FActorComponentSelector ComponentSelector;
		UActorComponent* OutComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ComponentSelector" },
		{ "ModuleRelativePath", "CustomActor/CustomTypeDefine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerActor_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComponentSelector_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetComponentBySelector constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ComponentSelector;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OutComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetComponentBySelector constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetComponentBySelector Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::NewProp_OwnerActor = { "OwnerActor", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComponentSelectorStatics_eventGetComponentBySelector_Parms, OwnerActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerActor_MetaData), NewProp_OwnerActor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::NewProp_ComponentSelector = { "ComponentSelector", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComponentSelectorStatics_eventGetComponentBySelector_Parms, ComponentSelector), Z_Construct_UScriptStruct_FActorComponentSelector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComponentSelector_MetaData), NewProp_ComponentSelector_MetaData) }; // 2031125257
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::NewProp_OutComponent = { "OutComponent", nullptr, (EPropertyFlags)0x0010000000080180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ComponentSelectorStatics_eventGetComponentBySelector_Parms, OutComponent), Z_Construct_UClass_UActorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutComponent_MetaData), NewProp_OutComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::NewProp_OwnerActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::NewProp_ComponentSelector,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::NewProp_OutComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::PropPointers) < 2048);
// ********** End Function GetComponentBySelector Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UComponentSelectorStatics, nullptr, "GetComponentBySelector", 	Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::ComponentSelectorStatics_eventGetComponentBySelector_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::Function_MetaDataParams), Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::ComponentSelectorStatics_eventGetComponentBySelector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UComponentSelectorStatics::execGetComponentBySelector)
{
	P_GET_OBJECT(AActor,Z_Param_OwnerActor);
	P_GET_STRUCT_REF(FActorComponentSelector,Z_Param_Out_ComponentSelector);
	P_GET_OBJECT_REF(UActorComponent,Z_Param_Out_OutComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	UComponentSelectorStatics::GetComponentBySelector(Z_Param_OwnerActor,Z_Param_Out_ComponentSelector,P_ARG_GC_BARRIER(Z_Param_Out_OutComponent));
	P_NATIVE_END;
}
// ********** End Class UComponentSelectorStatics Function GetComponentBySelector ******************

// ********** Begin Class UComponentSelectorStatics ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UComponentSelectorStatics;
UClass* UComponentSelectorStatics::GetPrivateStaticClass()
{
	using TClass = UComponentSelectorStatics;
	if (!Z_Registration_Info_UClass_UComponentSelectorStatics.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ComponentSelectorStatics"),
			Z_Registration_Info_UClass_UComponentSelectorStatics.InnerSingleton,
			StaticRegisterNativesUComponentSelectorStatics,
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
	return Z_Registration_Info_UClass_UComponentSelectorStatics.InnerSingleton;
}
UClass* Z_Construct_UClass_UComponentSelectorStatics_NoRegister()
{
	return UComponentSelectorStatics::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UComponentSelectorStatics_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "CustomActor/CustomTypeDefine.h" },
		{ "ModuleRelativePath", "CustomActor/CustomTypeDefine.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UComponentSelectorStatics constinit property declarations ****************
// ********** End Class UComponentSelectorStatics constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetComponentBySelector"), .Pointer = &UComponentSelectorStatics::execGetComponentBySelector },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UComponentSelectorStatics_GetComponentBySelector, "GetComponentBySelector" }, // 403502344
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UComponentSelectorStatics>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UComponentSelectorStatics_Statics
UObject* (*const Z_Construct_UClass_UComponentSelectorStatics_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UComponentSelectorStatics_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UComponentSelectorStatics_Statics::ClassParams = {
	&UComponentSelectorStatics::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UComponentSelectorStatics_Statics::Class_MetaDataParams), Z_Construct_UClass_UComponentSelectorStatics_Statics::Class_MetaDataParams)
};
void UComponentSelectorStatics::StaticRegisterNativesUComponentSelectorStatics()
{
	UClass* Class = UComponentSelectorStatics::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UComponentSelectorStatics_Statics::Funcs));
}
UClass* Z_Construct_UClass_UComponentSelectorStatics()
{
	if (!Z_Registration_Info_UClass_UComponentSelectorStatics.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UComponentSelectorStatics.OuterSingleton, Z_Construct_UClass_UComponentSelectorStatics_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UComponentSelectorStatics.OuterSingleton;
}
UComponentSelectorStatics::UComponentSelectorStatics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UComponentSelectorStatics);
UComponentSelectorStatics::~UComponentSelectorStatics() {}
// ********** End Class UComponentSelectorStatics **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h__Script_MyProject_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FActorComponentSelector::StaticStruct, Z_Construct_UScriptStruct_FActorComponentSelector_Statics::NewStructOps, TEXT("ActorComponentSelector"),&Z_Registration_Info_UScriptStruct_FActorComponentSelector, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActorComponentSelector), 2031125257U) },
		{ FShapeComponentSelector::StaticStruct, Z_Construct_UScriptStruct_FShapeComponentSelector_Statics::NewStructOps, TEXT("ShapeComponentSelector"),&Z_Registration_Info_UScriptStruct_FShapeComponentSelector, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FShapeComponentSelector), 2091030609U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UComponentSelectorStatics, UComponentSelectorStatics::StaticClass, TEXT("UComponentSelectorStatics"), &Z_Registration_Info_UClass_UComponentSelectorStatics, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UComponentSelectorStatics), 2783105839U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h__Script_MyProject_1059776289{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h__Script_MyProject_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h__Script_MyProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_CustomActor_CustomTypeDefine_h__Script_MyProject_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
