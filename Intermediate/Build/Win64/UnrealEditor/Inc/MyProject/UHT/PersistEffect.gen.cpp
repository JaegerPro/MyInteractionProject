// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/PersistEffect.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodePersistEffect() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UPersistBaseComponent_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UPersistEffectBase();
MYPROJECT_API UClass* Z_Construct_UClass_UPersistEffectBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPersistEffectBase Function CanApply *************************************
struct Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics
{
	struct PersistEffectBase_eventCanApply_Parms
	{
		AActor* OwnerActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistEffect.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanApply constinit property declarations ******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerActor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanApply constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanApply Property Definitions *****************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::NewProp_OwnerActor = { "OwnerActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectBase_eventCanApply_Parms, OwnerActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PersistEffectBase_eventCanApply_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PersistEffectBase_eventCanApply_Parms), &Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::NewProp_OwnerActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::PropPointers) < 2048);
// ********** End Function CanApply Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectBase, nullptr, "CanApply", 	Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::PersistEffectBase_eventCanApply_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::PersistEffectBase_eventCanApply_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectBase_CanApply()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectBase_CanApply_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistEffectBase::execCanApply)
{
	P_GET_OBJECT(AActor,Z_Param_OwnerActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanApply(Z_Param_OwnerActor);
	P_NATIVE_END;
}
// ********** End Class UPersistEffectBase Function CanApply ***************************************

// ********** Begin Class UPersistEffectBase Function CanApply_BP **********************************
struct PersistEffectBase_eventCanApply_BP_Parms
{
	AActor* Character;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	PersistEffectBase_eventCanApply_BP_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UPersistEffectBase_CanApply_BP = FName(TEXT("CanApply_BP"));
bool UPersistEffectBase::CanApply_BP(AActor* Character)
{
	UFunction* Func = FindFunctionChecked(NAME_UPersistEffectBase_CanApply_BP);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		PersistEffectBase_eventCanApply_BP_Parms Parms;
		Parms.Character=Character;
	ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return CanApply_BP_Implementation(Character);
	}
}
struct Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistEffect.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanApply_BP constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanApply_BP constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanApply_BP Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectBase_eventCanApply_BP_Parms, Character), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PersistEffectBase_eventCanApply_BP_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PersistEffectBase_eventCanApply_BP_Parms), &Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::NewProp_Character,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::PropPointers) < 2048);
// ********** End Function CanApply_BP Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectBase, nullptr, "CanApply_BP", 	Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::PropPointers), 
sizeof(PersistEffectBase_eventCanApply_BP_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(PersistEffectBase_eventCanApply_BP_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectBase_CanApply_BP()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectBase_CanApply_BP_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistEffectBase::execCanApply_BP)
{
	P_GET_OBJECT(AActor,Z_Param_Character);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanApply_BP_Implementation(Z_Param_Character);
	P_NATIVE_END;
}
// ********** End Class UPersistEffectBase Function CanApply_BP ************************************

// ********** Begin Class UPersistEffectBase Function GetNetOwnerActor *****************************
struct Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics
{
	struct PersistEffectBase_eventGetNetOwnerActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistEffect.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetNetOwnerActor constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNetOwnerActor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNetOwnerActor Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectBase_eventGetNetOwnerActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::PropPointers) < 2048);
// ********** End Function GetNetOwnerActor Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectBase, nullptr, "GetNetOwnerActor", 	Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::PersistEffectBase_eventGetNetOwnerActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::PersistEffectBase_eventGetNetOwnerActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistEffectBase::execGetNetOwnerActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetNetOwnerActor();
	P_NATIVE_END;
}
// ********** End Class UPersistEffectBase Function GetNetOwnerActor *******************************

// ********** Begin Class UPersistEffectBase Function GetOwnerSafety *******************************
struct Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics
{
	struct PersistEffectBase_eventGetOwnerSafety_Parms
	{
		UPersistBaseComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistEffect.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetOwnerSafety constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOwnerSafety constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOwnerSafety Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectBase_eventGetOwnerSafety_Parms, ReturnValue), Z_Construct_UClass_UPersistBaseComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::PropPointers) < 2048);
