// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	_playerController = WCParams._playerController;
	_playerState = WCParams._playerState;
	_abilitySystemComponent = WCParams._abilitySystemComponent;
	_attributeSet = WCParams._attributeSet;
}
