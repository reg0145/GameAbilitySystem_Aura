// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
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

	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->Get_healthAttribute()).
	AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		});
	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->Get_maxHealthAttribute()).
	AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		});
	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->Get_manaAttribute())
	.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);
		});
	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->Get_maxManaAttribute())
	.AddLambda([this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		});

	Cast<UAuraAbilitySystemComponent>(_abilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));

			for (const FGameplayTag& Tag : AssetTags)
			{
				// "Messsage.HealthPotion".MatchesTag("Message") will return true, "Message".MatchesTag("Message.HealthPotion") will return false
				if (Tag.MatchesTagExact(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row); // Warning : 메시지 테이블에 데이터가 없을 경우 에러가 널포인트 참조 에러가 발생한다.
				}
			}
		}
	);
}
