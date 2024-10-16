// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GAS_GameplayAbilityBase.h"
#include "AnimSequences/PaperZDAnimSequence.h"
#include "PaperZDAnimInstance.h"
#include "GA_MontageAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_MontageAbility : public UGAS_GameplayAbilityBase
{
	GENERATED_BODY()

public:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);

	UPROPERTY(EditDefaultsOnly, Category = "MontageAbility|Montage")
	UPaperZDAnimSequence* AnimSequence;

	UPROPERTY(EditDefaultsOnly, Category = "MontageAbility|Montage")
	FName SlotName = "DefaultSlot";

	UPROPERTY(EditDefaultsOnly, Category = "MontageAbility|Montage")
	float PlayRate = 1.0f;


	void AnimEndd(bool End);
};
