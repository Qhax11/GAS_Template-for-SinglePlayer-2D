// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/Bars/W_HealthBar.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "Components/ProgressBar.h"


void UW_HealthBar::BindAttributes(UAbilitySystemComponent* OwnerASC)
{
	if (UAS_Base* AttributeBase = const_cast<UAS_Base*>(OwnerASC->GetSet<UAS_Base>()))
	{
		AttributeBase->OnHealthChanged.AddDynamic(this, &UW_HealthBar::HealthChanged);
		AttributeBase->OnMaxHealthChanged.AddDynamic(this, &UW_HealthBar::MaxHealthChanged);
	}
}

void UW_HealthBar::SetDefaultValues(UAbilitySystemComponent* OwnerASC)
{
	if (UAS_Base* AttributeBase = const_cast<UAS_Base*>(OwnerASC->GetSet<UAS_Base>()))
	{
		BackgroundProgressBar->SetPercent(AttributeBase->GetHealth() / AttributeBase->GetMaxHealth());
		SetPercantage(AttributeBase->GetHealth(), AttributeBase->GetMaxHealth());
		SetValuesToTexts(AttributeBase->GetHealth(), AttributeBase->GetMaxHealth());
	}
}

void UW_HealthBar::HealthChanged(const FAttributeChangeCallbackData& Data)
{
	SetPercantage(Data.CurrentValue, Data.MaxValue);
	SetValuesToTexts(Data.CurrentValue, Data.MaxValue);
	BP_OnHealthChanged(Data);
}

void UW_HealthBar::MaxHealthChanged(const FAttributeChangeCallbackData& Data)
{
	SetPercantage(Data.CurrentValue, Data.MaxValue);
	SetValuesToTexts(Data.CurrentValue, Data.MaxValue);
	BP_OnHealthChanged(Data);
}
