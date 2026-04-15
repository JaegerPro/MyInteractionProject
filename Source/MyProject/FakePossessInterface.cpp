// Fill out your copyright notice in the Description page of Project Settings.
#include "FakePossessInterface.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"

// Add default functionality here for any IFa functions that are not pure virtual.
// Fill out your copyright notice in the Description page of Project Settings.

DEFINE_LOG_CATEGORY(LogActivityFakePossessCore)

namespace ActivityFakePossessCoreCVars
{

#if UE_BUILD_DEVELOPMENT
	static int32 ShowActivityFakePossessLog = 1;
#else
	static int32 ShowActivityFakePossessLog = 0;
#endif

	FAutoConsoleVariableRef CVarShowActivityBaseActorLog(
		TEXT("p.ShowActivityFakePossessCoreLog"),
		ShowActivityFakePossessLog,
		TEXT("0: Disable; 1: Enable"),
		ECVF_Default);

	static int32 ActivityOpenFakePossessBanDieState = 1;

	FAutoConsoleVariableRef CVarOpenFakePossessBanDieState(
		TEXT("p.OpenFakePossessBanDieState"),
		ActivityOpenFakePossessBanDieState,
		TEXT("0: Disable; 1: Enable"),
		ECVF_Default);

}

static int32 ActivityOpenFakePossessReport = 1;

FAutoConsoleVariableRef CVarOpenFakePossessReport(
	TEXT("p.OpenFakePossessReport"),
	ActivityOpenFakePossessReport,
	TEXT("0: Disable; 1: Enable"),
	ECVF_Default);

UActivityFakePossessCore::UActivityFakePossessCore()
{

}

void UActivityFakePossessCore::Init(const FRegistPossessValue& Value)
{
	PossessValue = Value;
#if WITH_EDITOR
	if (PossessValue.DisablePawnState.Contains(EPawnState::Dying) || PossessValue.DisablePawnState.Contains(EPawnState::Dead))
	{
		if (!IsRunningCommandlet())
		{
			FPlatformMisc::MessageBoxExt(EAppMsgType::Type::Ok, *FString::Printf(TEXT("UActivityFakePossessComponent from %s\n wants to disable Dying or Dead state"), *GetFullName()), TEXT("Configuration Error"));
		}
	}
#endif

	if (ActivityFakePossessCoreCVars::ActivityOpenFakePossessBanDieState > 0)
	{
		PossessValue.DisablePawnState.Remove(EPawnState::Dying);
		PossessValue.DisablePawnState.Remove(EPawnState::Dead);
	}
}

void UActivityFakePossessCore::UnInit()
{

}

bool UActivityFakePossessCore::FakePossess(AController* PC)
{
	if (!PC)
	{
		return false;
	}

	if (bHandleFakeUnPossess)
	{
		return false;
	}

	AMyCharacter* Character =PC->GetPawn<AMyCharacter>();
	if (!Character)
	{
		return false;
	}

	FFakePossessQueue_Node NewPossess;
	NewPossess.PC = PC;
	NewPossess.bPossessOrUnPossess = true;
	PossessQueue.Enqueue(NewPossess);
	while (PossessQueue.IsVaildQueue())
	{
		FFakePossessQueue_Node CurPossess = PossessQueue.Dequeue();
		if (CurPossess.bPossessOrUnPossess)
		{
			LockQueuePossess();
			FakePossess_Inner(NewPossess.PC);
			UnlockQueuePossess();
		}
		else
		{
			FakeUnpossessByOuter(CurPossess.Reason);
		}
	}

	return IsPossessedBy(Character);
}

void UActivityFakePossessCore::FakeUnPossess(EUnPossessReason Reason /*= EUnPossessReason::Finished*/)
{
	if (!CurrentPossessCharacter)
	{
		return;
	}

	if (bHandleFakeUnPossess)
	{
		return;
	}

	if (IsLockedQueuePossess())
	{
		FFakePossessQueue_Node NewUnPossess;
		NewUnPossess.Reason = Reason;
		NewUnPossess.bPossessOrUnPossess = false;
		NewUnPossess.PC = CurrentPossessCharacter->GetController();
		PossessQueue.Enqueue(NewUnPossess);
		return;
	}

	bHandleFakeUnPossess = true;

	UnpossessHookDetach.ExecuteIfBound(Reason);

	if (CurrentPossessCharacter)
	{
		for (auto& Var : PossessValue.DisablePawnState)
		{
			CurrentPossessCharacter->StateComponent->SetStateDisabled(Var, false);
		}

		CurrentPossessCharacter->StateComponent->OnStateEnter.RemoveAll(this);

		AMyPlayerController* PC = CurrentPossessCharacter->GetController<AMyPlayerController>();

		if (OnUnPossess.IsBound())
		{
			OnUnPossess.Broadcast(PC);
		}
		if (OnUnPossessWithReason.IsBound())
		{
			OnUnPossessWithReason.Broadcast(PC, Reason);
		}

		AController* PCMayAI = CurrentPossessCharacter->GetController();
		if (PCMayAI && OnUnPossessIncludingAI.IsBound())
		{
			OnUnPossessIncludingAI.Broadcast(PCMayAI, Reason);
		}

		UnpossessHook.ExecuteIfBound(Reason);

		CurrentPossessCharacter = nullptr;
	}

	bHandleFakeUnPossess = false;
}

