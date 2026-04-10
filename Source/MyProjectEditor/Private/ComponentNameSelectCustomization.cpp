// Fill out your copyright notice in the Description page of Project Settings.

#include "ComponentNameSelectCustomization.h"
#include "PropertyHandle.h"
#include "DetailWidgetRow.h"
#include "IPropertyUtilities.h"
#include "Widgets/Input/SComboButton.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "GameFramework/Actor.h"
#include "IDetailChildrenBuilder.h"
#include "DetailLayoutBuilder.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Engine/SCS_Node.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/UnrealTypePrivate.h"
#include "Components/ActorComponent.h" 

/*
* 是否在查找ParentOuter
* 二进制标志
* 1: 开启功能
* 2: 如果UObject再嵌套多层，那么就需要往上递归找
*/
static int32 OpenComponentNameSelectCustomizationFindParentOuter = 3;
static FAutoConsoleVariableRef CVarOpenComponentNameSelectCustomizationFindParentOuter(
	TEXT("Name.OpenComponentNameSelectCustomizationFindParentOuter"),
	OpenComponentNameSelectCustomizationFindParentOuter,
	TEXT("0: Disable 1:Enable"),
	ECVF_Default);

TSharedRef<IPropertyTypeCustomization> FComponentNameSelectCustomization::MakeInstance()
{
	return MakeShareable(new FComponentNameSelectCustomization);
}

void FComponentNameSelectCustomization::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	MyStructProperty = StructPropertyHandle;
	PropUtils = StructCustomizationUtils.GetPropertyUtilities().Get();
	CacheData();
	HeaderRow.IsEnabled(TAttribute<bool>::Create(TAttribute<bool>::FGetter::CreateSP(this, &FComponentNameSelectCustomization::IsEditingEnabled)))
		.NameContent()
		[
			StructPropertyHandle->CreatePropertyNameWidget()
		];

	InitKeyFromProperty();
}

void FComponentNameSelectCustomization::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	uint32 NumChildren = 0;
	StructPropertyHandle->GetNumChildren(NumChildren);

	for (uint32 Idx = 0; Idx < NumChildren; Idx++)
	{
		TSharedPtr<IPropertyHandle> PropHandle = StructPropertyHandle->GetChildHandle(Idx);
		if (PropHandle->GetProperty() && PropHandle->GetProperty()->GetFName().IsEqual(FName(TEXT("ComponentName"))))
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
					SNew(SComboButton)
						.OnComboBoxOpened(this, &FComponentNameSelectCustomization::OnComboBoxClick)
						.OnGetMenuContent(this, &FComponentNameSelectCustomization::OnGetKeyContent)
						.ContentPadding(FMargin(2.0f, 2.0f))
						.ButtonContent()
						[
							SNew(STextBlock)
								.Text(this, &FComponentNameSelectCustomization::GetCondtionCurrentKeyDesc)
								.Font(IDetailLayoutBuilder::GetDetailFont())
						]
				];
		}
		else
		{
			StructBuilder.AddProperty(PropHandle.ToSharedRef());
		}
	}

}

