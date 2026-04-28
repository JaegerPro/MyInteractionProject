// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GASLearnGameplayAbility.h"
#include "MyProject/CustomActor/AFireballProjectile.h"
#include "UGA_Fireball.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UGA_Fireball : public UGASLearnGameplayAbility
{
	GENERATED_BODY()
public:
	UGA_Fireball();
    // Ability 激活入口
    virtual void ActivateAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        const FGameplayEventData* TriggerEventData) override;
    // 伤害 Effect（在蓝图里指派 GE_Damage20）
    virtual void EndAbility(
        const FGameplayAbilitySpecHandle Handle,
        const FGameplayAbilityActorInfo* ActorInfo,
        const FGameplayAbilityActivationInfo ActivationInfo,
        bool bReplicateEndAbility,
        bool bWasCancelled) override;

    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball")
    TSubclassOf<class UGameplayEffect> DamageEffect;
    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball")
    TSubclassOf<UGameplayEffect> CostEffectClass;

    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball")
    TSubclassOf<UGameplayEffect> CooldownEffectClass;
    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball|Charge")
    TObjectPtr<UAnimMontage> ChargeMontage;     // 蓄力动画（循环）

    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball|Charge")
    TObjectPtr<UAnimMontage> ReleaseMontage;    // 释放动画（原 CastMontage 改名）
    // 火球 Actor 类
    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball")
    TSubclassOf<AFireballProjectile> FireballClass;

    // 从角色哪个骨骼生成火球
    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball")
    FName MuzzleSocketName = TEXT("hand_r");
    // 重写这两个虚函数，告诉 GAS 我们的 Cost/CD 用哪个 Effect
    virtual UGameplayEffect* GetCostGameplayEffect() const override;
    virtual UGameplayEffect* GetCooldownGameplayEffect() const override;

    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball|Charge")
    float MaxChargeTime = 2.f;

    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball|Damage")
    float BaseDamage = 20.f;

    UPROPERTY(EditDefaultsOnly, Category = "GAS|Fireball|Damage")
    float MaxDamage = 100.f;

protected:
    UFUNCTION()
    void OnInputReleased(float TimeHeld);

    UFUNCTION()
    void OnChargeInterrupted();

    float ChargeStartTime = 0.f;
    float CachedChargedDamage = 20.f;
protected:
    float CalculateDamage() const;
    UFUNCTION()
    void OnMontageCompleted();

    UFUNCTION()
    void OnMontageInterrupted();

    UFUNCTION()
    void OnFireballLaunchEvent(FGameplayEventData Payload);

    void SpawnFireball();
    // 缓存 Handle，回调里要用来 EndAbility
    FGameplayAbilitySpecHandle CachedHandle;
    const FGameplayAbilityActorInfo* CachedActorInfo = nullptr;
    FGameplayAbilityActivationInfo CachedActivationInfo;
};
