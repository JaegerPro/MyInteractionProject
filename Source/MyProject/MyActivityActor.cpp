// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActivityActor.h"
#include <Net/UnrealNetwork.h>
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include <GameFramework/GameState.h>

// Sets default values
AMyActivityActor::AMyActivityActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NetRelevantComponent = CreateDefaultSubobject<UCustomNetRelevantComponent>(TEXT("NetRelevantComponent"));
}
void AMyActivityActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// 
	DOREPLIFETIME(AMyActivityActor, CurrentIndex);
	// 	DOREPLIFETIME(AActivityBaseActor, ServeEnterSequenceTime);
}
bool AMyActivityActor::IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation) const
{
	// 设计选择：白名单优先，**完全替换** Super 的距离/Owner 等默认逻辑。
	// 原因：本 Actor 想表达的是"逻辑可见性"——只有交互参与者才该看到，
	// 不应再被距离剔除等默认规则推翻。如果将来需要"白名单 AND 距离"，
	// 把下一行改成: return Super::IsNetRelevantFor(...) && NetRelevancyComponent->IsViewerRelevant(RealViewer);
	if (NetRelevantComponent)
	{
		return NetRelevantComponent->IsViewerRelevant(RealViewer);
	}
	return Super::IsNetRelevantFor(RealViewer, ViewTarget, SrcLocation);
}
ULevelSequencePlayer* AMyActivityActor::GetLevelSequencePlayer()
{
	SequenceWrapper.Init(this);
	return SequenceWrapper.GetLevelSequencePlayer();
}
void AMyActivityActor::ChangeCurrentSequence(const FActivityState& StateInfo, bool bEnter)
{
	FString PreName = SequenceWrapper.GetCurrentName();
	SequenceWrapper.Stop();

	if (bEnter)
	{
		if (HasAuthority())
		{
			SequenceWrapper.ChangeSequence(Cast<ULevelSequence>(StateInfo.LevelSequencePath.TryLoad()));
		}
		else
		{
			UObject* SequenceAsset = StateInfo.LevelSequencePath.ResolveObject();
			if (SequenceAsset)
			{
				SequenceWrapper.ChangeSequence(Cast<ULevelSequence>(SequenceAsset));
			}
			else
			{
				FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
				PendingSequenceHandle = Streamable.RequestAsyncLoad(
					StateInfo.LevelSequencePath,
					FStreamableDelegate::CreateUObject(this, &AMyActivityActor::OnSequenceRequestBack, StateInfo.LevelSequencePath, StateInfo.StateName),
					FStreamableManager::AsyncLoadHighPriority);
			}
		}
	}
	else
	{
		SequenceWrapper.ChangeSequence();
	}


	FString CurrentName = SequenceWrapper.GetCurrentName();

	UE_LOG(LogTemp, Log, TEXT("---AActivityBaseActor:ChangeCurrentSequnce, PreSequence[%s] CurrentSequence=[%s]"),
			*PreName, *CurrentName);
}
void AMyActivityActor::AddBinding(const FMovieSceneObjectBindingID& Binding, AActor* Actor)
{
	SequenceWrapper.Init(this);
	SequenceWrapper.AddBinding(Binding, Actor);
}
void AMyActivityActor::RemoveBinding(const FMovieSceneObjectBindingID& Binding, AActor* Actor)
{
	SequenceWrapper.Init(this);
	SequenceWrapper.RemoveBinding(Binding, Actor);
}
FName AMyActivityActor::GetCurrentStateName()
{
	if (!StateMachineInfo.IsValidIndex(CurrentIndex.StateIndex))
	{
		return FName(TEXT("NullState"));
	}
	return StateMachineInfo[CurrentIndex.StateIndex].StateName;
}

void AMyActivityActor::OnSequenceRequestBack(FSoftObjectPath SequncePath, FName StateName)
{

	UE_LOG(LogTemp, Log, TEXT("---AActivityBaseActor:OnSequenceRequestBack CurrentSequence=[%s] "), *SequncePath.ToString());

	if (GetCurrentStateName() != StateName)
	{
		UE_LOG(LogTemp, Log, TEXT("---AActivityBaseActor:OnSequenceRequestBack GetCurrentStateName=[%s] != State [%s]"), *GetCurrentStateName().ToString(), *StateName.ToString());
		return;
	}

	SequenceWrapper.ChangeSequence(Cast<ULevelSequence>(SequncePath.ResolveObject()));
	FActivityStateRep StateRep = CurrentIndex;

	SequenceWrapper.StartPlay(StateRep.EnterTime);

}
float AMyActivityActor::GetTimeStamp()
{
	AGameState* GS = GetWorld() ? GetWorld()->GetGameState<AGameState>() : nullptr;
	if (GS)
	{
		return GS->GetServerWorldTimeSeconds();
	}
	else
	{
		//理论上这个调用都是在beginplay之后，如果没有gamestate，那么一定有问题
#if !UE_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("---AActivityBaseActor:GetTimeStamp, bNetStartup=[%d] Role=[%d] ActorFullName=[%s]"),
			(int32)bNetStartup, (int32)Role, *GetFullName());
		if (GetWorld() == nullptr || !GetWorld()->IsPlayingReplay())
		{
			ensure(false);
		}
#endif
	}

	return 0;
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
	SequenceWrapper.Init(this);
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

	if (Index == NullStateIndex || !StateMachineInfo.IsValidIndex(Index))
	{
		UE_LOG(LogTemp, Log, TEXT("---AActivityBaseActor:EnterState ActorName = [%s]"), *GetFullName());
		return;
	}
	const FActivityState& StateInfo = StateMachineInfo[Index];
	ChangeCurrentSequence(StateInfo, true);
	if (HasAuthority())
	{
		CurrentIndex.StateIndex = Index;
		CurrentIndex.EnterTime = IndexInfo.EnterTime;
		ForceNetUpdate();
	}

	if (OnActivityActorChangeState.IsBound())
	{
		if (LocalPreIndex != NullStateIndex && StateMachineInfo.IsValidIndex(LocalPreIndex))
		{
			OnActivityActorChangeState.Broadcast(StateMachineInfo[LocalPreIndex].StateName, StateInfo.StateName);
		}
		else
		{
			OnActivityActorChangeState.Broadcast(TEXT(""), StateInfo.StateName);
		}
	}

	LocalPreIndex = Index;
	UE_LOG(LogTemp, Log, TEXT("---AActivityBaseActor:EnterState ActorName [%s], StateName[%s]"), *GetFullName(), *StateInfo.StateName.ToString());

	SequenceWrapper.StartPlay(IndexInfo.EnterTime);
	if (StateInfo.StateEnterFunction)
	{
		ProcessEvent(StateInfo.StateEnterFunction, nullptr);
	}
}

void AMyActivityActor::EnterState(int32 Index, float EnterTime, bool bPause)
{
	FActivityStateRep Rep;
	Rep.StateIndex = Index;
	Rep.EnterTime = EnterTime;
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
	ChangeCurrentSequence(StateMachineInfo[Index], false);
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
	EnsureStateInfoInit();
	UE_LOG(LogTemp, Log, TEXT("---AActivityBaseActor:OnRep_CurrentStateIndexInfo PreIndex[%d] CurrentIndex=[%d]"), PreCurrentIndex.StateIndex, CurrentIndex.StateIndex);
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

