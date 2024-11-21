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

void UEC_Base::MakeAggregatorEvaluatedParamsByEffectSpec(const FGameplayEffectSpec& EffectSpec, FAggregatorEvaluateParameters& OutEvaluatedParams) const
{
	MakeAggregatorEvaluatedParamsBySourceTagsAndTargetTags(EffectSpec.CapturedSourceTags.GetAggregatedTags(), EffectSpec.CapturedTargetTags.GetAggregatedTags(), OutEvaluatedParams);
}

void UEC_Base::MakeAggregatorEvaluatedParamsBySourceTagsAndTargetTags(const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FAggregatorEvaluateParameters& OutEvaluatedParams) const
{
	OutEvaluatedParams.SourceTags = SourceTags;
	OutEvaluatedParams.TargetTags = TargetTags;
}

float UEC_Base::GetSetByCallerMagnitude(const FGameplayEffectSpec& EffectSpec, const FGameplayTag& DataTag, float DefaultIfNotFound, bool bWarnIfNotFound) const
{
	return FMath::Max<float>(EffectSpec.GetSetByCallerMagnitude(DataTag, bWarnIfNotFound, DefaultIfNotFound), .0f);
}
