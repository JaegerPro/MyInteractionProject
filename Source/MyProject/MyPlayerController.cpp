// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Net/UnrealNetwork.h"

void AMyPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyPlayerController, ClickRepInfo);
}

bool AMyPlayerController::IsLocalController() const
{
	const ENetMode NetMode = GetNetMode();

	if (NetMode == NM_Standalone)
	{
		// Not networked.
		return true;
	}

	if (NetMode == NM_Client && GetLocalRole() == ROLE_AutonomousProxy)
	{
		// Networked client in control.
		return true;
	}

	if (GetRemoteRole() != ROLE_AutonomousProxy && GetLocalRole() == ROLE_Authority)
	{
		// Local authority in control.
		return true;
	}

	return false;
}
void AMyPlayerController::AddRepValidInfo(UMyClickActorComponent* Compoent, FClick_ValidInfo& VaildInfo)
{
	if (!Compoent || !HasAuthority())
	{
		return;
	}

	bool bNeedRep = false;
	bool bAdd = false;
	for (FClick_ValidInfo_Rep& Var : ClickRepInfo)
	{
		if (Var.Component == Compoent)
		{
			if (!Var.PassInfo.Contains(VaildInfo.PassInfo))
			{
				Var.PassInfo.AddUnique(VaildInfo.PassInfo);
				bNeedRep = true;
			}
			bAdd = true;
			break;
		}
	}

	if (!bAdd)
	{
		FClick_ValidInfo_Rep Info;
		Info.OwingActor = Compoent->GetOwner();
		Info.PassInfo.Add(VaildInfo.PassInfo);
		Info.Component = Compoent;
		ClickRepInfo.Add(Info);
		bNeedRep = true;
	}
#if UE_BUILD_DEVELOPMENT
	if (bNeedRep)
	{
		for (int32 index = 0; index < ClickRepInfo.Num(); ++index)
		{
			UE_LOG(LogTemp, Log, TEXT("ASTExtraPlayerController::AddRepValidInfo [%d][%s]"), index, *ClickRepInfo[index].ToString());
		}
	}
#endif
}

void AMyPlayerController::RemoveRepValidInfo(UMyClickActorComponent* Compoent, FClick_ValidInfo& VaildInfo)
{
	if (!Compoent || !HasAuthority())
	{
		return;
	}

	bool bNeedRep = false;

	for (int32 i = ClickRepInfo.Num() - 1; i >= 0; i--)
	{
		FClick_ValidInfo_Rep& Var = ClickRepInfo[i];
		if (Var.Component == Compoent)
		{
			if (Var.PassInfo.Contains(VaildInfo.PassInfo))
			{
				Var.PassInfo.Remove(VaildInfo.PassInfo);
				bNeedRep = true;
				if (Var.PassInfo.Num() == 0)
				{
					ClickRepInfo.RemoveAt(i);
				}
			}
			break;
		}
	}

#if UE_BUILD_DEVELOPMENT
	if (bNeedRep)
	{
		for (int32 index = 0; index < ClickRepInfo.Num(); ++index)
		{
			UE_LOG(LogTemp, Log, TEXT("ASTExtraPlayerController::RemoveRepValidInfo [%d][%s]"), index, *ClickRepInfo[index].ToString());
		}
	}
#endif
}

void AMyPlayerController::HandleClearValidInfo(UMyClickActorComponent* Compoent)
{
	if (!Compoent || !HasAuthority())
	{
		return;
	}

	for (int32 i = ClickRepInfo.Num() - 1; i >= 0; i--)
	{
		FClick_ValidInfo_Rep& Var = ClickRepInfo[i];
		if (Var.Component == Compoent)
		{
			ClickRepInfo.RemoveAt(i);
			break;
		}
	}
}

void AMyPlayerController::PrintAllClickValidInfo()
{
#if UE_BUILD_DEVELOPMENT
	for (int32 Localindex = 0; Localindex < LocalClickRepInfo.Num(); ++Localindex)
	{
		UE_LOG(LogTemp, Log, TEXT("ASTExtraPlayerController::PrintAllClickValidInfo LocalClickRepInfo [%d][%s]"), Localindex, *LocalClickRepInfo[Localindex].ToString());
	}
	for (int32 index = 0; index < ClickRepInfo.Num(); ++index)
	{
		UE_LOG(LogTemp, Log, TEXT("ASTExtraPlayerController::PrintAllClickValidInfo [%d][%s]"), index, *ClickRepInfo[index].ToString());
	}
#endif
}

bool AMyPlayerController::ExcuteClientClickRequest_Validate(UMyClickActorComponent* Compoent, int32 ID)
{
	return true;
}

void AMyPlayerController::ExcuteClientClickRequest_Implementation(UMyClickActorComponent* Compoent, int32 ID)
{
	if (Compoent)
	{
		Compoent->ExcuteClientClick(this, ID, true);
	}
}

void AMyPlayerController::OnRep_ClickInfo()
{
#if UE_BUILD_DEVELOPMENT
	UE_LOG(LogTemp, Log, TEXT("ASTExtraPlayerController::OnRep_ClickInfo NetMode:%d UClickActorComponentBase"),GetNetMode());
	PrintAllClickValidInfo();
#endif

	for (FClick_ValidInfo_Rep& Var : LocalClickRepInfo)
	{
		bool bContains = false;
		for (FClick_ValidInfo_Rep& New : ClickRepInfo)
		{
			if (New.Component == Var.Component)
			{
				bContains = true;
				break;
			}
		}

		if (!bContains)
		{
			Var.HandleClear(this);
		}
	}


	for (FClick_ValidInfo_Rep& Var : ClickRepInfo)
	{
		bool bContains = false;
		for (FClick_ValidInfo_Rep& Tmp : LocalClickRepInfo)
		{
			if (Tmp.Component == Var.Component)
			{
				bContains = true;
				Var.HandleChange(this, Tmp.PassInfo);
				break;
			}
		}

		if (!bContains)
		{
			TArray<FClick_PassInfo> tmp;
			Var.HandleChange(this, tmp);
		}
	}

	LocalClickRepInfo = ClickRepInfo;
}