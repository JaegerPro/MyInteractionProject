// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PersistEffect.generated.h"
class UPersistBaseComponent;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), Blueprintable)
class MYPROJECT_API UPersistEffectBase : public UObject
{
	GENERATED_BODY()
public:

protected:
	UPROPERTY(Replicated)
	UPersistBaseComponent* Owner;
	bool bHaveApplyed = false;
public:
	UPersistEffectBase();
	virtual bool IsSupportedForNetworking() const override{ return true;}
	virtual void PostNetReceive() override;
	virtual void PreDestroyFromReplication() override;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void Init(UPersistBaseComponent* InOwner);

	virtual void OnApply(AActor* OwnerActor);

	virtual void OnUnApply(AActor* OwnerActor);
	UFUNCTION(BlueprintPure)
	virtual bool CanApply(AActor* OwnerActor);
	UFUNCTION(BlueprintCallable)
	bool HasAuthority();
	UFUNCTION(BlueprintCallable)
	virtual AActor* GetNetOwnerActor() const;
	UFUNCTION(BlueprintCallable)
	UPersistBaseComponent* GetOwnerSafety() const;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnApply_BP(AActor* Character);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnApply_BP(AActor* Character);

	UFUNCTION(BlueprintNativeEvent)
	bool CanApply_BP(AActor* Character);
};
