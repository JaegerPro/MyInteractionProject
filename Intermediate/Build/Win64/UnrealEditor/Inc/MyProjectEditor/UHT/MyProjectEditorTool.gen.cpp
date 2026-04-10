// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProjectEditor/Tools/MyProjectEditorTool.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMyProjectEditorTool() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
MYPROJECTEDITOR_API UClass* Z_Construct_UClass_UMyProjectEditorTool();
MYPROJECTEDITOR_API UClass* Z_Construct_UClass_UMyProjectEditorTool_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProjectEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UMyProjectEditorTool Function AddTagToSelectedActors *********************
struct Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics
{
	struct MyProjectEditorTool_eventAddTagToSelectedActors_Parms
	{
		FName TagName;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MyProject|Editor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xe4\xb8\xba\xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\xe6\xb7\xbb\xe5\x8a\xa0\xe6\xa0\x87\xe7\xad\xbe\n\x09 * @param TagName \xe6\xa0\x87\xe7\xad\xbe\xe5\x90\x8d\xe7\xa7\xb0\n\x09 * @return \xe6\xb7\xbb\xe5\x8a\xa0\xe6\xa0\x87\xe7\xad\xbe\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Tools/MyProjectEditorTool.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\xba\xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\xe6\xb7\xbb\xe5\x8a\xa0\xe6\xa0\x87\xe7\xad\xbe\n@param TagName \xe6\xa0\x87\xe7\xad\xbe\xe5\x90\x8d\xe7\xa7\xb0\n@return \xe6\xb7\xbb\xe5\x8a\xa0\xe6\xa0\x87\xe7\xad\xbe\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddTagToSelectedActors constinit property declarations ****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_TagName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddTagToSelectedActors constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddTagToSelectedActors Property Definitions ***************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::NewProp_TagName = { "TagName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyProjectEditorTool_eventAddTagToSelectedActors_Parms, TagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagName_MetaData), NewProp_TagName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyProjectEditorTool_eventAddTagToSelectedActors_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::NewProp_TagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::PropPointers) < 2048);
// ********** End Function AddTagToSelectedActors Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMyProjectEditorTool, nullptr, "AddTagToSelectedActors", 	Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::MyProjectEditorTool_eventAddTagToSelectedActors_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::MyProjectEditorTool_eventAddTagToSelectedActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyProjectEditorTool::execAddTagToSelectedActors)
{
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_TagName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UMyProjectEditorTool::AddTagToSelectedActors(Z_Param_Out_TagName);
	P_NATIVE_END;
}
// ********** End Class UMyProjectEditorTool Function AddTagToSelectedActors ***********************

// ********** Begin Class UMyProjectEditorTool Function BatchMoveActors ****************************
struct Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics
{
	struct MyProjectEditorTool_eventBatchMoveActors_Parms
	{
		FVector Offset;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MyProject|Editor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xe6\x89\xb9\xe9\x87\x8f\xe7\xa7\xbb\xe5\x8a\xa8\xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\xe5\x88\xb0\xe6\x8c\x87\xe5\xae\x9a\xe4\xbd\x8d\xe7\xbd\xae\n\x09 * @param Offset \xe4\xbd\x8d\xe7\xbd\xae\xe5\x81\x8f\xe7\xa7\xbb\n\x09 * @return \xe7\xa7\xbb\xe5\x8a\xa8\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Tools/MyProjectEditorTool.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\xb9\xe9\x87\x8f\xe7\xa7\xbb\xe5\x8a\xa8\xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\xe5\x88\xb0\xe6\x8c\x87\xe5\xae\x9a\xe4\xbd\x8d\xe7\xbd\xae\n@param Offset \xe4\xbd\x8d\xe7\xbd\xae\xe5\x81\x8f\xe7\xa7\xbb\n@return \xe7\xa7\xbb\xe5\x8a\xa8\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BatchMoveActors constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Offset;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BatchMoveActors constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BatchMoveActors Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyProjectEditorTool_eventBatchMoveActors_Parms, Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyProjectEditorTool_eventBatchMoveActors_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::PropPointers) < 2048);
// ********** End Function BatchMoveActors Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMyProjectEditorTool, nullptr, "BatchMoveActors", 	Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::MyProjectEditorTool_eventBatchMoveActors_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::MyProjectEditorTool_eventBatchMoveActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyProjectEditorTool::execBatchMoveActors)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Offset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UMyProjectEditorTool::BatchMoveActors(Z_Param_Out_Offset);
	P_NATIVE_END;
}
// ********** End Class UMyProjectEditorTool Function BatchMoveActors ******************************

// ********** Begin Class UMyProjectEditorTool Function BatchRenameActors **************************
struct Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics
{
	struct MyProjectEditorTool_eventBatchRenameActors_Parms
	{
		FString Prefix;
		FString Suffix;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MyProject|Editor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xe6\x89\xb9\xe9\x87\x8f\xe9\x87\x8d\xe5\x91\xbd\xe5\x90\x8d\xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\n\x09 * @param Prefix \xe5\x90\x8d\xe7\xa7\xb0\xe5\x89\x8d\xe7\xbc\x80\n\x09 * @param Suffix \xe5\x90\x8d\xe7\xa7\xb0\xe5\x90\x8e\xe7\xbc\x80\n\x09 * @return \xe9\x87\x8d\xe5\x91\xbd\xe5\x90\x8d\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Tools/MyProjectEditorTool.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\xb9\xe9\x87\x8f\xe9\x87\x8d\xe5\x91\xbd\xe5\x90\x8d\xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\n@param Prefix \xe5\x90\x8d\xe7\xa7\xb0\xe5\x89\x8d\xe7\xbc\x80\n@param Suffix \xe5\x90\x8d\xe7\xa7\xb0\xe5\x90\x8e\xe7\xbc\x80\n@return \xe9\x87\x8d\xe5\x91\xbd\xe5\x90\x8d\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Prefix_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Suffix_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BatchRenameActors constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Prefix;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Suffix;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BatchRenameActors constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BatchRenameActors Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::NewProp_Prefix = { "Prefix", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyProjectEditorTool_eventBatchRenameActors_Parms, Prefix), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Prefix_MetaData), NewProp_Prefix_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::NewProp_Suffix = { "Suffix", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyProjectEditorTool_eventBatchRenameActors_Parms, Suffix), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Suffix_MetaData), NewProp_Suffix_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyProjectEditorTool_eventBatchRenameActors_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::NewProp_Prefix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::NewProp_Suffix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::PropPointers) < 2048);
