// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY();
	
	FEffectProperties() {}
	
	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	AActor* SourceAvatarActor;

	UPROPERTY()
	APlayerController* SourceController;

	UPROPERTY()
	ACharacter* SourceCharacter;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC;

	UPROPERTY()
	AActor* TargetAvatarActor;

	UPROPERTY()
	APlayerController* TargetController;

	UPROPERTY()
	ACharacter* TargetCharacter;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC;
};

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
private:
	GENERATED_BODY()
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

public:
	UAuraAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;

	/**
	* Primary Attribute
	*/
	
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Properties")
	FGameplayAttributeData _strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _strength);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Properties")
	FGameplayAttributeData _intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ReSilience, Category = "Primary Properties")
	FGameplayAttributeData _resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _resilience);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Properties")
	FGameplayAttributeData _vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _vigor);
	
	/**
	 * Secondary Properties
	 */
	
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;

	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;

	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Properties")
	FGameplayAttributeData _armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "Secondary Properties")
	FGameplayAttributeData _armorPenetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _armorPenetration);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary Properties")
	FGameplayAttributeData _blockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _blockChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Secondary Properties")
	FGameplayAttributeData _criticalHitChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _criticalHitChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Secondary Properties")
	FGameplayAttributeData _criticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _criticalHitDamage);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistance, Category = "Secondary Properties")
	FGameplayAttributeData _criticalHitResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _criticalHitResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Secondary Properties")
	FGameplayAttributeData _healthRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _healthRegeneration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Secondary Properties")
	FGameplayAttributeData _manaRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _manaRegeneration);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Secondary Properties")
	FGameplayAttributeData _maxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _maxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Secondary Properties")
	FGameplayAttributeData _maxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _maxMana);
	
	/**
	 * Vital Attribute
	 */

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Secondary Properties")
	FGameplayAttributeData _health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Secondary Properties")
	FGameplayAttributeData _mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _mana);
};
