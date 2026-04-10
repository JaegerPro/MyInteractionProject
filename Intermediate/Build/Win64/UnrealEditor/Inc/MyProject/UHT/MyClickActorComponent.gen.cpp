// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/MyClickActorComponent.h"
#include "Engine/HitResult.h"
#include "MyProject/CustomActor/CustomTypeDefine.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeMyClickActorComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UFunction_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UShapeComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
MYPROJECT_API UClass* Z_Construct_UClass_UClickActorPCInterface();
MYPROJECT_API UClass* Z_Construct_UClass_UClickActorPCInterface_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UClickButtonWidget();
MYPROJECT_API UClass* Z_Construct_UClass_UClickButtonWidget_NoRegister();
MYPROJECT_API UClass* Z_Construct_UClass_UMyClickActorComponent();
MYPROJECT_API UClass* Z_Construct_UClass_UMyClickActorComponent_NoRegister();
MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClick_CheckFunctionName();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClick_ExecuteFunctionName();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClick_Param();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClick_PassInfo();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClick_ValidInfo();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClick_ValidInfo_Rep();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClickInfo();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClickUIInfo();
MYPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FShapeComponentSelector();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FClick_PassInfo ***************************************************
struct Z_Construct_UScriptStruct_FClick_PassInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClick_PassInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClick_PassInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PassID_MetaData[] = {
		{ "Category", "Click_PassInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeginTimeStamp_MetaData[] = {
		{ "Category", "Click_PassInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndTimeStamp_MetaData[] = {
		{ "Category", "Click_PassInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClick_PassInfo constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_PassID;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BeginTimeStamp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EndTimeStamp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClick_PassInfo constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClick_PassInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClick_PassInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClick_PassInfo;
class UScriptStruct* FClick_PassInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_PassInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClick_PassInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClick_PassInfo, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("Click_PassInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FClick_PassInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FClick_PassInfo Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClick_PassInfo_Statics::NewProp_PassID = { "PassID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_PassInfo, PassID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PassID_MetaData), NewProp_PassID_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FClick_PassInfo_Statics::NewProp_BeginTimeStamp = { "BeginTimeStamp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_PassInfo, BeginTimeStamp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeginTimeStamp_MetaData), NewProp_BeginTimeStamp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FClick_PassInfo_Statics::NewProp_EndTimeStamp = { "EndTimeStamp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_PassInfo, EndTimeStamp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndTimeStamp_MetaData), NewProp_EndTimeStamp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClick_PassInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_PassInfo_Statics::NewProp_PassID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_PassInfo_Statics::NewProp_BeginTimeStamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_PassInfo_Statics::NewProp_EndTimeStamp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_PassInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClick_PassInfo Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClick_PassInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"Click_PassInfo",
	Z_Construct_UScriptStruct_FClick_PassInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_PassInfo_Statics::PropPointers),
	sizeof(FClick_PassInfo),
	alignof(FClick_PassInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_PassInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClick_PassInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClick_PassInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_PassInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClick_PassInfo.InnerSingleton, Z_Construct_UScriptStruct_FClick_PassInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClick_PassInfo.InnerSingleton);
}
// ********** End ScriptStruct FClick_PassInfo *****************************************************

// ********** Begin ScriptStruct FClick_ValidInfo **************************************************
struct Z_Construct_UScriptStruct_FClick_ValidInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClick_ValidInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClick_ValidInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PC_MetaData[] = {
		{ "Category", "Click_ValidInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PassInfo_MetaData[] = {
		{ "Category", "Click_ValidInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClick_ValidInfo constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PC;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PassInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClick_ValidInfo constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClick_ValidInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClick_ValidInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClick_ValidInfo;
class UScriptStruct* FClick_ValidInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_ValidInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClick_ValidInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClick_ValidInfo, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("Click_ValidInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FClick_ValidInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FClick_ValidInfo Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::NewProp_PC = { "PC", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_ValidInfo, PC), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PC_MetaData), NewProp_PC_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::NewProp_PassInfo = { "PassInfo", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_ValidInfo, PassInfo), Z_Construct_UScriptStruct_FClick_PassInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PassInfo_MetaData), NewProp_PassInfo_MetaData) }; // 1396582729
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::NewProp_PC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::NewProp_PassInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClick_ValidInfo Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"Click_ValidInfo",
	Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::PropPointers),
	sizeof(FClick_ValidInfo),
	alignof(FClick_ValidInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClick_ValidInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_ValidInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClick_ValidInfo.InnerSingleton, Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClick_ValidInfo.InnerSingleton);
}
// ********** End ScriptStruct FClick_ValidInfo ****************************************************

// ********** Begin ScriptStruct FClickUIInfo ******************************************************
struct Z_Construct_UScriptStruct_FClickUIInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClickUIInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClickUIInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ButtonName_MetaData[] = {
		{ "Category", "ClickUIInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xc7\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xa1\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc7\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xa1\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ButtonUI_MetaData[] = {
		{ "Category", "ClickUIInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MountWidgetName_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClientCD_MetaData[] = {
		{ "Category", "ClickUIInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressureTime_MetaData[] = {
		{ "Category", "ClickUIInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd\xd2\xaa\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xd2\xaa\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OuterClass_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoSize_MetaData[] = {
		{ "Category", "Layout|Canvas Slot" },
		{ "DisplayName", "Size To Content" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZOrder_MetaData[] = {
		{ "Category", "Layout|Canvas Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The order priority this widget is rendered in.  Higher values are rendered last (and so they will appear to be on top). */" },
#endif
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The order priority this widget is rendered in.  Higher values are rendered last (and so they will appear to be on top)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SortOrder_MetaData[] = {
		{ "Category", "Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The order priority this widget is rendered in.  Higher values are rendered last (and so they will appear to be on top). */" },
#endif
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The order priority this widget is rendered in.  Higher values are rendered last (and so they will appear to be on top)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ButtonClass_MetaData[] = {
		{ "Category", "ClickUIInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc4\xac\xef\xbf\xbd\xef\xbf\xbd""class\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xce\xaa\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd8\xb5\xef\xbf\xbd""class\n" },
#endif
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc4\xac\xef\xbf\xbd\xef\xbf\xbd""class\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xce\xaa\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd8\xb5\xef\xbf\xbd""class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtraMessage_MetaData[] = {
		{ "Category", "ClickUIInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderOpacity_MetaData[] = {
		{ "Category", "ClickUIInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlobalCDEndTimeStamp_MetaData[] = {
		{ "Category", "ClickUIInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xc8\xab\xef\xbf\xbd\xef\xbf\xbd""CD\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xc8\xab\xef\xbf\xbd\xef\xbf\xbd""CD\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlobalCDBeginTimeStamp_MetaData[] = {
		{ "Category", "ClickUIInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BisPostEventAtPlayerLocation_MetaData[] = {
		{ "Category", "ClickUIInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xc4\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc5\xa5\xef\xbf\xbd\xef\xbf\xbd\xd0\xa7\xef\xbf\xbd\xef\xbf\xbd 0,0,0 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb9\xef\xbf\xbd\xef\xbf\xbd""AKRoom \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc2\xbf\xef\xbf\xbd\xef\xbf\xbd\xdc\xbb\xe1\xb5\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xc4\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc5\xa5\xef\xbf\xbd\xef\xbf\xbd\xd0\xa7\xef\xbf\xbd\xef\xbf\xbd 0,0,0 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb9\xef\xbf\xbd\xef\xbf\xbd""AKRoom \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc2\xbf\xef\xbf\xbd\xef\xbf\xbd\xdc\xbb\xe1\xb5\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClickUIInfo constinit property declarations **********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ButtonName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ButtonUI;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MountWidgetName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ClientCD;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PressureTime;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_OuterClass;
	static void NewProp_bAutoSize_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ZOrder;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SortOrder;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ButtonClass;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ExtraMessage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RenderOpacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlobalCDEndTimeStamp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlobalCDBeginTimeStamp;
	static void NewProp_BisPostEventAtPlayerLocation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_BisPostEventAtPlayerLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClickUIInfo constinit property declarations ************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClickUIInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClickUIInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClickUIInfo;
class UScriptStruct* FClickUIInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClickUIInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClickUIInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClickUIInfo, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("ClickUIInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FClickUIInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FClickUIInfo Property Definitions *********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ButtonName = { "ButtonName", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, ButtonName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ButtonName_MetaData), NewProp_ButtonName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ButtonUI = { "ButtonUI", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, ButtonUI), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ButtonUI_MetaData), NewProp_ButtonUI_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_MountWidgetName = { "MountWidgetName", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, MountWidgetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MountWidgetName_MetaData), NewProp_MountWidgetName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ClientCD = { "ClientCD", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, ClientCD), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClientCD_MetaData), NewProp_ClientCD_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_PressureTime = { "PressureTime", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, PressureTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressureTime_MetaData), NewProp_PressureTime_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_OuterClass = { "OuterClass", nullptr, (EPropertyFlags)0x0014040000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, OuterClass), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OuterClass_MetaData), NewProp_OuterClass_MetaData) };
void Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_bAutoSize_SetBit(void* Obj)
{
	((FClickUIInfo*)Obj)->bAutoSize = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_bAutoSize = { "bAutoSize", nullptr, (EPropertyFlags)0x0010040000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FClickUIInfo), &Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_bAutoSize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoSize_MetaData), NewProp_bAutoSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ZOrder = { "ZOrder", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, ZOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZOrder_MetaData), NewProp_ZOrder_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_SortOrder = { "SortOrder", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, SortOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SortOrder_MetaData), NewProp_SortOrder_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ButtonClass = { "ButtonClass", nullptr, (EPropertyFlags)0x0014000000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, ButtonClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UClickButtonWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ButtonClass_MetaData), NewProp_ButtonClass_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ExtraMessage = { "ExtraMessage", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, ExtraMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtraMessage_MetaData), NewProp_ExtraMessage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_RenderOpacity = { "RenderOpacity", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, RenderOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderOpacity_MetaData), NewProp_RenderOpacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_GlobalCDEndTimeStamp = { "GlobalCDEndTimeStamp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, GlobalCDEndTimeStamp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlobalCDEndTimeStamp_MetaData), NewProp_GlobalCDEndTimeStamp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_GlobalCDBeginTimeStamp = { "GlobalCDBeginTimeStamp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickUIInfo, GlobalCDBeginTimeStamp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlobalCDBeginTimeStamp_MetaData), NewProp_GlobalCDBeginTimeStamp_MetaData) };
void Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_BisPostEventAtPlayerLocation_SetBit(void* Obj)
{
	((FClickUIInfo*)Obj)->BisPostEventAtPlayerLocation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_BisPostEventAtPlayerLocation = { "BisPostEventAtPlayerLocation", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FClickUIInfo), &Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_BisPostEventAtPlayerLocation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BisPostEventAtPlayerLocation_MetaData), NewProp_BisPostEventAtPlayerLocation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClickUIInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ButtonName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ButtonUI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_MountWidgetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ClientCD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_PressureTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_OuterClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_bAutoSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ZOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_SortOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ButtonClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_ExtraMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_RenderOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_GlobalCDEndTimeStamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_GlobalCDBeginTimeStamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewProp_BisPostEventAtPlayerLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClickUIInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClickUIInfo Property Definitions ***********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClickUIInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"ClickUIInfo",
	Z_Construct_UScriptStruct_FClickUIInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClickUIInfo_Statics::PropPointers),
	sizeof(FClickUIInfo),
	alignof(FClickUIInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClickUIInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClickUIInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClickUIInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FClickUIInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClickUIInfo.InnerSingleton, Z_Construct_UScriptStruct_FClickUIInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClickUIInfo.InnerSingleton);
}
// ********** End ScriptStruct FClickUIInfo ********************************************************

// ********** Begin ScriptStruct FClick_Param ******************************************************
struct Z_Construct_UScriptStruct_FClick_Param_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClick_Param); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClick_Param); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerController_MetaData[] = {
		{ "Category", "Click_Param" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "Click_Param" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClick_Param constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClick_Param constinit property declarations ************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClick_Param>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClick_Param_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClick_Param;
class UScriptStruct* FClick_Param::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_Param.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClick_Param.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClick_Param, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("Click_Param"));
	}
	return Z_Registration_Info_UScriptStruct_FClick_Param.OuterSingleton;
	}

// ********** Begin ScriptStruct FClick_Param Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FClick_Param_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_Param, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerController_MetaData), NewProp_PlayerController_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FClick_Param_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_Param, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClick_Param_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_Param_Statics::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_Param_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_Param_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClick_Param Property Definitions ***********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClick_Param_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"Click_Param",
	Z_Construct_UScriptStruct_FClick_Param_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_Param_Statics::PropPointers),
	sizeof(FClick_Param),
	alignof(FClick_Param),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_Param_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClick_Param_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClick_Param()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_Param.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClick_Param.InnerSingleton, Z_Construct_UScriptStruct_FClick_Param_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClick_Param.InnerSingleton);
}
// ********** End ScriptStruct FClick_Param ********************************************************

// ********** Begin ScriptStruct FClick_CheckFunctionName ******************************************
struct Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClick_CheckFunctionName); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClick_CheckFunctionName); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomFunctionName_MetaData[] = {
		{ "Category", "Click_CheckFunctionName" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Function_MetaData[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClick_CheckFunctionName constinit property declarations **********
	static const UECodeGen_Private::FNamePropertyParams NewProp_CustomFunctionName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Function;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClick_CheckFunctionName constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClick_CheckFunctionName>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClick_CheckFunctionName;
class UScriptStruct* FClick_CheckFunctionName::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_CheckFunctionName.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClick_CheckFunctionName.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClick_CheckFunctionName, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("Click_CheckFunctionName"));
	}
	return Z_Registration_Info_UScriptStruct_FClick_CheckFunctionName.OuterSingleton;
	}

// ********** Begin ScriptStruct FClick_CheckFunctionName Property Definitions *********************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::NewProp_CustomFunctionName = { "CustomFunctionName", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_CheckFunctionName, CustomFunctionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomFunctionName_MetaData), NewProp_CustomFunctionName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::NewProp_Function = { "Function", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_CheckFunctionName, Function), Z_Construct_UClass_UFunction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Function_MetaData), NewProp_Function_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::NewProp_CustomFunctionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::NewProp_Function,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClick_CheckFunctionName Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"Click_CheckFunctionName",
	Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::PropPointers),
	sizeof(FClick_CheckFunctionName),
	alignof(FClick_CheckFunctionName),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClick_CheckFunctionName()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_CheckFunctionName.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClick_CheckFunctionName.InnerSingleton, Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClick_CheckFunctionName.InnerSingleton);
}
// ********** End ScriptStruct FClick_CheckFunctionName ********************************************

// ********** Begin ScriptStruct FClick_ExecuteFunctionName ****************************************
struct Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClick_ExecuteFunctionName); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClick_ExecuteFunctionName); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomFunctionName_MetaData[] = {
		{ "Category", "Click_ExecuteFunctionName" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocalFunction_MetaData[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClick_ExecuteFunctionName constinit property declarations ********
	static const UECodeGen_Private::FNamePropertyParams NewProp_CustomFunctionName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LocalFunction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClick_ExecuteFunctionName constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClick_ExecuteFunctionName>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClick_ExecuteFunctionName;
class UScriptStruct* FClick_ExecuteFunctionName::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_ExecuteFunctionName.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClick_ExecuteFunctionName.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClick_ExecuteFunctionName, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("Click_ExecuteFunctionName"));
	}
	return Z_Registration_Info_UScriptStruct_FClick_ExecuteFunctionName.OuterSingleton;
	}

// ********** Begin ScriptStruct FClick_ExecuteFunctionName Property Definitions *******************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::NewProp_CustomFunctionName = { "CustomFunctionName", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_ExecuteFunctionName, CustomFunctionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomFunctionName_MetaData), NewProp_CustomFunctionName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::NewProp_LocalFunction = { "LocalFunction", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_ExecuteFunctionName, LocalFunction), Z_Construct_UClass_UFunction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocalFunction_MetaData), NewProp_LocalFunction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::NewProp_CustomFunctionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::NewProp_LocalFunction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClick_ExecuteFunctionName Property Definitions *********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"Click_ExecuteFunctionName",
	Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::PropPointers),
	sizeof(FClick_ExecuteFunctionName),
	alignof(FClick_ExecuteFunctionName),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClick_ExecuteFunctionName()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_ExecuteFunctionName.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClick_ExecuteFunctionName.InnerSingleton, Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClick_ExecuteFunctionName.InnerSingleton);
}
// ********** End ScriptStruct FClick_ExecuteFunctionName ******************************************

