// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomFunction_Customization.h"
#include "PropertyHandle.h"
#include "DetailWidgetRow.h"
#include "IPropertyUtilities.h"
#include "Widgets/Input/SComboButton.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "GameFramework/Actor.h"
#include "IDetailChildrenBuilder.h"
#include "DetailLayoutBuilder.h"
#include "Widgets/Input/SButton.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Engine/SCS_Node.h"
#include "MyProject/MyClickActorComponent.h"
#include "GameFramework/PlayerController.h"
#include "UObject/UObjectGlobals.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"

// TSharedRef<IPropertyTypeCustomization> FCustomFunction_Customization::MakeInstance()
// {
// 	return MakeShareable(new FCustomFunction_Customization);
// }

void FCustomFunction_Customization::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	StructProperty = StructPropertyHandle;
	PropUtils = StructCustomizationUtils.GetPropertyUtilities().Get();
	CacheData();
	HeaderRow.IsEnabled(TAttribute<bool>::Create(TAttribute<bool>::FGetter::CreateSP(this, &FCustomFunction_Customization::IsEditingEnabled)))
		.NameContent()
		[
			StructPropertyHandle->CreatePropertyNameWidget()
		];

	InitKeyFromProperty();
}

void FCustomFunction_Customization::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	uint32 NumChildren = 0;
	StructPropertyHandle->GetNumChildren(NumChildren);

	for (uint32 Idx = 0; Idx < NumChildren; Idx++)
	{
		TSharedPtr<IPropertyHandle> PropHandle = StructPropertyHandle->GetChildHandle(Idx);
		if (PropHandle->GetProperty() && PropHandle->GetProperty()->GetFName().IsEqual(FName(TEXT("CustomFunctionName"))))
		{
			FText PropName = FText::FromName(PropHandle->GetProperty()->GetFName());
			StructBuilder.AddCustomRow(PropName)
				.NameContent()
				[
					SNew(STextBlock)
						.Text(PropName)
						.Font(StructCustomizationUtils.GetRegularFont())
				]
				.ValueContent()
				[
					SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						[
							SNew(SComboButton)
								.OnComboBoxOpened(this, &FCustomFunction_Customization::OnComboBoxClick)
								.OnGetMenuContent(this, &FCustomFunction_Customization::OnGetKeyContent)
								.ContentPadding(FMargin(2.0f, 2.0f))
								.ButtonContent()
								[
									SNew(STextBlock)
										.Text(this, &FCustomFunction_Customization::GetCondtionCurrentKeyDesc)
										.Font(IDetailLayoutBuilder::GetDetailFont())
								]
						]
					+ SHorizontalBox::Slot()
						.AutoWidth()
						[
							SAssignNew(FunctionNameSuggestionTextBox, SEditableTextBox)
								.MinDesiredWidth(180.0f)
								.HintText(FText::FromString("Function Name Suggestion"))
						]

						+ SHorizontalBox::Slot()
						.AutoWidth()
						[
							SNew(SButton)
								.HAlign(HAlign_Fill)
								.VAlign(VAlign_Center)
								.Text(FText::FromString(TEXT("Assign New")))
								.OnClicked(this, &FCustomFunction_Customization::AssignNew)

						]
				]
			;
		}
		else
		{
			StructBuilder.AddProperty(PropHandle.ToSharedRef());
		}
	}

}

bool FCustomFunction_Customization::IsValidFunction(UFunction* Function)
{
	return false;
}

void FCustomFunction_Customization::CacheData()
{
	FunctionNameProperty = StructProperty->GetChildHandle(TEXT("CustomFunctionName"));
	if (true)
	{
		FunctionNames.Reset();
		FunctionNames.Add(TEXT("None"));
		TArray<UClass*> RelatedClasses;
		TArray<UObject*> OuterObjects;
		//��ȡCDO
		StructProperty->GetOuterObjects(OuterObjects);
		for (UObject* ObjItr : OuterObjects)
		{
			if (!ObjItr)
			{
				continue;
			}

			UBlueprintGeneratedClass* GeneratedClass = nullptr;

			AActor* CDO = Cast<AActor>(ObjItr);
			if (!CDO)
			{
				if (UActorComponent* Component = Cast<UActorComponent>(ObjItr))
				{
					CDO = Cast<AActor>(Component->GetOwner());
				}
			}

			if (CDO)
			{
				UClass* ActorClass = CDO->GetClass();
				if (ActorClass)
				{
					GeneratedClass = Cast<UBlueprintGeneratedClass>(ActorClass);
				}
			}

			UClass* RelatedClass = GeneratedClass = GeneratedClass ? GeneratedClass : ObjItr->GetTypedOuter<UBlueprintGeneratedClass>();
			while (RelatedClass)
			{
				RelatedClasses.AddUnique(RelatedClass);
				RelatedClass = RelatedClass->GetSuperClass();
			}
		}

		for (const UClass* RelatedClass : RelatedClasses)
		{
			if (!RelatedClass)
			{
				continue;
			}
			for (TFieldIterator<UFunction> FuncIt(RelatedClass, EFieldIteratorFlags::ExcludeSuper); FuncIt; ++FuncIt)
			{
				UFunction* Function = *FuncIt;
				if (Function && IsValidFunction(Function))
				{
					FunctionNames.AddUnique(Function->GetFName());
				}
			}
		}
	}
}

