// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FakePossessInterface.h"
#include "FakePossessComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogActivityFakePossessComponent, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFakeCurrentPossesserChangeDelegate, class AMyCharacter*, BS);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPreUnPossesseDelegate, class AMyCharacter*, BS);

UCLASS( ClassGroup=(Custom), Blueprintable, meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UFakePossessComponent : public UActorComponent, public IFakePossessInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFakePossessComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UFUNCTION()
	void InitFakePossessContainer();

	virtual void QuitPossess(AController* PC, EUnPossessReason Reason = EUnPossessReason::Finished) override;

	virtual void QuitPossessWithDetach(AController* PC, EUnPossessReason Reason = EUnPossessReason::Finished) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintCallable)
	bool FakePossess(AController* PC);

	UFUNCTION(BlueprintCallable)
	void FakeUnPossess(EUnPossessReason Reason = EUnPossessReason::Finished);

	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "bMulticastToClient"))
	bool FakePossessWithAttach(AController* PC, USceneComponent* AttachScene, FName SocketName, bool bMulticastToClient = false);

	UFUNCTION(BlueprintCallable)
	void FakeUnPossessWithDettach(EUnPossessReason Reason = EUnPossessReason::Finished);

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FPreUnPossesseDelegate PreUnPossess;


	UFUNCTION(BlueprintCallable)
	void	SetDoNotSwitchWeaponWhenRecover(bool Setup);

	UFUNCTION(BlueprintCallable)
	bool CanBePossess(AMyCharacter* Character);

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakePossesserChangeDelegate OnPossess;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakePossesserChangeDelegate OnUnPossess;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakeUnPossessDelegate OnUnPossessWithReason;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakePossesseIncludingAIDelegate OnPossessIncludingAI;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakeUnPossessIncludingAIDelegate OnUnPossessIncludingAI;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakeCurrentPossesserChangeDelegate OnRepCurrentPossesser;

	UFUNCTION(BlueprintCallable)
	AMyCharacter* GetCurrentPossesser() { return CurrentPossessCharacter; };

	UFUNCTION(BlueprintCallable)
	bool HasAuthority();

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Attach)
	float DetachSpareOffsetZ = 300.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Attach)
	int32 Iterations = 1;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = Attach)
	bool bDettachSetMovementMode = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Attach)
	bool bOnDettachedRecoverMovement = true;

	bool bIsAttachPossess = false;

protected:
	UPROPERTY(ReplicatedUsing = OnRep_Possesser)
	AMyCharacter* CurrentPossessCharacter;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "禁用人物状态"))
	TArray<EPawnState> DisablePawnState;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "打断交互的人物状态"))
	TArray<EPawnState> RejectPawnState;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "不能进入的人物状态"))
	TArray<EPawnState> CantPossessState;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	bool bAllowEditPawnStateProperty = true;
#endif

	UPROPERTY(BlueprintReadOnly, AdvancedDisplay, EditDefaultsOnly, meta = (DisplayName = "是否设置Owner"))
	bool bSetOwnerToPC;
	UPROPERTY(BlueprintReadOnly, AdvancedDisplay, EditDefaultsOnly, meta = (DisplayName = "结算后是否启用"))
	bool bOpenAfterResult = false;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName SubInstanceSlotName;
	UPROPERTY(BlueprintReadWrite, Transient)
	class UActivityFakePossessCore* FakepossessCore;

protected:
	bool bUnpossessing = false;

	UFUNCTION(BlueprintCallable, Server, reliable, WithValidation)
	void RequestReject(AMyCharacter* Character);

	void ForceOnRepPossesser() { OnRep_Possesser(nullptr); };

	UFUNCTION()
	void OnRep_Possesser(AMyCharacter* PrePossesser);

	UFUNCTION()
	void OnPossessAction(AController* PC);
	UFUNCTION()
	void OnUnpossessAction(EUnPossessReason Reason);
protected:
	UPROPERTY()
	bool bIsInitActionContainer = false;

#if WITH_EDITOR
public:
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

private:
	void RefreshPawnStateSettingProperties(const FRegistPossessValue& SelectedValue);
#endif
};