// ********** End Function BatchRenameActors Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMyProjectEditorTool, nullptr, "BatchRenameActors", 	Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::MyProjectEditorTool_eventBatchRenameActors_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::MyProjectEditorTool_eventBatchRenameActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyProjectEditorTool::execBatchRenameActors)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Prefix);
	P_GET_PROPERTY(FStrProperty,Z_Param_Suffix);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UMyProjectEditorTool::BatchRenameActors(Z_Param_Prefix,Z_Param_Suffix);
	P_NATIVE_END;
}
// ********** End Class UMyProjectEditorTool Function BatchRenameActors ****************************

// ********** Begin Class UMyProjectEditorTool Function GetSelectedActorCount **********************
struct Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics
{
	struct MyProjectEditorTool_eventGetSelectedActorCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MyProject|Editor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xe8\x8e\xb7\xe5\x8f\x96\xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f\n\x09 * @return \xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Tools/MyProjectEditorTool.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f\n@return \xe9\x80\x89\xe4\xb8\xad\xe7\x9a\x84""Actor\xe6\x95\xb0\xe9\x87\x8f" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedActorCount constinit property declarations *****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedActorCount constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedActorCount Property Definitions ****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyProjectEditorTool_eventGetSelectedActorCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::PropPointers) < 2048);
// ********** End Function GetSelectedActorCount Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMyProjectEditorTool, nullptr, "GetSelectedActorCount", 	Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::MyProjectEditorTool_eventGetSelectedActorCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::MyProjectEditorTool_eventGetSelectedActorCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyProjectEditorTool::execGetSelectedActorCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UMyProjectEditorTool::GetSelectedActorCount();
	P_NATIVE_END;
}
// ********** End Class UMyProjectEditorTool Function GetSelectedActorCount ************************

