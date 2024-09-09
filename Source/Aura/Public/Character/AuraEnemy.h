// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	/* CombatInterface */
	virtual int32 GetPlayerLevel() override;
	/* end CombatInterface */
	
	/* IEnemyInterface 상속 */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* end EnemyInterfcae */
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Character Class Default")
	int32 _level = 1.f;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	bool bHighlighted = false;

};