void FCustomFunction_Customization::InitKeyFromProperty()
{
	FName KeyNameValue;
	if (FunctionNameProperty.IsValid())
	{
		FPropertyAccess::Result Result = FunctionNameProperty->GetValue(KeyNameValue);
		if (Result == FPropertyAccess::Success)
		{
			if (KeyNameValue.ToString().IsEmpty())
			{
				OnKeyComboChange(0);
			}
		}
	}
}

void FCustomFunction_Customization::OnKeyComboChange(int32 Index)
{
	if (FunctionNameProperty.IsValid() && FunctionNames.IsValidIndex(Index))
	{
		FunctionNameProperty->SetValue(FunctionNames[Index]);
	}
}

void FCustomFunction_Customization::OnComboBoxClick()
{
	CacheData();
}

TSharedRef<SWidget> FCustomFunction_Customization::OnGetKeyContent()
{
	FMenuBuilder MenuBuilder(true, NULL);

	for (int32 Idx = 0; Idx < FunctionNames.Num(); Idx++)
	{
		FUIAction ItemAction(FExecuteAction::CreateSP(this, &FCustomFunction_Customization::OnKeyComboChange, Idx));
		MenuBuilder.AddMenuEntry(FText::FromName(FunctionNames[Idx]), TAttribute<FText>(), FSlateIcon(), ItemAction);
	}

	return MenuBuilder.MakeWidget();
}

FText FCustomFunction_Customization::GetCondtionCurrentKeyDesc() const
{
	FName NameValue;
	if (FunctionNameProperty.IsValid())
	{
		FunctionNameProperty->GetValue(NameValue);
	}

	return FText::FromName(NameValue);
}

bool FCustomFunction_Customization::IsEditingEnabled() const
{
	return PropUtils->IsPropertyEditingEnabled();
}

