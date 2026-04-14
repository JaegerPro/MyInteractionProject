// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActivityStateInterface.generated.h"

#define  NullStateIndex 999
UENUM(BlueprintType)
enum class ESequenceBindingType : uint8
{
	None,
	GenerateActorSequence,
	BindingActorSequence,
	BindingLevelSequence,
	BindingSoftLevelSequence,
	GenerateSkillSequence
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActivityChangeState, const FName&, LeaveState, const FName&, EnterState);
USTRUCT(BlueprintType)
struct FActivityLink
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	FName LinkName;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName LinkConditionFunctionName;

	//�Ƿ������ȡ��
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bNotCondition = false;

	UPROPERTY(Transient)
	UFunction* LinkConditionFunction = nullptr;

	UPROPERTY()
	int32  LinkStateIndex;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName  LinkStateName;
};

USTRUCT(BlueprintType)
struct FActivityState
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName StateName;

	UPROPERTY(Transient)
	UFunction* StateEnterFunction = nullptr;

	UPROPERTY()
	FName StateEnterFunctionName;

	UPROPERTY(Transient)
	UFunction* StateLeaveFunction = nullptr;

	UPROPERTY()
	FName StateLeaveFunctionName;

	UPROPERTY()
	int32  StateIndex;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TArray<FActivityLink> LinkArray;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bStateMachineEntry = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	ESequenceBindingType SequenceType = ESequenceBindingType::None;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int32 TlogStatisticsID = -1;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName StateSequenceName;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	class ULevelSequence* LevelSequence = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General", meta = (AllowedClasses = "/Script/Engine.LevelSequence"))
	FSoftObjectPath LevelSequencePath;

	//-1��������ѭ����0�����һ�Σ�1���������
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General", meta = (UIMin = -1, DisplayName = "Loop"))
	int32 LoopCount = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General", meta = (Units = Multiplier))
	float PlayRate = 1.0f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (EditCondition = "LoopCount==0"))
	bool ShouldPauseAtLastFrame = false;

	UPROPERTY(Transient)
	class UActorSequenceComponent* StateSequence = nullptr;

};

USTRUCT()
struct FActivityStateRep
{
	GENERATED_BODY()

	UPROPERTY()
	int32 StateIndex = NullStateIndex;

	//һ����ҵ�����ֵ��һ����ʱ����������<0.5 (gamestate��һ�θ���ʱ����ʱ),��entertimeΪsequence����ת����
	UPROPERTY()
	float EnterTime = 0;

	UPROPERTY()
	float ServeEnterSequenceTime = 0;

	UPROPERTY()
	bool bPause = false;

	UPROPERTY()
	int32 PredictID = 0;

	bool operator==(const FActivityStateRep b)
	{
		return this->StateIndex == b.StateIndex && this->bPause == b.bPause && this->EnterTime == b.EnterTime && this->ServeEnterSequenceTime == b.ServeEnterSequenceTime;
	}
};
// This class does not need to be modified.
UINTERFACE()
class UActivityStateInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYPROJECT_API IActivityStateInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual int32 GetCurrentStateIndex() { return -1; };

	virtual TArray<FActivityState>& GetStateMachineInfo() = 0;

	virtual FTransform GetTransform_Interface() = 0;

	virtual TArray<FString> GetSequenceTag_Interface() {
		return TArray<FString>();
	};

	virtual void RecoverClientStateReplayRelevant_Interface() {};

	virtual FActivityChangeState& GetChangeStateDelegate() = 0;

	virtual void OverrideCurrentState(const FActivityStateRep& Rep) {};

	virtual void RestoreCurrentState() {};
};


