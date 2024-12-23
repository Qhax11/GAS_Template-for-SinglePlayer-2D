// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Gameplay/Effects/Calculations/EC_Base.h"
#include "EC_DamageBase.generated.h"


UCLASS()
class GAS_TEMPLATESP2D_API UEC_DamageBase : public UEC_Base
{
	GENERATED_BODY()
	
public:

	virtual void ExecuteWithParams(FExecCalculationParameters Params, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

	virtual float GetBaseDamage(const FExecCalculationParameters& Params) const;

	virtual float GetBonusDamagePercentage(const FExecCalculationParameters& Params) const;

	virtual float GetTotalDamage(const FExecCalculationParameters& Params) const;

	virtual float GetDamageReduction(const FExecCalculationParameters& Params) const;

	virtual float GetTotalDamageReduction(const FExecCalculationParameters& Params, float MitigatedDamage) const;

	virtual void CalculateDamageReduction(FExecCalculationParameters& Params, float& MitigatedDamage, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const;

	virtual float CalculateHealth(FExecCalculationParameters& Params, float& MitigatedDamage, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const;

	virtual void TriggerGameplayEvent(FExecCalculationParameters& Params, const FGameplayTag& EventTag, float EventMagnitude = 0.0f) const;

	virtual void CalculateCritical(FExecCalculationParameters& Params, float& MitigatedDamage, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const;

	virtual bool CalculateCriticalChance(float CriticalChance) const;

	virtual void CalculateLifeSteal(FExecCalculationParameters& Params, float DamageDone, float& HealDone, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const;
};
