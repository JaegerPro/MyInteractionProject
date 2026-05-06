// GASLearnAttributeSet.h
#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"                  // UAttributeSet 基类
#include "AbilitySystemComponent.h"        // 为了用 GAMEPLAYATTRIBUTE_REPNOTIFY 宏
#include "GASLearnAttributeSet.generated.h"

// ─────────────────────────────────────────────
// 这个宏是 GAS 的"标准八股文"，一次性帮你生成 4 个方法：
//   GetHealthAttribute()  → 返回 FGameplayAttribute（属性的"身份证"）
//   GetHealth()           → 返回当前值
//   SetHealth(NewVal)     → 设置基础值
//   InitHealth(NewVal)    → 初始化（不触发变化通知）
// 你只要写这一行，四个方法就有了。
// ─────────────────────────────────────────────
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class MYPROJECT_API UGASLearnAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UGASLearnAttributeSet();

    // 告诉 UE 这个类的哪些属性需要网络同步
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // ───────── 当前生命值 ─────────
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, Health)

        // ───────── 最大生命值 ─────────
        UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, MaxHealth)

        // ───────── 当前MP ─────────
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Mana)
    FGameplayAttributeData Mana;
    ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, Mana)

        // ───────── 最大MP ─────────
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxMana)
    FGameplayAttributeData MaxMana;
    ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, MaxMana)
        // ───────── 攻击力（Source 用） ─────────
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AttackPower)
    FGameplayAttributeData AttackPower;
    ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, AttackPower)

        // ───────── 护甲（Target 用） ─────────
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Armor)
    FGameplayAttributeData Armor;
    ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, Armor)
        // ───────── 暴击率（0~1） ─────────
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CritChance)
    FGameplayAttributeData CritChance;
    ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, CritChance)

        // ───────── 暴击倍率（默认 2.0） ─────────
    UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CritMultiplier)
    FGameplayAttributeData CritMultiplier;
    ATTRIBUTE_ACCESSORS(UGASLearnAttributeSet, CritMultiplier)

        // Effect 即将修改属性前调用（你有机会 Clamp 输入值）
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

    // Effect 已经修改完属性后调用（你可以触发衍生逻辑，比如"血量归零 → 死亡"）
    virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

protected:
    // RepNotify 回调：客户端收到同步时，GAS 要求我们手动通知一下，才能触发监听回调
    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

    UFUNCTION()
    virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
    UFUNCTION()
    virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);

    UFUNCTION()
    virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
    UFUNCTION()
    virtual void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower);

    UFUNCTION()
    virtual void OnRep_Armor(const FGameplayAttributeData& OldArmor);
    UFUNCTION()
    virtual void OnRep_CritChance(const FGameplayAttributeData& Old);

    UFUNCTION()
    virtual void OnRep_CritMultiplier(const FGameplayAttributeData& Old);


};
