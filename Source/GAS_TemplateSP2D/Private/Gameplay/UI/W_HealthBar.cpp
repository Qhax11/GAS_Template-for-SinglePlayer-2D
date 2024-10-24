// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/W_HealthBar.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "AbilitySystemGlobals.h"


void UW_HealthBar::Initialize(AActor* Owner)
{
	UAbilitySystemComponent* OwnerASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Owner);
	if (!OwnerASC)
	{
		return;
	}
	BindAttributesAndSetDefaultValues(OwnerASC);
}

void UW_HealthBar::BindAttributesAndSetDefaultValues(UAbilitySystemComponent* OwnerASC)
{
	if (UAS_Base* GSCAttributeSet = const_cast<UAS_Base*>(OwnerASC->GetSet<UAS_Base>()))
	{
		SetPercantage(GSCAttributeSet->GetHealth(), GSCAttributeSet->GetMaxHealth());
		GSCAttributeSet->OnHealthChanged.AddDynamic(this, &UW_HealthBar::HealthChanged);
	}
}

void UW_HealthBar::HealthChanged(const FAttributeChangeCallbackData& Data)
{
	SetPercantage(Data.CurrentValue, Data.MaxValue);
}
