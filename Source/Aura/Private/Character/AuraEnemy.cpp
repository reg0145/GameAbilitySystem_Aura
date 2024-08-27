#include "Character/AuraEnemy.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"


AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetMesh()->SetRenderCustomDepth(false);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	_weapon->SetRenderCustomDepth(false);
	_weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	_abilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>(TEXT("AbilitySystem"));
	_abilitySystemComponent->SetIsReplicated(true);
	_abilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	_attributeSet = CreateDefaultSubobject<UAuraAttributeSet>(TEXT("AttibuteSet"));
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();

	_abilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	_weapon->SetRenderCustomDepth(true);
}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	_weapon->SetRenderCustomDepth(false);
}
