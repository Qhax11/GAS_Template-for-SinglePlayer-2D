// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Effects/Calculations/EC_Base.h"

void UEC_Base::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	FExecCalculationParameters Params = FExecCalculationParameters(ExecutionParams);
	ExecuteWithParams(Params, OutExecutionOutput);
}

void UEC_Base::ExecuteWithParams(FExecCalculationParameters Params, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	UE_LOG(LogTemp, Error, TEXT("ExecuteWithParams not implemented in %s"), *GetName());
}
