// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyClickActorComponent.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlayerController : public APlayerController, public IClickActorPCInterface
{
	GENERATED_BODY()
private:
	UPROPERTY(ReplicatedUsing = OnRep_ClickInfo)
	TArray<FClick_ValidInfo_Rep> ClickRepInfo;

	UPROPERTY()
	TArray<FClick_ValidInfo_Rep> LocalClickRepInfo;

public:
	bool IsLocalController() const;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void AddRepValidInfo(UMyClickActorComponent* Compoent, FClick_ValidInfo& VaildInfo) override;
	virtual void RemoveRepValidInfo(UMyClickActorComponent* Compoent, FClick_ValidInfo& VaildInfo) override;
	virtual void HandleClearValidInfo(UMyClickActorComponent* Compoent) override;
	void PrintAllClickValidInfo();
	UFUNCTION(Server, Reliable, WithValidation)
	void ExcuteClientClickRequest(UMyClickActorComponent* Compoent, int32 ID);
public:
	UFUNCTION()
	void OnRep_ClickInfo();
};
