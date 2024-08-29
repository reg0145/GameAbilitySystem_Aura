// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	APlayerController* _playerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	APlayerState* _playerState;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	UAbilitySystemComponent* _abilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	UAttributeSet* _attributeSet;
};
