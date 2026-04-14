// Fill out your copyright notice in the Description page of Project Settings.


#include "FakePossessComponent.h"
#include "PersistBaseComponent.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"
#include <Net/UnrealNetwork.h>
#if WITH_EDITOR
#include "PropertyEditorModule.h"
#endif

DEFINE_LOG_CATEGORY(LogActivityFakePossessComponent)

static int32 ActivityFakePossessErrorLogStack = 0;

FAutoConsoleVariableRef CVarShowActivityBaseActorLog(
	TEXT("p.ActivityFakePossessErrorLogStack"),
	ActivityFakePossessErrorLogStack,
	TEXT("0: Disable; 1: Enable"),
	ECVF_Default);


static float FakePossessNetUpFreq = 0.1f;
static FAutoConsoleVariableRef CVarFakePossessNetUpFreq(
	TEXT("net.FakePossessNetUpFreq"),
	FakePossessNetUpFreq,
	TEXT(".\n"),
	ECVF_Default
);

// CVars
namespace ActivityFakePossessCVars
{

#if UE_BUILD_DEVELOPMENT
	static int32 ShowActivityFakePossessLog = 1;
#else
	static int32 ShowActivityFakePossessLog = 0;
#endif

	FAutoConsoleVariableRef CVarShowActivityBaseActorLog(
		TEXT("p.ShowActivityFakePossessLog"),
		ShowActivityFakePossessLog,
		TEXT("0: Disable; 1: Enable"),
		ECVF_Default);

}

UFakePossessComponent::UFakePossessComponent()
{
	SetIsReplicatedByDefault(true);

	SubInstanceSlotName = TEXT("Final");

	bSetOwnerToPC = true;
}

void UFakePossessComponent::BeginPlay()
{
	Super::BeginPlay();

	InitFakePossessContainer();

	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &UFakePossessComponent::ForceOnRepPossesser);
}

void UFakePossessComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UFakePossessComponent, CurrentPossessCharacter);
}

void UFakePossessComponent::InitFakePossessContainer()
{
	if (!FakepossessCore)
	{
		FakepossessCore = NewObject<UActivityFakePossessCore>(this);
		check(FakepossessCore);
		FRegistPossessValue Value = FRegistPossessValue(DisablePawnState, RejectPawnState, CantPossessState);
		FakepossessCore->Init(Value);
		FakepossessCore->PossessHook.BindUObject(this, &UFakePossessComponent::OnPossessAction);
		FakepossessCore->UnpossessHook.BindUObject(this, &UFakePossessComponent::OnUnpossessAction);
	}
}

void UFakePossessComponent::QuitPossess(AController* PC, EUnPossessReason Reason /*= EUnPossessReason::Finished*/)
{
	if (!bIsAttachPossess)
	{
		FakeUnPossess(Reason);
	}
	else
	{
		FakeUnPossessWithDettach(Reason);
	}
}

void UFakePossessComponent::QuitPossessWithDetach(AController* PC, EUnPossessReason Reason /*= EUnPossessReason::Finished*/)
{
	if (HasAuthority())
	{
		QuitPossess(PC, Reason);
	}
	else
	{
		AMyCharacter* Pre = CurrentPossessCharacter;
		CurrentPossessCharacter = nullptr;
		OnRep_Possesser(Pre);
	}
}

void UFakePossessComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	FakeUnPossessWithDettach();

	if (FakepossessCore)
	{
		FakepossessCore->UnInit();
		FakepossessCore = nullptr;
	}
}

bool UFakePossessComponent::FakePossess(AController* PC)
{
	AActor* Owner = GetOwner();
	if (!HasAuthority())
	{
		return false;
	}

	if (!PC)
	{
		return false;
	}

	if (!Owner)
	{
		return false;
	}

	AMyCharacter* Character = PC->GetPawn<AMyCharacter>();
	if (!Character)
	{
		return false;
	}

	if (!CanBePossess(Character))
	{
		return false;
	}

	InitFakePossessContainer();

	if (FakepossessCore)
	{
		if (!FakepossessCore->FakePossess(PC))
		{
			return false;
		}
	}
	return true;
}

void UFakePossessComponent::FakeUnPossess(EUnPossessReason Reason /*= EUnPossessReason::Finished*/)
{
	AActor* Owner = GetOwner();
	if (!HasAuthority())
	{
		return;
	}

	if (!CurrentPossessCharacter)
	{
		return;
	}

	if (bUnpossessing)
	{
		return;
	}

	if (!Owner)
	{
		return;
	}

	bUnpossessing = true;

	if (FakepossessCore)
	{
		FakepossessCore->FakeUnPossess(Reason);
	}

	bUnpossessing = false;
}

