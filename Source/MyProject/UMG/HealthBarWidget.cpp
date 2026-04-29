// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidget.h"

void UHealthBarWidget::SetHealthPercent(float CurrentHealth, float MaxHealth)
{
    const float Pct = (MaxHealth > KINDA_SMALL_NUMBER) ? (CurrentHealth / MaxHealth) : 0.f;
    OnHealthPercentChanged(FMath::Clamp(Pct, 0.f, 1.f));
}