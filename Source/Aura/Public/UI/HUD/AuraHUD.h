// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UOverlayWidgetController;
class UAttributeMenuWidgetController;
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
	UAttributeMenuWidgetController* GetAttributeMenuController(const FWidgetControllerParams& WCParams);
	
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> _OverlayWidget;


private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> _OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> _OverlayController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> _OverlayControllerClass;

	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> _AttributeMenuController;
    	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeMenuWidgetController> _AttributeMenuControllerClass;
};