bool UFakePossessComponent::FakePossessWithAttach(AController* PC, USceneComponent* AttachScene, FName SocketName, bool bMulticastToClient)
{
	if (!PC)
	{
		return false;
	}

	AMyCharacter* Character = PC->GetPawn<AMyCharacter>();
	if (!Character)
	{
		return false;
	}

	if (!CanBePossess(Character))
	{
		return false;
	}

	if (!FakepossessCore)
	{
		if (ActivityFakePossessCVars::ShowActivityFakePossessLog)
		{
			UE_LOG(LogActivityFakePossessComponent, Log, TEXT("---ActivityFakePossessComponent:FakePossessWithAttach Possess failed FakepossessCore not init"));
		}
		return false;
	}
	TWeakObjectPtr<USceneComponent> WeakAttachScene(AttachScene);
	if (FakePossess(PC))
	{
		FakepossessCore->PossessHookAttach.Unbind();
		return true;
	}
	else
	{
		if (ActivityFakePossessCVars::ShowActivityFakePossessLog)
		{
			UE_LOG(LogActivityFakePossessComponent, Log, TEXT("---ActivityFakePossessComponent:FakePossessWithAttach Possess failed"));
		}
	}
	FakepossessCore->PossessHookAttach.Unbind();
	return false;
}

void UFakePossessComponent::FakeUnPossessWithDettach(EUnPossessReason Reason /*= EUnPossessReason::Finished*/)
{
	if (bUnpossessing)
	{
		return;
	}
	if (!FakepossessCore)
	{
		if (ActivityFakePossessCVars::ShowActivityFakePossessLog)
		{
			UE_LOG(LogActivityFakePossessComponent, Log, TEXT("---ActivityFakePossessComponent:FakeUnPossessWithDettach Possess failed FakepossessCore not init"));
		}
		return;
	}
	if (HasAuthority() && CurrentPossessCharacter)
	{
		if (ActivityFakePossessCVars::ShowActivityFakePossessLog)
		{
			UE_LOG(LogActivityFakePossessComponent, Log, TEXT("---ActivityFakePossessComponent:FakeUnPossessWithDeAttach "));
		}
		FakeUnPossess(Reason);
		FakepossessCore->UnpossessHookDetach.Unbind();
	}
}

void UFakePossessComponent::SetDoNotSwitchWeaponWhenRecover(bool Setup)
{
	if (FakepossessCore)
	{
		FakepossessCore->SetDoNotSwitchWeaponWhenRecover(Setup);
	}
}

bool UFakePossessComponent::CanBePossess(AMyCharacter* Character)
{
	if (Character)
	{
		if (FakepossessCore && !FakepossessCore->CanBePossess(Character))
		{
			return false;
		}

		if (!Character->StateComponent->CanEnterState(EPawnState::Interacting))
		{
			return false;
		}
	}

	return CurrentPossessCharacter == nullptr;
}

bool UFakePossessComponent::HasAuthority()
{
	AActor* Owner = GetOwner();

	//不复制的也算主端逻辑
	if (!Owner || !Owner->IsValidLowLevelFast() || !(Owner->HasAuthority() || Owner->GetLocalRole() == ROLE_None))
	{
		return false;
	}

	return true;
}

void UFakePossessComponent::RequestReject_Implementation(AMyCharacter* Character)
{
	if (CurrentPossessCharacter == Character)
	{

		FakeUnPossess(EUnPossessReason::Interrupt);
	}
}

bool UFakePossessComponent::RequestReject_Validate(AMyCharacter* Character)
{
	return true;
}

void UFakePossessComponent::OnRep_Possesser(AMyCharacter* PrePossesser)
{
	AActor* Owner = GetOwner();
	check(Owner);
	if (PrePossesser)
	{
		//SetUpSubAnimInstance(PrePossesser, false);
		AMyPlayerController* PC = Cast<AMyPlayerController>(PrePossesser->GetController());
		if (ActivityFakePossessCVars::ShowActivityFakePossessLog)
		{
			UE_LOG(LogActivityFakePossessComponent, Log, TEXT("---ActivityFakePossessComponent:OnRep_Possesser PrePossesser Owner %s,"), PrePossesser->GetOwner() ? TEXT("True") : TEXT("Null"));
		}
		if (PreUnPossess.IsBound())
		{
			PreUnPossess.Broadcast(PrePossesser);
		}
		if (PC && PC->IsLocalController())
		{
			if (OnUnPossess.IsBound())
			{
				OnUnPossess.Broadcast(PC);
			}

			Owner->DisableInput(PC);
		}
	}

	OnRepCurrentPossesser.Broadcast(CurrentPossessCharacter);

	if (CurrentPossessCharacter)
	{
		AMyPlayerController* PC = Cast<AMyPlayerController>(CurrentPossessCharacter->GetController());
		if (ActivityFakePossessCVars::ShowActivityFakePossessLog)
		{
			UE_LOG(LogActivityFakePossessComponent, Log, TEXT("---ActivityFakePossessComponent:OnRep_Possesser CurrentPossessCharacter Owner %s,"), CurrentPossessCharacter->GetOwner() ? TEXT("True") : TEXT("Null"));
			UE_LOG(LogActivityFakePossessComponent, Log, TEXT("---ActivityFakePossessComponent:OnRep_Possesser CurrentPossessCharacter Is Local Controller %s,"), PC ? (PC->IsLocalController() ? TEXT("True") : TEXT("False")) : TEXT("Null"));
		}
		if (PC && PC->IsLocalController())
		{
			if (OnPossess.IsBound())
			{
				OnPossess.Broadcast(PC);
			}

			Owner->EnableInput(PC);
		}
	}
}

