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
	float HealAmount = GetSetByCallerMagnitude(Params.GetSpec(), GAS_Tags::TAG_Gameplay_EffectData_SetByCaller_HealingAmount, .0f, true);

	float MaxHealAmountValue = TargetMaxHealth - TargetHealth;
	float FinalHealAmount = FMath::Clamp(HealAmount, 0, MaxHealAmountValue);

	if (FinalHealAmount <= 0)
	{
		return;
	}

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Params.GetTargetAttributeSet()->GetHealthAttribute(), EGameplayModOp::Additive, FinalHealAmount));
}
