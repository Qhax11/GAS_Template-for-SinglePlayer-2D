// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/GCN_ShowTextWidgetCompBase.h"

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

	TriggerWidget(FinalTextColor, FinalTextString, FinalShowTextType);

}

void AGCN_ShowTextWidgetCompBase::DefaultSettings(float Value)
{
}

void AGCN_ShowTextWidgetCompBase::DefaultTextTypeChecks(const FGameplayTagContainer TextTags)
{
}

FString AGCN_ShowTextWidgetCompBase::AddingToString(FString String, FString AddedString, bool EndOfString)
{
	return FString();
}
