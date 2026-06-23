// Fill out your copyright notice in the Description page of Project Settings.


#include "AFireballProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffect.h"
#include <GameplayCueManager.h>
#include"AbilitySystemGlobals.h"
#include "MyProject/GAS/GASLearnGameplayTags.h"
#include "Engine/OverlapResult.h"

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
    if (bHit) { Destroy(); return; }
    FGameplayCueParameters CueParams;
    CueParams.Location = Hit.ImpactPoint;
    CueParams.Normal = Hit.ImpactNormal;
    CueParams.Instigator = GetInstigator();
    CueParams.EffectCauser = this;
    CueParams.SourceObject = this;
    // 找目标 ASC
    UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);

    if (TargetASC && DamageEffectClass)
    {

        if (SourceASC.IsValid())
        {
            SourceASC->ExecuteGameplayCue(GASTags::Cue_Fireball_Explode, CueParams);
            // 做 Context
            FGameplayEffectContextHandle Ctx = SourceASC->MakeEffectContext();
            Ctx.AddSourceObject(this);
            Ctx.AddHitResult(Hit);

            // 做 Spec
            FGameplayEffectSpecHandle Spec = SourceASC->MakeOutgoingSpec(DamageEffectClass, /*Level=*/1.f, Ctx);
            if (Spec.IsValid())
            {
                // SourceASC 对 TargetASC 应用伤害 —— 标准姿势
                SourceASC->ApplyGameplayEffectSpecToTarget(*Spec.Data.Get(), TargetASC);
            }
        }
    }
    else
    {
        if (HasAuthority() && SourceASC.IsValid())
        {
            // 播放爆炸特效
            SourceASC->ExecuteGameplayCue(GASTags::Cue_Fireball_Explode, CueParams);

            // AOE 范围检测参数
            const float ExplosionRadius = 300.0f;

            // 进行球形范围检测
            TArray<FOverlapResult> OverlapResults;
            FCollisionQueryParams QueryParams;
            QueryParams.AddIgnoredActor(this);
            QueryParams.AddIgnoredActor(GetInstigator());
            QueryParams.bTraceComplex = false;

            bool bHasOverlaps = GetWorld()->OverlapMultiByChannel(
                OverlapResults,
                Hit.ImpactPoint,  // 爆炸中心：击中点的位置
                FQuat::Identity,
                ECC_Pawn,  // 检测 Pawn 类型的 Actor
                FCollisionShape::MakeSphere(ExplosionRadius),
                QueryParams
            );

            if (bHasOverlaps)
            {
                for (const FOverlapResult& Result : OverlapResults)
                {
                    AActor* OverlappedActor = Result.GetActor();
                    if (!OverlappedActor) continue;

                    // 获取目标的 ASC
                    UAbilitySystemComponent* AOETargetASC =
                        UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OverlappedActor);

                    if (AOETargetASC && DamageEffectClass)
                    {
                        // 做 Context
                        FGameplayEffectContextHandle Ctx = SourceASC->MakeEffectContext();
                        Ctx.AddSourceObject(this);

                        FHitResult AOEHit;
                        AOEHit.ImpactPoint = OverlappedActor->GetActorLocation();
                        AOEHit.ImpactNormal = (OverlappedActor->GetActorLocation() - Hit.ImpactPoint).GetSafeNormal();
                        Ctx.AddHitResult(AOEHit);

                        // 做 Spec
                        FGameplayEffectSpecHandle Spec = SourceASC->MakeOutgoingSpec(
                            DamageEffectClass, /*Level=*/1.f, Ctx);

                        if (Spec.IsValid())
                        {
                            // 应用 AOE 伤害
                            SourceASC->ApplyGameplayEffectSpecToTarget(*Spec.Data.Get(), AOETargetASC);
                        }
                    }
                }
            }
        }
        
    }
    Destroy();
}