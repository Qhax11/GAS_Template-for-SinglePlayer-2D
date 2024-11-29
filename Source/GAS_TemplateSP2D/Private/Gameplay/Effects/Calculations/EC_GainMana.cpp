// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Effects/Calculations/EC_GainMana.h"
#include "Gameplay/Attributes/AS_Hero.h"

void UEC_GainMana::ExecuteWithParams(FExecCalculationParameters Params, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
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
	float GainManaAmount = GetSetByCallerMagnitude(Params.GetSpec(), GAS_Tags::TAG_Gameplay_EffectData_SetByCaller_GainManaAmount, .0f, true);

	float MaxGainManaAmountValue = TargetMaxMana - TargetMana;
	float FinalGainManaAmount = FMath::Clamp(GainManaAmount, 0, MaxGainManaAmountValue);

	if (FinalGainManaAmount <= 0)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("GainManaAmount: %d"), GainManaAmount);
	UE_LOG(LogTemp, Warning, TEXT("MaxGainManaAmountValue: %d"), MaxGainManaAmountValue);
	UE_LOG(LogTemp, Warning, TEXT("FinalGainManaAmount: %d"), FinalGainManaAmount);

	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(HeroAttributeSet->GetManaAttribute(), EGameplayModOp::Additive, FinalGainManaAmount));
}
