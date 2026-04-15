// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomTypeDefine.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct FActorComponentSelector
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName ComponentName;
};

USTRUCT(BlueprintType, meta = (ComponentSelectorClassFilter = "/Script/Engine.ShapeComponent"))
struct FShapeComponentSelector : public FActorComponentSelector
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class UComponentSelectorStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ComponentSelector")
	static void GetComponentBySelector(const AActor* OwnerActor, const FActorComponentSelector& ComponentSelector, UActorComponent*& OutComponent);
};
