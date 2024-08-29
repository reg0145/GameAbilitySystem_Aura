// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"
#include "UI/Widgets/AuraUserWidget.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* OverlayWidget = CreateWidget<UUserWidget>(GetWorld(), _overlayWidgetClass);
	OverlayWidget->AddToViewport();
}
