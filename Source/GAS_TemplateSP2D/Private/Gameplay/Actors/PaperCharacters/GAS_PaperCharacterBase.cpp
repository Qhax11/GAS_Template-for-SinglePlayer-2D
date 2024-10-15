// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "PaperFlipbookComponent.h"


AGAS_PaperCharacterBase::AGAS_PaperCharacterBase()
{
	// We want see shadows of characters
	GetSprite()->CastShadow = true;

	PaperCharacterASC = CreateDefaultSubobject<UGAS_AbilitySystemComponent>(TEXT("PaperCharacterASC"));
	AbilitySetComponent = CreateDefaultSubobject<UAC_AbilitySet>(TEXT("AbilitySetComponent"));
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

	if (UGAS_AttributeSetBase* GSCAttributeSet = const_cast<UGAS_AttributeSetBase*>(PaperCharacterASC->GetSet<UGAS_AttributeSetBase>()))
	{
		GSCAttributeSet->OnHealthChanged.AddDynamic(this, &AGAS_PaperCharacterBase::HealthChanged);
	}
}

UAbilitySystemComponent* AGAS_PaperCharacterBase::GetAbilitySystemComponent() const
{
	return PaperCharacterASC;
}

void AGAS_PaperCharacterBase::HealthChanged(const FAttributeChangeCallbackData& Data)
{
	if (Data.CurrentValue <= 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("UR DEAD"));
	}
}


