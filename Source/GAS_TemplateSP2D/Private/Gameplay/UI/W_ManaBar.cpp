// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/W_ManaBar.h"

void UW_ManaBar::BindAttributesAndSetDefaultValues(UAbilitySystemComponent* OwnerASC)
{
	if (UAS_Hero* HeroAttributes = const_cast<UAS_Hero*>(OwnerASC->GetSet<UAS_Hero>()))
	{
		SetPercantage(HeroAttributes->GetMana(), HeroAttributes->GetMaxMana());
		HeroAttributes->OnManaChanged.AddDynamic(this, &UW_ManaBar::ManaChanged);
	}
}

void UW_ManaBar::ManaChanged(const FAttributeChangeCallbackData& Data)
{
	SetPercantage(Data.CurrentValue, Data.MaxValue);
}
