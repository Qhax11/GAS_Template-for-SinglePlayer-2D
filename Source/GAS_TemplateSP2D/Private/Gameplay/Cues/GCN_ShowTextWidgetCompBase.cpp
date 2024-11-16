// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/GCN_ShowTextWidgetCompBase.h"
#include "Kismet/KismetStringLibrary.h"
#include "Gameplay/Tags/GAS_Tags.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"

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

	// If we execute different cue
	if (TagChecks(Target, Parameters))
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
		PrepareText(Parameters.RawMagnitude);
		TriggerWidget(FinalTextColor, FinalTextString, FinalShowTextType);
	}
}

bool AGCN_ShowTextWidgetCompBase::TagChecks(AActor* Target, FGameplayCueParameters Parameters)
{
	// If we have a critical text tag in spec we just execute Critical cue
	if (Parameters.AggregatedSourceTags.HasTagExact(GAS_Tags::TAG_UI_HitTypeText_Critical))
	{
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Target))
		{
			// Removing critical tag for don't be loop
			Parameters.AggregatedSourceTags.RemoveTag(GAS_Tags::TAG_UI_HitTypeText_Critical);
			TargetASC->ExecuteGameplayCue(GAS_Tags::TAG_GameplayCue_ShowText_Critical, Parameters);
			return true;
		}
	}
	return false;
}

void AGCN_ShowTextWidgetCompBase::PrepareText(float Value)
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