void FComponentNameSelectCustomization::CacheData()
{
	MyComponentNameProperty = MyStructProperty->GetChildHandle(TEXT("ComponentName"));
	TArray<UClass*> FilterComponentClasses;
	//属性的元数据
	const FString& ComponentFilterName = MyStructProperty->GetMetaData(FName(TEXT("ComponentSelectorClassFilter")));
	UClass* FilterComponentClass = FindObject<UClass>(nullptr, ComponentFilterName.IsEmpty() ? TEXT("/Script/Engine.ActorComponent") : *ComponentFilterName);
	if (FilterComponentClass)
	{
		FilterComponentClasses.AddUnique(FilterComponentClass);
	}
	//结构本身的元数据
	FProperty* RawStructProperty = MyStructProperty->GetProperty();
	if (FStructProperty* CastedStructProperty = CastField<FStructProperty>(RawStructProperty))
	{
		UScriptStruct* ScriptStruct = CastedStructProperty->Struct;
		if (ScriptStruct)
		{
			const FString& ComponentFilterNameByClass = ScriptStruct->GetMetaData(FName(TEXT("ComponentSelectorClassFilter")));
			UClass* FilterComponentClass_ClassMeta = FindObject<UClass>(nullptr, ComponentFilterNameByClass.IsEmpty() ? TEXT("/Script/Engine.ActorComponent") : *ComponentFilterNameByClass);
			
			if (FilterComponentClass_ClassMeta)
			{
				FilterComponentClasses.AddUnique(FilterComponentClass_ClassMeta);
			}
		}
	}

	if (FilterComponentClasses.Num() > 0)
	{
		KeyValues.Reset();
		KeyValues.Add(TEXT("None"));
		TArray<UClass*> RelatedClasses;
		TArray<UObject*> OuterObjects;
		//获取CDO
		MyStructProperty->GetOuterObjects(OuterObjects);
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
				UActorComponent* Component = Cast<UActorComponent>(ObjItr);
				if (Component)
				{
					CDO = Cast<AActor>(Component->GetOwner());
				}
				else if (OpenComponentNameSelectCustomizationFindParentOuter)
				{
					//有可能自身是UObject对象，需要向上找组件。
					UObject* NextOuter = ObjItr->GetOuter();
					while (NextOuter != nullptr)
					{
						Component = Cast<UActorComponent>(NextOuter);
						if (Component)
						{
							CDO = Cast<AActor>(Component->GetOwner());
						}
						else
						{
							CDO = Cast<AActor>(NextOuter);
						}

						if (CDO)//找到了，退出
						{
							break;
						}

						if (OpenComponentNameSelectCustomizationFindParentOuter & 2)//开启了递归查找
						{
							NextOuter = NextOuter->GetOuter();
						}
						else
						{
							break;
						}
					}
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
			if (const UBlueprintGeneratedClass* GeneratedClass = Cast<UBlueprintGeneratedClass>(RelatedClass))
			{
				const USimpleConstructionScript* ConstructionScript = GeneratedClass->SimpleConstructionScript;
				if (!ConstructionScript)
				{
					continue;
				}

				const TArray<USCS_Node*>& allNodes = ConstructionScript->GetAllNodes();
				for (const USCS_Node* oneNode : allNodes)
				{
					if (oneNode && oneNode->ComponentClass)
					{
						bool bClassMatch = true;
						for (auto FilterClass : FilterComponentClasses)
						{
							if (!oneNode->ComponentClass->IsChildOf(FilterClass))
							{
								bClassMatch = false;
								break;
							}
						}
						if (bClassMatch)
						{
							KeyValues.AddUnique(oneNode->GetVariableName());
						}
					}
				}
			}
			else if (AActor* RelatedCDO = Cast<AActor>(RelatedClass->ClassDefaultObject))
			{
				TArray<UActorComponent*> CompList = RelatedCDO->K2_GetComponentsByClass(UActorComponent::StaticClass());
				for (const UActorComponent* OneComp : CompList)
				{
					if (OneComp)
					{
						if (const UClass* CompClass = OneComp->GetClass())
						{
							bool bClassMatch = true;
							for (auto FilterClass : FilterComponentClasses)
							{
								if (!CompClass->IsChildOf(FilterClass))
								{
									bClassMatch = false;
									break;
								}
							}
							if (bClassMatch)
							{
								KeyValues.AddUnique(FName(*OneComp->GetName()));
							}
						}
					}
				}
			}
		}

	}
}

void FComponentNameSelectCustomization::InitKeyFromProperty()
{
	FName KeyNameValue;
	if (MyComponentNameProperty.IsValid())
	{
		FPropertyAccess::Result Result = MyComponentNameProperty->GetValue(KeyNameValue);
		if (Result == FPropertyAccess::Success)
		{
			if (KeyNameValue.ToString().IsEmpty())
			{
				OnKeyComboChange(0);
			}
		}
	}
}

void FComponentNameSelectCustomization::OnKeyComboChange(int32 Index)
{
	if (MyComponentNameProperty.IsValid() && KeyValues.IsValidIndex(Index))
	{
		MyComponentNameProperty->SetValue(KeyValues[Index]);
	}
}

void FComponentNameSelectCustomization::OnComboBoxClick()
{
	CacheData();
}

TSharedRef<SWidget> FComponentNameSelectCustomization::OnGetKeyContent()
{
	FMenuBuilder MenuBuilder(true, NULL);

	for (int32 Idx = 0; Idx < KeyValues.Num(); Idx++)
	{
		FUIAction ItemAction(FExecuteAction::CreateSP(this, &FComponentNameSelectCustomization::OnKeyComboChange, Idx));
		MenuBuilder.AddMenuEntry(FText::FromName(KeyValues[Idx]), TAttribute<FText>(), FSlateIcon(), ItemAction);
	}

	return MenuBuilder.MakeWidget();
}

FText FComponentNameSelectCustomization::GetCondtionCurrentKeyDesc() const
{
	FName NameValue;
	if (MyComponentNameProperty.IsValid())
	{
		MyComponentNameProperty->GetValue(NameValue);
	}

	return FText::FromName(NameValue);
}

bool FComponentNameSelectCustomization::IsEditingEnabled() const
{
	return PropUtils->IsPropertyEditingEnabled();
}
