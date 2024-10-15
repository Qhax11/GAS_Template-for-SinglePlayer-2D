// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/W_PropertyBar.h"
#include "Components/ProgressBar.h"


void UW_PropertyBar::SetPercantage(float Value1, float Value2)
{
	float NewValue = Value1 / Value2;
	if (NewValue >= 0)
	{
		ProgressBar->SetPercent(NewValue);
	}
}
