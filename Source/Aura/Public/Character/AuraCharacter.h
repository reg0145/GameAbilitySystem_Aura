// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
private:
	GENERATED_BODY()

public:
	AAuraCharacter();
	
	/* PlayerController에 의해 폰이 빙의된 후 호출된다. */
	virtual void PossessedBy(AController* NewController) override;
	
	/* 서버에 의해 PlayerState가 업데이트되었을 때 호출된다. */
	virtual void OnRep_PlayerState() override;
	
private:
	virtual void InitAbilityActorInfo() override;
};
