// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Effects/GE_GainHealth.h"
#include "Gameplay/Effects/Calculations/EC_GainHealth.h"

UGE_GainHealth::UGE_GainHealth()
{
	FGameplayEffectExecutionDefinition GainHealthCalculation;
	GainHealthCalculation.CalculationClass = UEC_GainHealth::StaticClass();
	Executions.Add(GainHealthCalculation);

	FGameplayEffectCue GainHealthAttachedTextCue = FGameplayEffectCue(GAS_Tags::TAG_GameplayCue_AttachedEffectText_GainHealth, .0f, .0f);
	GainHealthAttachedTextCue.MagnitudeAttribute = UAS_Base::GetHealthAttribute();
	GameplayCues.Add(GainHealthAttachedTextCue);
}
