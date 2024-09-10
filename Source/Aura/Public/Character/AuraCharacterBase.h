// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();
	
	/* AbilitySystemInterface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const { return _abilitySystemComponent; }
	/* end AbilitySystemInterface */

	UAttributeSet* GetAttributeSet() { return _attributeSet; }

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo();
	virtual void InitializeDefaultAttributes();

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> _weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> _abilitySystemComponent;

	UPROPERTY()
    TObjectPtr<UAttributeSet> _attributeSet;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> _defaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> _defaultSecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> _defaultVitalAttributes;
};
