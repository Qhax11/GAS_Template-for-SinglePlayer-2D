// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Gameplay/Abilities/GAS_GameplayAbilityBase.h"
#include "AnimSequences/PaperZDAnimSequence.h"
#include "GA_SequenceAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_SequenceAbility : public UGAS_GameplayAbilityBase
{
	GENERATED_BODY()

public:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);

	UPROPERTY(EditDefaultsOnly, Category = "SequenceAbility|Montage")
	TArray<TObjectPtr<UPaperZDAnimSequence>> AnimSequences;

	UPROPERTY(EditDefaultsOnly, Category = "SequenceAbility|Montage")
	FGameplayTag EventTag;

	UPROPERTY(EditDefaultsOnly, Category = "SequenceAbility|Montage")
	FName SlotName = "DefaultSlot";

	UPROPERTY(EditDefaultsOnly, Category = "SequenceAbility|Montage")
	float PlayRate = 1.0f;

protected:
	virtual UPaperZDAnimSequence* SelectSequence();

	virtual void OnCompleted();

	virtual void OnCancelled();

	UFUNCTION()
	virtual void OnEventRecieved();

private:
	void OnOverrideEnd(bool OverrideEnd);

	void BindEventRecievedInAnimSequence(UPaperZDAnimSequence* SelectedSequence);

};
