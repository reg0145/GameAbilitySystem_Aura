// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(_attributeSet);

	OnHealthChanged.Broadcast(AuraAttributeSet->Get_health());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->Get_maxHealth());
	OnManaChanged.Broadcast(AuraAttributeSet->Get_mana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->Get_maxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(_attributeSet);

	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->Get_healthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->Get_maxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->Get_manaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->Get_maxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
