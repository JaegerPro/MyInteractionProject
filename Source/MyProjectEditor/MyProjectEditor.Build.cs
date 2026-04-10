// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyProjectEditor : ModuleRules
{
	public MyProjectEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"UnrealEd",
			"Slate",
			"SlateCore",
			"EditorStyle",
            "PropertyEditor",
            "BlueprintGraph",
			"Kismet",
            "KismetCompiler",
        });

		PrivateDependencyModuleNames.AddRange(new string[] {
            "MyProject"
        });
	}
}
