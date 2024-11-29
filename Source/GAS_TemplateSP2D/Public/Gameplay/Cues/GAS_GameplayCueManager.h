// Qhax's GAS Template for SinglePlayer

#pragma once

#include "GameplayCueManager.h"
#include "GAS_GameplayCueManager.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGAS_GameplayCueManager : public UGameplayCueManager
{
	GENERATED_BODY()
	
public:

	virtual void InvokeGameplayCueExecuted_FromSpec(UAbilitySystemComponent* OwningComponent, const FGameplayEffectSpec& Spec, FPredictionKey PredictionKey) override;

	virtual void InvokeGameplayCueExecuted(UAbilitySystemComponent* OwningComponent, const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext) override;

	virtual void InvokeGameplayCueExecuted_WithParams(UAbilitySystemComponent* OwningComponent, const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters) override;

	virtual bool ProcessPendingCueExecute(FGameplayCuePendingExecute& PendingCue) override;
};