// ********** End Function GetOwnerSafety Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectBase, nullptr, "GetOwnerSafety", 	Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::PersistEffectBase_eventGetOwnerSafety_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::PersistEffectBase_eventGetOwnerSafety_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistEffectBase::execGetOwnerSafety)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPersistBaseComponent**)Z_Param__Result=P_THIS->GetOwnerSafety();
	P_NATIVE_END;
}
// ********** End Class UPersistEffectBase Function GetOwnerSafety *********************************

// ********** Begin Class UPersistEffectBase Function HasAuthority *********************************
struct Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics
{
	struct PersistEffectBase_eventHasAuthority_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistEffect.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasAuthority constinit property declarations **************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasAuthority constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasAuthority Property Definitions *************************************
void Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PersistEffectBase_eventHasAuthority_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PersistEffectBase_eventHasAuthority_Parms), &Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::PropPointers) < 2048);
// ********** End Function HasAuthority Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectBase, nullptr, "HasAuthority", 	Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::PersistEffectBase_eventHasAuthority_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::PersistEffectBase_eventHasAuthority_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectBase_HasAuthority()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectBase_HasAuthority_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistEffectBase::execHasAuthority)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasAuthority();
	P_NATIVE_END;
}
// ********** End Class UPersistEffectBase Function HasAuthority ***********************************

// ********** Begin Class UPersistEffectBase Function OnApply_BP ***********************************
struct PersistEffectBase_eventOnApply_BP_Parms
{
	AActor* Character;
};
static FName NAME_UPersistEffectBase_OnApply_BP = FName(TEXT("OnApply_BP"));
void UPersistEffectBase::OnApply_BP(AActor* Character)
{
	PersistEffectBase_eventOnApply_BP_Parms Parms;
	Parms.Character=Character;
	UFunction* Func = FindFunctionChecked(NAME_UPersistEffectBase_OnApply_BP);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistEffect.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnApply_BP constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnApply_BP constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnApply_BP Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectBase_eventOnApply_BP_Parms, Character), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::NewProp_Character,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::PropPointers) < 2048);
// ********** End Function OnApply_BP Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectBase, nullptr, "OnApply_BP", 	Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::PropPointers), 
sizeof(PersistEffectBase_eventOnApply_BP_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(PersistEffectBase_eventOnApply_BP_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectBase_OnApply_BP()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectBase_OnApply_BP_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UPersistEffectBase Function OnApply_BP *************************************

// ********** Begin Class UPersistEffectBase Function OnUnApply_BP *********************************
struct PersistEffectBase_eventOnUnApply_BP_Parms
{
	AActor* Character;
};
static FName NAME_UPersistEffectBase_OnUnApply_BP = FName(TEXT("OnUnApply_BP"));
void UPersistEffectBase::OnUnApply_BP(AActor* Character)
{
	PersistEffectBase_eventOnUnApply_BP_Parms Parms;
	Parms.Character=Character;
	UFunction* Func = FindFunctionChecked(NAME_UPersistEffectBase_OnUnApply_BP);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PersistEffect.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnUnApply_BP constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Character;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnUnApply_BP constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnUnApply_BP Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistEffectBase_eventOnUnApply_BP_Parms, Character), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::NewProp_Character,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::PropPointers) < 2048);
