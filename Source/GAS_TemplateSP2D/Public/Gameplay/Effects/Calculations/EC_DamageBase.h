// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
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

	virtual void CalculateHealth(FExecCalculationParameters& Params, float& MitigatedDamage, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const;

};
