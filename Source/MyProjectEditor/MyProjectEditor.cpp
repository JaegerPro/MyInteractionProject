// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectEditor.h"
#include "ComponentNameSelectCustomization.h"
#include "CustomFunction_Customization.h"
#include "KismetCompiler.h"
#include "Engine/Blueprint.h"
#include "ActivityBaseActorBlueprintCompiler.h"

IMPLEMENT_MODULE(FMyProjectEditorModule, MyProjectEditor);

void FMyProjectEditorModule::StartupModule()
{
	FKismetCompilerContext::RegisterCompilerForBP(UBlueprint::StaticClass(),
		[](UBlueprint* Blueprint, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompilerOptions)
		{
			return MakeShared<FActivityBaseActorBlueprintCompilerContext>(Blueprint, InMessageLog, InCompilerOptions);
		});
	UE_LOG(LogTemp, Warning, TEXT("RegisterCompilerForBP done for UBlueprint"));

	if (GIsEditor && !IsRunningCommandlet())
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
		{
			PropertyModule.RegisterCustomPropertyTypeLayout(TEXT("ShapeComponentSelector"), FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FComponentNameSelectCustomization::MakeInstance));
			PropertyModule.RegisterCustomPropertyTypeLayout(TEXT("Click_CheckFunctionName"), FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FCustomFunction_CheckFunctionName::MakeInstance));
			PropertyModule.RegisterCustomPropertyTypeLayout(TEXT("Click_ExecuteFunctionName"), FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FCustomFunction_ExecuteFunctionName::MakeInstance));
		}
	}
}

void FMyProjectEditorModule::ShutdownModule()
{

}
