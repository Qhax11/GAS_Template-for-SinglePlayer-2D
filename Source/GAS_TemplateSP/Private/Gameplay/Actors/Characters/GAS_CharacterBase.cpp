// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/Characters/GAS_CharacterBase.h"

// Sets default values
AGAS_CharacterBase::AGAS_CharacterBase()
{
	CharacterBaseASC = CreateDefaultSubobject<UGAS_AbilitySystemComponent>(TEXT("CharacterBaseASC"));
	AbilitySetComponent = CreateDefaultSubobject<UAC_AbilitySet>(TEXT("AbilitySetComponent"));
}

void AGAS_CharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (CharacterBaseASC)
	{
		CharacterBaseASC->InitAbilityActorInfo(this, this);
		AbilitySetComponent->Initialize(CharacterBaseASC);
	}
}

UAbilitySystemComponent* AGAS_CharacterBase::GetAbilitySystemComponent() const
{
	return CharacterBaseASC;
}



