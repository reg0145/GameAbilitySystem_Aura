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

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;

	/**
	 * Vital Properties
	 */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Properties")
	FGameplayAttributeData _health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Properties")
	FGameplayAttributeData _maxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _maxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Properties")
	FGameplayAttributeData _mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _mana);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Properties")
	FGameplayAttributeData _maxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, _maxMana);

	/**
	 * Primary Attribute
	 */
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
};
