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

	//ֻ�ܱ�һ����possess�����Ҫ���˽�����Ū���childactor����һ����Ļactor������
	/* UGC
	 * ��Ч��Χ��S
	 * ��һ��PlayerController�������Actor
	 * @param PC ��ÿ���Ȩ��PlayerController
	 */
	UFUNCTION(BlueprintCallable)
	bool FakePossess(AController* PC);

	/* UGC
	 * ��Ч��Χ��S
	 * ������Actor�ϵ�PC�Ŀ���Ȩ
	 * @param Reason �������Ȩ��ԭ��
	 */
	UFUNCTION(BlueprintCallable)
	void FakeUnPossess(EUnPossessReason Reason = EUnPossessReason::Finished);

	/* UGC
	 * ��Ч��Χ��S
	 * ��һ��PlayerController�������Actor��������ǰ���ƵĽ�ɫAttach�����Actor��
	 * @param PC ��ÿ���Ȩ��PlayerController
	 * @param AttachScene Attach�������
	 * @param SocketName Attach����Socket
	 */
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "bMulticastToClient"))
	bool FakePossessWithAttach(AController* PC, USceneComponent* AttachScene, FName SocketName, bool bMulticastToClient = false);

	/* UGC
	 * ��Ч��Χ��S
	 * ������Actor�ϵ�PC�Ŀ���Ȩ��������ɫ�����Actor��Detach
	 * @param Reason �������Ȩ��ԭ��
	 */
	UFUNCTION(BlueprintCallable)
	void FakeUnPossessWithDettach(EUnPossessReason Reason = EUnPossessReason::Finished);

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FPreUnPossesseDelegate PreUnPossess;


	UFUNCTION(BlueprintCallable)
	void	SetDoNotSwitchWeaponWhenRecover(bool Setup);

	/* UGC
	 * ��Ч��Χ��S
	 * ��ȡ�Ƿ���������Character���Ƶ�ǰActor
	 * @param Character	Ҫ����Character
	 */
	UFUNCTION(BlueprintCallable)
	bool CanBePossess(AMyCharacter* Character);

	/* UGC
	* ��ȡ����Ȩ�¼��¼�ί��
	* @param PC ��ȡ�����Actor����Ȩ��PC
	*/
	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakePossesserChangeDelegate OnPossess;

	/* UGC
	* �������Ȩ�¼�ί��
	* @param PC ������Actor����Ȩ��PC
	*/
	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FFakePossesserChangeDelegate OnUnPossess;

	/* UGC
	* �������Ȩ�¼�ί��
	* @param PC ������Actor����Ȩ��PC
	* @param Reason �������Ȩ��ԭ��
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
	//�Ƿ���possessʱ������attach
	bool bIsAttachPossess = false;

protected:
	UPROPERTY(ReplicatedUsing = OnRep_Possesser)
	AMyCharacter* CurrentPossessCharacter;

	//��possess��ʱ��������Щ״̬
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "��������״̬", EditCondition = "bAllowEditPawnStateProperty"))
	TArray<EPawnState> DisablePawnState;
	//����������Щpawnstate��ʱ��ᵯ��
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "��Ͻ���������״̬", EditCondition = "bAllowEditPawnStateProperty"))
	TArray<EPawnState> RejectPawnState;
	//��possess��ʱ��,ִ��һЩ����������߼�
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (DisplayName = "���ܽ��������״̬", EditCondition = "bAllowEditPawnStateProperty"))
	TArray<EPawnState> CantPossessState;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	bool bAllowEditPawnStateProperty = true;
#endif

	UPROPERTY(BlueprintReadOnly, AdvancedDisplay, EditDefaultsOnly, meta = (DisplayName = "�Ƿ�����Owner"))
	bool bSetOwnerToPC;
	UPROPERTY(BlueprintReadOnly, AdvancedDisplay, EditDefaultsOnly, meta = (DisplayName = "������Ƿ�����"))
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
