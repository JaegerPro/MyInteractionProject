// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PersistBaseComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UPersistBaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

protected:
	UPROPERTY()
	AActor* CacheOwner = nullptr;
	UPROPERTY()
	TArray<UPersistEffectBase*> PersistDataArray;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	bool IsAuthority();
public:	
	// Sets default values for this component's properties
	UPersistBaseComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AddReference(UPersistEffectBase* Data);
	void RemoveReference(UPersistEffectBase* Data);
	UFUNCTION(BlueprintCallable)
	bool ApplyPersistEffectData(UPersistEffectBase* DataModel, float OverrideApplyTime = -1.0f);
	UFUNCTION(BlueprintCallable)
	UPersistEffectBase* ApplyPersistEffectDataByClass(TSubclassOf<UPersistEffectBase> Class, float OverrideApplyTime = -1.0f);
	UFUNCTION(BlueprintCallable)
	UPersistEffectBase* CreatePersistEffectDataByClass(TSubclassOf<UPersistEffectBase> Class);
	UFUNCTION(BlueprintCallable, Category = "PersistBaseComponent", meta = (BlueprintInternalUseOnly = "true"))
	static UPersistEffectBase* ApplyPersistEffect(UPersistBaseComponent* PersistComponent, UPersistEffectBase* DataModel, float OverrideApplyTime = -1.0f);
	UFUNCTION(BlueprintCallable)
	void UnApplyPersistEffectData(UPersistEffectBase* Data);
	UFUNCTION(BlueprintPure)
	virtual AActor* GetNetOwnerActor();

};
