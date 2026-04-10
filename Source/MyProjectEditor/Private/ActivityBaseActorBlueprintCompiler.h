// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "KismetCompiler.h"

struct FActivityLink;
struct FActivityState;
class AActivityBaseActor;

class FActivityBaseActorBlueprintCompilerContext : public FKismetCompilerContext
{
public:
	FActivityBaseActorBlueprintCompilerContext(UBlueprint* SourceSketch, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompilerOptions)
		: FKismetCompilerContext(SourceSketch, InMessageLog, InCompilerOptions)
	{
	}

	virtual void PreCompile() override;
	virtual void PostCompile() override;
	virtual void OnPostCDOCompiled(const UObject::FPostCDOCompiledContext& Context) override;

public:
	void CheckIsValid(UClass* Class, FCompilerResultsLog& Results);

private:
	FString  EnterSuffix = TEXT("_Entry");
	FString  LeaveSuffix = TEXT("_Exit");
	FString  LinkInfix = TEXT("_LinkTo_");
	FText StateMachineCategoryName = FText::FromString(TEXT("StateMachineAutoFunction"));
	FString TriggerCategoryNamePreffix = TEXT("TriggerOutFunction_");
	FString  SnapShootSuffix = TEXT("_Sequence");
	FName InstanceConditionName = FName(TEXT("InstanceCondition"));

private:
	void CheckStateIsValid(class IActivityStateInterface* CDO, UClass* Class, FCompilerResultsLog& Results);
	void CheckStateFunctionIsValid(FActivityState& State, FCompilerResultsLog& Results);
	void ReAssignStateIndex(TArray<FActivityState>& StateInfo, FCompilerResultsLog& Results);
	//ToolFunction
private:
	UEdGraph* RenameOrAddNewFunction(FName& FunctionOldName, FName& NewName, FName& StateName, FCompilerResultsLog& Results);
	void DecorateFunctionCategory(UEdGraph* FunctionGraph, FText& CategoryName, FCompilerResultsLog& Results);
	void ReAssignPropertyToInstance(class IActivityStateInterface* CDO, FCompilerResultsLog& Results);
	void CopyAutoStatePropetyToInstance(FActivityState& Template, FActivityState& Instance, FCompilerResultsLog& Results);
	bool CheckParentClassHaveSameNameFunction(FName FunctionName);
	bool CheckHaveNodeInHierarchyClass(FName NodeName);
private:
	void AddCustomEvent(UEdGraph* Graph, FName NodeName);
	class UK2Node_CustomEvent* FindExistingNode(UEdGraph* Graph, FName NodeName);

};