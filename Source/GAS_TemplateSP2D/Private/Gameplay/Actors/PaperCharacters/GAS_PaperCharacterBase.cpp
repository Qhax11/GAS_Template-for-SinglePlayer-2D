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

	if (UAS_Base* BaseAttributes = const_cast<UAS_Base*>(PaperCharacterASC->GetSet<UAS_Base>()))
	{
		BaseAttributes->OnHealthChanged.AddDynamic(this, &AGAS_PaperCharacterBase::HealthChanged);

		if (BaseAttributes->GetHealth() == BaseAttributes->GetMaxHealth())
		{
			GetAbilitySystemComponent()->AddLooseGameplayTag(GAS_Tags::TAG_Gameplay_Health_Full);
		}
	}
}

UAbilitySystemComponent* AGAS_PaperCharacterBase::GetAbilitySystemComponent() const
{
	return PaperCharacterASC;
}

void AGAS_PaperCharacterBase::HealthChanged(const FAttributeChangeCallbackData& Data)
{
	if (Data.CurrentValue >= Data.MaxValue)
	{
		GetAbilitySystemComponent()->AddLooseGameplayTag(GAS_Tags::TAG_Gameplay_Health_Full);
	}
	else
	{
		if (GetAbilitySystemComponent()->HasMatchingGameplayTag(GAS_Tags::TAG_Gameplay_Health_Full))
		{
			GetAbilitySystemComponent()->RemoveLooseGameplayTag(GAS_Tags::TAG_Gameplay_Health_Full, 100);
		}
	}
}




