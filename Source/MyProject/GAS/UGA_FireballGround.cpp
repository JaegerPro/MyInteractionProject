// UGA_FireballGround.cpp
#include "UGA_FireballGround.h"
#include "GASLearnGameplayTags.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/Tasks/AbilityTask_WaitTargetData.h"
#include "GameFramework/Character.h"
#include <Abilities/GameplayAbilityTargetActor_GroundTrace.h>

UGA_FireballGround::UGA_FireballGround()
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
    NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;

    ActivationBlockedTags.AddTag(GASTags::State_Dead);
    ActivationBlockedTags.AddTag(GASTags::State_Stunned);
}

void UGA_FireballGround::ActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const FGameplayEventData* TriggerEventData)
{
    CachedHandle = Handle;
    CachedActorInfo = ActorInfo;
    CachedActivationInfo = ActivationInfo;

    if (!TargetActorClass)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    // 1) 创建 Task（不会自己 Spawn）
    UAbilityTask_WaitTargetData* Task =
        UAbilityTask_WaitTargetData::WaitTargetData(
            this,
            TEXT("FireballGroundTargeting"),
            EGameplayTargetingConfirmation::UserConfirmed,
            TargetActorClass);

    if (!Task) { EndAbility(Handle, ActorInfo, ActivationInfo, true, true); return; }

    // 2) 绑回调
    Task->ValidData.AddDynamic(this, &UGA_FireballGround::OnTargetDataReady);
    Task->Cancelled.AddDynamic(this, &UGA_FireballGround::OnTargetDataCancelled);

    // 3) 关键：手动 Spawn Target Actor
    AGameplayAbilityTargetActor* SpawnedActor = nullptr;
    if (!Task->BeginSpawningActor(this, TargetActorClass, SpawnedActor))
    {
        // Spawn 失败（少见）
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    // 4) 这里可以配置 SpawnedActor 的属性（可选，比如设 Reticle、最大距离等）
    if (AGameplayAbilityTargetActor_GroundTrace* GroundTrace =
        Cast<AGameplayAbilityTargetActor_GroundTrace>(SpawnedActor))
    {
        APlayerController* PC = Cast<APlayerController>(
            ActorInfo->PlayerController.Get());

        // 方式 A：用玩家摄像机 Actor（最简单，效果最接近 FPS/TPS 鼠标指向）
        if (PC && PC->PlayerCameraManager)
        {
            GroundTrace->StartLocation.LocationType =
                EGameplayAbilityTargetingLocationType::ActorTransform;
            GroundTrace->StartLocation.SourceActor = PC->PlayerCameraManager;
        }
    }

    // 5) 关键：FinishSpawningActor，从这里开始 Target Actor 真正进入场景并 StartTargeting
    Task->FinishSpawningActor(this, SpawnedActor);

    // 6) 启动 Task
    Task->ReadyForActivation();
}

void UGA_FireballGround::OnTargetDataReady(const FGameplayAbilityTargetDataHandle& Data)
{
    // 先 CommitCost / Cooldown（如果你要加的话，这里是正确时机——玩家已经确认目标了）
    // if (!CommitAbility(...)) { EndAbility(...); return; }

    // 从 TargetData 提取落点
    // GetTargetDataEndPoint 对 SingleTargetHit 返回 ImpactPoint，对 LocationInfo 返回 TargetLocation
    const FVector GroundLoc =
        UAbilitySystemBlueprintLibrary::GetTargetDataEndPoint(Data, 0);

    // 服务器才真正 Spawn 火球（和你原火球一致）
    if (HasAuthority(&CachedActivationInfo))
    {
        SpawnFireballToLocation(GroundLoc);
    }

    EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, false);
}

void UGA_FireballGround::OnTargetDataCancelled(const FGameplayAbilityTargetDataHandle& Data)
{
    // 玩家右键取消
    EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, true);
}

void UGA_FireballGround::SpawnFireballToLocation(const FVector& GroundLoc)
{
    if (!CachedActorInfo || !FireballClass) return;

    ACharacter* Avatar = Cast<ACharacter>(CachedActorInfo->AvatarActor.Get());
    if (!Avatar) return;

    // 起始位置：手部
    FVector MuzzleLoc = Avatar->GetActorLocation();
    if (USkeletalMeshComponent* Mesh = Avatar->GetMesh())
    {
        if (Mesh->DoesSocketExist(MuzzleSocketName))
        {
            MuzzleLoc = Mesh->GetSocketLocation(MuzzleSocketName);
        }
    }

    // 朝向落点发射
    const FRotator MuzzleRot = (GroundLoc - MuzzleLoc).Rotation();

    FActorSpawnParameters Params;
    Params.Owner = Avatar;
    Params.Instigator = Avatar;
    Params.SpawnCollisionHandlingOverride =
        ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    AFireballProjectile* Fireball =
        GetWorld()->SpawnActor<AFireballProjectile>(FireballClass, MuzzleLoc, MuzzleRot, Params);

    if (Fireball)
    {
        if (UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(Fireball->GetRootComponent()))
        {
            Root->IgnoreActorWhenMoving(Avatar, true);
        }
        Fireball->DamageEffectClass = DamageEffect;
        Fireball->SourceASC = CachedActorInfo->AbilitySystemComponent.Get();
    }
}
