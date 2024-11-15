// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/Bars/W_PropertyBar.h"
#include "Components/ProgressBar.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "AbilitySystemGlobals.h"

void UW_PropertyBar::SetPercantage(float Value1, float Value2)
{
	float NewValue = Value1 / Value2;
	if (NewValue >= 0)
	{
		ProgressBar->SetPercent(NewValue);
	}
}

void UW_PropertyBar::InitializePropertyBar(AActor* Owner)
{
	UAbilitySystemComponent* OwnerASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Owner);
	if (!OwnerASC)
	{
		return;
	}
	BindAttributesAndSetDefaultValues(OwnerASC);
}

void UW_PropertyBar::BindAttributesAndSetDefaultValues(UAbilitySystemComponent* OwnerASC)
{
	// Implementation will be in subclasses
}