// ********** Begin ScriptStruct FClickInfo ********************************************************
struct Z_Construct_UScriptStruct_FClickInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClickInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClickInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CheckFunction_MetaData[] = {
		{ "Category", "ClickInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExcuteFunction_MetaData[] = {
		{ "Category", "ClickInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIInfo_MetaData[] = {
		{ "Category", "ClickInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xc7\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xa1\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc7\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc8\xa1\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtraMessage_MetaData[] = {
		{ "Category", "ClickInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlobalCD_MetaData[] = {
		{ "Category", "ClickInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[] = {
		{ "Category", "ClickInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TlogID_MetaData[] = {
		{ "Category", "ClickInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAddDynamically_MetaData[] = {
		{ "Category", "ClickInfo" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClickInfo constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_CheckFunction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExcuteFunction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UIInfo;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ExtraMessage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlobalCD;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TlogID;
	static void NewProp_bAddDynamically_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAddDynamically;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClickInfo constinit property declarations **************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClickInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClickInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClickInfo;
class UScriptStruct* FClickInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClickInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClickInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClickInfo, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("ClickInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FClickInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FClickInfo Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_CheckFunction = { "CheckFunction", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickInfo, CheckFunction), Z_Construct_UScriptStruct_FClick_CheckFunctionName, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CheckFunction_MetaData), NewProp_CheckFunction_MetaData) }; // 376245754
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_ExcuteFunction = { "ExcuteFunction", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickInfo, ExcuteFunction), Z_Construct_UScriptStruct_FClick_ExecuteFunctionName, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExcuteFunction_MetaData), NewProp_ExcuteFunction_MetaData) }; // 4244669964
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_UIInfo = { "UIInfo", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickInfo, UIInfo), Z_Construct_UScriptStruct_FClickUIInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIInfo_MetaData), NewProp_UIInfo_MetaData) }; // 3142199531
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_ExtraMessage = { "ExtraMessage", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickInfo, ExtraMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtraMessage_MetaData), NewProp_ExtraMessage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_GlobalCD = { "GlobalCD", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickInfo, GlobalCD), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlobalCD_MetaData), NewProp_GlobalCD_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickInfo, ID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ID_MetaData), NewProp_ID_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_TlogID = { "TlogID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClickInfo, TlogID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TlogID_MetaData), NewProp_TlogID_MetaData) };
void Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_bAddDynamically_SetBit(void* Obj)
{
	((FClickInfo*)Obj)->bAddDynamically = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_bAddDynamically = { "bAddDynamically", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FClickInfo), &Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_bAddDynamically_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAddDynamically_MetaData), NewProp_bAddDynamically_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClickInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_CheckFunction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_ExcuteFunction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_UIInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_ExtraMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_GlobalCD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_ID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_TlogID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClickInfo_Statics::NewProp_bAddDynamically,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClickInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClickInfo Property Definitions *************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClickInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"ClickInfo",
	Z_Construct_UScriptStruct_FClickInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClickInfo_Statics::PropPointers),
	sizeof(FClickInfo),
	alignof(FClickInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClickInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClickInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClickInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FClickInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClickInfo.InnerSingleton, Z_Construct_UScriptStruct_FClickInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClickInfo.InnerSingleton);
}
// ********** End ScriptStruct FClickInfo **********************************************************

// ********** Begin ScriptStruct FClick_ValidInfo_Rep **********************************************
struct Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClick_ValidInfo_Rep); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClick_ValidInfo_Rep); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwingActor_MetaData[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Component_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PassInfo_MetaData[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClick_ValidInfo_Rep constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwingActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Component;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PassInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PassInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClick_ValidInfo_Rep constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClick_ValidInfo_Rep>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClick_ValidInfo_Rep;
class UScriptStruct* FClick_ValidInfo_Rep::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_ValidInfo_Rep.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClick_ValidInfo_Rep.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClick_ValidInfo_Rep, (UObject*)Z_Construct_UPackage__Script_MyProject(), TEXT("Click_ValidInfo_Rep"));
	}
	return Z_Registration_Info_UScriptStruct_FClick_ValidInfo_Rep.OuterSingleton;
	}

