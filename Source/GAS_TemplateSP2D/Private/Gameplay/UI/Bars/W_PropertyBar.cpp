// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/Bars/W_PropertyBar.h"
#include "Components/ProgressBar.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "AbilitySystemGlobals.h"
#include "Kismet/KismetTextLibrary.h"

void UW_PropertyBar::SetPercantage(float Value1, float Value2)
{
	float NewValue = Value1 / Value2;
	if (NewValue >= 0)
	{
		ProgressBar->SetPercent(NewValue);
	}
}

void UW_PropertyBar::SetValuesToTexts(float CurrentValue, float MaxValue)
{
	if (T_CurrentValue && T_MaxValue) 
	{
		T_CurrentValue->SetText(UKismetTextLibrary::Conv_DoubleToText(CurrentValue,
			HalfToEven, false, true, 1, 324, 0, 3));

		T_MaxValue->SetText(UKismetTextLibrary::Conv_DoubleToText(MaxValue,
			HalfToEven, false, true, 1, 324, 0, 3));
	}
}

void UW_PropertyBar::BindAttributes(UAbilitySystemComponent* OwnerASC)
{
	// Implementation will be in subclasses
}

void UW_PropertyBar::SetDefaultValues(UAbilitySystemComponent* OwnerASC)
{
	// Implementation will be in subclasses
}

void UW_PropertyBar::InitializePropertyBar(AActor* Owner)
{
	UAbilitySystemComponent* OwnerASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Owner);
	if (!OwnerASC)
	{
		return;
	}
	SetDefaultValues(OwnerASC);
	BindAttributes(OwnerASC);
}

