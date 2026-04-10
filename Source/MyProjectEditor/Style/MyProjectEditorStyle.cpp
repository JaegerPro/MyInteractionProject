// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectEditorStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"

TSharedPtr<FSlateStyleSet> FMyProjectEditorStyle::StyleInstance = NULL;

void FMyProjectEditorStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
		StyleInstance->SetContentRoot(FPaths::ProjectDir() / TEXT("Content/Editor/Icons"));
		
		// 注册自定义画笔和样式
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMyProjectEditorStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

void FMyProjectEditorStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMyProjectEditorStyle::Get()
{
	return *StyleInstance;
}

FName FMyProjectEditorStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MyProjectEditorStyle"));
	return StyleSetName;
}
