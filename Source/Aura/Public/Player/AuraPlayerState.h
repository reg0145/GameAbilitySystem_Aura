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

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	/* AbilitySystemInterface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return _abilitySystemComponent; }
	/** end AbilitySystemInterfcae */

	UAttributeSet* GetAttributeSet() const { return _attributeSet; }
	FORCEINLINE int32 GetPlayerLevel() const { return _level; } 
private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAbilitySystemComponent> _abilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> _attributeSet;
	
	UFUNCTION()
	void OnRep_Level(int32 OldLevel);
	
	UPROPERTY(VisibleAnywhere, ReplicatedUsing=OnRep_Level)
	int32 _level = 1.f;
};
