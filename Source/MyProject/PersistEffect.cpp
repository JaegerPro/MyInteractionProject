// Fill out your copyright notice in the Description page of Project Settings.


#include "PersistEffect.h"
#include "UObject/UObjectBaseUtility.h"
#include "PersistBaseComponent.h"
#include <Net/UnrealNetwork.h>

UPersistEffectBase::UPersistEffectBase()
{
}
void UPersistEffectBase::PostNetReceive()
{
	Super::PostNetReceive();

	// 模拟“复制创建完成”回调：仅客户端、仅一次
	if (!HasAuthority()&& !bHaveApplyed)
	{
		UPersistBaseComponent* OwnerComp = GetOwnerSafety();
		if (OwnerComp)
		{
			OwnerComp->AddReference(this);
			Init(GetOwnerSafety());
			OnApply(GetNetOwnerActor());
		}
	}
}
void UPersistEffectBase::PreDestroyFromReplication()
{
	if (bHaveApplyed)
	{
		if (GetOwnerSafety())
		{
			Owner->RemoveReference(this);
		}
		OnUnApply(GetNetOwnerActor());
	}
	Super::PreDestroyFromReplication();
}
void UPersistEffectBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	UBlueprintGeneratedClass* BPClass = Cast<UBlueprintGeneratedClass>(GetClass());
	if (BPClass != NULL)
	{
		BPClass->GetLifetimeBlueprintReplicationList(OutLifetimeProps);
	}
	DOREPLIFETIME(UPersistEffectBase, Owner);
}
void UPersistEffectBase::Init(UPersistBaseComponent* InOwner)
{
	if (!InOwner)
	{
		UE_LOG(LogTemp, Log, TEXT("UPersistEffectBase::Init InOwner null!"));
		return;
	}

	AActor* OwnerActor = InOwner->GetOwner();
	if (!OwnerActor)
	{
		UE_LOG(LogTemp, Log, TEXT("UPersistEffectBase::Init OwnerActor null!"));
		return;
	}

	if (OwnerActor->HasAuthority())
	{
		if (Owner != nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("UPersistEffectBase::Init Has Init"));
		}
		else
		{
			Owner = InOwner;
		}
	}
}

void UPersistEffectBase::OnApply(AActor* OwnerActor)
{
	if (bHaveApplyed)
	{
		check(0)
		return;
	}
	UE_LOG(LogTemp, Log, TEXT("UPersistEffectBase::OnApply %s"), *GetFullNameSafe(this));

	bool bCallBP = true;
#if UE_EDITOR
	bCallBP = GetWorld() && GetWorld()->IsGameWorld();
#endif
	if (bCallBP)
	{
		OnApply_BP(OwnerActor);
	}

	UE_LOG(LogTemp, Log, TEXT("UPersistEffectBase::OnApply before set bHaveApplyed %s"), *GetFullNameSafe(this));
	bHaveApplyed = true;
}

void UPersistEffectBase::OnUnApply(AActor* OwnerActor)
{
	if (!bHaveApplyed)
	{
		return;
	}

	bool bCallBP = true;
#if UE_EDITOR || WITH_UGC_EDITOR
	bCallBP = GetWorld() && GetWorld()->IsGameWorld();
#endif
	if (bCallBP)
	{
		OnUnApply_BP(OwnerActor);
	}
}

bool UPersistEffectBase::CanApply(AActor* OwnerActor)
{
	return CanApply_BP(OwnerActor);
}
bool UPersistEffectBase::CanApply_BP_Implementation(AActor* Character)
{
	return true;
}
bool UPersistEffectBase::HasAuthority()
{
	if (GetNetOwnerActor())
	{
		return GetNetOwnerActor()->HasAuthority();
	}

	return true;
}
AActor* UPersistEffectBase::GetNetOwnerActor() const
{
	if (GetOwnerSafety())
	{
		return Owner->GetOwner();
	}
	return GetTypedOuter<AActor>();
}

UPersistBaseComponent* UPersistEffectBase::GetOwnerSafety() const
{
	if (!Owner)
	{
		AActor* actor = GetTypedOuter<AActor>();
		if (actor)
		{
			UPersistBaseComponent* pComp = Cast<UPersistBaseComponent>(actor->GetComponentByClass(UPersistBaseComponent::StaticClass()));
			UPersistEffectBase* const Self = const_cast<UPersistEffectBase*>(this);
			Self->Owner = pComp;
			return Owner;
		}
	}

	return Owner;
}
