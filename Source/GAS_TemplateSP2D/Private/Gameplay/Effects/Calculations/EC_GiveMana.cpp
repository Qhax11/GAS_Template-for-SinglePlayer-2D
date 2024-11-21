// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Effects/Calculations/EC_GiveMana.h"
#include "Gameplay/Attributes/AS_Hero.h"

void UEC_GiveMana::ExecuteWithParams(FExecCalculationParameters Params, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const UAS_Hero* HeroAttributeSet = Cast<UAS_Hero>(Params.GetSourceAttributeSet());
	if (!HeroAttributeSet)
	{
		return;
	}

	// Source attributes
	float TargetMana = HeroAttributeSet->GetMana();
	float TargetMaxMana = HeroAttributeSet->GetMaxMana();

	// We take damage magnitude from SetByCaller, it is in EffectSpec.
	float GiveManaAmount = GetSetByCallerMagnitude(Params.GetSpec(), GAS_Tags::TAG_Gameplay_EffectData_SetByCaller_GiveManaAmount, .0f, true);

	float MaxGiveManaAmountValue = TargetMaxMana - TargetMana;
	float FinalGiveManaAmount = FMath::Clamp(GiveManaAmount, 0, MaxGiveManaAmountValue);

	if (FinalGiveManaAmount <= 0)
	{
		return;
	}

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(HeroAttributeSet->GetManaAttribute(), EGameplayModOp::Additive, FinalGiveManaAmount));
}
