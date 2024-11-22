// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/Bars/W_ManaBar.h"

void UW_ManaBar::SetDefaultValues(UAbilitySystemComponent* OwnerASC)
{
	if (UAS_Hero* HeroAttributes = const_cast<UAS_Hero*>(OwnerASC->GetSet<UAS_Hero>()))
	{
		SetPercantage(HeroAttributes->GetMana(), HeroAttributes->GetMaxMana());
		SetValuesToTexts(HeroAttributes->GetMana(), HeroAttributes->GetMaxMana());
	}
}

void UW_ManaBar::BindAttributes(UAbilitySystemComponent* OwnerASC)
{
	if (UAS_Hero* HeroAttributes = const_cast<UAS_Hero*>(OwnerASC->GetSet<UAS_Hero>()))
	{
		HeroAttributes->OnManaChanged.AddDynamic(this, &UW_ManaBar::ManaChanged);
		HeroAttributes->OnMaxManaChanged.AddDynamic(this, &UW_ManaBar::MaxManaChanged);
	}
}

void UW_ManaBar::ManaChanged(const FAttributeChangeCallbackData& Data)
{
	SetPercantage(Data.CurrentValue, Data.MaxValue);
	SetValuesToTexts(Data.CurrentValue, Data.MaxValue);
}

void UW_ManaBar::MaxManaChanged(const FAttributeChangeCallbackData& Data)
{
	SetPercantage(Data.CurrentValue, Data.MaxValue);
	SetValuesToTexts(Data.CurrentValue, Data.MaxValue);
}
