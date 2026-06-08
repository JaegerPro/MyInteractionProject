// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActivityStateInterface.h"
#include "MyProject/CustomActor/CustomNetRelevantComponent.h"
#include <LevelSequencePlayer.h>
#include "Anim/ActivitySequenceWrapper.h"
#include "Engine/StreamableManager.h"
#include "MyActivityActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActivityActor : public AActor, public IActivityStateInterface
{
	GENERATED_BODY()
	
private:
	// 当前正在加载的 Sequence 句柄（可取消）
	TSharedPtr<FStreamableHandle> PendingSequenceHandle;
	int32 LocalPreIndex = NullStateIndex;
	bool bInit = false;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Config")
	TArray<FActivityState> StateMachineInfo;
	UPROPERTY(ReplicatedUsing = OnRep_CurrentTransform)
	FTransform CurrentTransform;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentStateIndexInfo)
	FActivityStateRep CurrentIndex;
	// 组件作为子对象由本 Actor 拥有。EditAnywhere 让蓝图实例可以看到（只是查看，配置走运行时接口）。
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NetRelevancy")
	TObjectPtr<UCustomNetRelevantComponent> NetRelevantComponent;
	UPROPERTY()
	FActivitySequenceWrapper SequenceWrapper;

private:
	void OnSequenceRequestBack(FSoftObjectPath SequncePath, FName StateName);
	float GetTimeStamp();
	void EnsureStateInfoInit();
	void EnterState(const FActivityStateRep& IndexInfo);
	void EnterState(int32 Index, float EnterTime, bool bPause);

	void LeaveState(int32 Index);
	UFUNCTION()
	void OnRep_CurrentTransform();

	UFUNCTION()
	void OnRep_CurrentStateIndexInfo(const FActivityStateRep& PreIndex);
	int32 FindEntry();
	void ChangeCurrentSequence(const FActivityState& StateInfo, bool bEnter);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Sets default values for this actor's properties
	AMyActivityActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	ULevelSequencePlayer* GetLevelSequencePlayer();
	virtual TArray<FActivityState>& GetStateMachineInfo() override { return StateMachineInfo; };
	UFUNCTION(BlueprintCallable)
	FName GetCurrentStateName();
	virtual FTransform GetTransform_Interface() override;
	UPROPERTY(BlueprintAssignable)
	FActivityChangeState OnActivityActorChangeState;
	virtual FActivityChangeState& GetChangeStateDelegate() { return OnActivityActorChangeState; };

	virtual void RestoreCurrentState() {};
	UFUNCTION(BlueprintCallable)
	void JumpToState(FName StateName, float EnterTime = 0.0f, bool bPause = false);
	virtual bool IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation) const override;

	UCustomNetRelevantComponent* GetNetRelevantComponent() const { return NetRelevantComponent; }

	UFUNCTION(BlueprintCallable)
	void AddBinding(const FMovieSceneObjectBindingID& Binding, AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void RemoveBinding(const FMovieSceneObjectBindingID& Binding, AActor* Actor);
};
