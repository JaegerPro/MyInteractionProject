// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ActivityBaseActorBlueprintCompiler.h"
#include "KismetCompiler.h"
#include "MyProject/MyActivityActor.h"
#include "MyProject/ActivityStateInterface.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Engine/SCS_Node.h"
#include "Engine/SimpleConstructionScript.h"
#include "ActorSequenceComponent.h"
#include "K2Node_CustomEvent.h"
#include "Kismet2/ComponentEditorUtils.h"
#include "Tracks/MovieSceneSubTrack.h"
#include "Sections/MovieSceneSubSection.h"
#include "Engine/InheritableComponentHandler.h"

void FActivityBaseActorBlueprintCompilerContext::PreCompile()
{
	FKismetCompilerContext::PreCompile();
}

void FActivityBaseActorBlueprintCompilerContext::PostCompile()
{
	FKismetCompilerContext::PostCompile();
}

void FActivityBaseActorBlueprintCompilerContext::OnPostCDOCompiled(const UObject::FPostCDOCompiledContext& Context)
{
	FKismetCompilerContext::OnPostCDOCompiled(Context);

	if (!Blueprint || !Blueprint->ParentClass)
	{
		return;
	}
	if (!Blueprint->ParentClass->ImplementsInterface(UActivityStateInterface::StaticClass()))
	{
		return;
	}
	if (NewClass)
	{
		CheckIsValid(NewClass, MessageLog);
	}
}


#pragma region StateCheck
void FActivityBaseActorBlueprintCompilerContext::CheckIsValid(UClass* Class, FCompilerResultsLog& Results)
{
	check(NULL != Blueprint);
	check(NULL != Class);
	if (Class->ClassDefaultObject == nullptr)
	{
		//蓝图新建的时候cdo为空，所以return
		return;
	}

	if (!Class->ImplementsInterface(UActivityStateInterface::StaticClass()))
	{
		return;
	}
	UObject* Object = Class->GetDefaultObject<UObject>();
	IActivityStateInterface* TmpActor = Cast<IActivityStateInterface>(Object);
	if (TmpActor == nullptr) return;

	CheckStateIsValid(TmpActor, Class, Results);
	ReAssignPropertyToInstance(TmpActor, Results);
}

void FActivityBaseActorBlueprintCompilerContext::CheckStateIsValid(class IActivityStateInterface* CDO, UClass* Class, FCompilerResultsLog& Results)
{

	TArray<FActivityState>& StateInfo = CDO->GetStateMachineInfo();

	if (StateInfo.Num() <= 0)
	{
		FActivityState State;
		State.StateName = FName("Normal");
		State.bStateMachineEntry = true;
		StateInfo.Add(State);
	}

	ReAssignStateIndex(StateInfo, Results);

	for (auto& Var : StateInfo)
	{
		CheckStateFunctionIsValid(Var, Results);
	}

}

void FActivityBaseActorBlueprintCompilerContext::CheckStateFunctionIsValid(FActivityState& State, FCompilerResultsLog& Results)
{
	if (State.StateName.IsNone())
	{
		Results.Error(*FString::Printf(TEXT("ActivityBaseActor State Index %d, StateName Con't Be None"), State.StateIndex));
		return;
	}

	FName EnterDocumentName = FName(*State.StateName.ToString().Append(EnterSuffix));
	FName LeaveDocumentName = FName(*State.StateName.ToString().Append(LeaveSuffix));
	UEdGraph* Ret = RenameOrAddNewFunction(State.StateEnterFunctionName, EnterDocumentName, State.StateName, Results);
	DecorateFunctionCategory(Ret, StateMachineCategoryName, Results);
	Ret = RenameOrAddNewFunction(State.StateLeaveFunctionName, LeaveDocumentName, State.StateName, Results);
	DecorateFunctionCategory(Ret, StateMachineCategoryName, Results);

}

void FActivityBaseActorBlueprintCompilerContext::ReAssignStateIndex(TArray<FActivityState>& StateInfo, FCompilerResultsLog& Results)
{
	int32 Index = 0;
	int32 FindEntryNum = 0;
	for (auto& Var : StateInfo)
	{
		Var.StateIndex = Index++;
		if (Var.bStateMachineEntry)
		{
			FindEntryNum++;
		}
	}

	if (FindEntryNum != 1)
	{
		Results.Error(*FString::Printf(TEXT("ActivityBaseActor Must Only Have One Entry!")));
	}
}

#pragma endregion StateCheck

