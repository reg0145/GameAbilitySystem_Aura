// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return _abilitySystemComponent; }
	UAttributeSet* GetAttributeSet() const { return _attributeSet; }

private:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> _abilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> _attributeSet;
};