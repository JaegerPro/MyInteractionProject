// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Views/SListView.h"

class SMyProjectEditorWindow : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMyProjectEditorWindow)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	// 示例按钮点击处理
	FReply OnButtonClick();

	// 示例复选框状态
	ECheckBoxState IsCheckboxChecked() const;
	void OnCheckboxChanged(ECheckBoxState NewState);

	// 数据成员
	bool bIsCheckboxChecked;
	FString StatusText;
};
