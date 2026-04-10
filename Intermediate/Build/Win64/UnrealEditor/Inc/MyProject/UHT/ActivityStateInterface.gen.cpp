// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/ActivityStateInterface.h"
#include "UObject/SoftObjectPath.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeActivityStateInterface() {}

// ********** Begin Cross Module References ********************************************************
ACTORSEQUENCE_API UClass* Z_Construct_UClass_UActorSequenceComponent_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UFunction_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
LEVELSEQUENCE_API UClass* Z_Construct_UClass_ULevelSequence_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UActivityStateInterface();
MYPROJECT_API UClass* Z_Construct_UClass_UActivityStateInterface_NoRegister();
MYPROJECT_API UEnum* Z_Construct_UEnum_MyProject_ESequenceBindingType();
MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FActivityLink();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FActivityState();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FActivityStateRep();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ESequenceBindingType ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESequenceBindingType;
static UEnum* ESequenceBindingType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESequenceBindingType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESequenceBindingType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MyProject_ESequenceBindingType, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("ESequenceBindingType"));
	}
	return Z_Registration_Info_UEnum_ESequenceBindingType.OuterSingleton;
}
template<> MYPROJECT_NON_ATTRIBUTED_API UEnum* StaticEnum<ESequenceBindingType>()
{
	return ESequenceBindingType_StaticEnum();
}
struct Z_Construct_UEnum_MyProject_ESequenceBindingType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BindingActorSequence.Name", "ESequenceBindingType::BindingActorSequence" },
		{ "BindingLevelSequence.Name", "ESequenceBindingType::BindingLevelSequence" },
		{ "BindingSoftLevelSequence.Name", "ESequenceBindingType::BindingSoftLevelSequence" },
		{ "BlueprintType", "true" },
		{ "GenerateActorSequence.Name", "ESequenceBindingType::GenerateActorSequence" },
		{ "GenerateSkillSequence.Name", "ESequenceBindingType::GenerateSkillSequence" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
		{ "None.Name", "ESequenceBindingType::None" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESequenceBindingType::None", (int64)ESequenceBindingType::None },
		{ "ESequenceBindingType::GenerateActorSequence", (int64)ESequenceBindingType::GenerateActorSequence },
		{ "ESequenceBindingType::BindingActorSequence", (int64)ESequenceBindingType::BindingActorSequence },
		{ "ESequenceBindingType::BindingLevelSequence", (int64)ESequenceBindingType::BindingLevelSequence },
		{ "ESequenceBindingType::BindingSoftLevelSequence", (int64)ESequenceBindingType::BindingSoftLevelSequence },
		{ "ESequenceBindingType::GenerateSkillSequence", (int64)ESequenceBindingType::GenerateSkillSequence },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_MyProject_ESequenceBindingType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MyProject_ESequenceBindingType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	"ESequenceBindingType",
	"ESequenceBindingType",
	Z_Construct_UEnum_MyProject_ESequenceBindingType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MyProject_ESequenceBindingType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MyProject_ESequenceBindingType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MyProject_ESequenceBindingType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MyProject_ESequenceBindingType()
{
	if (!Z_Registration_Info_UEnum_ESequenceBindingType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESequenceBindingType.InnerSingleton, Z_Construct_UEnum_MyProject_ESequenceBindingType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESequenceBindingType.InnerSingleton;
}
// ********** End Enum ESequenceBindingType ********************************************************

// ********** Begin Delegate FActivityChangeState **************************************************
struct Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics
{
	struct _Script_MyProject_eventActivityChangeState_Parms
	{
		FName LeaveState;
		FName EnterState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeaveState_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnterState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FActivityChangeState constinit property declarations ******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_LeaveState;
	static const UECodeGen_Private::FNamePropertyParams NewProp_EnterState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FActivityChangeState constinit property declarations ********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FActivityChangeState Property Definitions *****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::NewProp_LeaveState = { "LeaveState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_MyProject_eventActivityChangeState_Parms, LeaveState), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeaveState_MetaData), NewProp_LeaveState_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::NewProp_EnterState = { "EnterState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_MyProject_eventActivityChangeState_Parms, EnterState), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnterState_MetaData), NewProp_EnterState_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::NewProp_LeaveState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::NewProp_EnterState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FActivityChangeState Property Definitions *******************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_MyProject, nullptr, "ActivityChangeState__DelegateSignature", 	Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::_Script_MyProject_eventActivityChangeState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::_Script_MyProject_eventActivityChangeState_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FActivityChangeState_DelegateWrapper(const FMulticastScriptDelegate& ActivityChangeState, FName const& LeaveState, FName const& EnterState)
{
	struct _Script_MyProject_eventActivityChangeState_Parms
	{
		FName LeaveState;
		FName EnterState;
	};
	_Script_MyProject_eventActivityChangeState_Parms Parms;
	Parms.LeaveState=LeaveState;
	Parms.EnterState=EnterState;
	ActivityChangeState.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FActivityChangeState ****************************************************

// ********** Begin ScriptStruct FActivityLink *****************************************************
struct Z_Construct_UScriptStruct_FActivityLink_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FActivityLink); }
	static inline consteval int16 GetStructAlignment() { return alignof(FActivityLink); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinkName_MetaData[] = {
		{ "Category", "ActivityLink" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinkConditionFunctionName_MetaData[] = {
		{ "Category", "ActivityLink" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bNotCondition_MetaData[] = {
		{ "Category", "ActivityLink" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xc7\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xa1\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc7\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xa1\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinkConditionFunction_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinkStateIndex_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinkStateName_MetaData[] = {
		{ "Category", "ActivityLink" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FActivityLink constinit property declarations *********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_LinkName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_LinkConditionFunctionName;
	static void NewProp_bNotCondition_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNotCondition;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LinkConditionFunction;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LinkStateIndex;
	static const UECodeGen_Private::FNamePropertyParams NewProp_LinkStateName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FActivityLink constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActivityLink>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FActivityLink_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FActivityLink;
class UScriptStruct* FActivityLink::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FActivityLink.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FActivityLink.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActivityLink, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("ActivityLink"));
	}
	return Z_Registration_Info_UScriptStruct_FActivityLink.OuterSingleton;
	}

// ********** Begin ScriptStruct FActivityLink Property Definitions ********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkName = { "LinkName", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityLink, LinkName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinkName_MetaData), NewProp_LinkName_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkConditionFunctionName = { "LinkConditionFunctionName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityLink, LinkConditionFunctionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinkConditionFunctionName_MetaData), NewProp_LinkConditionFunctionName_MetaData) };
void Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_bNotCondition_SetBit(void* Obj)
{
	((FActivityLink*)Obj)->bNotCondition = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_bNotCondition = { "bNotCondition", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FActivityLink), &Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_bNotCondition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bNotCondition_MetaData), NewProp_bNotCondition_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkConditionFunction = { "LinkConditionFunction", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityLink, LinkConditionFunction), Z_Construct_UClass_UFunction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinkConditionFunction_MetaData), NewProp_LinkConditionFunction_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkStateIndex = { "LinkStateIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityLink, LinkStateIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinkStateIndex_MetaData), NewProp_LinkStateIndex_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkStateName = { "LinkStateName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityLink, LinkStateName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinkStateName_MetaData), NewProp_LinkStateName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActivityLink_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkConditionFunctionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_bNotCondition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkConditionFunction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkStateIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityLink_Statics::NewProp_LinkStateName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActivityLink_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FActivityLink Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActivityLink_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"ActivityLink",
	Z_Construct_UScriptStruct_FActivityLink_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActivityLink_Statics::PropPointers),
	sizeof(FActivityLink),
	alignof(FActivityLink),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActivityLink_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FActivityLink_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FActivityLink()
{
	if (!Z_Registration_Info_UScriptStruct_FActivityLink.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FActivityLink.InnerSingleton, Z_Construct_UScriptStruct_FActivityLink_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FActivityLink.InnerSingleton);
}
// ********** End ScriptStruct FActivityLink *******************************************************

// ********** Begin ScriptStruct FActivityState ****************************************************
struct Z_Construct_UScriptStruct_FActivityState_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FActivityState); }
	static inline consteval int16 GetStructAlignment() { return alignof(FActivityState); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateName_MetaData[] = {
		{ "Category", "ActivityState" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateEnterFunction_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateEnterFunctionName_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateLeaveFunction_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateLeaveFunctionName_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateIndex_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LinkArray_MetaData[] = {
		{ "Category", "ActivityState" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStateMachineEntry_MetaData[] = {
		{ "Category", "ActivityState" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SequenceType_MetaData[] = {
		{ "Category", "ActivityState" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TlogStatisticsID_MetaData[] = {
		{ "Category", "ActivityState" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateSequenceName_MetaData[] = {
		{ "Category", "ActivityState" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelSequence_MetaData[] = {
		{ "Category", "ActivityState" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelSequencePath_MetaData[] = {
		{ "AllowedClasses", "/Script/Engine.LevelSequence" },
		{ "Category", "General" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoopCount_MetaData[] = {
		{ "Category", "General" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//-1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd1\xad\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd""0\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd2\xbb\xef\xbf\xbd\xce\xa3\xef\xbf\xbd""1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "DisplayName", "Loop" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "-1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd1\xad\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd""0\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd2\xbb\xef\xbf\xbd\xce\xa3\xef\xbf\xbd""1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
		{ "UIMin", "-1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
		{ "Units", "Multiplier" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShouldPauseAtLastFrame_MetaData[] = {
		{ "Category", "ActivityState" },
		{ "EditCondition", "LoopCount==0" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateSequence_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FActivityState constinit property declarations ********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_StateName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StateEnterFunction;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StateEnterFunctionName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StateLeaveFunction;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StateLeaveFunctionName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StateIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LinkArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LinkArray;
	static void NewProp_bStateMachineEntry_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStateMachineEntry;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SequenceType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SequenceType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TlogStatisticsID;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StateSequenceName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LevelSequence;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LevelSequencePath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LoopCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
	static void NewProp_ShouldPauseAtLastFrame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ShouldPauseAtLastFrame;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StateSequence;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FActivityState constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActivityState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FActivityState_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FActivityState;
class UScriptStruct* FActivityState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FActivityState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FActivityState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActivityState, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("ActivityState"));
	}
	return Z_Registration_Info_UScriptStruct_FActivityState.OuterSingleton;
	}

// ********** Begin ScriptStruct FActivityState Property Definitions *******************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateName = { "StateName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, StateName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateName_MetaData), NewProp_StateName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateEnterFunction = { "StateEnterFunction", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, StateEnterFunction), Z_Construct_UClass_UFunction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateEnterFunction_MetaData), NewProp_StateEnterFunction_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateEnterFunctionName = { "StateEnterFunctionName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, StateEnterFunctionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateEnterFunctionName_MetaData), NewProp_StateEnterFunctionName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateLeaveFunction = { "StateLeaveFunction", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, StateLeaveFunction), Z_Construct_UClass_UFunction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateLeaveFunction_MetaData), NewProp_StateLeaveFunction_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateLeaveFunctionName = { "StateLeaveFunctionName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, StateLeaveFunctionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateLeaveFunctionName_MetaData), NewProp_StateLeaveFunctionName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateIndex = { "StateIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, StateIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateIndex_MetaData), NewProp_StateIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LinkArray_Inner = { "LinkArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FActivityLink, METADATA_PARAMS(0, nullptr) }; // 4172990053
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LinkArray = { "LinkArray", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, LinkArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LinkArray_MetaData), NewProp_LinkArray_MetaData) }; // 4172990053
void Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_bStateMachineEntry_SetBit(void* Obj)
{
	((FActivityState*)Obj)->bStateMachineEntry = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_bStateMachineEntry = { "bStateMachineEntry", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FActivityState), &Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_bStateMachineEntry_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStateMachineEntry_MetaData), NewProp_bStateMachineEntry_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_SequenceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_SequenceType = { "SequenceType", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, SequenceType), Z_Construct_UEnum_MyProject_ESequenceBindingType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SequenceType_MetaData), NewProp_SequenceType_MetaData) }; // 1135200017
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_TlogStatisticsID = { "TlogStatisticsID", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, TlogStatisticsID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TlogStatisticsID_MetaData), NewProp_TlogStatisticsID_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateSequenceName = { "StateSequenceName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, StateSequenceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateSequenceName_MetaData), NewProp_StateSequenceName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LevelSequence = { "LevelSequence", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, LevelSequence), Z_Construct_UClass_ULevelSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelSequence_MetaData), NewProp_LevelSequence_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LevelSequencePath = { "LevelSequencePath", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, LevelSequencePath), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelSequencePath_MetaData), NewProp_LevelSequencePath_MetaData) }; // 2425717601
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LoopCount = { "LoopCount", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, LoopCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoopCount_MetaData), NewProp_LoopCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, PlayRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_MetaData), NewProp_PlayRate_MetaData) };
void Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_ShouldPauseAtLastFrame_SetBit(void* Obj)
{
	((FActivityState*)Obj)->ShouldPauseAtLastFrame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_ShouldPauseAtLastFrame = { "ShouldPauseAtLastFrame", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FActivityState), &Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_ShouldPauseAtLastFrame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShouldPauseAtLastFrame_MetaData), NewProp_ShouldPauseAtLastFrame_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateSequence = { "StateSequence", nullptr, (EPropertyFlags)0x0010000000082008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityState, StateSequence), Z_Construct_UClass_UActorSequenceComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateSequence_MetaData), NewProp_StateSequence_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActivityState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateEnterFunction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateEnterFunctionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateLeaveFunction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateLeaveFunctionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LinkArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LinkArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_bStateMachineEntry,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_SequenceType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_SequenceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_TlogStatisticsID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateSequenceName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LevelSequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LevelSequencePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_LoopCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_PlayRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_ShouldPauseAtLastFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityState_Statics::NewProp_StateSequence,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActivityState_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FActivityState Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActivityState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"ActivityState",
	Z_Construct_UScriptStruct_FActivityState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActivityState_Statics::PropPointers),
	sizeof(FActivityState),
	alignof(FActivityState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActivityState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FActivityState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FActivityState()
{
	if (!Z_Registration_Info_UScriptStruct_FActivityState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FActivityState.InnerSingleton, Z_Construct_UScriptStruct_FActivityState_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FActivityState.InnerSingleton);
}
// ********** End ScriptStruct FActivityState ******************************************************

// ********** Begin ScriptStruct FActivityStateRep *************************************************
struct Z_Construct_UScriptStruct_FActivityStateRep_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FActivityStateRep); }
	static inline consteval int16 GetStructAlignment() { return alignof(FActivityStateRep); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateIndex_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnterTime_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xd2\xbb\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd2\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xb5\xef\xbf\xbd\xef\xbf\xbd\xd2\xbb\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd<0.5 (gamestate\xef\xbf\xbd\xef\xbf\xbd\xd2\xbb\xef\xbf\xbd\xce\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1),\xef\xbf\xbd\xef\xbf\xbd""entertime\xce\xaasequence\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd7\xaa\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xd2\xbb\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd2\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xb5\xef\xbf\xbd\xef\xbf\xbd\xd2\xbb\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd<0.5 (gamestate\xef\xbf\xbd\xef\xbf\xbd\xd2\xbb\xef\xbf\xbd\xce\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1),\xef\xbf\xbd\xef\xbf\xbd""entertime\xce\xaasequence\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd7\xaa\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServeEnterSequenceTime_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPause_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PredictID_MetaData[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FActivityStateRep constinit property declarations *****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_StateIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnterTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ServeEnterSequenceTime;
	static void NewProp_bPause_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPause;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PredictID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FActivityStateRep constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActivityStateRep>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FActivityStateRep_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FActivityStateRep;
class UScriptStruct* FActivityStateRep::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FActivityStateRep.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FActivityStateRep.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActivityStateRep, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("ActivityStateRep"));
	}
	return Z_Registration_Info_UScriptStruct_FActivityStateRep.OuterSingleton;
	}

// ********** Begin ScriptStruct FActivityStateRep Property Definitions ****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_StateIndex = { "StateIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityStateRep, StateIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateIndex_MetaData), NewProp_StateIndex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_EnterTime = { "EnterTime", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityStateRep, EnterTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnterTime_MetaData), NewProp_EnterTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_ServeEnterSequenceTime = { "ServeEnterSequenceTime", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityStateRep, ServeEnterSequenceTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServeEnterSequenceTime_MetaData), NewProp_ServeEnterSequenceTime_MetaData) };
void Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_bPause_SetBit(void* Obj)
{
	((FActivityStateRep*)Obj)->bPause = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_bPause = { "bPause", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FActivityStateRep), &Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_bPause_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPause_MetaData), NewProp_bPause_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_PredictID = { "PredictID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActivityStateRep, PredictID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PredictID_MetaData), NewProp_PredictID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActivityStateRep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_StateIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_EnterTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_ServeEnterSequenceTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_bPause,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewProp_PredictID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActivityStateRep_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FActivityStateRep Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActivityStateRep_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"ActivityStateRep",
	Z_Construct_UScriptStruct_FActivityStateRep_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActivityStateRep_Statics::PropPointers),
	sizeof(FActivityStateRep),
	alignof(FActivityStateRep),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActivityStateRep_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FActivityStateRep_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FActivityStateRep()
{
	if (!Z_Registration_Info_UScriptStruct_FActivityStateRep.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FActivityStateRep.InnerSingleton, Z_Construct_UScriptStruct_FActivityStateRep_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FActivityStateRep.InnerSingleton);
}
// ********** End ScriptStruct FActivityStateRep ***************************************************

// ********** Begin Interface UActivityStateInterface **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UActivityStateInterface;
UClass* UActivityStateInterface::GetPrivateStaticClass()
{
	using TClass = UActivityStateInterface;
	if (!Z_Registration_Info_UClass_UActivityStateInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ActivityStateInterface"),
			Z_Registration_Info_UClass_UActivityStateInterface.InnerSingleton,
			StaticRegisterNativesUActivityStateInterface,
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
	return Z_Registration_Info_UClass_UActivityStateInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UActivityStateInterface_NoRegister()
{
	return UActivityStateInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UActivityStateInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "ActivityStateInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UActivityStateInterface constinit property declarations **************
// ********** End Interface UActivityStateInterface constinit property declarations ****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IActivityStateInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UActivityStateInterface_Statics
UObject* (*const Z_Construct_UClass_UActivityStateInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UActivityStateInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UActivityStateInterface_Statics::ClassParams = {
	&UActivityStateInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UActivityStateInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UActivityStateInterface_Statics::Class_MetaDataParams)
};
void UActivityStateInterface::StaticRegisterNativesUActivityStateInterface()
{
}
UClass* Z_Construct_UClass_UActivityStateInterface()
{
	if (!Z_Registration_Info_UClass_UActivityStateInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UActivityStateInterface.OuterSingleton, Z_Construct_UClass_UActivityStateInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UActivityStateInterface.OuterSingleton;
}
UActivityStateInterface::UActivityStateInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UActivityStateInterface);
// ********** End Interface UActivityStateInterface ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h__Script_MyProject_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESequenceBindingType_StaticEnum, TEXT("ESequenceBindingType"), &Z_Registration_Info_UEnum_ESequenceBindingType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1135200017U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FActivityLink::StaticStruct, Z_Construct_UScriptStruct_FActivityLink_Statics::NewStructOps, TEXT("ActivityLink"),&Z_Registration_Info_UScriptStruct_FActivityLink, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActivityLink), 4172990053U) },
		{ FActivityState::StaticStruct, Z_Construct_UScriptStruct_FActivityState_Statics::NewStructOps, TEXT("ActivityState"),&Z_Registration_Info_UScriptStruct_FActivityState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActivityState), 4017843703U) },
		{ FActivityStateRep::StaticStruct, Z_Construct_UScriptStruct_FActivityStateRep_Statics::NewStructOps, TEXT("ActivityStateRep"),&Z_Registration_Info_UScriptStruct_FActivityStateRep, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActivityStateRep), 4003429430U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UActivityStateInterface, UActivityStateInterface::StaticClass, TEXT("UActivityStateInterface"), &Z_Registration_Info_UClass_UActivityStateInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UActivityStateInterface), 209411951U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h__Script_MyProject_3526785033{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h__Script_MyProject_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h__Script_MyProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h__Script_MyProject_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h__Script_MyProject_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_ActivityStateInterface_h__Script_MyProject_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