// ********** Begin ScriptStruct FClick_ValidInfo_Rep Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::NewProp_OwingActor = { "OwingActor", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_ValidInfo_Rep, OwingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwingActor_MetaData), NewProp_OwingActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::NewProp_Component = { "Component", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_ValidInfo_Rep, Component), Z_Construct_UClass_UMyClickActorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Component_MetaData), NewProp_Component_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::NewProp_PassInfo_Inner = { "PassInfo", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FClick_PassInfo, METADATA_PARAMS(0, nullptr) }; // 1396582729
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::NewProp_PassInfo = { "PassInfo", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClick_ValidInfo_Rep, PassInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PassInfo_MetaData), NewProp_PassInfo_MetaData) }; // 1396582729
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::NewProp_OwingActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::NewProp_Component,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::NewProp_PassInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::NewProp_PassInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClick_ValidInfo_Rep Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	nullptr,
	&NewStructOps,
	"Click_ValidInfo_Rep",
	Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::PropPointers),
	sizeof(FClick_ValidInfo_Rep),
	alignof(FClick_ValidInfo_Rep),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClick_ValidInfo_Rep()
{
	if (!Z_Registration_Info_UScriptStruct_FClick_ValidInfo_Rep.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClick_ValidInfo_Rep.InnerSingleton, Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClick_ValidInfo_Rep.InnerSingleton);
}
// ********** End ScriptStruct FClick_ValidInfo_Rep ************************************************

