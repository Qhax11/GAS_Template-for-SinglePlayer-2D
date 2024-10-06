// Qhax's GAS Template for SinglePlayer



#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"

AGAS_PaperCharacterBase::AGAS_PaperCharacterBase()
{
	PaperCharacterASC = CreateDefaultSubobject<UGAS_AbilitySystemComponent>(TEXT("PaperCharacterASC"));
	AbilitySetComponent = CreateDefaultSubobject<UAC_AbilitySet>(TEXT("AbilitySetComponent"));
}

void AGAS_PaperCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (PaperCharacterASC)
	{
		PaperCharacterASC->InitAbilityActorInfo(this, this);
		AbilitySetComponent->Initialize(PaperCharacterASC);
	}
}

UAbilitySystemComponent* AGAS_PaperCharacterBase::GetAbilitySystemComponent() const
{
	return PaperCharacterASC;
}


