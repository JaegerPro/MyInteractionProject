// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/PersistBaseComponent.h"
#include "UObject/Class.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePersistBaseComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
MYPROJECT_API UClass* Z_Construct_UClass_UPersistBaseComponent();
MYPROJECT_API UClass* Z_Construct_UClass_UPersistBaseComponent_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UPersistEffectBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPersistBaseComponent Function ApplyPersistEffect ************************
struct Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics
{
	struct PersistBaseComponent_eventApplyPersistEffect_Parms
	{
		UPersistBaseComponent* PersistComponent;
		UPersistEffectBase* DataModel;
		float OverrideApplyTime;
		UPersistEffectBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "PersistBaseComponent" },
		{ "CPP_Default_OverrideApplyTime", "-1.000000" },
		{ "ModuleRelativePath", "PersistBaseComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PersistComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyPersistEffect constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PersistComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DataModel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OverrideApplyTime;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyPersistEffect constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyPersistEffect Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::NewProp_PersistComponent = { "PersistComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventApplyPersistEffect_Parms, PersistComponent), Z_Construct_UClass_UPersistBaseComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PersistComponent_MetaData), NewProp_PersistComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::NewProp_DataModel = { "DataModel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventApplyPersistEffect_Parms, DataModel), Z_Construct_UClass_UPersistEffectBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::NewProp_OverrideApplyTime = { "OverrideApplyTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventApplyPersistEffect_Parms, OverrideApplyTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventApplyPersistEffect_Parms, ReturnValue), Z_Construct_UClass_UPersistEffectBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::NewProp_PersistComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::NewProp_DataModel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::NewProp_OverrideApplyTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::PropPointers) < 2048);
// ********** End Function ApplyPersistEffect Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistBaseComponent, nullptr, "ApplyPersistEffect", 	Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::PersistBaseComponent_eventApplyPersistEffect_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::PersistBaseComponent_eventApplyPersistEffect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistBaseComponent::execApplyPersistEffect)
{
	P_GET_OBJECT(UPersistBaseComponent,Z_Param_PersistComponent);
	P_GET_OBJECT(UPersistEffectBase,Z_Param_DataModel);
	P_GET_PROPERTY(FFloatProperty,Z_Param_OverrideApplyTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPersistEffectBase**)Z_Param__Result=UPersistBaseComponent::ApplyPersistEffect(Z_Param_PersistComponent,Z_Param_DataModel,Z_Param_OverrideApplyTime);
	P_NATIVE_END;
}
// ********** End Class UPersistBaseComponent Function ApplyPersistEffect **************************