// ********** Begin Interface UClickActorPCInterface ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UClickActorPCInterface;
UClass* UClickActorPCInterface::GetPrivateStaticClass()
{
	using TClass = UClickActorPCInterface;
	if (!Z_Registration_Info_UClass_UClickActorPCInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ClickActorPCInterface"),
			Z_Registration_Info_UClass_UClickActorPCInterface.InnerSingleton,
			StaticRegisterNativesUClickActorPCInterface,
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
	return Z_Registration_Info_UClass_UClickActorPCInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UClickActorPCInterface_NoRegister()
{
	return UClickActorPCInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UClickActorPCInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CannotImplementInterfaceInBlueprint", "" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UClickActorPCInterface constinit property declarations ***************
// ********** End Interface UClickActorPCInterface constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IClickActorPCInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UClickActorPCInterface_Statics
UObject* (*const Z_Construct_UClass_UClickActorPCInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClickActorPCInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UClickActorPCInterface_Statics::ClassParams = {
	&UClickActorPCInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClickActorPCInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UClickActorPCInterface_Statics::Class_MetaDataParams)
};
void UClickActorPCInterface::StaticRegisterNativesUClickActorPCInterface()
{
}
UClass* Z_Construct_UClass_UClickActorPCInterface()
{
	if (!Z_Registration_Info_UClass_UClickActorPCInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UClickActorPCInterface.OuterSingleton, Z_Construct_UClass_UClickActorPCInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UClickActorPCInterface.OuterSingleton;
}
UClickActorPCInterface::UClickActorPCInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UClickActorPCInterface);
// ********** End Interface UClickActorPCInterface *************************************************

// ********** Begin Class UMyClickActorComponent Function OnBeginOverlap ***************************
struct Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics
{
	struct MyClickActorComponent_eventOnBeginOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnBeginOverlap constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnBeginOverlap constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnBeginOverlap Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((MyClickActorComponent_eventOnBeginOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MyClickActorComponent_eventOnBeginOverlap_Parms), &Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 222120718
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::PropPointers) < 2048);
// ********** End Function OnBeginOverlap Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMyClickActorComponent, nullptr, "OnBeginOverlap", 	Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::MyClickActorComponent_eventOnBeginOverlap_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::MyClickActorComponent_eventOnBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyClickActorComponent::execOnBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class UMyClickActorComponent Function OnBeginOverlap *****************************

// ********** Begin Class UMyClickActorComponent Function OnButtonClick ****************************
struct Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics
{
	struct MyClickActorComponent_eventOnButtonClick_Parms
	{
		FClick_ValidInfo Info;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnButtonClick constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Info;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnButtonClick constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnButtonClick Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::NewProp_Info = { "Info", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnButtonClick_Parms, Info), Z_Construct_UScriptStruct_FClick_ValidInfo, METADATA_PARAMS(0, nullptr) }; // 478412711
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::NewProp_Info,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::PropPointers) < 2048);
// ********** End Function OnButtonClick Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMyClickActorComponent, nullptr, "OnButtonClick", 	Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::MyClickActorComponent_eventOnButtonClick_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::MyClickActorComponent_eventOnButtonClick_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyClickActorComponent::execOnButtonClick)
{
	P_GET_STRUCT(FClick_ValidInfo,Z_Param_Info);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnButtonClick(Z_Param_Info);
	P_NATIVE_END;
}
// ********** End Class UMyClickActorComponent Function OnButtonClick ******************************

// ********** Begin Class UMyClickActorComponent Function OnEndOverlap *****************************
struct Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics
{
	struct MyClickActorComponent_eventOnEndOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnEndOverlap constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnEndOverlap constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnEndOverlap Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnEndOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnEndOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnEndOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyClickActorComponent_eventOnEndOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::NewProp_OtherBodyIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::PropPointers) < 2048);
// ********** End Function OnEndOverlap Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UMyClickActorComponent, nullptr, "OnEndOverlap", 	Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::MyClickActorComponent_eventOnEndOverlap_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::MyClickActorComponent_eventOnEndOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyClickActorComponent::execOnEndOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnEndOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex);
	P_NATIVE_END;
}
// ********** End Class UMyClickActorComponent Function OnEndOverlap *******************************

