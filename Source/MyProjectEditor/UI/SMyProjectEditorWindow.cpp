// Copyright Epic Games, Inc. All Rights Reserved.

#include "SMyProjectEditorWindow.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Layout/SSeparator.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

#define LOCTEXT_NAMESPACE "MyProjectEditorWindow"

void SMyProjectEditorWindow::Construct(const FArguments& InArgs)
{
	bIsCheckboxChecked = false;
	StatusText = TEXT("Ready");

	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("WindowTitle", "My Project Editor Window"))
			.Font(FCoreStyle::GetDefaultFontStyle("Bold", 14))
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f)
		[
			SNew(SSeparator)
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f)
		[
			SNew(STextBlock)
			.Text_Lambda([this]() { return FText::FromString(StatusText); })
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f)
		[
			SNew(SCheckBox)
			.IsChecked(this, &SMyProjectEditorWindow::IsCheckboxChecked)
			.OnCheckStateChanged(this, &SMyProjectEditorWindow::OnCheckboxChanged)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("EnableFeature", "Enable Custom Feature"))
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(10.0f)
		[
			SNew(SButton)
			.Text(LOCTEXT("PerformAction", "Perform Action"))
			.OnClicked(this, &SMyProjectEditorWindow::OnButtonClick)
		]
	];
}

FReply SMyProjectEditorWindow::OnButtonClick()
{
	StatusText = TEXT("Action Performed!");
	
	// 显示通知
	FNotificationInfo Info(LOCTEXT("ActionPerformed", "Action has been performed successfully!"));
	Info.ExpireDuration = 3.0f;
	FSlateNotificationManager::Get().AddNotification(Info);

	return FReply::Handled();
}

ECheckBoxState SMyProjectEditorWindow::IsCheckboxChecked() const
{
	return bIsCheckboxChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

void SMyProjectEditorWindow::OnCheckboxChanged(ECheckBoxState NewState)
{
	bIsCheckboxChecked = (NewState == ECheckBoxState::Checked);
	StatusText = bIsCheckboxChecked ? TEXT("Feature Enabled") : TEXT("Feature Disabled");
}

#undef LOCTEXT_NAMESPACE
