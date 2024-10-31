// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Effects/Calculations/EC_DamageBase.h"
#include "Gameplay/Attributes/AS_Hero.h"


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

	// Calculate Critical Damage
	CalculateCritical(Params, MitigatedDamage, OutExecutionOutput);

	float HealthDamageDone = MitigatedDamage;
	CalculateHealth(Params, MitigatedDamage, OutExecutionOutput);
	if (MitigatedDamage < HealthDamageDone)
	{
		HealthDamageDone -= MitigatedDamage;
	}

	//life steal
	float LifeStealDone = .0f;
	CalculateLifeSteal(Params, HealthDamageDone, LifeStealDone, OutExecutionOutput);
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

		Params.TargetASC->HandleGameplayEvent(DeathPayload.EventTag, &DeathPayload);
	}

	// subtract health damage done from mitigated damage
	MitigatedDamage -= HealthDamageDone;
}

void UEC_DamageBase::CalculateCritical(FExecCalculationParameters& Params, float& MitigatedDamage, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	if (const UAS_Hero* HeroAttributeSet = Cast<UAS_Hero>(Params.GetSourceAttributeSet()))
	{
		// Critical, if target is build we don't allow critical hit 
		if (Params.EffectAssetTags.HasTag(GAS_Tags::TAG_Gameplay_EffectData_EnableCriticalDamage))
		{
			float CriticalChance = HeroAttributeSet->GetCriticalChance();
			if (CriticalChance > 0 && CalculateCriticalChance(CriticalChance))
			{
				const float CriticalDamage = MitigatedDamage * (HeroAttributeSet->GetCriticalDamage() / 100);

				if (CriticalDamage > 0)
				{
					// For ShowText gameplaycue, we need to know it is critical 
					Params.MutableSpec->AddDynamicAssetTag(GAS_Tags::TAG_UI_HitTypeText_Critical);
				}

				MitigatedDamage += CriticalDamage;
			}
		}
	}
}

bool UEC_DamageBase::CalculateCriticalChance(float CriticalChance) const
{
	int32 x = 100 / CriticalChance;
	float RandomNumber = FMath::RandRange(1, x);
	if (RandomNumber == FMath::RandRange(1, x))
	{
		return true;
	}

	return false;
}

void UEC_DamageBase::CalculateLifeSteal(FExecCalculationParameters& Params, float DamageDone, float& HealDone, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	if (const UAS_Hero* HeroAttributeSet = Cast<UAS_Hero>(Params.GetSourceAttributeSet()))
	{
		/*
		if (Params.EffectAssetTags.HasTag(HDA_Tags::TAG_Gameplay_EnableLifeSteal))
		{
			const float LifeSteal = HeroAttributeSet->GetLifeSteal();
			if (LifeSteal <= 0)
			{
				return;
			}
			HealDone = UHDA_ExecCalcFunctionLibary::CalculateLifeSteal(DamageDone, LifeSteal);
			// Create Effect and assign spec
			FGameplayEffectSpec HealingSpec; // TODO: Life steal
			UHDA_EffectFunctionLibary::CreateEffectWithMagnitude(HealingSpec, Params.SourceASC, UGE_Healing::StaticClass(), HDA_Tags::TAG_Gameplay_SetByCallerHealingAmount, HealDone);
			// Making spec customize 
			UHDA_EffectFunctionLibary::AddTagInEffectSpecWithContain(HealingSpec, Params.EffectAssetTags);
			FActiveGameplayEffectHandle ActiveGEHandle = Params.SourceASC->ApplyGameplayEffectSpecToTarget(HealingSpec, Params.SourceASC);
		}
		*/
	}
}

