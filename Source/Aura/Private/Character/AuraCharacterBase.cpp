#include "Character/AuraCharacterBase.h"
#include "AbilitySystemComponent.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	_weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	_weapon->SetupAttachment(GetMesh(), FName(TEXT("WeaponHandSocket")));
	_weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
	
}

void AAuraCharacterBase::InitializeDefaultAttributes()
{
	ApplyEffectToSelf(_defaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(_defaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(_defaultVitalAttributes, 1.f);
}

void AAuraCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	
	FGameplayEffectContextHandle EffectContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, EffectContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), GetAbilitySystemComponent());
}
