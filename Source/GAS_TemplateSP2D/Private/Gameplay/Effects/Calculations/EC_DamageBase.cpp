// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Effects/Calculations/EC_DamageBase.h"

void UEC_DamageBase::ExecuteWithParams(FExecCalculationParameters Params, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	// Gameplay tags that are attached to the ***Effect*** (not the actor!)

	// If we target has a damage immune tage, we shouldn't be able to attack
	/*
	if (Params.TargetASC->HasMatchingGameplayTag(GAS_Tags::TAG_Gameplay_DamageImmune))
	{
		return;
	}
	*/

	float MitigatedDamage = GetTotalDamage(Params);

	float HealthDamageDone = MitigatedDamage;
	CalculateHealth(Params, MitigatedDamage, OutExecutionOutput);
	if (MitigatedDamage < HealthDamageDone)
	{
		HealthDamageDone -= MitigatedDamage;
	}

	/*
	// Capture DamageDone in spec for acces from outside of effect
	Params.MutableSpec->SetSetByCallerMagnitude(HDA_Tags::TAG_Gameplay_ExecCalculation_TotalDamageDone, HealthDamageDone + ShieldDamageDone);
	*/
}

float UEC_DamageBase::GetBaseDamage(const FExecCalculationParameters& Params) const
{
	const float CustomDamage = FMath::Max<float>(Params.GetSpec().GetSetByCallerMagnitude(GAS_Tags::TAG_Gameplay_SetByCaller_DamageAmount, .0f, true), .0f);
	return CustomDamage;
}

float UEC_DamageBase::GetBonusDamagePercentage(const FExecCalculationParameters& Params) const
{
	return 0.f;
}

float UEC_DamageBase::GetTotalDamage(const FExecCalculationParameters& Params) const
{
	const float BaseDamage = GetBaseDamage(Params);
	const float BonusDamagePercentage = GetBonusDamagePercentage(Params);

	if (BonusDamagePercentage > 1) 
	{
		return  BaseDamage * BonusDamagePercentage;
	}
	return  BaseDamage;
}


void UEC_DamageBase::CalculateHealth(FExecCalculationParameters& Params, float& MitigatedDamage, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const float CurrentTargetHealth = Params.GetTargetAttributeSet()->GetHealth();
	// This clamp prevents us from doing more damage than there is health available.
	const float HealthDamageDone = FMath::Clamp(MitigatedDamage, 0.0f, CurrentTargetHealth);

	// ****************** APPLY DAMAGE ******************
	// apply that damage to the target's health  
	if (HealthDamageDone > 0)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Params.GetTargetAttributeSet()->GetHealthAttribute(), EGameplayModOp::Additive, -HealthDamageDone));
	}
	//Params.MutableSpec->SetSetByCallerMagnitude(GAS_Tags::TAG_Gameplay_ExecCalculation_HealthDamageAmount, HealthDamageDone);

	// Trigger TakeDamage Ability
	if (HealthDamageDone > 0)
	{
		FGameplayEventData TakeDamagePaload;
		TakeDamagePaload.EventTag = GAS_Tags::TAG_Gameplay_GameplayEvent_TakeDamage;
		TakeDamagePaload.Instigator = Params.SourceActor;
		TakeDamagePaload.Target = Params.TargetActor;
		TakeDamagePaload.EventMagnitude = HealthDamageDone;
		TakeDamagePaload.ContextHandle = Params.GetSpec().GetContext();
		TakeDamagePaload.InstigatorTags = Params.GetSpec().CapturedSourceTags.GetActorTags();

		//FScopedPredictionWindow NewScopedWindow(Params.TargetASC, true);
		Params.TargetASC->HandleGameplayEvent(TakeDamagePaload.EventTag, &TakeDamagePaload);
	}

	// Trigger Death Ability
	if (MitigatedDamage >= CurrentTargetHealth)
	{
		FGameplayEventData DeathPayload;
		DeathPayload.EventTag = GAS_Tags::TAG_Gameplay_GameplayEvent_Death;
		DeathPayload.Instigator = Params.SourceActor;
		DeathPayload.Target = Params.TargetActor;
		DeathPayload.ContextHandle = Params.GetSpec().GetContext();
		DeathPayload.InstigatorTags = Params.GetSpec().CapturedSourceTags.GetActorTags();

		//FScopedPredictionWindow NewScopedWindow(Params.TargetASC, true);
		Params.TargetASC->HandleGameplayEvent(DeathPayload.EventTag, &DeathPayload);
	}

	// subtract health damage done from mitigated damage
	MitigatedDamage -= HealthDamageDone;
}