// ********** Begin Class UPersistBaseComponent Function ApplyPersistEffectData ********************
struct Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics
{
	struct PersistBaseComponent_eventApplyPersistEffectData_Parms
	{
		UPersistEffectBase* DataModel;
		float OverrideApplyTime;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CPP_Default_OverrideApplyTime", "-1.000000" },
		{ "ModuleRelativePath", "PersistBaseComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyPersistEffectData constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DataModel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OverrideApplyTime;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyPersistEffectData constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyPersistEffectData Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::NewProp_DataModel = { "DataModel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventApplyPersistEffectData_Parms, DataModel), Z_Construct_UClass_UPersistEffectBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::NewProp_OverrideApplyTime = { "OverrideApplyTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventApplyPersistEffectData_Parms, OverrideApplyTime), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PersistBaseComponent_eventApplyPersistEffectData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PersistBaseComponent_eventApplyPersistEffectData_Parms), &Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::NewProp_DataModel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::NewProp_OverrideApplyTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::PropPointers) < 2048);
// ********** End Function ApplyPersistEffectData Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistBaseComponent, nullptr, "ApplyPersistEffectData", 	Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::PersistBaseComponent_eventApplyPersistEffectData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::PersistBaseComponent_eventApplyPersistEffectData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistBaseComponent::execApplyPersistEffectData)
{
	P_GET_OBJECT(UPersistEffectBase,Z_Param_DataModel);
	P_GET_PROPERTY(FFloatProperty,Z_Param_OverrideApplyTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ApplyPersistEffectData(Z_Param_DataModel,Z_Param_OverrideApplyTime);
	P_NATIVE_END;
}
// ********** End Class UPersistBaseComponent Function ApplyPersistEffectData **********************

// ********** Begin Class UPersistBaseComponent Function ApplyPersistEffectDataByClass *************
struct Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics
{
	struct PersistBaseComponent_eventApplyPersistEffectDataByClass_Parms
	{
		TSubclassOf<UPersistEffectBase> Class;
		float OverrideApplyTime;
		UPersistEffectBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CPP_Default_OverrideApplyTime", "-1.000000" },
		{ "ModuleRelativePath", "PersistBaseComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyPersistEffectDataByClass constinit property declarations *********
	static const UECodeGen_Private::FClassPropertyParams NewProp_Class;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OverrideApplyTime;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyPersistEffectDataByClass constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyPersistEffectDataByClass Property Definitions ********************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::NewProp_Class = { "Class", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventApplyPersistEffectDataByClass_Parms, Class), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UPersistEffectBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::NewProp_OverrideApplyTime = { "OverrideApplyTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventApplyPersistEffectDataByClass_Parms, OverrideApplyTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventApplyPersistEffectDataByClass_Parms, ReturnValue), Z_Construct_UClass_UPersistEffectBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::NewProp_Class,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::NewProp_OverrideApplyTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::PropPointers) < 2048);
// ********** End Function ApplyPersistEffectDataByClass Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistBaseComponent, nullptr, "ApplyPersistEffectDataByClass", 	Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::PersistBaseComponent_eventApplyPersistEffectDataByClass_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::PersistBaseComponent_eventApplyPersistEffectDataByClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistBaseComponent::execApplyPersistEffectDataByClass)
{
	P_GET_OBJECT(UClass,Z_Param_Class);
	P_GET_PROPERTY(FFloatProperty,Z_Param_OverrideApplyTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPersistEffectBase**)Z_Param__Result=P_THIS->ApplyPersistEffectDataByClass(Z_Param_Class,Z_Param_OverrideApplyTime);
	P_NATIVE_END;
}
// ********** End Class UPersistBaseComponent Function ApplyPersistEffectDataByClass ***************

// ********** Begin Class UPersistBaseComponent Function CreatePersistEffectDataByClass ************
struct Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics
{
	struct PersistBaseComponent_eventCreatePersistEffectDataByClass_Parms
	{
		TSubclassOf<UPersistEffectBase> Class;
		UPersistEffectBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistBaseComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreatePersistEffectDataByClass constinit property declarations ********
	static const UECodeGen_Private::FClassPropertyParams NewProp_Class;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreatePersistEffectDataByClass constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreatePersistEffectDataByClass Property Definitions *******************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::NewProp_Class = { "Class", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventCreatePersistEffectDataByClass_Parms, Class), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UPersistEffectBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventCreatePersistEffectDataByClass_Parms, ReturnValue), Z_Construct_UClass_UPersistEffectBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::NewProp_Class,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::PropPointers) < 2048);
// ********** End Function CreatePersistEffectDataByClass Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistBaseComponent, nullptr, "CreatePersistEffectDataByClass", 	Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::PersistBaseComponent_eventCreatePersistEffectDataByClass_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::PersistBaseComponent_eventCreatePersistEffectDataByClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistBaseComponent::execCreatePersistEffectDataByClass)
{
	P_GET_OBJECT(UClass,Z_Param_Class);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPersistEffectBase**)Z_Param__Result=P_THIS->CreatePersistEffectDataByClass(Z_Param_Class);
	P_NATIVE_END;
}
// ********** End Class UPersistBaseComponent Function CreatePersistEffectDataByClass **************

// ********** Begin Class UPersistBaseComponent Function GetNetOwnerActor **************************
struct Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics
{
	struct PersistBaseComponent_eventGetNetOwnerActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistBaseComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetNetOwnerActor constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNetOwnerActor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNetOwnerActor Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventGetNetOwnerActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::PropPointers) < 2048);
// ********** End Function GetNetOwnerActor Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistBaseComponent, nullptr, "GetNetOwnerActor", 	Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::PersistBaseComponent_eventGetNetOwnerActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::PersistBaseComponent_eventGetNetOwnerActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistBaseComponent::execGetNetOwnerActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetNetOwnerActor();
	P_NATIVE_END;
}
// ********** End Class UPersistBaseComponent Function GetNetOwnerActor ****************************

// ********** Begin Class UPersistBaseComponent Function UnApplyPersistEffectData ******************
struct Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics
{
	struct PersistBaseComponent_eventUnApplyPersistEffectData_Parms
	{
		UPersistEffectBase* Data;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistBaseComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UnApplyPersistEffectData constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Data;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnApplyPersistEffectData constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnApplyPersistEffectData Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistBaseComponent_eventUnApplyPersistEffectData_Parms, Data), Z_Construct_UClass_UPersistEffectBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::NewProp_Data,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::PropPointers) < 2048);
// ********** End Function UnApplyPersistEffectData Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistBaseComponent, nullptr, "UnApplyPersistEffectData", 	Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::PersistBaseComponent_eventUnApplyPersistEffectData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::PersistBaseComponent_eventUnApplyPersistEffectData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistBaseComponent::execUnApplyPersistEffectData)
{
	P_GET_OBJECT(UPersistEffectBase,Z_Param_Data);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnApplyPersistEffectData(Z_Param_Data);
	P_NATIVE_END;
}
// ********** End Class UPersistBaseComponent Function UnApplyPersistEffectData ********************

// ********** Begin Class UPersistBaseComponent ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPersistBaseComponent;
UClass* UPersistBaseComponent::GetPrivateStaticClass()
{
	using TClass = UPersistBaseComponent;
	if (!Z_Registration_Info_UClass_UPersistBaseComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PersistBaseComponent"),
			Z_Registration_Info_UClass_UPersistBaseComponent.InnerSingleton,
			StaticRegisterNativesUPersistBaseComponent,
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
	return Z_Registration_Info_UClass_UPersistBaseComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UPersistBaseComponent_NoRegister()
{
	return UPersistBaseComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPersistBaseComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "PersistBaseComponent.h" },
		{ "ModuleRelativePath", "PersistBaseComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CacheOwner_MetaData[] = {
		{ "ModuleRelativePath", "PersistBaseComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PersistDataArray_MetaData[] = {
		{ "ModuleRelativePath", "PersistBaseComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPersistBaseComponent constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CacheOwner;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PersistDataArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PersistDataArray;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPersistBaseComponent constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyPersistEffect"), .Pointer = &UPersistBaseComponent::execApplyPersistEffect },
		{ .NameUTF8 = UTF8TEXT("ApplyPersistEffectData"), .Pointer = &UPersistBaseComponent::execApplyPersistEffectData },
		{ .NameUTF8 = UTF8TEXT("ApplyPersistEffectDataByClass"), .Pointer = &UPersistBaseComponent::execApplyPersistEffectDataByClass },
		{ .NameUTF8 = UTF8TEXT("CreatePersistEffectDataByClass"), .Pointer = &UPersistBaseComponent::execCreatePersistEffectDataByClass },
		{ .NameUTF8 = UTF8TEXT("GetNetOwnerActor"), .Pointer = &UPersistBaseComponent::execGetNetOwnerActor },
		{ .NameUTF8 = UTF8TEXT("UnApplyPersistEffectData"), .Pointer = &UPersistBaseComponent::execUnApplyPersistEffectData },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffect, "ApplyPersistEffect" }, // 2883177217
		{ &Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectData, "ApplyPersistEffectData" }, // 1033379225
		{ &Z_Construct_UFunction_UPersistBaseComponent_ApplyPersistEffectDataByClass, "ApplyPersistEffectDataByClass" }, // 3442170098
		{ &Z_Construct_UFunction_UPersistBaseComponent_CreatePersistEffectDataByClass, "CreatePersistEffectDataByClass" }, // 1181078464
		{ &Z_Construct_UFunction_UPersistBaseComponent_GetNetOwnerActor, "GetNetOwnerActor" }, // 3320682147
		{ &Z_Construct_UFunction_UPersistBaseComponent_UnApplyPersistEffectData, "UnApplyPersistEffectData" }, // 1369412860
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPersistBaseComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPersistBaseComponent_Statics

// ********** Begin Class UPersistBaseComponent Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPersistBaseComponent_Statics::NewProp_CacheOwner = { "CacheOwner", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistBaseComponent, CacheOwner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CacheOwner_MetaData), NewProp_CacheOwner_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPersistBaseComponent_Statics::NewProp_PersistDataArray_Inner = { "PersistDataArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPersistEffectBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPersistBaseComponent_Statics::NewProp_PersistDataArray = { "PersistDataArray", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistBaseComponent, PersistDataArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PersistDataArray_MetaData), NewProp_PersistDataArray_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPersistBaseComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistBaseComponent_Statics::NewProp_CacheOwner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistBaseComponent_Statics::NewProp_PersistDataArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistBaseComponent_Statics::NewProp_PersistDataArray,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistBaseComponent_Statics::PropPointers) < 2048);
// ********** End Class UPersistBaseComponent Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UPersistBaseComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistBaseComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPersistBaseComponent_Statics::ClassParams = {
	&UPersistBaseComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPersistBaseComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPersistBaseComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistBaseComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPersistBaseComponent_Statics::Class_MetaDataParams)
};
void UPersistBaseComponent::StaticRegisterNativesUPersistBaseComponent()
{
	UClass* Class = UPersistBaseComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPersistBaseComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPersistBaseComponent()
{
	if (!Z_Registration_Info_UClass_UPersistBaseComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPersistBaseComponent.OuterSingleton, Z_Construct_UClass_UPersistBaseComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPersistBaseComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPersistBaseComponent);
UPersistBaseComponent::~UPersistBaseComponent() {}
// ********** End Class UPersistBaseComponent ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h__Script_MyProject_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPersistBaseComponent, UPersistBaseComponent::StaticClass, TEXT("UPersistBaseComponent"), &Z_Registration_Info_UClass_UPersistBaseComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPersistBaseComponent), 3251552850U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h__Script_MyProject_3575852507{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistBaseComponent_h__Script_MyProject_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
