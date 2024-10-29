// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/GCN_ShowTextWidgetCompBase.h"
#include "Kismet/KismetStringLibrary.h"

AGCN_ShowTextWidgetCompBase::AGCN_ShowTextWidgetCompBase()
{
	ShowTextHandle = CreateDefaultSubobject<UWC_ShowTextHandle>(TEXT("WC_ShowTextHandle"));
}

void AGCN_ShowTextWidgetCompBase::OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	if (!Source || !Target)
	{
		return;
	}

	FinalTextColor = WidgetTextColor;
	FinalShowTextType = WidgetTextAnim;

	if (bOverrideText) 
	{
		FinalTextString = OverridedText;
		TriggerWidget(FinalTextColor, FinalTextString, FinalShowTextType);
	}
	else
	{
		DefaultSettings(Parameters.RawMagnitude);
		TriggerWidget(FinalTextColor, FinalTextString, FinalShowTextType);
	}
}

void AGCN_ShowTextWidgetCompBase::DefaultSettings(float Value)
{
	FString ValueString = UKismetStringLibrary::Conv_IntToString(FMath::Abs(Value));

	FinalTextString = AddingToString(ValueString, WillBeAddedEndOfText, true);
	FinalTextString = AddingToString(FinalTextString, WillBeAddedFrontOfText, false);
}

FString AGCN_ShowTextWidgetCompBase::AddingToString(FString String, FString AddedString, bool EndOfString)
{
	if (EndOfString)
	{
		return UKismetStringLibrary::Concat_StrStr(String, AddedString);
	}
	else
	{
		return UKismetStringLibrary::Concat_StrStr(AddedString, String);
	}
}