bool UActivityFakePossessCore::CanBePossess(AMyCharacter* Character)
{
	if (!Character)
	{
		return false;
	}

	if (bHandleFakeUnPossess)
	{
		if (ActivityFakePossessCoreCVars::ShowActivityFakePossessLog)
		{
			UE_LOG(LogActivityFakePossessCore, Error, TEXT("---UActivityFakePossessCore:CanBePossess Ret By bHandleFakeUnPossess %s"), *Character->GetFullName());
		}
		return false;
	}

	if (IsLockedQueuePossess())
	{
		if (ActivityFakePossessCoreCVars::ShowActivityFakePossessLog)
		{
			UE_LOG(LogActivityFakePossessCore, Error, TEXT("---UActivityFakePossessCore:CanBePossess Ret By Lock %s"), *Character->GetFullName());
		}
		return false;
	}


	for (auto& Var : PossessValue.CantPossessState)
	{
		//真正possess时做一遍合法检测
		if (Character->StateComponent->HasState(Var))
		{
			if (ActivityFakePossessCoreCVars::ShowActivityFakePossessLog)
			{
				UE_LOG(LogActivityFakePossessCore, Log, TEXT("---UActivityFakePossessCore:CanBePossess Ret By %s"), *UEnum::GetDisplayValueAsText(Var).ToString() );
			}
			return false;
		}
	}

	return true;
}

bool UActivityFakePossessCore::IsPossessedBy(AMyCharacter* Character)
{
	return Character && CurrentPossessCharacter == Character;
}

void UActivityFakePossessCore::SetDoNotSwitchWeaponWhenRecover(bool Setup)
{
	DoNotSwitchWeaponWhenRecover = Setup;
}

void UActivityFakePossessCore::LockQueuePossess()
{
	PossessQueueLock.Lock();
}

void UActivityFakePossessCore::UnlockQueuePossess()
{
	PossessQueueLock.UnLock();
}

bool UActivityFakePossessCore::IsLockedQueuePossess()
{
	return PossessQueueLock.IsLocked();
}

bool UActivityFakePossessCore::FakePossess_Inner(AController* PC)
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

	bHandleFakePossess = true;

	CurrentPossessCharacter = Character;

	if (!CurrentPossessCharacter)
	{
		bHandleFakePossess = false;
		return false;
	}

	if (!CurrentPossessCharacter)
	{
		bHandleFakePossess = false;
		return false;
	}

	if (CurrentPossessCharacter)
	{
		CurrentPossessCharacter->StateComponent->OnStateEnter.AddDynamic(this, &UActivityFakePossessCore::OnPawnStateEnter);

		for (auto& Var : PossessValue.DisablePawnState)
		{
			CurrentPossessCharacter->StateComponent->SetStateDisabled(Var, true);
		}


		if (OnPossess.IsBound())
		{
			if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(PC))
			{
				OnPossess.Broadcast(PlayerController);
			}
		}

		if (OnPossessIncludingAI.IsBound())
		{
			OnPossessIncludingAI.Broadcast(PC);
		}

		PossessHook.ExecuteIfBound(PC);
		PossessHookAttach.ExecuteIfBound(PC);
	}

	bHandleFakePossess = false;
	return true;
}

void UActivityFakePossessCore::FakeUnpossessByOuter(EUnPossessReason Reason)
{
	if (IFakePossessInterface* PossessInterface = Cast<IFakePossessInterface>(GetOuter()))
	{
		AController* PC = CurrentPossessCharacter->GetController();
		PossessInterface->QuitPossess(PC, Reason);
	}
	else
	{
		FakeUnPossess(Reason);
	}
}

void UActivityFakePossessCore::OnPawnStateEnter(EPawnState State)
{
	if (PossessValue.RejectPawnState.Contains(State))
	{
		if (ActivityFakePossessCoreCVars::ShowActivityFakePossessLog)
		{
			UE_LOG(LogActivityFakePossessCore, Log, TEXT("---UActivityFakePossessCore::OnPawnStateEnter  RejectPawnState "));
		}

		FakeUnpossessByOuter(EUnPossessReason::Interrupt);
	}
}
