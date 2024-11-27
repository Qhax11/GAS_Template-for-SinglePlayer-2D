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

	if (CheckAndExecuteGameplay(Target, Parameters))
	{
		return;
	}

	PrepareText(Parameters.RawMagnitude);

	if (bOverrideText)
	{
		WidgetMessageData.MessageString = OverridedText;
	}

	BP_TriggerWidget(WidgetMessageData);
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

void AGCN_AttachedEffectTextBase::PrepareText(float RawMagnitudeValue)
{
	FString RawMagnitudeValueString = UKismetStringLibrary::Conv_IntToString(FMath::Abs(RawMagnitudeValue));

	FString FinalMessage = PrefixText + RawMagnitudeValueString + SuffixText;

	WidgetMessageData.MessageString = FinalMessage;
}


