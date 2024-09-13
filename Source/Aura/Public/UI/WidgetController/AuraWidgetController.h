// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class APlayerController;

struct FWidgetControllerParams
{
	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
	: _playerController(PC), _playerState(PS), _abilitySystemComponent(ASC), _attributeSet(AS) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerController* _playerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerState* _playerState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAbilitySystemComponent* _abilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAttributeSet* _attributeSet;
};

/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()

public:
	
	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

	UFUNCTION(BlueprintCallable)
	virtual void BroadcastInitialValues();
	virtual void BindCallbacksToDependencies();
	
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	APlayerController* _playerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	APlayerState* _playerState;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	UAbilitySystemComponent* _abilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	UAttributeSet* _attributeSet;
};