UEdGraph* FActivityBaseActorBlueprintCompilerContext::RenameOrAddNewFunction(FName& FunctionOldName, FName& NewName, FName& StateName, FCompilerResultsLog& Results)
{
	if (!Blueprint->GeneratedClass)
	{
		Results.Error(*FString::Printf(TEXT("ActivityBaseActor(%s) GeneratedClass none. FuncName:%s"), *(Blueprint->GetFullName()), *NewName.ToString()));
		return nullptr;
	}
	if (!Blueprint->SkeletonGeneratedClass)
	{
		Results.Error(*FString::Printf(TEXT("ActivityBaseActor(%s) SkeletonGeneratedClass none. FuncName:%s"), *(Blueprint->GetFullName()), *NewName.ToString()));
		return nullptr;
	}

	//如果旧名字和新名字相同且能找到方法，说明不需要走新建流程
	if (FunctionOldName == NewName)
	{
		if (Blueprint->GeneratedClass->FindFunctionByName(NewName) || Blueprint->SkeletonGeneratedClass->FindFunctionByName(NewName))
		{
			return nullptr;
		}
	}

	if (CheckParentClassHaveSameNameFunction(NewName))
	{
		if (FunctionOldName.IsNone())
		{
			FunctionOldName = NewName;
		}
		Results.Warning(*FString::Printf(TEXT("ActivityBaseActor State ParentClass HaveSameName  %s"), *(NewName.ToString())));
		return nullptr;
	}

	if (Blueprint->GeneratedClass->FindFunctionByName(NewName))
	{
		if (FunctionOldName.IsNone())
		{
			FunctionOldName = NewName;
		}
		Results.Warning(*FString::Printf(TEXT("ActivityBaseActor State FindFunction  %s"), *(NewName.ToString())));
		return nullptr;
	}

	UEdGraph* ExistingGraph = FindObject<UEdGraph>(Blueprint, *(StateName.ToString()));
	if (!ExistingGraph)
	{
		ExistingGraph = FBlueprintEditorUtils::CreateNewGraph(Blueprint, StateName, UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
		FBlueprintEditorUtils::AddUbergraphPage(Blueprint, ExistingGraph);
	}

	UK2Node_CustomEvent* CustomEvent = FindExistingNode(ExistingGraph, FunctionOldName);
	if (!CustomEvent)
	{
		AddCustomEvent(ExistingGraph, NewName);
		FunctionOldName = NewName;
	}
	else
	{
		CustomEvent->CustomFunctionName = NewName;
		FunctionOldName = NewName;
	}

	return ExistingGraph;
}

void FActivityBaseActorBlueprintCompilerContext::DecorateFunctionCategory(UEdGraph* FunctionGraph, FText& CategoryName, FCompilerResultsLog& Results)
{
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();
	check(K2Schema);

	if (!FunctionGraph)
	{
		return;
	}

	K2Schema->MarkFunctionEntryAsEditable(FunctionGraph, true);
	FBlueprintEditorUtils::SetBlueprintFunctionOrMacroCategory(FunctionGraph, CategoryName);

	K2Schema->MarkFunctionEntryAsEditable(FunctionGraph, false);
	FBlueprintEditorUtils::MarkBlueprintAsModified(Blueprint);
}


void FActivityBaseActorBlueprintCompilerContext::ReAssignPropertyToInstance(class IActivityStateInterface* CDO, FCompilerResultsLog& Results)
{

	// 	UClass* Class = CDO->GetClass();
	// 	UProperty* Property = Class->FindPropertyByName(FName(TEXT("StateMachineInfo"))	check(Property);
	TArray<FActivityState>& CDOState = CDO->GetStateMachineInfo();
	TArray<UObject*> Instances;
	UObject* Object = Cast<UObject>(CDO);
	Object->GetArchetypeInstances(Instances);
	for (UObject* Var : Instances)
	{
		IActivityStateInterface* Actor = Cast<IActivityStateInterface>(Var);
		if (!Actor)
		{
			continue;
		}

		if (Actor != CDO)
		{
			TArray<FActivityState>& TmpState = Actor->GetStateMachineInfo();
			for (int32 i = 0; i < TmpState.Num(); i++)
			{
				//子类再派生的，不允许再修改状态机
				if (!CDOState.IsValidIndex(i) || !CDOState[i].StateName.IsEqual(TmpState[i].StateName))
				{
					continue;
				}
				//拷贝所有自动生成的东西，其他编辑器操作部分不需要拷贝
				CopyAutoStatePropetyToInstance(CDOState[i], TmpState[i], Results);

			}
		}
	}

}

void FActivityBaseActorBlueprintCompilerContext::CopyAutoStatePropetyToInstance(FActivityState& Template, FActivityState& Instance, FCompilerResultsLog& Results)
{
	Instance.StateEnterFunctionName = Template.StateEnterFunctionName;
	Instance.StateLeaveFunctionName = Template.StateLeaveFunctionName;
	Instance.StateIndex = Template.StateIndex;
	if (Template.SequenceType == ESequenceBindingType::GenerateActorSequence)
	{
		Instance.StateSequenceName = Template.StateSequenceName;
	}

	TArray<FActivityLink>& TemlateLink = Template.LinkArray;
	TArray<FActivityLink>& InstanceLink = Instance.LinkArray;

	for (int32 i = 0; i < InstanceLink.Num(); i++)
	{
		if (!TemlateLink.IsValidIndex(i))
		{
			continue;
		}
		//子类再派生的，不允许再修改状态机
// 		if (!TemlateLink.IsValidIndex(i) || !TemlateLink[i].LinkConditionFunctionName.IsEqual(InstanceLink[i].LinkConditionFunctionName) || !TemlateLink[i].LinkStateName.IsEqual(InstanceLink[i].LinkStateName))
// 		{
// 			Results.Error(*FString::Printf(TEXT("ActivityBaseActor ReAssignPropertyToInstance  ChildClass State %s Link %s Has Modify,Not Allow Modify In ChildClass "), *(Instance.StateName.ToString()), *(InstanceLink[i].LinkName.ToString())));
// 		}
		InstanceLink[i].LinkStateIndex = TemlateLink[i].LinkStateIndex;
		InstanceLink[i].LinkName = TemlateLink[i].LinkName;
	}
}

bool FActivityBaseActorBlueprintCompilerContext::CheckParentClassHaveSameNameFunction(FName FunctionName)
{
	UClass* ParentClass = Blueprint->ParentClass;
	if (ParentClass)
	{
		return	IsValid(ParentClass->FindFunctionByName(FunctionName)) ;
	}

	return false;
}

bool FActivityBaseActorBlueprintCompilerContext::CheckHaveNodeInHierarchyClass(FName NodeName)
{
	TArray<UBlueprint*> Blueprints;

	Blueprint->GetBlueprintHierarchyFromClass(Blueprint->SkeletonGeneratedClass, Blueprints);
	for (UBlueprint* Var : Blueprints)
	{
		if (!Var)
		{
			continue;;
		}

		USimpleConstructionScript* SCS = Var->SimpleConstructionScript;
		if (USCS_Node* Node = SCS->FindSCSNode(NodeName))
		{
			return true;
		}

	}

	return false;
}

void FActivityBaseActorBlueprintCompilerContext::AddCustomEvent(UEdGraph* Graph, FName NodeName)
{
	UK2Node_CustomEvent* CustomEventNode = NewObject<UK2Node_CustomEvent>(Graph);

	CustomEventNode->CustomFunctionName = NodeName;

	// Ensure that it is editable
	CustomEventNode->bIsEditable = false;

	CustomEventNode->CreateNewGuid();
	CustomEventNode->PostPlacedNewNode();
	CustomEventNode->AllocateDefaultPins();

	const FVector2D NewPosition = Graph->GetGoodPlaceForNewNode();
	CustomEventNode->NodePosX = NewPosition.X;
	CustomEventNode->NodePosY = NewPosition.Y;

	Graph->AddNode(CustomEventNode, false, false);

	FBlueprintEditorUtils::ValidateBlueprintChildVariables(Blueprint, CustomEventNode->CustomFunctionName);
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
}

UK2Node_CustomEvent* FActivityBaseActorBlueprintCompilerContext::FindExistingNode(UEdGraph* Graph, FName NodeName)
{
	if (!Graph)
	{
		return nullptr;
	}

	UK2Node_CustomEvent* ExistingNode = NULL;

	for (int32 NodeIndex = 0; NodeIndex < Graph->Nodes.Num(); ++NodeIndex)
	{
		UK2Node_CustomEvent* Node = CastChecked<UK2Node_CustomEvent>(Graph->Nodes[NodeIndex]);
		if (Node->CustomFunctionName == NodeName)
		{
			ExistingNode = Node;
			break;
		}
	}

	return ExistingNode;
}