void UFakePossessComponent::OnPossessAction(AController* PC)
{
	AActor* Owner = GetOwner();
	if (!HasAuthority())
	{
		return;
	}

	if (!PC)
	{
		return;
	}

	if (!Owner)
	{
		return;
	}

	AMyCharacter* Character = PC->GetPawn<AMyCharacter>();
	if (!Character)
	{
		return;
	}

	CurrentPossessCharacter = Character;

	if (CurrentPossessCharacter)
	{
		CurrentPossessCharacter->StateComponent->EnterState(EPawnState::Interacting);
		if (bSetOwnerToPC)
		{
			Owner->SetOwner(PC);
		}

		AMyPlayerController* PlayerController = Cast<AMyPlayerController>(PC);

		if (PlayerController && OnPossess.IsBound())
		{
			OnPossess.Broadcast(PlayerController);
		}

		if (PC && OnPossessIncludingAI.IsBound())
		{
			OnPossessIncludingAI.Broadcast(PC);
		}

		Owner->ForceNetUpdate();

		if (CurrentPossessCharacter)
		{
			CurrentPossessCharacter->ForceNetRelevant();
		}
	}
}

void UFakePossessComponent::OnUnpossessAction(EUnPossessReason Reason)
{
	AActor* Owner = GetOwner();
	if (!HasAuthority())
	{
		return;
	}

	if (!Owner)
	{
		return;
	}

	if (!CurrentPossessCharacter)
	{
		return;
	}

	AMyPlayerController* PC = Cast<AMyPlayerController>(CurrentPossessCharacter->GetController());

	if (bSetOwnerToPC)
	{
		Owner->SetOwner(nullptr);
	}

	if (CurrentPossessCharacter)
	{
		CurrentPossessCharacter->StateComponent->LeaveState(EPawnState::Interacting);

		CurrentPossessCharacter->ForceNetRelevant();
	}

	if (OnUnPossess.IsBound())
	{
		OnUnPossess.Broadcast(PC);
	}
	if (OnUnPossessWithReason.IsBound())
	{
		OnUnPossessWithReason.Broadcast(PC, Reason);
	}

	if (OnUnPossessIncludingAI.IsBound())
	{
		AController* Controller = CurrentPossessCharacter->GetController();
		if (Controller)
		{
			OnUnPossessIncludingAI.Broadcast(Controller, Reason);
		}
	}


	CurrentPossessCharacter = nullptr;
}

#if WITH_EDITOR
void UFakePossessComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (DisablePawnState.Contains(EPawnState::Dying) || DisablePawnState.Contains(EPawnState::Dead))
	{
		if (!IsRunningCommandlet())
		{
			FPlatformMisc::MessageBoxExt(EAppMsgType::Type::Ok, *FString::Printf(TEXT("UFakePossessComponent from %s\n wants to disable Dying or Dead state"), *GetFullName()), TEXT("Configuration Error"));
		}
	}
}

void UFakePossessComponent::RefreshPawnStateSettingProperties(const FRegistPossessValue& SelectedValue)
{
	DisablePawnState = SelectedValue.DisablePawnState;
	RejectPawnState = SelectedValue.RejectPawnState;
	CantPossessState = SelectedValue.CantPossessState;

	MarkPackageDirty();

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UpdatePropertyViews({ this });

	// 修改地图中的实例
	TArray<UObject*> ArchetypeInstances;
	GetArchetypeInstances(ArchetypeInstances);
	if (ArchetypeInstances.Num() > 0)
	{
		for (UObject* Instance : ArchetypeInstances)
		{
			UFakePossessComponent* Component = Cast<UFakePossessComponent>(Instance);
			if (IsValid(Component))
			{
				Component->DisablePawnState = SelectedValue.DisablePawnState;
				Component->RejectPawnState = SelectedValue.RejectPawnState;
				Component->CantPossessState = SelectedValue.CantPossessState;
			}
		}
	}
}

#endif