// ********** End Function OnUnApply_BP Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistEffectBase, nullptr, "OnUnApply_BP", 	Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::PropPointers), 
sizeof(PersistEffectBase_eventOnUnApply_BP_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(PersistEffectBase_eventOnUnApply_BP_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UPersistEffectBase Function OnUnApply_BP ***********************************

// ********** Begin Class UPersistEffectBase *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UPersistEffectBase;
UClass* UPersistEffectBase::GetPrivateStaticClass()
{
	using TClass = UPersistEffectBase;
	if (!Z_Registration_Info_UClass_UPersistEffectBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("PersistEffectBase"),
			Z_Registration_Info_UClass_UPersistEffectBase.InnerSingleton,
			StaticRegisterNativesUPersistEffectBase,
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
	return Z_Registration_Info_UClass_UPersistEffectBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UPersistEffectBase_NoRegister()
{
	return UPersistEffectBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPersistEffectBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "PersistEffect.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "PersistEffect.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Owner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PersistEffect.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UPersistEffectBase constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Owner;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UPersistEffectBase constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanApply"), .Pointer = &UPersistEffectBase::execCanApply },
		{ .NameUTF8 = UTF8TEXT("CanApply_BP"), .Pointer = &UPersistEffectBase::execCanApply_BP },
		{ .NameUTF8 = UTF8TEXT("GetNetOwnerActor"), .Pointer = &UPersistEffectBase::execGetNetOwnerActor },
		{ .NameUTF8 = UTF8TEXT("GetOwnerSafety"), .Pointer = &UPersistEffectBase::execGetOwnerSafety },
		{ .NameUTF8 = UTF8TEXT("HasAuthority"), .Pointer = &UPersistEffectBase::execHasAuthority },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPersistEffectBase_CanApply, "CanApply" }, // 1199104243
		{ &Z_Construct_UFunction_UPersistEffectBase_CanApply_BP, "CanApply_BP" }, // 2513096443
		{ &Z_Construct_UFunction_UPersistEffectBase_GetNetOwnerActor, "GetNetOwnerActor" }, // 1133826603
		{ &Z_Construct_UFunction_UPersistEffectBase_GetOwnerSafety, "GetOwnerSafety" }, // 8614038
		{ &Z_Construct_UFunction_UPersistEffectBase_HasAuthority, "HasAuthority" }, // 1851723758
		{ &Z_Construct_UFunction_UPersistEffectBase_OnApply_BP, "OnApply_BP" }, // 1667518109
		{ &Z_Construct_UFunction_UPersistEffectBase_OnUnApply_BP, "OnUnApply_BP" }, // 3087268783
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPersistEffectBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UPersistEffectBase_Statics

// ********** Begin Class UPersistEffectBase Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPersistEffectBase_Statics::NewProp_Owner = { "Owner", nullptr, (EPropertyFlags)0x0020080000080028, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistEffectBase, Owner), Z_Construct_UClass_UPersistBaseComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Owner_MetaData), NewProp_Owner_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPersistEffectBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistEffectBase_Statics::NewProp_Owner,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistEffectBase_Statics::PropPointers) < 2048);
// ********** End Class UPersistEffectBase Property Definitions ************************************
UObject* (*const Z_Construct_UClass_UPersistEffectBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistEffectBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPersistEffectBase_Statics::ClassParams = {
	&UPersistEffectBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPersistEffectBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPersistEffectBase_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistEffectBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UPersistEffectBase_Statics::Class_MetaDataParams)
};
void UPersistEffectBase::StaticRegisterNativesUPersistEffectBase()
{
	UClass* Class = UPersistEffectBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UPersistEffectBase_Statics::Funcs));
}
UClass* Z_Construct_UClass_UPersistEffectBase()
{
	if (!Z_Registration_Info_UClass_UPersistEffectBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPersistEffectBase.OuterSingleton, Z_Construct_UClass_UPersistEffectBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPersistEffectBase.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UPersistEffectBase::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_Owner(TEXT("Owner"));
	const bool bIsValid = true
		&& Name_Owner == ClassReps[(int32)ENetFields_Private::Owner].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UPersistEffectBase"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UPersistEffectBase);
UPersistEffectBase::~UPersistEffectBase() {}
// ********** End Class UPersistEffectBase *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h__Script_MyProject_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPersistEffectBase, UPersistEffectBase::StaticClass, TEXT("UPersistEffectBase"), &Z_Registration_Info_UClass_UPersistEffectBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPersistEffectBase), 3192121942U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h__Script_MyProject_432320046{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_PersistEffect_h__Script_MyProject_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
