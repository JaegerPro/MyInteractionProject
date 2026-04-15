// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PersistEffect.h"
#include "ActivityStateInterface.h"
#include "PersistEffectWithState.generated.h"

#define  NullStateIndex 999
/**
 * 
 */
UCLASS()
class MYPROJECT_API UPersistEffectWithState : public UPersistEffectBase, public IActivityStateInterface
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, Category = "SkillConfig")
	TArray<FActivityState> StateMachineInfo;
	UPROPERTY(ReplicatedUsing = OnRep_CurrentStateIndexInfo)
	FActivityStateRep CurrentIndex;
	int32 LocalPreIndex = NullStateIndex;
	bool bInit = false;
private:
	int32 FindEntry();

	//客户端不保证所有状态都会执行，但保证enter和leave匹配，DS所有状态流的Enter和Leave保证都会执行
	void EnterState(int32 Index, float EnterTime, bool bPause);

	void LeaveState(int32 Index);
	void EnsureStateInfoInit();
	UFUNCTION()
	virtual	void OnRep_CurrentStateIndexInfo(const FActivityStateRep& PreIndex);
public:
	virtual void OnApply(AActor* Character) override;
	virtual void OnUnApply(AActor* Character) override;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual int32 GetCurrentStateIndex() override { return CurrentIndex.StateIndex; }
	TArray<FActivityState>& GetStateMachineInfo() { return StateMachineInfo; }
	virtual FTransform GetTransform_Interface() override;
	UFUNCTION(BlueprintCallable)
	FName GetCurrentStateName();
	UFUNCTION(BlueprintCallable)
	virtual void JumpToState(FName StateName, float EnterTime = 0.0f, bool bPause = false);
	FActivityChangeState OnPersistEffectChangeState;
	FActivityChangeState& GetChangeStateDelegate() { return OnPersistEffectChangeState; }

};
