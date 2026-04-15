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

	//只能被一个人possess，如果要多人交互，弄多个childactor，用一个大的活动actor来管理
	/* UGC
	 * 生效范围：S
	 * 让一个PlayerController控制这个Actor
	 * @param PC 获得控制权的PlayerController
	 */
	UFUNCTION(BlueprintCallable)
	bool FakePossess(AController* PC);

	/* UGC
	 * 生效范围：S
	 * 解除这个Actor上的PC的控制权
	 * @param Reason 解除控制权的原因
	 */
	UFUNCTION(BlueprintCallable)
	void FakeUnPossess(EUnPossessReason Reason = EUnPossessReason::Finished);

	/* UGC
	 * 生效范围：S
	 * 让一个PlayerController控制这个Actor，并将当前控制的角色Attach到这个Actor上
	 * @param PC 获得控制权的PlayerController
	 * @param AttachScene Attach到的组件
	 * @param SocketName Attach到的Socket
	 */
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "bMulticastToClient"))
	bool FakePossessWithAttach(AController* PC, USceneComponent* AttachScene, FName SocketName, bool bMulticastToClient = false);

	/* UGC
	 * 生效范围：S
	 * 解除这个Actor上的PC的控制权，并将角色从这个Actor上Detach
	 * @param Reason 解除控制权的原因
	 */
	UFUNCTION(BlueprintCallable)
	void FakeUnPossessWithDettach(EUnPossessReason Reason = EUnPossessReason::Finished);

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FPreUnPossesseDelegate PreUnPossess;


	UFUNCTION(BlueprintCallable)
	void	SetDoNotSwitchWeaponWhenRecover(bool Setup);

	/* UGC
	 * 生效范围：S
	 * 获取是否可以由这个Character控制当前Actor
	 * @param Character	要检查的Character
	 */
	UFUNCTION(BlueprintCallable)
	bool CanBePossess(AMyCharacter* Character);

	/* UGC
	* 获取控制权事件事件委托
	* @param PC 获取到这个Actor控制权的PC
	*/
	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakePossesserChangeDelegate OnPossess;

	/* UGC
	* 解除控制权事件委托
	* @param PC 解除这个Actor控制权的PC
	*/
	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakePossesserChangeDelegate OnUnPossess;

	/* UGC
	* 解除控制权事件委托
	* @param PC 解除这个Actor控制权的PC
	* @param Reason 解除控制权的原因
	*/
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
	//是否在possess时进行了attach
	bool bIsAttachPossess = false;

protected:
	UPROPERTY(ReplicatedUsing = OnRep_Possesser)
	AMyCharacter* CurrentPossessCharacter;

	//当possess的时候会禁用这些状态
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "禁用人物状态", EditCondition = "bAllowEditPawnStateProperty"))
	TArray<EPawnState> DisablePawnState;
	//当监听到这些pawnstate的时候会弹出
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "打断交互的人物状态", EditCondition = "bAllowEditPawnStateProperty"))
	TArray<EPawnState> RejectPawnState;
	//当possess的时候,执行一些人物的清理逻辑
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "不能进入的人物状态", EditCondition = "bAllowEditPawnStateProperty"))
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