// ********** Begin Class UMyProjectEditorTool *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UMyProjectEditorTool;
UClass* UMyProjectEditorTool::GetPrivateStaticClass()
{
	using TClass = UMyProjectEditorTool;
	if (!Z_Registration_Info_UClass_UMyProjectEditorTool.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MyProjectEditorTool"),
			Z_Registration_Info_UClass_UMyProjectEditorTool.InnerSingleton,
			StaticRegisterNativesUMyProjectEditorTool,
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
	return Z_Registration_Info_UClass_UMyProjectEditorTool.InnerSingleton;
}
UClass* Z_Construct_UClass_UMyProjectEditorTool_NoRegister()
{
	return UMyProjectEditorTool::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UMyProjectEditorTool_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe7\xb1\xbb\n * \xe6\x8f\x90\xe4\xbe\x9b\xe5\xb8\xb8\xe7\x94\xa8\xe7\x9a\x84\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe8\xbe\x85\xe5\x8a\xa9\xe5\x8a\x9f\xe8\x83\xbd\n */" },
#endif
		{ "IncludePath", "Tools/MyProjectEditorTool.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Tools/MyProjectEditorTool.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe7\xb1\xbb\n\xe6\x8f\x90\xe4\xbe\x9b\xe5\xb8\xb8\xe7\x94\xa8\xe7\x9a\x84\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe8\xbe\x85\xe5\x8a\xa9\xe5\x8a\x9f\xe8\x83\xbd" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UMyProjectEditorTool constinit property declarations *********************
// ********** End Class UMyProjectEditorTool constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddTagToSelectedActors"), .Pointer = &UMyProjectEditorTool::execAddTagToSelectedActors },
		{ .NameUTF8 = UTF8TEXT("BatchMoveActors"), .Pointer = &UMyProjectEditorTool::execBatchMoveActors },
		{ .NameUTF8 = UTF8TEXT("BatchRenameActors"), .Pointer = &UMyProjectEditorTool::execBatchRenameActors },
		{ .NameUTF8 = UTF8TEXT("GetSelectedActorCount"), .Pointer = &UMyProjectEditorTool::execGetSelectedActorCount },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyProjectEditorTool_AddTagToSelectedActors, "AddTagToSelectedActors" }, // 3764455689
		{ &Z_Construct_UFunction_UMyProjectEditorTool_BatchMoveActors, "BatchMoveActors" }, // 1338762465
		{ &Z_Construct_UFunction_UMyProjectEditorTool_BatchRenameActors, "BatchRenameActors" }, // 3728155069
		{ &Z_Construct_UFunction_UMyProjectEditorTool_GetSelectedActorCount, "GetSelectedActorCount" }, // 2182618191
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyProjectEditorTool>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UMyProjectEditorTool_Statics
UObject* (*const Z_Construct_UClass_UMyProjectEditorTool_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProjectEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyProjectEditorTool_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyProjectEditorTool_Statics::ClassParams = {
	&UMyProjectEditorTool::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyProjectEditorTool_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyProjectEditorTool_Statics::Class_MetaDataParams)
};
void UMyProjectEditorTool::StaticRegisterNativesUMyProjectEditorTool()
{
	UClass* Class = UMyProjectEditorTool::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UMyProjectEditorTool_Statics::Funcs));
}
UClass* Z_Construct_UClass_UMyProjectEditorTool()
{
	if (!Z_Registration_Info_UClass_UMyProjectEditorTool.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyProjectEditorTool.OuterSingleton, Z_Construct_UClass_UMyProjectEditorTool_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyProjectEditorTool.OuterSingleton;
}
UMyProjectEditorTool::UMyProjectEditorTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMyProjectEditorTool);
UMyProjectEditorTool::~UMyProjectEditorTool() {}
// ********** End Class UMyProjectEditorTool *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h__Script_MyProjectEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyProjectEditorTool, UMyProjectEditorTool::StaticClass, TEXT("UMyProjectEditorTool"), &Z_Registration_Info_UClass_UMyProjectEditorTool, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyProjectEditorTool), 594964880U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h__Script_MyProjectEditor_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h__Script_MyProjectEditor_1900366269{
	TEXT("/Script/MyProjectEditor"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h__Script_MyProjectEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProjectEditor_Tools_MyProjectEditorTool_h__Script_MyProjectEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
