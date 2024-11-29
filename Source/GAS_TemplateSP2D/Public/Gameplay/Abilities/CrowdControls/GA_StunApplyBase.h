// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Gameplay/Abilities/GA_SequenceAbility.h"
#include "GA_StunApplyBase.generated.h"


UCLASS()
class GAS_TEMPLATESP2D_API UGA_StunApplyBase : public UGA_SequenceAbility
{
	GENERATED_BODY()

public:

	UGA_StunApplyBase();
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* OwnerInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled);

protected:

	ACharacter* Character;

	class UCharacterMovementComponent* CharacterMoveComp;
};
