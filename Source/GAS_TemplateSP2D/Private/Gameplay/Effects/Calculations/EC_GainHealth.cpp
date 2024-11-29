// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Effects/Calculations/EC_GainHealth.h"

void UEC_GainHealth::ExecuteWithParams(FExecCalculationParameters Params, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	if (!Params.GetTargetAttributeSet())
	{
		return;
	}

	// Source attributes
	float TargetHealth = Params.GetTargetAttributeSet()->GetHealth();
	float TargetMaxHealth = Params.GetTargetAttributeSet()->GetMaxHealth();

	// We take damage magnitude from SetByCaller, it is in EffectSpec.
	float GainHealthAmount = GetSetByCallerMagnitude(Params.GetSpec(), GAS_Tags::TAG_Gameplay_EffectData_SetByCaller_GainHealthAmount, .0f, true);

	float MaxGainHealthAmountValue = TargetMaxHealth - TargetHealth;
	float FinalGainHealthAmount = FMath::Clamp(GainHealthAmount, 0, MaxGainHealthAmountValue);

	if (FinalGainHealthAmount <= 0)
	{
		return;
	}

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Params.GetTargetAttributeSet()->GetHealthAttribute(), EGameplayModOp::Additive, FinalGainHealthAmount));
}
