// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroAttributesListener.h"
#include "Gameplay/Attributes/AS_Hero.h"

bool UAC_HeroAttributesListener::Initialize(const AActor* OwnerActor)
{
	if (!Super::Initialize(OwnerActor)) 
	{
		return false;
	}

	if (UAS_Hero* BaseAttributes = const_cast<UAS_Hero*>(OwnerASC->GetSet<UAS_Hero>()))
	{
		BaseAttributes->OnManaChanged.AddDynamic(this, &UAC_HeroAttributesListener::ManaChanged);

		if (BaseAttributes->GetMana() == BaseAttributes->GetMaxMana())
		{
			OwnerASC->AddLooseGameplayTag(GAS_Tags::TAG_Gameplay_Mana_Full);
		}

		return true;
	}

	return false;
}

void UAC_HeroAttributesListener::ManaChanged(const FAttributeChangeCallbackData& Data)
{
	if (Data.CurrentValue >= Data.MaxValue)
	{
		OwnerASC->AddLooseGameplayTag(GAS_Tags::TAG_Gameplay_Mana_Full);
	}
	else
	{
		if (OwnerASC->HasMatchingGameplayTag(GAS_Tags::TAG_Gameplay_Mana_Full))
		{
			OwnerASC->RemoveLooseGameplayTag(GAS_Tags::TAG_Gameplay_Mana_Full, 100);
		}
	}
}
