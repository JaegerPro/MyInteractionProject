// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PawnStateComponent.h"
#include "PersistBaseComponent.h"
#include "AbilitySystemInterface.h"
#include "GAS/GASLearnAttributeSet.h"
#include "MyCharacter.generated.h"


UCLASS()
class MYPROJECT_API AMyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPawnStateComponent* StateComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPersistBaseComponent* PersistComponent;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// 服务器：PossessedBy 时初始化 ASC
	virtual void PossessedBy(AController* NewController) override;
	// 客户端：PlayerState 同步过来时初始化 ASC（本课暂时用 Character 自己持有，后面会重构）
	virtual void OnRep_PlayerState() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UGASLearnAttributeSet> AttributeSet;
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Init")
	TSubclassOf<class UGameplayEffect> DefaultAttributesEffect;
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Init")
	TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input")
	TObjectPtr<class UInputAction> Ability1Action;
	UPROPERTY(EditDefaultsOnly, Category = "GAS|Input")
	TObjectPtr<class UInputAction> CancelAction;
	void OnAbility1Pressed();
	void OnAbility1Released();
	void OnCancelPressed();
	virtual void GiveDefaultAbilities();
	// 统一的初始化入口
	virtual void InitAbilitySystem();
	virtual void ApplyInitialEffects();
public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Jump() override;
	virtual void Landed(const FHitResult& Hit) override;
};
