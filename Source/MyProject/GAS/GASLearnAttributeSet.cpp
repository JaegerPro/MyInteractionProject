// GASLearnAttributeSet.cpp
#include "GASLearnAttributeSet.h"
#include "Net/UnrealNetwork.h"   // DOREPLIFETIME_CONDITION_NOTIFY
#include "GameplayEffectExtension.h"   // FGameplayEffectModCallbackData 在这
#include "GASLearnGameplayTags.h"

void UGASLearnAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    // 关键规则：Health 不能超过 MaxHealth，也不能小于 0
    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
    }
    else if (Attribute == GetMaxHealthAttribute())
    {
        // MaxHealth 至少是 1，避免除零
        NewValue = FMath::Max(NewValue, 1.f);
    }
}

void UGASLearnAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    // 只处理 Instant/Periodic（会修改 BaseValue 的）
    // Duration/Infinite 不走这里
    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        // Clamp 一下 BaseValue，防止越界
        SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));

        // 死亡检测（先打 Log，后面课再做真正的死亡逻辑）
        if (GetHealth() <= 0.f)
        {
            UAbilitySystemComponent& ASC = Data.Target;
            if (!ASC.HasMatchingGameplayTag(GASTags::State_Dead))
            {
                ASC.AddLooseGameplayTag(GASTags::State_Dead);

                // 取消所有正在激活的 Ability（因为 ActivationBlockedTags 里有 State.Dead）
                ASC.CancelAllAbilities();

                UE_LOG(LogTemp, Warning, TEXT("[GAS] %s died!"),
                    *GetNameSafe(ASC.GetAvatarActor_Direct()));
            }
        }
    }
}
UGASLearnAttributeSet::UGASLearnAttributeSet()
{
    InitMaxHealth(100.f);
    InitHealth(100.f);
}

void UGASLearnAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // COND_None: 总是同步；REPNOTIFY_Always: 即使值没变也调回调
    // 这是 GAS 的"规矩"，必须这么写，否则联机表现层会丢事件
    DOREPLIFETIME_CONDITION_NOTIFY(UGASLearnAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UGASLearnAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UGASLearnAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
    // GAS 的"仪式"：告诉系统这个属性被同步过来了，让所有监听器能收到变化事件
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGASLearnAttributeSet, Health, OldHealth);
}

void UGASLearnAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGASLearnAttributeSet, MaxHealth, OldMaxHealth);
}

void UGASLearnAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGASLearnAttributeSet, Mana, OldMana);
}

void UGASLearnAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UGASLearnAttributeSet, MaxMana, OldMaxMana);
}
