// Fill out your copyright notice in the Description page of Project Settings.


#include "UGA_Fireball.h"
#include "GASLearnGameplayTags.h"
#include "AbilitySystemComponent.h"
#include <Abilities/Tasks/AbilityTask_PlayMontageAndWait.h>
#include <Abilities/Tasks/AbilityTask_WaitGameplayEvent.h>
#include "GameFramework/Character.h"
#include <Abilities/Tasks/AbilityTask_WaitInputRelease.h>

UGA_Fireball::UGA_Fireball()
{
    // 实例化策略：每个施法者一个实例（最常用）
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
    NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
    // 给这个 Ability 本身打上标签（其他系统可以查"谁在放火球"）
    AbilityTags.AddTag(GASTags::Ability_Fireball);

    // 如果身上有这些 Tag，就不能激活
    // 比如死了、被眩晕了，不能放技能
    ActivationBlockedTags.AddTag(GASTags::State_Dead);
    ActivationBlockedTags.AddTag(GASTags::State_Stunned);
    ActivationOwnedTags.AddTag(GASTags::State_Charging);
}

void UGA_Fireball::ActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const FGameplayEventData* TriggerEventData)
{
    CachedHandle = Handle;
    CachedActorInfo = ActorInfo;
    CachedActivationInfo = ActivationInfo;
    if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }
    // 注意：这里只 CommitCooldown，没 CommitCost——蓝在松开时才扣

    // 记录蓄力开始时间
    ChargeStartTime = GetWorld()->GetTimeSeconds();

    // 播蓄力动画（循环 Montage）

    // 等待输入松开
    UAbilityTask_WaitInputRelease* ReleaseTask = UAbilityTask_WaitInputRelease::WaitInputRelease(this, false);
    ReleaseTask->OnRelease.AddDynamic(this, &UGA_Fireball::OnInputReleased);
    ReleaseTask->ReadyForActivation();
}

void UGA_Fireball::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UGA_Fireball::OnInputReleased(float TimeHeld)
{
    // TimeHeld 是 GAS 自己算的"按下到松开"的时长
    const float ChargeDuration = FMath::Clamp(TimeHeld, 0.f, MaxChargeTime);
    const float ChargeRatio = ChargeDuration / MaxChargeTime;   // 0~1

    // 现在才真正扣蓝
    if (!CommitAbilityCost(CachedHandle, CachedActorInfo, CachedActivationInfo))
    {
        // 蓝不够？直接取消
        EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, true);
        return;
    }

    // 根据蓄力比算伤害：[BaseDamage, MaxDamage]
    CachedChargedDamage = FMath::Lerp(BaseDamage, MaxDamage, ChargeRatio);

    // 播释放动画
    if (ReleaseMontage)
    {
        UAbilityTask_PlayMontageAndWait* MontageTask =
            UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, NAME_None, ReleaseMontage);
        MontageTask->OnCompleted.AddDynamic(this, &UGA_Fireball::OnMontageCompleted);
        MontageTask->OnBlendOut.AddDynamic(this, &UGA_Fireball::OnMontageCompleted);
        MontageTask->OnInterrupted.AddDynamic(this, &UGA_Fireball::OnMontageInterrupted);
        MontageTask->OnCancelled.AddDynamic(this, &UGA_Fireball::OnMontageInterrupted);
        MontageTask->ReadyForActivation();
    }

    // 等释放动画的 Launch Event
    UAbilityTask_WaitGameplayEvent* EventTask =
        UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(this, GASTags::Event_Fireball_Launch);
    EventTask->EventReceived.AddDynamic(this, &UGA_Fireball::OnFireballLaunchEvent);
    EventTask->ReadyForActivation();
}
void UGA_Fireball::OnChargeInterrupted()
{
    EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, true);
}

void UGA_Fireball::OnFireballLaunchEvent(FGameplayEventData Payload)
{
    // 动画到了发射帧 → 生成火球
    SpawnFireball();
}

void UGA_Fireball::OnMontageCompleted()
{
    EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, false);
}

void UGA_Fireball::OnMontageInterrupted()
{
    EndAbility(CachedHandle, CachedActorInfo, CachedActivationInfo, true, true);
}

void UGA_Fireball::SpawnFireball()
{
    if (!CachedActorInfo || !FireballClass) return;
    if (!HasAuthority(&CachedActivationInfo)) return;

    ACharacter* Avatar = Cast<ACharacter>(CachedActorInfo->AvatarActor.Get());
    if (!Avatar) return;

    FVector MuzzleLoc = Avatar->GetActorLocation();
    if (USkeletalMeshComponent* Mesh = Avatar->GetMesh())
    {
        if (Mesh->DoesSocketExist(MuzzleSocketName))
        {
            MuzzleLoc = Mesh->GetSocketLocation(MuzzleSocketName);
        }
    }
    const FRotator MuzzleRot = Avatar->GetActorRotation();

    FActorSpawnParameters Params;
    Params.Owner = Avatar;
    Params.Instigator = Avatar;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    AFireballProjectile* Fireball = GetWorld()->SpawnActor<AFireballProjectile>(FireballClass, MuzzleLoc, MuzzleRot, Params);
    if (Fireball)
    {
        // 把伤害 Effect 塞给火球，让它命中后施加
        Fireball->DamageEffectClass = DamageEffect;
        // 记录施法者 ASC，后面命中时制作 EffectContext 用
        Fireball->SourceASC = CachedActorInfo->AbilitySystemComponent.Get();
        Fireball->DamageAmount = CachedChargedDamage;
    }
}
float UGA_Fireball::CalculateDamage() const
{
    // 简单公式：基础伤害 + 等级 × 5
    const float Base = 20.f;
    const float PerLevel = 5.f;
    return Base + (GetAbilityLevel() - 1) * PerLevel;
}
UGameplayEffect* UGA_Fireball::GetCostGameplayEffect() const
{
    if (CostEffectClass) return CostEffectClass->GetDefaultObject<UGameplayEffect>();
    return Super::GetCostGameplayEffect();
}

UGameplayEffect* UGA_Fireball::GetCooldownGameplayEffect() const
{
    if (CooldownEffectClass) return CooldownEffectClass->GetDefaultObject<UGameplayEffect>();
    return Super::GetCooldownGameplayEffect();
}
