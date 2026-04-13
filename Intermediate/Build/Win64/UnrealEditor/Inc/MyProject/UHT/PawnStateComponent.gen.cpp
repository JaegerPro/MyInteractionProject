// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/PawnStateComponent.h"
#include "MyProject/PawnState.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePawnStateComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
MYPROJECT_API UClass* Z_Construct_UClass_UPawnStateComponent();
MYPROJECT_API UClass* Z_Construct_UClass_UPawnStateComponent_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_USimpleStateConfig();
MYPROJECT_API UClass* Z_Construct_UClass_USimpleStateConfig_NoRegister();
MYPROJECT_API UEnum* Z_Construct_UEnum_MyProject_EPawnState();
MYPROJECT_API UEnum* Z_Construct_UEnum_MyProject_EPawnStateRelation();
MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature();
MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature();
MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleBitMask();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FStateCounter();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FStateRelationConfig();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FStateRelationConfig **********************************************
struct Z_Construct_UScriptStruct_FStateRelationConfig_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FStateRelationConfig); }
	static inline consteval int16 GetStructAlignment() { return alignof(FStateRelationConfig); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * State relation configuration (editable in Blueprint/DataAsset)\n */" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State relation configuration (editable in Blueprint/DataAsset)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateA_MetaData[] = {
		{ "Category", "StateRelationConfig" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// State X\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State X" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateB_MetaData[] = {
		{ "Category", "StateRelationConfig" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// State Y\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State Y" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Relation_MetaData[] = {
		{ "Category", "StateRelationConfig" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Relation type\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Relation type" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FStateRelationConfig constinit property declarations **************
	static const UECodeGen_Private::FBytePropertyParams NewProp_StateA_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StateA;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StateB_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StateB;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Relation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Relation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FStateRelationConfig constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStateRelationConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FStateRelationConfig_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FStateRelationConfig;
class UScriptStruct* FStateRelationConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FStateRelationConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FStateRelationConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStateRelationConfig, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("StateRelationConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FStateRelationConfig.OuterSingleton;
	}

// ********** Begin ScriptStruct FStateRelationConfig Property Definitions *************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_StateA_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_StateA = { "StateA", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStateRelationConfig, StateA), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateA_MetaData), NewProp_StateA_MetaData) }; // 2115640282
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_StateB_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_StateB = { "StateB", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStateRelationConfig, StateB), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateB_MetaData), NewProp_StateB_MetaData) }; // 2115640282
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_Relation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_Relation = { "Relation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStateRelationConfig, Relation), Z_Construct_UEnum_MyProject_EPawnStateRelation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Relation_MetaData), NewProp_Relation_MetaData) }; // 3503330507
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStateRelationConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_StateA_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_StateA,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_StateB_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_StateB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_Relation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewProp_Relation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateRelationConfig_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FStateRelationConfig Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStateRelationConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"StateRelationConfig",
	Z_Construct_UScriptStruct_FStateRelationConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateRelationConfig_Statics::PropPointers),
	sizeof(FStateRelationConfig),
	alignof(FStateRelationConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateRelationConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStateRelationConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStateRelationConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FStateRelationConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FStateRelationConfig.InnerSingleton, Z_Construct_UScriptStruct_FStateRelationConfig_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FStateRelationConfig.InnerSingleton);
}
// ********** End ScriptStruct FStateRelationConfig ************************************************

