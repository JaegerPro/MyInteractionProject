// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyProjectEditor_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MyProjectEditor;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MyProjectEditor()
	{
		if (!Z_Registration_Info_UPackage__Script_MyProjectEditor.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/MyProjectEditor",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000040,
			0xB69FD55A,
			0x33E2A0F9,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MyProjectEditor.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_MyProjectEditor.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MyProjectEditor(Z_Construct_UPackage__Script_MyProjectEditor, TEXT("/Script/MyProjectEditor"), Z_Registration_Info_UPackage__Script_MyProjectEditor, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB69FD55A, 0x33E2A0F9));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
