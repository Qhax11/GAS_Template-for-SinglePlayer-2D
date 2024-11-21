// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/Bars/W_HealthBar.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "Components/ProgressBar.h"


void UW_HealthBar::BindAttributesAndSetDefaultValues(UAbilitySystemComponent* OwnerASC)
{
	if (UAS_Base* AttributeBase = const_cast<UAS_Base*>(OwnerASC->GetSet<UAS_Base>()))
	{
		BackgroundProgressBar->SetPercent(AttributeBase->GetHealth() / AttributeBase->GetMaxHealth());
		SetPercantage(AttributeBase->GetHealth(), AttributeBase->GetMaxHealth());
		AttributeBase->OnHealthChanged.AddDynamic(this, &UW_HealthBar::HealthChanged);
	}
}

void UW_HealthBar::HealthChanged(const FAttributeChangeCallbackData& Data)
{
	SetPercantage(Data.CurrentValue, Data.MaxValue);
	BP_OnHealthChanged(Data);
}
