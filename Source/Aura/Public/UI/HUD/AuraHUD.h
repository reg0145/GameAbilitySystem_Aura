// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UOverlayWidgetController;
class UAuraUserWidget;
struct FWidgetControllerParams;
/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> _overlayWidget;

protected:
	
	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> _overlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> _overlayController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> _overlayControllerClass;
};
