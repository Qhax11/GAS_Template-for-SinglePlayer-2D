// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/W_HealthBar.h"
#include "Gameplay/Attributes/GAS_AttributeSetBase.h"
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
	if (UGAS_AttributeSetBase* GSCAttributeSet = const_cast<UGAS_AttributeSetBase*>(OwnerASC->GetSet<UGAS_AttributeSetBase>()))
	{
		SetPercantage(GSCAttributeSet->GetHealth(), GSCAttributeSet->GetMaxHealth());
		GSCAttributeSet->OnHealthChanged.AddDynamic(this, &UW_HealthBar::HealthChanged);
	}
}

void UW_HealthBar::HealthChanged(const FAttributeChangeCallbackData& Data)
{
	SetPercantage(Data.CurrentValue, Data.MaxValue);
}