// ********** Begin Class UMyClickActorComponent ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UMyClickActorComponent;
UClass* UMyClickActorComponent::GetPrivateStaticClass()
{
	using TClass = UMyClickActorComponent;
	if (!Z_Registration_Info_UClass_UMyClickActorComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("MyClickActorComponent"),
			Z_Registration_Info_UClass_UMyClickActorComponent.InnerSingleton,
			StaticRegisterNativesUMyClickActorComponent,
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
	return Z_Registration_Info_UClass_UMyClickActorComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UMyClickActorComponent_NoRegister()
{
	return UMyClickActorComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UMyClickActorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MyClickActorComponent.h" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VaildPC_MetaData[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocalValidInfo_MetaData[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Widgets_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainWidgetClass_MetaData[] = {
		{ "Category", "MyClickActorComponent" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClickComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClickButtonInfo_MetaData[] = {
		{ "Category", "MyClickActorComponent" },
		{ "InteractionButton", "" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlapCompoentSelector_MetaData[] = {
		{ "Category", "MyClickActorComponent" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UMyClickActorComponent constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VaildPC_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_VaildPC;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LocalValidInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LocalValidInfo;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Widgets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Widgets;
	static const UECodeGen_Private::FClassPropertyParams NewProp_MainWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClickComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClickButtonInfo_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ClickButtonInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OverlapCompoentSelector;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UMyClickActorComponent constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnBeginOverlap"), .Pointer = &UMyClickActorComponent::execOnBeginOverlap },
		{ .NameUTF8 = UTF8TEXT("OnButtonClick"), .Pointer = &UMyClickActorComponent::execOnButtonClick },
		{ .NameUTF8 = UTF8TEXT("OnEndOverlap"), .Pointer = &UMyClickActorComponent::execOnEndOverlap },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyClickActorComponent_OnBeginOverlap, "OnBeginOverlap" }, // 3661325670
		{ &Z_Construct_UFunction_UMyClickActorComponent_OnButtonClick, "OnButtonClick" }, // 3378028367
		{ &Z_Construct_UFunction_UMyClickActorComponent_OnEndOverlap, "OnEndOverlap" }, // 751682437
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyClickActorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UMyClickActorComponent_Statics

// ********** Begin Class UMyClickActorComponent Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_VaildPC_Inner = { "VaildPC", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_VaildPC = { "VaildPC", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyClickActorComponent, VaildPC), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VaildPC_MetaData), NewProp_VaildPC_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_LocalValidInfo_Inner = { "LocalValidInfo", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FClick_ValidInfo, METADATA_PARAMS(0, nullptr) }; // 478412711
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_LocalValidInfo = { "LocalValidInfo", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyClickActorComponent, LocalValidInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocalValidInfo_MetaData), NewProp_LocalValidInfo_MetaData) }; // 478412711
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_Widgets_Inner = { "Widgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClickButtonWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_Widgets = { "Widgets", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyClickActorComponent, Widgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Widgets_MetaData), NewProp_Widgets_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_MainWidgetClass = { "MainWidgetClass", nullptr, (EPropertyFlags)0x0014000000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyClickActorComponent, MainWidgetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainWidgetClass_MetaData), NewProp_MainWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_ClickComponent = { "ClickComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyClickActorComponent, ClickComponent), Z_Construct_UClass_UShapeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClickComponent_MetaData), NewProp_ClickComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_ClickButtonInfo_Inner = { "ClickButtonInfo", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FClickInfo, METADATA_PARAMS(0, nullptr) }; // 3639400269
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_ClickButtonInfo = { "ClickButtonInfo", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyClickActorComponent, ClickButtonInfo), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClickButtonInfo_MetaData), NewProp_ClickButtonInfo_MetaData) }; // 3639400269
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_OverlapCompoentSelector = { "OverlapCompoentSelector", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyClickActorComponent, OverlapCompoentSelector), Z_Construct_UScriptStruct_FShapeComponentSelector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlapCompoentSelector_MetaData), NewProp_OverlapCompoentSelector_MetaData) }; // 2091030609
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyClickActorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_VaildPC_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_VaildPC,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_LocalValidInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_LocalValidInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_Widgets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_Widgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_MainWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_ClickComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_ClickButtonInfo_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_ClickButtonInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyClickActorComponent_Statics::NewProp_OverlapCompoentSelector,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyClickActorComponent_Statics::PropPointers) < 2048);
// ********** End Class UMyClickActorComponent Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UMyClickActorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyClickActorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyClickActorComponent_Statics::ClassParams = {
	&UMyClickActorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMyClickActorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMyClickActorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyClickActorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyClickActorComponent_Statics::Class_MetaDataParams)
};
void UMyClickActorComponent::StaticRegisterNativesUMyClickActorComponent()
{
	UClass* Class = UMyClickActorComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UMyClickActorComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UMyClickActorComponent()
{
	if (!Z_Registration_Info_UClass_UMyClickActorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyClickActorComponent.OuterSingleton, Z_Construct_UClass_UMyClickActorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyClickActorComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UMyClickActorComponent);
UMyClickActorComponent::~UMyClickActorComponent() {}
// ********** End Class UMyClickActorComponent *****************************************************

// ********** Begin Delegate FOnClickButton ********************************************************
struct Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics
{
	struct _Script_MyProject_eventOnClickButton_Parms
	{
		FClick_ValidInfo Info;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnClickButton constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Info;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnClickButton constinit property declarations **************************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnClickButton Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::NewProp_Info = { "Info", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_MyProject_eventOnClickButton_Parms, Info), Z_Construct_UScriptStruct_FClick_ValidInfo, METADATA_PARAMS(0, nullptr) }; // 478412711
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::NewProp_Info,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnClickButton Property Definitions *************************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_MyProject, nullptr, "OnClickButton__DelegateSignature", 	Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::_Script_MyProject_eventOnClickButton_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::_Script_MyProject_eventOnClickButton_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnClickButton_DelegateWrapper(const FMulticastScriptDelegate& OnClickButton, FClick_ValidInfo Info)
{
	struct _Script_MyProject_eventOnClickButton_Parms
	{
		FClick_ValidInfo Info;
	};
	_Script_MyProject_eventOnClickButton_Parms Parms;
	Parms.Info=Info;
	OnClickButton.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnClickButton **********************************************************

// ********** Begin Class UClickButtonWidget Function GetOwner *************************************
struct Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics
{
	struct ClickButtonWidget_eventGetOwner_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetOwner constinit property declarations ******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOwner constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOwner Property Definitions *****************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ClickButtonWidget_eventGetOwner_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::PropPointers) < 2048);
// ********** End Function GetOwner Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UClickButtonWidget, nullptr, "GetOwner", 	Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::ClickButtonWidget_eventGetOwner_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::Function_MetaDataParams), Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::ClickButtonWidget_eventGetOwner_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UClickButtonWidget_GetOwner()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UClickButtonWidget_GetOwner_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UClickButtonWidget::execGetOwner)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetOwner();
	P_NATIVE_END;
}
// ********** End Class UClickButtonWidget Function GetOwner ***************************************

// ********** Begin Class UClickButtonWidget Function Init_BP **************************************
struct ClickButtonWidget_eventInit_BP_Parms
{
	FClickUIInfo UIInfo;
};
static FName NAME_UClickButtonWidget_Init_BP = FName(TEXT("Init_BP"));
void UClickButtonWidget::Init_BP(FClickUIInfo const& UIInfo)
{
	ClickButtonWidget_eventInit_BP_Parms Parms;
	Parms.UIInfo=UIInfo;
	UFunction* Func = FindFunctionChecked(NAME_UClickButtonWidget_Init_BP);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Init_BP constinit property declarations *******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_UIInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Init_BP constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Init_BP Property Definitions ******************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::NewProp_UIInfo = { "UIInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ClickButtonWidget_eventInit_BP_Parms, UIInfo), Z_Construct_UScriptStruct_FClickUIInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIInfo_MetaData), NewProp_UIInfo_MetaData) }; // 3142199531
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::NewProp_UIInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::PropPointers) < 2048);
// ********** End Function Init_BP Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UClickButtonWidget, nullptr, "Init_BP", 	Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::PropPointers), 
sizeof(ClickButtonWidget_eventInit_BP_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::Function_MetaDataParams), Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ClickButtonWidget_eventInit_BP_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UClickButtonWidget_Init_BP()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UClickButtonWidget_Init_BP_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UClickButtonWidget Function Init_BP ****************************************

// ********** Begin Class UClickButtonWidget Function OnButtonRemove_BP ****************************
static FName NAME_UClickButtonWidget_OnButtonRemove_BP = FName(TEXT("OnButtonRemove_BP"));
void UClickButtonWidget::OnButtonRemove_BP()
{
	UFunction* Func = FindFunctionChecked(NAME_UClickButtonWidget_OnButtonRemove_BP);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UClickButtonWidget_OnButtonRemove_BP_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnButtonRemove_BP constinit property declarations *********************
// ********** End Function OnButtonRemove_BP constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UClickButtonWidget_OnButtonRemove_BP_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UClickButtonWidget, nullptr, "OnButtonRemove_BP", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UClickButtonWidget_OnButtonRemove_BP_Statics::Function_MetaDataParams), Z_Construct_UFunction_UClickButtonWidget_OnButtonRemove_BP_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UClickButtonWidget_OnButtonRemove_BP()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UClickButtonWidget_OnButtonRemove_BP_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UClickButtonWidget Function OnButtonRemove_BP ******************************

// ********** Begin Class UClickButtonWidget *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UClickButtonWidget;
UClass* UClickButtonWidget::GetPrivateStaticClass()
{
	using TClass = UClickButtonWidget;
	if (!Z_Registration_Info_UClass_UClickButtonWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ClickButtonWidget"),
			Z_Registration_Info_UClass_UClickButtonWidget.InnerSingleton,
			StaticRegisterNativesUClickButtonWidget,
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
	return Z_Registration_Info_UClass_UClickButtonWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UClickButtonWidget_NoRegister()
{
	return UClickButtonWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UClickButtonWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyClickActorComponent.h" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnClickButton_MetaData[] = {
		{ "Category", "ClickButtonWidget" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VaildInfo_MetaData[] = {
		{ "Category", "ClickButtonWidget" },
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeakOwner_MetaData[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIInfoLocal_MetaData[] = {
		{ "ModuleRelativePath", "MyClickActorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UClickButtonWidget constinit property declarations ***********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnClickButton;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VaildInfo;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_WeakOwner;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UIInfoLocal;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UClickButtonWidget constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetOwner"), .Pointer = &UClickButtonWidget::execGetOwner },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UClickButtonWidget_GetOwner, "GetOwner" }, // 586861110
		{ &Z_Construct_UFunction_UClickButtonWidget_Init_BP, "Init_BP" }, // 3688781544
		{ &Z_Construct_UFunction_UClickButtonWidget_OnButtonRemove_BP, "OnButtonRemove_BP" }, // 2506902362
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UClickButtonWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UClickButtonWidget_Statics

// ********** Begin Class UClickButtonWidget Property Definitions **********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UClickButtonWidget_Statics::NewProp_OnClickButton = { "OnClickButton", nullptr, (EPropertyFlags)0x0010100010080004, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UClickButtonWidget, OnClickButton), Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnClickButton_MetaData), NewProp_OnClickButton_MetaData) }; // 2414219031
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UClickButtonWidget_Statics::NewProp_VaildInfo = { "VaildInfo", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UClickButtonWidget, VaildInfo), Z_Construct_UScriptStruct_FClick_ValidInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VaildInfo_MetaData), NewProp_VaildInfo_MetaData) }; // 478412711
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UClickButtonWidget_Statics::NewProp_WeakOwner = { "WeakOwner", nullptr, (EPropertyFlags)0x0024080000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UClickButtonWidget, WeakOwner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeakOwner_MetaData), NewProp_WeakOwner_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UClickButtonWidget_Statics::NewProp_UIInfoLocal = { "UIInfoLocal", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UClickButtonWidget, UIInfoLocal), Z_Construct_UScriptStruct_FClickUIInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIInfoLocal_MetaData), NewProp_UIInfoLocal_MetaData) }; // 3142199531
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UClickButtonWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClickButtonWidget_Statics::NewProp_OnClickButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClickButtonWidget_Statics::NewProp_VaildInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClickButtonWidget_Statics::NewProp_WeakOwner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClickButtonWidget_Statics::NewProp_UIInfoLocal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClickButtonWidget_Statics::PropPointers) < 2048);
// ********** End Class UClickButtonWidget Property Definitions ************************************
UObject* (*const Z_Construct_UClass_UClickButtonWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClickButtonWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UClickButtonWidget_Statics::ClassParams = {
	&UClickButtonWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UClickButtonWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UClickButtonWidget_Statics::PropPointers),
	0,
	0x00A010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClickButtonWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UClickButtonWidget_Statics::Class_MetaDataParams)
};
void UClickButtonWidget::StaticRegisterNativesUClickButtonWidget()
{
	UClass* Class = UClickButtonWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UClickButtonWidget_Statics::Funcs));
}
UClass* Z_Construct_UClass_UClickButtonWidget()
{
	if (!Z_Registration_Info_UClass_UClickButtonWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UClickButtonWidget.OuterSingleton, Z_Construct_UClass_UClickButtonWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UClickButtonWidget.OuterSingleton;
}
UClickButtonWidget::UClickButtonWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UClickButtonWidget);
UClickButtonWidget::~UClickButtonWidget() {}
// ********** End Class UClickButtonWidget *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h__Script_MyProject_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FClick_PassInfo::StaticStruct, Z_Construct_UScriptStruct_FClick_PassInfo_Statics::NewStructOps, TEXT("Click_PassInfo"),&Z_Registration_Info_UScriptStruct_FClick_PassInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClick_PassInfo), 1396582729U) },
		{ FClick_ValidInfo::StaticStruct, Z_Construct_UScriptStruct_FClick_ValidInfo_Statics::NewStructOps, TEXT("Click_ValidInfo"),&Z_Registration_Info_UScriptStruct_FClick_ValidInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClick_ValidInfo), 478412711U) },
		{ FClickUIInfo::StaticStruct, Z_Construct_UScriptStruct_FClickUIInfo_Statics::NewStructOps, TEXT("ClickUIInfo"),&Z_Registration_Info_UScriptStruct_FClickUIInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClickUIInfo), 3142199531U) },
		{ FClick_Param::StaticStruct, Z_Construct_UScriptStruct_FClick_Param_Statics::NewStructOps, TEXT("Click_Param"),&Z_Registration_Info_UScriptStruct_FClick_Param, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClick_Param), 106418370U) },
		{ FClick_CheckFunctionName::StaticStruct, Z_Construct_UScriptStruct_FClick_CheckFunctionName_Statics::NewStructOps, TEXT("Click_CheckFunctionName"),&Z_Registration_Info_UScriptStruct_FClick_CheckFunctionName, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClick_CheckFunctionName), 376245754U) },
		{ FClick_ExecuteFunctionName::StaticStruct, Z_Construct_UScriptStruct_FClick_ExecuteFunctionName_Statics::NewStructOps, TEXT("Click_ExecuteFunctionName"),&Z_Registration_Info_UScriptStruct_FClick_ExecuteFunctionName, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClick_ExecuteFunctionName), 4244669964U) },
		{ FClickInfo::StaticStruct, Z_Construct_UScriptStruct_FClickInfo_Statics::NewStructOps, TEXT("ClickInfo"),&Z_Registration_Info_UScriptStruct_FClickInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClickInfo), 3639400269U) },
		{ FClick_ValidInfo_Rep::StaticStruct, Z_Construct_UScriptStruct_FClick_ValidInfo_Rep_Statics::NewStructOps, TEXT("Click_ValidInfo_Rep"),&Z_Registration_Info_UScriptStruct_FClick_ValidInfo_Rep, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClick_ValidInfo_Rep), 439374860U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UClickActorPCInterface, UClickActorPCInterface::StaticClass, TEXT("UClickActorPCInterface"), &Z_Registration_Info_UClass_UClickActorPCInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UClickActorPCInterface), 2134406423U) },
		{ Z_Construct_UClass_UMyClickActorComponent, UMyClickActorComponent::StaticClass, TEXT("UMyClickActorComponent"), &Z_Registration_Info_UClass_UMyClickActorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyClickActorComponent), 2537121789U) },
		{ Z_Construct_UClass_UClickButtonWidget, UClickButtonWidget::StaticClass, TEXT("UClickButtonWidget"), &Z_Registration_Info_UClass_UClickButtonWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UClickButtonWidget), 1220063452U) },
	};
}; // Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h__Script_MyProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h__Script_MyProject_4248111501{
	TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h__Script_MyProject_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h__Script_MyProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_MyProject_Source_MyProject_MyClickActorComponent_h__Script_MyProject_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
