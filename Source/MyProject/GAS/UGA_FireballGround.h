// UGA_FireballGround.h
#pragma once

#include "CoreMinimal.h"
#include "GASLearnGameplayAbility.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "MyProject/CustomActor/AFireballProjectile.h"
#include "UGA_FireballGround.generated.h"

UCLASS()
class MYPROJECT_API UGA_FireballGround : public UGASLearnGameplayAbility
{
    GENERATED_BODY()
public:
    UGA_FireballGround();

    virtual void ActivateAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        const FGameplayEventData* TriggerEventData) override;

    // 由蓝图子类指派：BP_TA_GroundTrace
    UPROPERTY(EditDefaultsOnly, Category = "GAS|FireballGround")
    TSubclassOf<AGameplayAbilityTargetActor> TargetActorClass;

    // 火球 Actor 类（沿用你现有的）
    UPROPERTY(EditDefaultsOnly, Category = "GAS|FireballGround")
    TSubclassOf<AFireballProjectile> FireballClass;

    // 命中后用的伤害 GE
    UPROPERTY(EditDefaultsOnly, Category = "GAS|FireballGround")
    TSubclassOf<UGameplayEffect> DamageEffect;

    UPROPERTY(EditDefaultsOnly, Category = "GAS|FireballGround")
    FName MuzzleSocketName = TEXT("hand_r");

    UPROPERTY(EditDefaultsOnly, Category = "GAS|FireballGround")
    float BaseDamage = 30.f;

protected:
    UFUNCTION()
    void OnTargetDataReady(const FGameplayAbilityTargetDataHandle& Data);

    UFUNCTION()
    void OnTargetDataCancelled(const FGameplayAbilityTargetDataHandle& Data);

    void SpawnFireballToLocation(const FVector& GroundLoc);

    // 缓存，回调里 EndAbility 用
    FGameplayAbilitySpecHandle CachedHandle;
    const FGameplayAbilityActorInfo* CachedActorInfo = nullptr;
    FGameplayAbilityActivationInfo CachedActivationInfo;
};
