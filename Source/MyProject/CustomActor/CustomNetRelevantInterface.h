// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CustomNetRelevantInterface.generated.h"

class AActor;

UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UCustomNetRelevantInterface : public UInterface
{
	GENERATED_BODY()
};

class MYPROJECT_API ICustomNetRelevantInterface
{
	GENERATED_IINTERFACE_BODY()
protected:
	TArray<AActor*> RegistActor;

public:
	/** Accessor to check if there is already server data, without potentially allocating it on demand.*/
	virtual bool IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation, const AActor* const SelfActor) { return false; };

	//ÊÇ·ñ¸²¸ÇActorµÄSuper 
	virtual bool GetIsReplace() const { return false; };

	virtual void OnRegisterTo(AActor* Actor) {};

	virtual void OnUnRegisterTo(AActor* Actor) {};
};
