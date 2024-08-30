// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"
#include "UI/Widgets/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(_overlayWidgetClass, TEXT("Overlay Widget Class uninitailized, please fill out BP_AuraHUD"));
	checkf(_overlayControllerClass, TEXT("Overlay ControllerClass uninitailized, please fill out BP_AuraHUD"));

	UUserWidget* OverlayWidget = CreateWidget<UUserWidget>(GetWorld(), _overlayWidgetClass);
	_overlayWidget = Cast<UAuraUserWidget>(OverlayWidget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	_overlayController = GetOverlayWidgetController(WidgetControllerParams);
	
	_overlayWidget->SetWidgetController(_overlayController);
	
	OverlayWidget->AddToViewport();
}

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (_overlayController == nullptr)
	{
		_overlayController = NewObject<UOverlayWidgetController>(this, _overlayControllerClass);
		_overlayController->SetWidgetControllerParams(WCParams);
	}

	return _overlayController;
}
