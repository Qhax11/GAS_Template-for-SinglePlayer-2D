// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "Gameplay/Components/AC_AttributesListenerBase.h"
#include "Gameplay/Components/AC_AbilitySet.h"
#include "Gameplay/Components/AC_Team.h"
#include "Gameplay/Components/AC_TagDelegates.h"
#include "Gameplay/Components/AC_GameplayData.h"
#include "GameFramework/CharacterMovementComponent.h"
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

	GameplayDataComponent = CreateDefaultSubobject<UAC_GameplayData>(TEXT("GameplayDataComponent"));
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

void AGAS_PaperCharacterBase::DisableMovement()
{
	if (UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement())
	{
		CharacterMovementComponent->DisableMovement();
	}
}

void AGAS_PaperCharacterBase::EnableMovement()
{
	if (UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement())
	{
		CharacterMovementComponent->SetMovementMode(EMovementMode::MOVE_Walking);
	}
}





