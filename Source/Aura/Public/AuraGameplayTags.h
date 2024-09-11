// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */
struct FAuraGameplayTags
{
public:
	static FAuraGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag _attributes_Primary_Strength;
	FGameplayTag _attributes_Primary_Intelligence;
	FGameplayTag _attributes_Primary_Resilience;
	FGameplayTag _attributes_Primary_Vigor;
	
	FGameplayTag _attributes_Secondary_Armor;
	FGameplayTag _attributes_Secondary_ArmorPenetration;
	FGameplayTag _attributes_Secondary_BlockChance;
	FGameplayTag _attributes_Secondary_CriticalHitChance;
	FGameplayTag _attributes_Secondary_CriticalHitDamage;
	FGameplayTag _attributes_Secondary_CriticalHitResistance;
	FGameplayTag _attributes_Secondary_HealthRegeneration;
	FGameplayTag _attributes_Secondary_ManaRegeneration;
	FGameplayTag _attributes_Secondary_MaxHealth;
	FGameplayTag _attributes_Secondary_MaxMana;
protected:
 
private:
	static FAuraGameplayTags GameplayTags;
};
