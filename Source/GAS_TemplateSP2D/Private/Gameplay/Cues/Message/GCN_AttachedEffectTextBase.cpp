// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/Message/GCN_AttachedEffectTextBase.h"
#include "Kismet/KismetStringLibrary.h"
#include "Gameplay/Tags/GAS_Tags.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"

AGCN_AttachedEffectTextBase::AGCN_AttachedEffectTextBase()
{
	WC_AttachedEffectText = CreateDefaultSubobject<UWC_AttachedEffectTextHandle>(TEXT("WC_AttachedEffectTextHandle"));
}

void AGCN_AttachedEffectTextBase::OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	Super::OnExecuted(Source, Target, Parameters);

	if (!Source || !Target)
	{
		return;
	}

	PrepareText(Parameters.RawMagnitude);

	if (bOverrideText)
	{
		FinalTextString = OverridedText;
	}

	BP_TriggerWidget(FinalTextColor, FinalTextString, FinalShowTextType);
}

bool AGCN_AttachedEffectTextBase::CheckAndExecuteGameplay(AActor* Target, FGameplayCueParameters Parameters)
{
	if (Parameters.AggregatedSourceTags.HasTagExact(GAS_Tags::TAG_UI_HitTypeText_Critical))
	{
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Target))
		{
			// Removing Critical GameplayTag to shouldn't be loop because of ExecuteGameplayCue
			Parameters.AggregatedSourceTags.RemoveTag(GAS_Tags::TAG_UI_HitTypeText_Critical);
			TargetASC->ExecuteGameplayCue(GAS_Tags::TAG_GameplayCue_AttachedEffectText_Critical, Parameters);
			return true;
		}
	}
	return false;
}

void AGCN_AttachedEffectTextBase::PrepareText(float Value)
{
	FString ValueString = UKismetStringLibrary::Conv_IntToString(FMath::Abs(Value));

	FinalTextString = AddingToString(ValueString, WillBeAddedEndOfText, true);
	FinalTextString = AddingToString(FinalTextString, WillBeAddedFrontOfText, false);
}

FString AGCN_AttachedEffectTextBase::AddingToString(FString String, FString AddedString, bool EndOfString)
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