// ********** Begin Class USimpleStateConfig *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USimpleStateConfig;
UClass* USimpleStateConfig::GetPrivateStaticClass()
{
	using TClass = USimpleStateConfig;
	if (!Z_Registration_Info_UClass_USimpleStateConfig.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SimpleStateConfig"),
			Z_Registration_Info_UClass_USimpleStateConfig.InnerSingleton,
			StaticRegisterNativesUSimpleStateConfig,
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
	return Z_Registration_Info_UClass_USimpleStateConfig.InnerSingleton;
}
UClass* Z_Construct_UClass_USimpleStateConfig_NoRegister()
{
	return USimpleStateConfig::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USimpleStateConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Configuration asset for state relations\n */" },
#endif
		{ "IncludePath", "PawnStateComponent.h" },
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration asset for state relations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateRelations_MetaData[] = {
		{ "Category", "State Relations" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// State mutex relations\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State mutex relations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDisabledStates_MetaData[] = {
		{ "Category", "Default" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// States that are disabled by default\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "States that are disabled by default" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USimpleStateConfig constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_StateRelations_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StateRelations;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultDisabledStates_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultDisabledStates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DefaultDisabledStates;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USimpleStateConfig constinit property declarations *************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USimpleStateConfig>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USimpleStateConfig_Statics

// ********** Begin Class USimpleStateConfig Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_StateRelations_Inner = { "StateRelations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FStateRelationConfig, METADATA_PARAMS(0, nullptr) }; // 702915379
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_StateRelations = { "StateRelations", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USimpleStateConfig, StateRelations), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateRelations_MetaData), NewProp_StateRelations_MetaData) }; // 702915379
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_DefaultDisabledStates_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_DefaultDisabledStates_Inner = { "DefaultDisabledStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_DefaultDisabledStates = { "DefaultDisabledStates", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USimpleStateConfig, DefaultDisabledStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDisabledStates_MetaData), NewProp_DefaultDisabledStates_MetaData) }; // 2115640282
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USimpleStateConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_StateRelations_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_StateRelations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_DefaultDisabledStates_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_DefaultDisabledStates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleStateConfig_Statics::NewProp_DefaultDisabledStates,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleStateConfig_Statics::PropPointers) < 2048);
// ********** End Class USimpleStateConfig Property Definitions ************************************
UObject* (*const Z_Construct_UClass_USimpleStateConfig_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleStateConfig_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USimpleStateConfig_Statics::ClassParams = {
	&USimpleStateConfig::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_USimpleStateConfig_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_USimpleStateConfig_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleStateConfig_Statics::Class_MetaDataParams), Z_Construct_UClass_USimpleStateConfig_Statics::Class_MetaDataParams)
};
void USimpleStateConfig::StaticRegisterNativesUSimpleStateConfig()
{
}
UClass* Z_Construct_UClass_USimpleStateConfig()
{
	if (!Z_Registration_Info_UClass_USimpleStateConfig.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USimpleStateConfig.OuterSingleton, Z_Construct_UClass_USimpleStateConfig_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USimpleStateConfig.OuterSingleton;
}
USimpleStateConfig::USimpleStateConfig(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USimpleStateConfig);
USimpleStateConfig::~USimpleStateConfig() {}
// ********** End Class USimpleStateConfig *********************************************************

// ********** Begin Class UPawnStateComponent Function AddStateRelation ****************************
struct Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics
{
	struct PawnStateComponent_eventAddStateRelation_Parms
	{
		EPawnState StateA;
		EPawnState StateB;
		EPawnStateRelation Relation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Add a state relation\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add a state relation" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddStateRelation constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_StateA_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StateA;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StateB_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StateB;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Relation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Relation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddStateRelation constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddStateRelation Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_StateA_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_StateA = { "StateA", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventAddStateRelation_Parms, StateA), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_StateB_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_StateB = { "StateB", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventAddStateRelation_Parms, StateB), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_Relation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_Relation = { "Relation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventAddStateRelation_Parms, Relation), Z_Construct_UEnum_MyProject_EPawnStateRelation, METADATA_PARAMS(0, nullptr) }; // 3503330507
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_StateA_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_StateA,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_StateB_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_StateB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_Relation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::NewProp_Relation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::PropPointers) < 2048);
// ********** End Function AddStateRelation Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "AddStateRelation", 	Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::PawnStateComponent_eventAddStateRelation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::PawnStateComponent_eventAddStateRelation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_AddStateRelation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_AddStateRelation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execAddStateRelation)
{
	P_GET_ENUM(EPawnState,Z_Param_StateA);
	P_GET_ENUM(EPawnState,Z_Param_StateB);
	P_GET_ENUM(EPawnStateRelation,Z_Param_Relation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddStateRelation(EPawnState(Z_Param_StateA),EPawnState(Z_Param_StateB),EPawnStateRelation(Z_Param_Relation));
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function AddStateRelation ******************************

// ********** Begin Class UPawnStateComponent Function CanEnterState *******************************
struct Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics
{
	struct PawnStateComponent_eventCanEnterState_Parms
	{
		EPawnState State;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Check if state can be entered (mutex check)\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if state can be entered (mutex check)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CanEnterState constinit property declarations *************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanEnterState constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanEnterState Property Definitions ************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventCanEnterState_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
void Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PawnStateComponent_eventCanEnterState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PawnStateComponent_eventCanEnterState_Parms), &Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::PropPointers) < 2048);
// ********** End Function CanEnterState Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "CanEnterState", 	Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::PawnStateComponent_eventCanEnterState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::PawnStateComponent_eventCanEnterState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_CanEnterState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_CanEnterState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execCanEnterState)
{
	P_GET_ENUM(EPawnState,Z_Param_State);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanEnterState(EPawnState(Z_Param_State));
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function CanEnterState *********************************

// ********** Begin Class UPawnStateComponent Function ClearStateRelations *************************
struct Z_Construct_UFunction_UPawnStateComponent_ClearStateRelations_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Clear all state relations\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear all state relations" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ClearStateRelations constinit property declarations *******************
// ********** End Function ClearStateRelations constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_ClearStateRelations_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "ClearStateRelations", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_ClearStateRelations_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_ClearStateRelations_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UPawnStateComponent_ClearStateRelations()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_ClearStateRelations_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execClearStateRelations)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearStateRelations();
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function ClearStateRelations ***************************

// ********** Begin Class UPawnStateComponent Function EnterState **********************************
struct Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics
{
	struct PawnStateComponent_eventEnterState_Parms
	{
		EPawnState State;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Enter a state (returns true if successful)\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enter a state (returns true if successful)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function EnterState constinit property declarations ****************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EnterState constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EnterState Property Definitions ***************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventEnterState_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
void Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PawnStateComponent_eventEnterState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PawnStateComponent_eventEnterState_Parms), &Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::PropPointers) < 2048);
// ********** End Function EnterState Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "EnterState", 	Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::PawnStateComponent_eventEnterState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::PawnStateComponent_eventEnterState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_EnterState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_EnterState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execEnterState)
{
	P_GET_ENUM(EPawnState,Z_Param_State);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->EnterState(EPawnState(Z_Param_State));
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function EnterState ************************************

// ********** Begin Class UPawnStateComponent Function GetActiveStates *****************************
struct Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics
{
	struct PawnStateComponent_eventGetActiveStates_Parms
	{
		TArray<EPawnState> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Get all active states\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get all active states" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveStates constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveStates constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveStates Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventGetActiveStates_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::NewProp_ReturnValue_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::PropPointers) < 2048);
// ********** End Function GetActiveStates Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "GetActiveStates", 	Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::PawnStateComponent_eventGetActiveStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::PawnStateComponent_eventGetActiveStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_GetActiveStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_GetActiveStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execGetActiveStates)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<EPawnState>*)Z_Param__Result=P_THIS->GetActiveStates();
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function GetActiveStates *******************************

// ********** Begin Class UPawnStateComponent Function GetCurrentStatesBits ************************
struct Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics
{
	struct PawnStateComponent_eventGetCurrentStatesBits_Parms
	{
		uint64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Get raw bitmask\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get raw bitmask" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentStatesBits constinit property declarations ******************
	static const UECodeGen_Private::FUInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentStatesBits constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentStatesBits Property Definitions *****************************
const UECodeGen_Private::FUInt64PropertyParams Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::UInt64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventGetCurrentStatesBits_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentStatesBits Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "GetCurrentStatesBits", 	Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::PawnStateComponent_eventGetCurrentStatesBits_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::PawnStateComponent_eventGetCurrentStatesBits_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execGetCurrentStatesBits)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(uint64*)Z_Param__Result=P_THIS->GetCurrentStatesBits();
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function GetCurrentStatesBits **************************

// ********** Begin Class UPawnStateComponent Function GetStateDebugString *************************
struct Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics
{
	struct PawnStateComponent_eventGetStateDebugString_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Debug ====================\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Debug ====================" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetStateDebugString constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetStateDebugString constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetStateDebugString Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventGetStateDebugString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::PropPointers) < 2048);
// ********** End Function GetStateDebugString Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "GetStateDebugString", 	Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::PawnStateComponent_eventGetStateDebugString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::PawnStateComponent_eventGetStateDebugString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execGetStateDebugString)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetStateDebugString();
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function GetStateDebugString ***************************

// ********** Begin Class UPawnStateComponent Function HasAllStates ********************************
struct Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics
{
	struct PawnStateComponent_eventHasAllStates_Parms
	{
		TArray<EPawnState> States;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Check if all given states are active\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if all given states are active" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_States_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasAllStates constinit property declarations **************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_States_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_States_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_States;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasAllStates constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasAllStates Property Definitions *************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_States_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_States_Inner = { "States", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_States = { "States", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventHasAllStates_Parms, States), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_States_MetaData), NewProp_States_MetaData) }; // 2115640282
void Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PawnStateComponent_eventHasAllStates_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PawnStateComponent_eventHasAllStates_Parms), &Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_States_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_States_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_States,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::PropPointers) < 2048);
// ********** End Function HasAllStates Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "HasAllStates", 	Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::PawnStateComponent_eventHasAllStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::PawnStateComponent_eventHasAllStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_HasAllStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_HasAllStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execHasAllStates)
{
	P_GET_TARRAY_REF(EPawnState,Z_Param_Out_States);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasAllStates(Z_Param_Out_States);
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function HasAllStates **********************************

// ********** Begin Class UPawnStateComponent Function HasAnyStates ********************************
struct Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics
{
	struct PawnStateComponent_eventHasAnyStates_Parms
	{
		TArray<EPawnState> States;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Check if any of the given states is active\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if any of the given states is active" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_States_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasAnyStates constinit property declarations **************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_States_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_States_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_States;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasAnyStates constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasAnyStates Property Definitions *************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_States_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_States_Inner = { "States", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_States = { "States", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventHasAnyStates_Parms, States), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_States_MetaData), NewProp_States_MetaData) }; // 2115640282
void Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PawnStateComponent_eventHasAnyStates_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PawnStateComponent_eventHasAnyStates_Parms), &Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_States_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_States_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_States,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::PropPointers) < 2048);
// ********** End Function HasAnyStates Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "HasAnyStates", 	Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::PawnStateComponent_eventHasAnyStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::PawnStateComponent_eventHasAnyStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_HasAnyStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_HasAnyStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execHasAnyStates)
{
	P_GET_TARRAY_REF(EPawnState,Z_Param_Out_States);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasAnyStates(Z_Param_Out_States);
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function HasAnyStates **********************************

// ********** Begin Class UPawnStateComponent Function HasState ************************************
struct Z_Construct_UFunction_UPawnStateComponent_HasState_Statics
{
	struct PawnStateComponent_eventHasState_Parms
	{
		EPawnState State;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Check if state is active\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if state is active" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HasState constinit property declarations ******************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasState constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasState Property Definitions *****************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventHasState_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
void Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PawnStateComponent_eventHasState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PawnStateComponent_eventHasState_Parms), &Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::PropPointers) < 2048);
// ********** End Function HasState Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "HasState", 	Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::PawnStateComponent_eventHasState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::PawnStateComponent_eventHasState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_HasState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_HasState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execHasState)
{
	P_GET_ENUM(EPawnState,Z_Param_State);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasState(EPawnState(Z_Param_State));
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function HasState **************************************

// ********** Begin Class UPawnStateComponent Function IsStateDisabled *****************************
struct Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics
{
	struct PawnStateComponent_eventIsStateDisabled_Parms
	{
		EPawnState State;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Check if state is disabled\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if state is disabled" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsStateDisabled constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsStateDisabled constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsStateDisabled Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventIsStateDisabled_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
void Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PawnStateComponent_eventIsStateDisabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PawnStateComponent_eventIsStateDisabled_Parms), &Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::PropPointers) < 2048);
// ********** End Function IsStateDisabled Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "IsStateDisabled", 	Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::PawnStateComponent_eventIsStateDisabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::PawnStateComponent_eventIsStateDisabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execIsStateDisabled)
{
	P_GET_ENUM(EPawnState,Z_Param_State);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsStateDisabled(EPawnState(Z_Param_State));
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function IsStateDisabled *******************************

// ********** Begin Class UPawnStateComponent Function LeaveAllStates ******************************
struct Z_Construct_UFunction_UPawnStateComponent_LeaveAllStates_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Leave all states\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Leave all states" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function LeaveAllStates constinit property declarations ************************
// ********** End Function LeaveAllStates constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_LeaveAllStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "LeaveAllStates", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_LeaveAllStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_LeaveAllStates_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UPawnStateComponent_LeaveAllStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_LeaveAllStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execLeaveAllStates)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LeaveAllStates();
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function LeaveAllStates ********************************

// ********** Begin Class UPawnStateComponent Function LeaveState **********************************
struct Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics
{
	struct PawnStateComponent_eventLeaveState_Parms
	{
		EPawnState State;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Leave a state (returns true if successful)\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Leave a state (returns true if successful)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function LeaveState constinit property declarations ****************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LeaveState constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LeaveState Property Definitions ***************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventLeaveState_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
void Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PawnStateComponent_eventLeaveState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PawnStateComponent_eventLeaveState_Parms), &Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::PropPointers) < 2048);
// ********** End Function LeaveState Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "LeaveState", 	Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::PawnStateComponent_eventLeaveState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::PawnStateComponent_eventLeaveState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_LeaveState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_LeaveState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execLeaveState)
{
	P_GET_ENUM(EPawnState,Z_Param_State);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LeaveState(EPawnState(Z_Param_State));
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function LeaveState ************************************

// ********** Begin Class UPawnStateComponent Function OnlyHasStates *******************************
struct Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics
{
	struct PawnStateComponent_eventOnlyHasStates_Parms
	{
		TArray<EPawnState> States;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Check if only these states are active\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if only these states are active" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_States_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnlyHasStates constinit property declarations *************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_States_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_States_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_States;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnlyHasStates constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnlyHasStates Property Definitions ************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_States_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_States_Inner = { "States", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_States = { "States", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventOnlyHasStates_Parms, States), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_States_MetaData), NewProp_States_MetaData) }; // 2115640282
void Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PawnStateComponent_eventOnlyHasStates_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PawnStateComponent_eventOnlyHasStates_Parms), &Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_States_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_States_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_States,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::PropPointers) < 2048);
// ********** End Function OnlyHasStates Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "OnlyHasStates", 	Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::PawnStateComponent_eventOnlyHasStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::PawnStateComponent_eventOnlyHasStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execOnlyHasStates)
{
	P_GET_TARRAY_REF(EPawnState,Z_Param_Out_States);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->OnlyHasStates(Z_Param_Out_States);
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function OnlyHasStates *********************************

// ********** Begin Class UPawnStateComponent Function OnRep_CurrentStates *************************
struct Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics
{
	struct PawnStateComponent_eventOnRep_CurrentStates_Parms
	{
		FSimpleBitMask OldStates;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PawnStateComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnRep_CurrentStates constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OldStates;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnRep_CurrentStates constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnRep_CurrentStates Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::NewProp_OldStates = { "OldStates", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventOnRep_CurrentStates_Parms, OldStates), Z_Construct_UScriptStruct_FSimpleBitMask, METADATA_PARAMS(0, nullptr) }; // 1093497791
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::NewProp_OldStates,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::PropPointers) < 2048);
// ********** End Function OnRep_CurrentStates Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "OnRep_CurrentStates", 	Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::PawnStateComponent_eventOnRep_CurrentStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::PawnStateComponent_eventOnRep_CurrentStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execOnRep_CurrentStates)
{
	P_GET_STRUCT(FSimpleBitMask,Z_Param_OldStates);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentStates(Z_Param_OldStates);
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function OnRep_CurrentStates ***************************

// ********** Begin Class UPawnStateComponent Function ResetStateDisabled **************************
struct Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics
{
	struct PawnStateComponent_eventResetStateDisabled_Parms
	{
		EPawnState State;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reset disabled state\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reset disabled state" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ResetStateDisabled constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetStateDisabled constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetStateDisabled Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventResetStateDisabled_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::NewProp_State,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::PropPointers) < 2048);
// ********** End Function ResetStateDisabled Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "ResetStateDisabled", 	Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::PawnStateComponent_eventResetStateDisabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::PawnStateComponent_eventResetStateDisabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execResetStateDisabled)
{
	P_GET_ENUM(EPawnState,Z_Param_State);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetStateDisabled(EPawnState(Z_Param_State));
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function ResetStateDisabled ****************************

// ********** Begin Class UPawnStateComponent Function SetStateConfig ******************************
struct Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics
{
	struct PawnStateComponent_eventSetStateConfig_Parms
	{
		USimpleStateConfig* InConfig;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Set state configuration\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set state configuration" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStateConfig constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InConfig;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStateConfig constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStateConfig Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::NewProp_InConfig = { "InConfig", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventSetStateConfig_Parms, InConfig), Z_Construct_UClass_USimpleStateConfig_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::NewProp_InConfig,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::PropPointers) < 2048);
// ********** End Function SetStateConfig Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "SetStateConfig", 	Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::PawnStateComponent_eventSetStateConfig_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::PawnStateComponent_eventSetStateConfig_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_SetStateConfig()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_SetStateConfig_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execSetStateConfig)
{
	P_GET_OBJECT(USimpleStateConfig,Z_Param_InConfig);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStateConfig(Z_Param_InConfig);
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function SetStateConfig ********************************

// ********** Begin Class UPawnStateComponent Function SetStateDisabled ****************************
struct Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics
{
	struct PawnStateComponent_eventSetStateDisabled_Parms
	{
		EPawnState State;
		bool bDisabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Disable a state (prevents entering)\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Disable a state (prevents entering)" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStateDisabled constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static void NewProp_bDisabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStateDisabled constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStateDisabled Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PawnStateComponent_eventSetStateDisabled_Parms, State), Z_Construct_UEnum_MyProject_EPawnState, METADATA_PARAMS(0, nullptr) }; // 2115640282
void Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::NewProp_bDisabled_SetBit(void* Obj)
{
	((PawnStateComponent_eventSetStateDisabled_Parms*)Obj)->bDisabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::NewProp_bDisabled = { "bDisabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PawnStateComponent_eventSetStateDisabled_Parms), &Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::NewProp_bDisabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::NewProp_bDisabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::PropPointers) < 2048);
// ********** End Function SetStateDisabled Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPawnStateComponent, nullptr, "SetStateDisabled", 	Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::PawnStateComponent_eventSetStateDisabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::PawnStateComponent_eventSetStateDisabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPawnStateComponent::execSetStateDisabled)
{
	P_GET_ENUM(EPawnState,Z_Param_State);
	P_GET_UBOOL(Z_Param_bDisabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStateDisabled(EPawnState(Z_Param_State),Z_Param_bDisabled);
	P_NATIVE_END;
}
// ********** End Class UPawnStateComponent Function SetStateDisabled ******************************

// ********** Begin Class UPawnStateComponent ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPawnStateComponent;
UClass* UPawnStateComponent::GetPrivateStaticClass()
{
	using TClass = UPawnStateComponent;
	if (!Z_Registration_Info_UClass_UPawnStateComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PawnStateComponent"),
			Z_Registration_Info_UClass_UPawnStateComponent.InnerSingleton,
			StaticRegisterNativesUPawnStateComponent,
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
	return Z_Registration_Info_UClass_UPawnStateComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UPawnStateComponent_NoRegister()
{
	return UPawnStateComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPawnStateComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Game" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Main state management component\n * Attach to any Character or Actor that needs state management\n */" },
#endif
		{ "IncludePath", "PawnStateComponent.h" },
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Main state management component\nAttach to any Character or Actor that needs state management" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStateEnter_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when a state is entered\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when a state is entered" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStateLeave_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when a state is left\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when a state is left" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStateInterrupt_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when a state is interrupted by another\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when a state is interrupted by another" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStates_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current active states\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current active states" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisabledStates_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Disabled states with reference counting\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Disabled states with reference counting" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateConfig_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// State configuration\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateRelations_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// State relation matrix: [StateA][StateB] = Relation\n// Stored in a flattened map for quick lookup\n" },
#endif
		{ "ModuleRelativePath", "PawnStateComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State relation matrix: [StateA][StateB] = Relation\nStored in a flattened map for quick lookup" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UPawnStateComponent constinit property declarations **********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateEnter;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateLeave;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateInterrupt;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentStates;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DisabledStates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DisabledStates;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StateConfig;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StateRelations_ValueProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StateRelations_ValueProp;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_StateRelations_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_StateRelations;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPawnStateComponent constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddStateRelation"), .Pointer = &UPawnStateComponent::execAddStateRelation },
		{ .NameUTF8 = UTF8TEXT("CanEnterState"), .Pointer = &UPawnStateComponent::execCanEnterState },
		{ .NameUTF8 = UTF8TEXT("ClearStateRelations"), .Pointer = &UPawnStateComponent::execClearStateRelations },
		{ .NameUTF8 = UTF8TEXT("EnterState"), .Pointer = &UPawnStateComponent::execEnterState },
		{ .NameUTF8 = UTF8TEXT("GetActiveStates"), .Pointer = &UPawnStateComponent::execGetActiveStates },
		{ .NameUTF8 = UTF8TEXT("GetCurrentStatesBits"), .Pointer = &UPawnStateComponent::execGetCurrentStatesBits },
		{ .NameUTF8 = UTF8TEXT("GetStateDebugString"), .Pointer = &UPawnStateComponent::execGetStateDebugString },
		{ .NameUTF8 = UTF8TEXT("HasAllStates"), .Pointer = &UPawnStateComponent::execHasAllStates },
		{ .NameUTF8 = UTF8TEXT("HasAnyStates"), .Pointer = &UPawnStateComponent::execHasAnyStates },
		{ .NameUTF8 = UTF8TEXT("HasState"), .Pointer = &UPawnStateComponent::execHasState },
		{ .NameUTF8 = UTF8TEXT("IsStateDisabled"), .Pointer = &UPawnStateComponent::execIsStateDisabled },
		{ .NameUTF8 = UTF8TEXT("LeaveAllStates"), .Pointer = &UPawnStateComponent::execLeaveAllStates },
		{ .NameUTF8 = UTF8TEXT("LeaveState"), .Pointer = &UPawnStateComponent::execLeaveState },
		{ .NameUTF8 = UTF8TEXT("OnlyHasStates"), .Pointer = &UPawnStateComponent::execOnlyHasStates },
		{ .NameUTF8 = UTF8TEXT("OnRep_CurrentStates"), .Pointer = &UPawnStateComponent::execOnRep_CurrentStates },
		{ .NameUTF8 = UTF8TEXT("ResetStateDisabled"), .Pointer = &UPawnStateComponent::execResetStateDisabled },
		{ .NameUTF8 = UTF8TEXT("SetStateConfig"), .Pointer = &UPawnStateComponent::execSetStateConfig },
		{ .NameUTF8 = UTF8TEXT("SetStateDisabled"), .Pointer = &UPawnStateComponent::execSetStateDisabled },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPawnStateComponent_AddStateRelation, "AddStateRelation" }, // 2412675077
		{ &Z_Construct_UFunction_UPawnStateComponent_CanEnterState, "CanEnterState" }, // 3535268107
		{ &Z_Construct_UFunction_UPawnStateComponent_ClearStateRelations, "ClearStateRelations" }, // 3410997971
		{ &Z_Construct_UFunction_UPawnStateComponent_EnterState, "EnterState" }, // 1313836120
		{ &Z_Construct_UFunction_UPawnStateComponent_GetActiveStates, "GetActiveStates" }, // 275944790
		{ &Z_Construct_UFunction_UPawnStateComponent_GetCurrentStatesBits, "GetCurrentStatesBits" }, // 203006475
		{ &Z_Construct_UFunction_UPawnStateComponent_GetStateDebugString, "GetStateDebugString" }, // 2559542991
		{ &Z_Construct_UFunction_UPawnStateComponent_HasAllStates, "HasAllStates" }, // 3395865763
		{ &Z_Construct_UFunction_UPawnStateComponent_HasAnyStates, "HasAnyStates" }, // 142104380
		{ &Z_Construct_UFunction_UPawnStateComponent_HasState, "HasState" }, // 3494061987
		{ &Z_Construct_UFunction_UPawnStateComponent_IsStateDisabled, "IsStateDisabled" }, // 2568730520
		{ &Z_Construct_UFunction_UPawnStateComponent_LeaveAllStates, "LeaveAllStates" }, // 3010956208
		{ &Z_Construct_UFunction_UPawnStateComponent_LeaveState, "LeaveState" }, // 4277335766
		{ &Z_Construct_UFunction_UPawnStateComponent_OnlyHasStates, "OnlyHasStates" }, // 1266143711
		{ &Z_Construct_UFunction_UPawnStateComponent_OnRep_CurrentStates, "OnRep_CurrentStates" }, // 3473728610
		{ &Z_Construct_UFunction_UPawnStateComponent_ResetStateDisabled, "ResetStateDisabled" }, // 1450864287
		{ &Z_Construct_UFunction_UPawnStateComponent_SetStateConfig, "SetStateConfig" }, // 2409728021
		{ &Z_Construct_UFunction_UPawnStateComponent_SetStateDisabled, "SetStateDisabled" }, // 4148751800
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPawnStateComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPawnStateComponent_Statics

// ********** Begin Class UPawnStateComponent Property Definitions *********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_OnStateEnter = { "OnStateEnter", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPawnStateComponent, OnStateEnter), Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStateEnter_MetaData), NewProp_OnStateEnter_MetaData) }; // 490324427
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_OnStateLeave = { "OnStateLeave", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPawnStateComponent, OnStateLeave), Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStateLeave_MetaData), NewProp_OnStateLeave_MetaData) }; // 3731987691
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_OnStateInterrupt = { "OnStateInterrupt", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPawnStateComponent, OnStateInterrupt), Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStateInterrupt_MetaData), NewProp_OnStateInterrupt_MetaData) }; // 1902260547
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_CurrentStates = { "CurrentStates", "OnRep_CurrentStates", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPawnStateComponent, CurrentStates), Z_Construct_UScriptStruct_FSimpleBitMask, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStates_MetaData), NewProp_CurrentStates_MetaData) }; // 1093497791
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_DisabledStates_Inner = { "DisabledStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FStateCounter, METADATA_PARAMS(0, nullptr) }; // 2607366446
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_DisabledStates = { "DisabledStates", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPawnStateComponent, DisabledStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisabledStates_MetaData), NewProp_DisabledStates_MetaData) }; // 2607366446
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateConfig = { "StateConfig", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPawnStateComponent, StateConfig), Z_Construct_UClass_USimpleStateConfig_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateConfig_MetaData), NewProp_StateConfig_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateRelations_ValueProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateRelations_ValueProp = { "StateRelations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UEnum_MyProject_EPawnStateRelation, METADATA_PARAMS(0, nullptr) }; // 3503330507
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateRelations_Key_KeyProp = { "StateRelations_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateRelations = { "StateRelations", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPawnStateComponent, StateRelations), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateRelations_MetaData), NewProp_StateRelations_MetaData) }; // 3503330507
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPawnStateComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_OnStateEnter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_OnStateLeave,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_OnStateInterrupt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_CurrentStates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_DisabledStates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_DisabledStates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateRelations_ValueProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateRelations_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateRelations_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnStateComponent_Statics::NewProp_StateRelations,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPawnStateComponent_Statics::PropPointers) < 2048);
// ********** End Class UPawnStateComponent Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UPawnStateComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPawnStateComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPawnStateComponent_Statics::ClassParams = {
	&UPawnStateComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPawnStateComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPawnStateComponent_Statics::PropPointers),
	0,
	0x00A000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPawnStateComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPawnStateComponent_Statics::Class_MetaDataParams)
};
void UPawnStateComponent::StaticRegisterNativesUPawnStateComponent()
{
	UClass* Class = UPawnStateComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPawnStateComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPawnStateComponent()
{
	if (!Z_Registration_Info_UClass_UPawnStateComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPawnStateComponent.OuterSingleton, Z_Construct_UClass_UPawnStateComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPawnStateComponent.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UPawnStateComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_CurrentStates(TEXT("CurrentStates"));
	const bool bIsValid = true
		&& Name_CurrentStates == ClassReps[(int32)ENetFields_Private::CurrentStates].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UPawnStateComponent"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPawnStateComponent);
UPawnStateComponent::~UPawnStateComponent() {}
// ********** End Class UPawnStateComponent ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h__Script_MyProject_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FStateRelationConfig::StaticStruct, Z_Construct_UScriptStruct_FStateRelationConfig_Statics::NewStructOps, TEXT("StateRelationConfig"),&Z_Registration_Info_UScriptStruct_FStateRelationConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStateRelationConfig), 702915379U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USimpleStateConfig, USimpleStateConfig::StaticClass, TEXT("USimpleStateConfig"), &Z_Registration_Info_UClass_USimpleStateConfig, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USimpleStateConfig), 1969322892U) },
		{ Z_Construct_UClass_UPawnStateComponent, UPawnStateComponent::StaticClass, TEXT("UPawnStateComponent"), &Z_Registration_Info_UClass_UPawnStateComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPawnStateComponent), 3797003828U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h__Script_MyProject_3271500564{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h__Script_MyProject_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h__Script_MyProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PawnStateComponent_h__Script_MyProject_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
