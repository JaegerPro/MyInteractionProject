// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActivityActor.h"
#include <Net/UnrealNetwork.h>

// Sets default values
AMyActivityActor::AMyActivityActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void AMyActivityActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// 
	DOREPLIFETIME(AMyActivityActor, CurrentIndex);
	// 	DOREPLIFETIME(AActivityBaseActor, ServeEnterSequenceTime);
}
void AMyActivityActor::EnsureStateInfoInit()
{
	if (bInit)
	{
		return;
	}

	if (IsRunningDedicatedServer())
	{
		PrimaryActorTick.TickInterval = 2.0f;
	}

	bInit = true;
	UClass* Class = GetClass();
	check(Class);
	for (FActivityState& Var : StateMachineInfo)
	{
		Var.StateEnterFunction = this->FindFunctionChecked(Var.StateEnterFunctionName);
		Var.StateLeaveFunction = this->FindFunctionChecked(Var.StateLeaveFunctionName);
	}
}
void AMyActivityActor::EnterState(const FActivityStateRep& IndexInfo)
{
	int32 Index = IndexInfo.StateIndex;
	float EnterTime = IndexInfo.EnterTime;
	bool bPause = IndexInfo.bPause;
	float ServeEnterSequenceTime = IndexInfo.ServeEnterSequenceTime;

	if (Index == NullStateIndex || !StateMachineInfo.IsValidIndex(Index))
	{
		UE_LOG(LogTemp, Log, TEXT("---AActivityBaseActor:EnterState ActorName = [%s]"), *GetFullName());
		return;
	}
	const FActivityState& StatInfo = StateMachineInfo[Index];

	if (HasAuthority())
	{
		CurrentIndex.StateIndex = Index;
		CurrentIndex.EnterTime = EnterTime;
		CurrentIndex.bPause = bPause;

		ForceNetUpdate();
	}

	if (OnActivityActorChangeState.IsBound())
	{
		if (LocalPreIndex != NullStateIndex && StateMachineInfo.IsValidIndex(LocalPreIndex))
		{
			OnActivityActorChangeState.Broadcast(StateMachineInfo[LocalPreIndex].StateName, StatInfo.StateName);
		}
		else
		{
			OnActivityActorChangeState.Broadcast(TEXT(""), StatInfo.StateName);
		}
	}

	LocalPreIndex = Index;
	UE_LOG(LogTemp, Log, TEXT("---AActivityBaseActor:EnterState ActorName [%s], StateName[%s], EnterTime=[%f], ServeEnterSequenceTime=[%f]"), *GetFullName(), *StatInfo.StateName.ToString(), CurrentIndex.EnterTime, CurrentIndex.ServeEnterSequenceTime);

	if (StatInfo.StateEnterFunction)
	{
		ProcessEvent(StatInfo.StateEnterFunction, nullptr);
	}
}

void AMyActivityActor::EnterState(int32 Index, float EnterTime, bool bPause)
{
	FActivityStateRep Rep;
	Rep.StateIndex = Index;
	Rep.EnterTime = EnterTime;
	Rep.bPause = bPause;
	EnterState(Rep);
}

void AMyActivityActor::LeaveState(int32 Index)
{
	if (Index == NullStateIndex || !StateMachineInfo.IsValidIndex(Index))
	{
		//因为初始状态是NullState，所以不check
		return;
	}

	FName StateName = FName(TEXT("NullState"));
	if (StateMachineInfo.IsValidIndex(Index))
	{
		StateName = StateMachineInfo[Index].StateName;
	}

	//调整leave逻辑到切sequence前
	const FActivityState& StatInfo = StateMachineInfo[Index];
	if (StatInfo.StateLeaveFunction)
	{
		ProcessEvent(StatInfo.StateLeaveFunction, nullptr);
	}
}

void AMyActivityActor::OnRep_CurrentTransform()
{
}

void AMyActivityActor::OnRep_CurrentStateIndexInfo(const FActivityStateRep& PreCurrentIndex)
{

	UE_LOG(LogTemp, Log, TEXT("---AActivityBaseActor:OnRep_CurrentStateIndexInfo PreIndex[%d] CurrentIndex=[%d], EnterTime=[%f], Pause=[%d], ServeEnterSequenceTime=[%f]"), PreCurrentIndex.StateIndex, CurrentIndex.StateIndex, CurrentIndex.EnterTime, (int32)CurrentIndex.bPause, CurrentIndex.ServeEnterSequenceTime);

	LeaveState(LocalPreIndex);
	EnterState(CurrentIndex);

}
// Called when the game starts or when spawned
void AMyActivityActor::BeginPlay()
{
	EnsureStateInfoInit();

	Super::BeginPlay();
	if (CurrentIndex.StateIndex == NullStateIndex )
	{
		EnterState(FindEntry(), 0.0f, false);
	}
}
int32 AMyActivityActor::FindEntry()
{
	for (auto& Var : StateMachineInfo)
	{
		if (Var.bStateMachineEntry)
		{
			return Var.StateIndex;
		}
	}
	return -1;
}
// Called every frame
void AMyActivityActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FTransform AMyActivityActor::GetTransform_Interface()
{
	return FTransform();
}

void AMyActivityActor::JumpToState(FName StateName, float EnterTime, bool bPause)
{
	if (!HasAuthority())
	{
		return;
	}
	EnsureStateInfoInit();
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

