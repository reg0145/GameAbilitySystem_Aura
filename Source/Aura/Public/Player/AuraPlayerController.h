// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	/**
	 * @brief Line trace from cursor.
	 * @Details There are several scenarios:
	 * A. LastActor is null && ThisActor is null
	 *    - Do nothing
	 * B. LastActor is null && ThisActor is valid
	 *    - Highlight ThisActor
	 * C. LastActor is valid && ThisActor is null
	 *    - UnHighlight LastActor
	 * D. Both actors are valid, but LastActor != ThisActor
	 *    - UnHighlight LastActor, and Highlight ThisActor
	 * E. Both actors are valid, and are the same actor
	 *    - Do nothing
	 */
	void CursorTrace();

	TScriptInterface<IEnemyInterface> _prevTarget;
	TScriptInterface<IEnemyInterface> _currentTarget;
	
private:
	UFUNCTION()
	void Move(const FInputActionValue& InputActionValue);
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputMappingContext> _auraContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> _moveAction;
};
