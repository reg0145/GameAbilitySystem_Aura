// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "UI/Widgets/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(_OverlayWidgetClass, TEXT("Overlay Widget Class uninitailized, please fill out BP_AuraHUD"));
	checkf(_OverlayControllerClass, TEXT("Overlay ControllerClass uninitailized, please fill out BP_AuraHUD"));
	
	UUserWidget* OverlayWidget = nullptr;
	OverlayWidget = CreateWidget<UUserWidget>(GetWorld(), _OverlayWidgetClass);
	_OverlayWidget = Cast<UAuraUserWidget>(OverlayWidget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	_OverlayController = GetOverlayWidgetController(WidgetControllerParams);

	_OverlayWidget->SetWidgetController(_OverlayController);
	_OverlayController->BroadcastInitialValues();
	OverlayWidget->AddToViewport();
}

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (_OverlayController == nullptr)
	{
		_OverlayController = NewObject<UOverlayWidgetController>(this, _OverlayControllerClass);
		_OverlayController->SetWidgetControllerParams(WCParams);
		_OverlayController->BindCallbacksToDependencies();
	}

	return _OverlayController;
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuController(const FWidgetControllerParams& WCParams)
{
	if (_AttributeMenuController == nullptr)
	{
		_AttributeMenuController = NewObject<UAttributeMenuWidgetController>(this, _AttributeMenuControllerClass);
		_AttributeMenuController->SetWidgetControllerParams(WCParams);
	}

	return _AttributeMenuController;
}
