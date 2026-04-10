// Fill out your copyright notice in the Description page of Project Settings.


#include "PersistBaseComponent.h"
#include "PersistEffect.h"
#include "Runtime\Engine\Classes\Engine\ActorChannel.h"
// Sets default values for this component's properties
UPersistBaseComponent::UPersistBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	// ...
}


// Called when the game starts
void UPersistBaseComponent::BeginPlay()
{
	Super::BeginPlay();
	SetIsReplicated(true);
}


// Called every frame
void UPersistBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPersistBaseComponent::AddReference(UPersistEffectBase* Data)
{
	if (!Data)
	{
		return;
	}

	PersistDataArray.AddUnique(Data);
}

void UPersistBaseComponent::RemoveReference(UPersistEffectBase* Data)
{
	if (!Data)
	{
		return;
	}

	PersistDataArray.Remove(Data);
}


bool UPersistBaseComponent::ApplyPersistEffectData(UPersistEffectBase* DataModel, float OverrideApplyTime)
{
#if !UE_BUILD_SHIPPING
	UE_LOG(LogTemp, Log, TEXT("UPersistBaseComponent::ApplyPersistEffectData , DataModel %s"), DataModel ? *DataModel->GetFullName() : TEXT("Null"));
#endif

	if (!DataModel)
	{
		UE_LOG(LogTemp, Log, TEXT("UPersistBaseComponent::ApplyPersistEffectData Failed, DataModel is NULL"));
		return false;
	}

	if (!DataModel->CanApply(GetNetOwnerActor()))
	{
#if !UE_BUILD_SHIPPING
		UE_LOG(LogTemp, Log, TEXT("UPersistBaseComponent::ApplyPersistEffectData Failed, CanApply is false"));
#endif
		return false;
	}

#if !UE_BUILD_SHIPPING
	UE_LOG(LogTemp, Log, TEXT("UPersistBaseComponent::ApplyPersistEffectData Class = %s"), *GetNameSafe(DataModel));
#endif
	DataModel->Init(this);
	PersistDataArray.Add(DataModel);
	if (AActor* OwnerActor = GetOwner())
	{
		OwnerActor->AddReplicatedSubObject(DataModel);
	}

	DataModel->OnApply(GetNetOwnerActor());

	if (!PersistDataArray.Contains(DataModel))
	{
		UE_LOG(LogTemp, Log, TEXT("UPersistBaseComponent::ApplyPersistEffectData Failed, Add Failed"));
		return false;
	}

	return true;
}

UPersistEffectBase* UPersistBaseComponent::ApplyPersistEffectDataByClass(TSubclassOf<UPersistEffectBase> Class, float OverrideApplyTime/*=-1.0f*/)
{
	UPersistEffectBase* DataModel = CreatePersistEffectDataByClass(Class);
	if (ApplyPersistEffectData(DataModel, OverrideApplyTime))
	{
		return DataModel;
	}
	else
	{
		return nullptr;
	}
}

UPersistEffectBase* UPersistBaseComponent::CreatePersistEffectDataByClass(TSubclassOf<UPersistEffectBase> Class)
{
	if (!IsAuthority())
	{
		return nullptr;
	}

	if (!Class.Get())
	{
#if !UE_BUILD_SHIPPING
		UE_LOG(LogTemp, Log, TEXT("UPersistBaseComponent::CreatePersistEffectDataByClass Failed, Class is NULL"));
#endif
		return nullptr;
	}

	UPersistEffectBase* DataModel = NewObject<UPersistEffectBase>(GetOwner(), Class);
	if (!DataModel)
	{
#if !UE_BUILD_SHIPPING
		UE_LOG(LogTemp, Log, TEXT("UPersistBaseComponent::CreatePersistEffectDataByClass Failed, DataModel is NULL"));
#endif
		return nullptr;
	}

	return DataModel;
}
UPersistEffectBase* UPersistBaseComponent::ApplyPersistEffect(UPersistBaseComponent* PersistComponent, UPersistEffectBase* DataModel, float OverrideApplyTime /*= -1.0f*/)
{
	if (PersistComponent && DataModel)
	{
		if (PersistComponent->ApplyPersistEffectData(DataModel, OverrideApplyTime))
		{
			return DataModel;
		}
	}
	return nullptr;
}

void UPersistBaseComponent::UnApplyPersistEffectData(UPersistEffectBase* Data)
{
   if (!IsAuthority() || !Data || !PersistDataArray.Contains(Data))
    {
        return;
    }


	PersistDataArray.Remove(Data);

	Data->OnUnApply(GetNetOwnerActor());

   if (AActor* OwnerActor = GetOwner())
    {
        // UE5原生：通知远端删除该子对象副本
        OwnerActor->DestroyReplicatedSubObjectOnRemotePeers(Data);

        // UE5原生：停止复制该子对象
        OwnerActor->RemoveReplicatedSubObject(Data);

        // 加速发包（不是“零延迟”，但会更快）
        OwnerActor->FlushNetDormancy();
        OwnerActor->ForceNetUpdate();
    }
}

AActor* UPersistBaseComponent::GetNetOwnerActor()
{
	if (!CacheOwner)
	{
		CacheOwner = GetOwner();
	}

	return CacheOwner;
}
bool UPersistBaseComponent::IsAuthority()
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor)
	{
		return false;
	}

	return 	OwnerActor->GetLocalRole() == ROLE_Authority;
}
