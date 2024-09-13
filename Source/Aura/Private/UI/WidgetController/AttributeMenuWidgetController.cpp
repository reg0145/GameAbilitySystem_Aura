// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = Cast<UAuraAttributeSet>(_attributeSet);
	check(_attributeInfo);
	
	FAuraAttributeInfo Info = _attributeInfo->FindAttributeInfoForTag(FAuraGameplayTags::Get()._attributes_Primary_Strength, false);
	Info.AttributeValue = AS->Get_health();
	AttributeInfoDelegate.Broadcast(Info);
}

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	
}
