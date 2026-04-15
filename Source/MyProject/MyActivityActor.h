// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActivityStateInterface.h"
#include "MyActivityActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActivityActor : public AActor, public IActivityStateInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActivityActor();
private:
	int32 LocalPreIndex = NullStateIndex;
	bool bInit = false;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Config")
	TArray<FActivityState> StateMachineInfo;
	UPROPERTY(ReplicatedUsing = OnRep_CurrentTransform)
	FTransform CurrentTransform;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentStateIndexInfo)
	FActivityStateRep CurrentIndex;
private:
	void EnsureStateInfoInit();
	void EnterState(const FActivityStateRep& IndexInfo);
	void EnterState(int32 Index, float EnterTime, bool bPause);

	void LeaveState(int32 Index);
	UFUNCTION()
	void OnRep_CurrentTransform();

	UFUNCTION()
	void OnRep_CurrentStateIndexInfo(const FActivityStateRep& PreIndex);
	int32 FindEntry();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual TArray<FActivityState>& GetStateMachineInfo() override { return StateMachineInfo; };

	virtual FTransform GetTransform_Interface() override;
	UPROPERTY(BlueprintAssignable)
	FActivityChangeState OnActivityActorChangeState;
	virtual FActivityChangeState& GetChangeStateDelegate() { return OnActivityActorChangeState; };

	virtual void RestoreCurrentState() {};
	UFUNCTION(BlueprintCallable)
	void JumpToState(FName StateName, float EnterTime = 0.0f, bool bPause = false);
};
