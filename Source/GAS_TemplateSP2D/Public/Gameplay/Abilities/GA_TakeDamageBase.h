// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GA_SequenceAbility.h"
#include "GA_TakeDamageBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_TakeDamageBase : public UGA_SequenceAbility
{
	GENERATED_BODY()

public:

	UGA_TakeDamageBase();

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

};
