// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyProject_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature();
	MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature();
	MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature();
	MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature();
	MYPROJECT_API UFunction* Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MyProject;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MyProject()
	{
		if (!Z_Registration_Info_UPackage__Script_MyProject.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_MyProject_ActivityChangeState__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_MyProject_OnClickButton__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_MyProject_OnPawnStateEnter__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_MyProject_OnPawnStateInterrupt__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_MyProject_OnPawnStateLeave__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/MyProject",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x3665467E,
			0xDECFB41D,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MyProject.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_MyProject.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MyProject(Z_Construct_UPackage__Script_MyProject, TEXT("/Script/MyProject"), Z_Registration_Info_UPackage__Script_MyProject, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x3665467E, 0xDECFB41D));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
