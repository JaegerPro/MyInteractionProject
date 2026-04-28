// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AFireballProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UStaticMeshComponent;
class UGameplayEffect;
class UAbilitySystemComponent;

UCLASS()
class MYPROJECT_API AFireballProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
    float DamageAmount = 20.f;
	// Sets default values for this actor's properties
	AFireballProjectile();

    // 伤害 Effect（由 Ability 在 Spawn 时赋值）
    TSubclassOf<UGameplayEffect> DamageEffectClass;

    // 施法者的 ASC（用来制作 EffectContext）
    TWeakObjectPtr<UAbilitySystemComponent> SourceASC;

protected:
    UPROPERTY(VisibleAnywhere)
    TObjectPtr<USphereComponent> CollisionComp;

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<UStaticMeshComponent> MeshComp;

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<UProjectileMovementComponent> MovementComp;

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
        FVector NormalImpulse, const FHitResult& Hit);
};
