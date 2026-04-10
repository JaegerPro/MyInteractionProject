// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "Components/ActorComponent.h"
/**
 *
 */
class FComponentNameSelectCustomization : public IPropertyTypeCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	/** IPropertyTypeCustomization interface */
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

private:
	void CacheData();
	void InitKeyFromProperty();
	void OnKeyComboChange(int32 Index);
	void OnComboBoxClick();
	TSharedRef<SWidget> OnGetKeyContent();
	FText GetCondtionCurrentKeyDesc() const;
	bool IsEditingEnabled() const;

	TSharedPtr<IPropertyHandle> MyStructProperty;
	TSharedPtr<IPropertyHandle> MyComponentNameProperty;

	TArray<FName> KeyValues;
	/** property utils */
	class IPropertyUtilities* PropUtils;
};
