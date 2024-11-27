// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GA_SequenceAbility.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GA_DeathBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_DeathBase : public UGA_SequenceAbility
{
	GENERATED_BODY()

public:

	UGA_DeathBase();

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void DisableCollisions();

	virtual void BroadcastDeSpawn();
	
};
