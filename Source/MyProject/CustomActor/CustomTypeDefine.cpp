// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomTypeDefine.h"

void UComponentSelectorStatics::GetComponentBySelector(const AActor* OwnerActor, const FActorComponentSelector& ComponentSelector, UActorComponent*& OutComponent)
{
	if (OwnerActor)
	{
		TArray<UActorComponent*> CompList = OwnerActor->K2_GetComponentsByClass(UActorComponent::StaticClass());
		for (UActorComponent* tmpComp : CompList)
		{
			if (tmpComp && tmpComp->GetFName().IsEqual(ComponentSelector.ComponentName, ENameCase::CaseSensitive))
			{
				OutComponent = tmpComp;
				break;
			}
		}
	}
}