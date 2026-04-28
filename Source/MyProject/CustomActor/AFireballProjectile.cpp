// Fill out your copyright notice in the Description page of Project Settings.


#include "AFireballProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffect.h"

AFireballProjectile::AFireballProjectile()
{
    bReplicates = true;
    SetReplicateMovement(true);

    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
    CollisionComp->InitSphereRadius(20.f);
    CollisionComp->SetCollisionProfileName(TEXT("BlockAllDynamic"));   // 简单起见用这个，正式项目要自定义
    CollisionComp->OnComponentHit.AddDynamic(this, &AFireballProjectile::OnHit);
    RootComponent = CollisionComp;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    MeshComp->SetupAttachment(RootComponent);
    MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
    MovementComp->InitialSpeed = 2000.f;
    MovementComp->MaxSpeed = 2000.f;
    MovementComp->ProjectileGravityScale = 0.f;

    InitialLifeSpan = 3.f;
}

void AFireballProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    FVector NormalImpulse, const FHitResult& Hit)
{
    if (!HasAuthority()) { Destroy(); return; }   // 伤害逻辑只在服务器
    if (!OtherActor || OtherActor == GetInstigator()) { Destroy(); return; }

    // 找目标 ASC
    UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
    if (TargetASC && DamageEffectClass && SourceASC.IsValid())
    {
        // 做 Context
        FGameplayEffectContextHandle Ctx = SourceASC->MakeEffectContext();
        Ctx.AddSourceObject(this);
        Ctx.AddHitResult(Hit);

        // 做 Spec
        FGameplayEffectSpecHandle Spec = SourceASC->MakeOutgoingSpec(DamageEffectClass, /*Level=*/1.f, Ctx);
        if (Spec.IsValid())
        {
            static const FGameplayTag DamageTag = FGameplayTag::RequestGameplayTag(FName("Data.Damage"));
            UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(Spec, DamageTag, DamageAmount);
            // SourceASC 对 TargetASC 应用伤害 —— 标准姿势
            SourceASC->ApplyGameplayEffectSpecToTarget(*Spec.Data.Get(), TargetASC);
        }
    }
    if (SourceASC.IsValid())
    {
        FGameplayCueParameters CueParams;
        CueParams.Location = Hit.ImpactPoint;
        CueParams.Normal = Hit.ImpactNormal;
        CueParams.Instigator = GetInstigator();
        CueParams.EffectCauser = this;
        CueParams.SourceObject = this;

        static const FGameplayTag ExplodeTag = FGameplayTag::RequestGameplayTag(FName("GameplayCue.Fireball.Explode"));
        SourceASC->ExecuteGameplayCue(ExplodeTag, CueParams);
    }

    Destroy();
}