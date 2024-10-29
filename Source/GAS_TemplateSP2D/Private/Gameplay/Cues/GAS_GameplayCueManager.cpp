// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/GAS_GameplayCueManager.h"

void UGAS_GameplayCueManager::InvokeGameplayCueExecuted_FromSpec(UAbilitySystemComponent* OwningComponent, const FGameplayEffectSpec& Spec, FPredictionKey PredictionKey)
{
	Super::InvokeGameplayCueExecuted_FromSpec(OwningComponent, Spec, PredictionKey);

	// Further Customizations will be added to here.
}

void UGAS_GameplayCueManager::InvokeGameplayCueExecuted(UAbilitySystemComponent* OwningComponent, const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext)
{
	Super::InvokeGameplayCueExecuted(OwningComponent, GameplayCueTag, PredictionKey, EffectContext);

	// Further Customizations will be added to here.
}

void UGAS_GameplayCueManager::InvokeGameplayCueExecuted_WithParams(UAbilitySystemComponent* OwningComponent, const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters)
{
	Super::InvokeGameplayCueExecuted_WithParams(OwningComponent, GameplayCueTag, PredictionKey, GameplayCueParameters);

	// Further Customizations will be added to here.
}

bool UGAS_GameplayCueManager::ProcessPendingCueExecute(FGameplayCuePendingExecute& PendingCue)
{
	return true;
}
