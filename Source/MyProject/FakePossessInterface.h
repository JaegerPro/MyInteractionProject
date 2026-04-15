// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnState.h"
#include "FakePossessInterface.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(LogActivityFakePossessCore, Log, All);


class AMyPlayerController;
class AMyCharacter;


UENUM(BlueprintType)
enum class EUnPossessReason : uint8
{
	None = 0 		UMETA(Hidden),
	Interrupt = 1          UMETA(DisplayName = "打断"),
	Finished = 2				UMETA(DisplayName = "正常结束"),
	MaxInvalid					UMETA(Hidden)
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFakePossesseIncludingAIDelegate, class AController*, PC);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFakeUnPossessIncludingAIDelegate, class AController*, PC, EUnPossessReason, Reason);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFakePossesserChangeDelegate, class AMyPlayerController*, PC);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFakeUnPossessDelegate, class AMyPlayerController*, PC, EUnPossessReason, Reason);
DECLARE_DELEGATE_OneParam(FFakePossessHookDelegate, class AController*);
DECLARE_DELEGATE_OneParam(FFakeUnPossessHookDelegate, EUnPossessReason);

USTRUCT(BlueprintType)
struct  FRegistPossessValue
{
	GENERATED_BODY()

	//possess时尝试进入的状态，进入失败则possess失败
	//当possess的时候会禁用这些状态
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (DisplayName = "禁用人物状态"))
	TArray<EPawnState> DisablePawnState;
	//当监听到这些pawnstate的时候会弹出
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (DisplayName = "打断交互的人物状态"))
	TArray<EPawnState> RejectPawnState;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "不能进入的人物状态"))
	TArray<EPawnState> CantPossessState;
};
USTRUCT(BlueprintType)
struct FFakePossessQueue_Node
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	AController* PC = nullptr;
	UPROPERTY(BlueprintReadWrite)
	bool bPossessOrUnPossess = true;
	UPROPERTY(BlueprintReadWrite)
	EUnPossessReason Reason = EUnPossessReason::Finished;
};

USTRUCT(BlueprintType)
struct FFakePossessQueue
{
	GENERATED_BODY()
public:
	FFakePossessQueue_Node Dequeue() { return PossessQueue.Pop(); };
	void Enqueue(const FFakePossessQueue_Node& Element) { PossessQueue.Insert(Element, 0); };
	void Enqueue(FFakePossessQueue_Node&& Element) { PossessQueue.Insert(Element, 0); };
	bool IsVaildQueue() { return PossessQueue.Num() > 0; };
private:
	UPROPERTY()
	TArray<FFakePossessQueue_Node> PossessQueue;
};

USTRUCT()
struct FFakePossessQueueLock
{
	GENERATED_BODY()
public:
	FFakePossessQueueLock() {};
	virtual ~FFakePossessQueueLock() {};

	void Lock() { LockList.AddZeroed(); };
	void UnLock()
	{
		if (IsLocked())
		{
			LockList.Pop();
		}
	};
	bool IsLocked() { return LockList.Num() > 0; };
private:
	TArray<bool> LockList;
};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFakePossessInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYPROJECT_API IFakePossessInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION()
	virtual void QuitPossess(AController* PC, EUnPossessReason Reason = EUnPossessReason::Finished) = 0;

	UFUNCTION()
	virtual void QuitPossessWithDetach(AController* PC, EUnPossessReason Reason = EUnPossessReason::Finished) = 0;
};
UCLASS(ClassGroup = (Custom))
class UActivityFakePossessCore : public UObject
{
	GENERATED_BODY()

public:
	UActivityFakePossessCore();

	UFUNCTION(BlueprintCallable)
	void Init(const FRegistPossessValue& Value);

	UFUNCTION(BlueprintCallable)
	virtual void UnInit();

	UFUNCTION(BlueprintCallable)
	bool FakePossess(AController* PC);

	UFUNCTION(BlueprintCallable)
	void FakeUnPossess(EUnPossessReason Reason = EUnPossessReason::Finished);

	UFUNCTION(BlueprintCallable)
	bool CanBePossess(AMyCharacter* Character);

	UFUNCTION(BlueprintCallable)
	bool IsPossessedBy(AMyCharacter* Character);

	UFUNCTION(BlueprintCallable)
	void	SetDoNotSwitchWeaponWhenRecover(bool Setup);

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

	UFUNCTION(BlueprintCallable)
	AMyCharacter* GetCurrentPossesser() { return CurrentPossessCharacter; };


	//用于解决递归问题，禁止外部使用
	FFakePossessHookDelegate PossessHook;
	FFakePossessHookDelegate PossessHookAttach;
	FFakeUnPossessHookDelegate UnpossessHook;
	FFakeUnPossessHookDelegate UnpossessHookDetach;
protected:
	//当possess的时候会禁用这些状态
	UPROPERTY(BlueprintReadWrite, meta = (DisplayName = "注册状态"))
	FRegistPossessValue PossessValue;

protected:
	UFUNCTION()
	bool FakePossess_Inner(AController* PC);

	UFUNCTION()
	void FakeUnpossessByOuter(EUnPossessReason Reason);

	UFUNCTION()
	void OnPawnStateEnter(EPawnState State);

	UFUNCTION()
	void LockQueuePossess();

	UFUNCTION()
	void UnlockQueuePossess();

	UFUNCTION()
	bool IsLockedQueuePossess();

private:
	UPROPERTY()
	FFakePossessQueue PossessQueue;
	UPROPERTY()
	FFakePossessQueueLock PossessQueueLock;
	bool bHandleFakePossess = false;

	bool bHandleFakeUnPossess = false;

	bool DoNotSwitchWeaponWhenRecover = false;

	UPROPERTY()
	AMyCharacter* CurrentPossessCharacter;

public:
	static TArray<EPawnState> DefaultDisablePawnState;
};
