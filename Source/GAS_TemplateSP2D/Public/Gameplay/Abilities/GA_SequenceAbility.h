// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GAS_GameplayAbilityBase.h"
#include "AnimSequences/PaperZDAnimSequence.h"
#include "AbilitySystemGlobals.h"
#include "GA_SequenceAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_SequenceAbility : public UGAS_GameplayAbilityBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "SequenceAbility|Montage")
	UPaperZDAnimSequence* AnimSequence;

	UPROPERTY(EditDefaultsOnly, Category = "SequenceAbility|Montage")
	FGameplayTag EventTag;

	UPROPERTY(EditDefaultsOnly, Category = "SequenceAbility|Montage")
	FName SlotName = "DefaultSlot";

	UPROPERTY(EditDefaultsOnly, Category = "SequenceAbility|Montage")
	float PlayRate = 1.0f;

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);

protected:
	virtual void OnCompleted();

	virtual void OnCancelled();

	UFUNCTION()
	virtual void OnEventRecieved();

private:
	void OnOverrideEnd(bool OverrideEnd);

	void BindEventRecievedInAnimSequence();

};
