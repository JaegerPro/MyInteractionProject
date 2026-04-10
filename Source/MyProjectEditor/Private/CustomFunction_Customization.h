// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "Widgets/Input/SEditableTextBox.h"

/**
 *
 */

class FCustomFunction_Customization : public IPropertyTypeCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
//	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	/** IPropertyTypeCustomization interface */
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

protected:
	virtual bool IsValidFunction(UFunction* Function);
	virtual FReply AssignNew();
	virtual void DefineEntryNote(TWeakObjectPtr<UK2Node_EditablePinBase> EntryNote);
	virtual void DefineRetNote(TWeakObjectPtr<UK2Node_EditablePinBase> RetNote);


private:
	void CacheData();
	void InitKeyFromProperty();
	void OnKeyComboChange(int32 Index);
	void OnComboBoxClick();
	TSharedRef<SWidget> OnGetKeyContent();
	FText GetCondtionCurrentKeyDesc() const;
	bool IsEditingEnabled() const;

	TSharedPtr<IPropertyHandle> StructProperty;
	TSharedPtr<IPropertyHandle> FunctionNameProperty;
	UObject* findSpecifiedOuter(UObject* InObj, UClass* InOuterClass);
	TArray<FName> FunctionNames;
	/** property utils */
	class IPropertyUtilities* PropUtils;
	TSharedPtr<SEditableTextBox> FunctionNameSuggestionTextBox;
};

class FCustomFunction_CheckFunctionName : public FCustomFunction_Customization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
protected:
	virtual bool IsValidFunction(UFunction* Function) override;
	virtual void DefineEntryNote(TWeakObjectPtr<UK2Node_EditablePinBase> EntryNote) override;
	virtual void DefineRetNote(TWeakObjectPtr<UK2Node_EditablePinBase> RetNote) override;
};

class FCustomFunction_ExecuteFunctionName : public FCustomFunction_Customization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
protected:
	virtual bool IsValidFunction(UFunction* Function) override;
	virtual void DefineEntryNote(TWeakObjectPtr<UK2Node_EditablePinBase> EntryNote) override;
	virtual void DefineRetNote(TWeakObjectPtr<UK2Node_EditablePinBase> RetNote) override;

};