FReply FCustomFunction_Customization::AssignNew()
{
	// Fetch Blueprint
	TArray<UObject*> Outers;
	UObject* pSelectedOuter = nullptr;
	StructProperty->GetOuterObjects(Outers);

	for (UObject* pObj : Outers)
	{
		if (pObj)
		{
			pSelectedOuter = pObj;
			break;
		}
	}

	UClass* pOuterActorClass = Cast<UClass>(findSpecifiedOuter(pSelectedOuter, AActor::StaticClass()));
	if (!pOuterActorClass)
	{
		return FReply::Handled();
	}
	UBlueprint* Blueprint = Cast<UBlueprint>(pOuterActorClass->ClassGeneratedBy);
	if (!Blueprint)
	{
		return FReply::Handled();
	}

	// Fetch properties
	bool bCheckFunction = StructProperty->GetPropertyDisplayName().ToString().Contains("Check Function");


	FString SuggestionFunctionName = FunctionNameSuggestionTextBox->GetText().ToString();

	if (SuggestionFunctionName.Len() == 0)
	{
		if (bCheckFunction)
		{
			SuggestionFunctionName = "Check";
		}
		else
		{
			SuggestionFunctionName = "Excute";
		}
	}

	FName NewEventName = FName(*SuggestionFunctionName);

	// Check if <NewEventName> has existed
	TSet<FName> BlueprintFunctionNameList;
	FBlueprintEditorUtils::GetFunctionNameList(Blueprint, BlueprintFunctionNameList);
	if (BlueprintFunctionNameList.Find(NewEventName))
	{
		NewEventName = FBlueprintEditorUtils::FindUniqueKismetName(Blueprint, SuggestionFunctionName);
	}

	// Create event graph
	auto&& Event = FBlueprintEditorUtils::CreateNewGraph(Blueprint, NewEventName, UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
	Blueprint->Modify();

	if (!Event)
	{
		return FReply::Handled();
	}

	// Create function graph
	FBlueprintEditorUtils::AddFunctionGraph<UClass>(Blueprint, Event, true, nullptr);

	TWeakObjectPtr<UK2Node_EditablePinBase> EntryNode{}, ResultNode{};
	Event->Modify();
	// Get entry node of this function graph
	EntryNode = FBlueprintEditorUtils::GetEntryNode(Event);
	// Add input parameter
	DefineEntryNote(EntryNode);

	//	if (bCheckFunction)
	{
		Event->Modify();
		// Try to create return node
		FBlueprintEditorUtils::FindOrCreateFunctionResultNode(EntryNode.Get());
		// Get return node of this function graph
		FBlueprintEditorUtils::GetEntryAndResultNodes(Event, EntryNode, ResultNode);
		// Add output boolean

		DefineRetNote(ResultNode);
	}

	// Compile blueprint manually
	FBlueprintEditorUtils::RefreshAllNodes(Blueprint);
	FKismetEditorUtilities::CompileBlueprint(Blueprint, EBlueprintCompileOptions::SkipGarbageCollection);
	FunctionNameProperty->SetValue(NewEventName);
	return FReply::Handled();
}

void FCustomFunction_Customization::DefineEntryNote(TWeakObjectPtr<UK2Node_EditablePinBase> EntryNote)
{
	//	EntryNote->CreateUserDefinedPin("Click_Param", FEdGraphPinType(UEdGraphSchema_K2::PC_Struct, {}, TBaseStructure<FClick_Param>::Get(), EPinContainerType::None, false, FEdGraphTerminalType{}), EEdGraphPinDirection::EGPD_Output, true);
}

void FCustomFunction_Customization::DefineRetNote(TWeakObjectPtr<UK2Node_EditablePinBase> RetNote)
{
	//	RetNote->CreateUserDefinedPin("result", FEdGraphPinType(UEdGraphSchema_K2::PC_Boolean, {}, nullptr, EPinContainerType::None, false, FEdGraphTerminalType{}), EEdGraphPinDirection::EGPD_Input, true);
}

UObject* FCustomFunction_Customization::findSpecifiedOuter(UObject* InObj, UClass* InOuterClass)
{
	if (!InObj || !InOuterClass) { return nullptr; }
	if (UBlueprintGeneratedClass* pBPClass = Cast<UBlueprintGeneratedClass>(InObj))
	{
		UStruct* pSuperStruct = pBPClass->GetSuperStruct();
		if (!pSuperStruct) { return nullptr; }
		if (pSuperStruct->IsChildOf(InOuterClass))
		{
			return InObj;
		}
		while (pSuperStruct->GetSuperStruct())
		{
			pSuperStruct = pSuperStruct->GetSuperStruct();
			if (pSuperStruct->IsChildOf(InOuterClass))
			{
				return InObj;
			}
		}
		return nullptr;
	}
	else if (InObj->GetClass() && InObj->GetClass()->IsChildOf(InOuterClass))
	{
		return InObj;
	};
	return findSpecifiedOuter(InObj->GetOuter(), InOuterClass);
};

TSharedRef<IPropertyTypeCustomization> FCustomFunction_CheckFunctionName::MakeInstance()
{
	return MakeShareable(new FCustomFunction_CheckFunctionName);
}

bool FCustomFunction_CheckFunctionName::IsValidFunction(UFunction* Function)
{
	return FClick_CheckFunctionName::IsValidFunction(Function);
}

void FCustomFunction_CheckFunctionName::DefineEntryNote(TWeakObjectPtr<UK2Node_EditablePinBase> EntryNote)
{
	EntryNote->CreateUserDefinedPin("Click_Param", FEdGraphPinType(UEdGraphSchema_K2::PC_Struct, {}, TBaseStructure<FClick_Param>::Get(), EPinContainerType::None, false, FEdGraphTerminalType{}), EEdGraphPinDirection::EGPD_Output, true);
}

void FCustomFunction_CheckFunctionName::DefineRetNote(TWeakObjectPtr<UK2Node_EditablePinBase> RetNote)
{
	RetNote->CreateUserDefinedPin("result", FEdGraphPinType(UEdGraphSchema_K2::PC_Boolean, {}, nullptr, EPinContainerType::None, false, FEdGraphTerminalType{}), EEdGraphPinDirection::EGPD_Input, true);
}

TSharedRef<IPropertyTypeCustomization> FCustomFunction_ExecuteFunctionName::MakeInstance()
{
	return MakeShareable(new FCustomFunction_ExecuteFunctionName);
}

bool FCustomFunction_ExecuteFunctionName::IsValidFunction(UFunction* Function)
{
	return FClick_ExecuteFunctionName::IsValidFunction(Function);
}

void FCustomFunction_ExecuteFunctionName::DefineEntryNote(TWeakObjectPtr<UK2Node_EditablePinBase> EntryNote)
{
	EntryNote->CreateUserDefinedPin("Click_Param", FEdGraphPinType(UEdGraphSchema_K2::PC_Struct, {}, TBaseStructure<FClick_Param>::Get(), EPinContainerType::None, false, FEdGraphTerminalType{}), EEdGraphPinDirection::EGPD_Output, true);
}

void FCustomFunction_ExecuteFunctionName::DefineRetNote(TWeakObjectPtr<UK2Node_EditablePinBase> RetNote)
{

}

