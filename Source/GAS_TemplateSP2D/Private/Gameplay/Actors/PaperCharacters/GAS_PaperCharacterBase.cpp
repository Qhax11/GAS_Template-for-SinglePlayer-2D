// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "Gameplay/Components/AC_AbilitySet.h"
#include "Gameplay/Components/AC_Team.h"
#include "Gameplay/Components/AC_TagDelegates.h"
#include "PaperFlipbookComponent.h"

AGAS_PaperCharacterBase::AGAS_PaperCharacterBase(const class FObjectInitializer& ObjectInitializer)
{
	// We want see shadows of characters
	GetSprite()->CastShadow = true;

	PaperCharacterASC = CreateDefaultSubobject<UGAS_AbilitySystemComponent>(TEXT("PaperCharacterASC"));

	AbilitySetComponent = CreateDefaultSubobject<UAC_AbilitySet>(TEXT("AbilitySetComponent"));

	TeamComponent = CreateDefaultSubobject<UAC_Team>(TEXT("TeamComponent"));

	TagDelegatesComponent = CreateDefaultSubobject<UAC_TagDelegates>(TEXT("TagDelegatesComponent"));

	AttributesListenerComponent = CreateDefaultSubobject<UAC_AttributesListenerBase>(TEXT("AttributesListenerComponent"));
}

void AGAS_PaperCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (!PaperCharacterASC)
	{
		UE_LOG(LogTemp, Warning, TEXT("PaperCharacterASC doesen't exist in %s"), *this->GetName());
		return;
	}

	PaperCharacterASC->InitAbilityActorInfo(this, this);
	AbilitySetComponent->Initialize(PaperCharacterASC);
}

UAbilitySystemComponent* AGAS_PaperCharacterBase::GetAbilitySystemComponent() const
{
	return PaperCharacterASC;
}





