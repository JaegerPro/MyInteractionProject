// Fill out your copyright notice in the Description page of Project Settings.


#include "PersistEffectWithState.h"
#include <Net/UnrealNetwork.h>
void UPersistEffectWithState::OnApply(AActor* Character)
{
	EnsureStateInfoInit();
	Super::OnApply(Character);

	if (CurrentIndex.StateIndex == NullStateIndex)
	{
		EnterState(FindEntry(), 0.0f, false);
		if (CurrentIndex.StateIndex == -1)
		{
			return;
		}
	}
}
void UPersistEffectWithState::OnUnApply(AActor* Character)
{
	Super::OnUnApply(Character);
	EnsureStateInfoInit();
	LeaveState(CurrentIndex.StateIndex);
}
void UPersistEffectWithState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPersistEffectWithState, CurrentIndex);
}
int32 UPersistEffectWithState::FindEntry()
{
	for (auto& Var : StateMachineInfo)
	{
		if (Var.bStateMachineEntry)
		{
			return Var.StateIndex;
		}
	}

#if !UE_EDITOR && !WITH_UGC_EDITOR
	//check(0)
#endif
	return -1;
}
void UPersistEffectWithState::EnterState(int32 Index, float EnterTime, bool bPause)
{
	if (Index == NullStateIndex || !StateMachineInfo.IsValidIndex(Index))
	{
#if !UE_EDITOR 
		FString MachineInfoStr = "";
		for (FActivityState& Info : StateMachineInfo)
		{
			MachineInfoStr.Append(Info.StateName.ToString());
		}
		UE_LOG(LogTemp, Log, TEXT("---UPersistEffectWithState:EnterStateError, Index[%d] CurrentSequence=[%s]"),
			Index, *MachineInfoStr);
		check(0)
#endif
			return;
	}

	if (HasAuthority())
	{
		CurrentIndex.StateIndex = Index;
		CurrentIndex.EnterTime = EnterTime;
		CurrentIndex.bPause = bPause;
	}

	LocalPreIndex = Index;

	if (Index >= StateMachineInfo.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("UPersistEffectWithState::ProcessEnterStateInternal Failed, Index is invalid."));
		return;
	}

	const FActivityState& StatInfo = StateMachineInfo[Index];

	ProcessEvent(StatInfo.StateEnterFunction, nullptr);

	UE_LOG(LogTemp, Log, TEXT("---UPersistEffectWithState:EnterState %s"), *GetCurrentStateName().ToString());
}
void UPersistEffectWithState::LeaveState(int32 Index)
{
	if (Index == NullStateIndex || !StateMachineInfo.IsValidIndex(Index))
	{
		//因为初始状态是NullState，所以不check
		return;
	}

	if (Index >= StateMachineInfo.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("UPersistEffectWithState::ProcessLeaveStateInternal Failed, Index is invalid."));
		return;
	}

	const FActivityState& StatInfo = StateMachineInfo[Index];

	ProcessEvent(StatInfo.StateLeaveFunction, nullptr);
}

FName UPersistEffectWithState::GetCurrentStateName()
{
	if (!StateMachineInfo.IsValidIndex(CurrentIndex.StateIndex))
	{
		return FName(TEXT("NullState"));
	}

	return StateMachineInfo[CurrentIndex.StateIndex].StateName;
}
void UPersistEffectWithState::JumpToState(FName StateName, float EnterTime /*= 0.0f*/, bool bPause /*= false*/)
{
	if (!HasAuthority())
	{
		return;
	}

	for (int32 i = 0; i < StateMachineInfo.Num(); i++)
	{
		if (StateMachineInfo[i].StateName.IsEqual(StateName))
		{
			LeaveState(CurrentIndex.StateIndex);
			EnterState(i, EnterTime, bPause);
			break;
		}
	}
}

FTransform UPersistEffectWithState::GetTransform_Interface()
{
	if (!GetNetOwnerActor())
	{
		return FTransform();
	}

	return GetNetOwnerActor()->GetActorTransform();
}
void UPersistEffectWithState::OnRep_CurrentStateIndexInfo(const FActivityStateRep& PreIndex)
{
	if (CurrentIndex.StateIndex == NullStateIndex)
	{
		return;
	}
	UE_LOG(LogTemp, Log, TEXT("---UPersistEffectWithState:OnRep_CurrentStateIndexInfo PreIndex[%d] CurrentIndex=[%d]"), PreIndex.StateIndex, CurrentIndex.StateIndex);
	LeaveState(LocalPreIndex);
	EnterState(CurrentIndex.StateIndex, CurrentIndex.EnterTime, CurrentIndex.bPause);
}
void UPersistEffectWithState::EnsureStateInfoInit()
{
	if (bInit)
	{
		return;
	}

	bInit = true;

	for (FActivityState& Var : StateMachineInfo)
	{
		if (Var.StateEnterFunctionName != NAME_None)
		{
			Var.StateEnterFunction = this->FindFunctionChecked(Var.StateEnterFunctionName);
		}
		if (Var.StateLeaveFunctionName != NAME_None)
		{
			Var.StateLeaveFunction = this->FindFunctionChecked(Var.StateLeaveFunctionName);
		}

	}

}
