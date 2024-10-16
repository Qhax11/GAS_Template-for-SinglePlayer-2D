// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_MontageAbility.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "PaperZDAnimationComponent.h"


void UGA_MontageAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	FZDOnAnimationOverrideEndSignature AnimEnd;
	AnimEnd.BindUObject(this, &UGA_MontageAbility::AnimEndd);

	AGAS_PaperCharacterBase* PaperCharacter = CastChecked<AGAS_PaperCharacterBase>(GetAvatarActorFromActorInfo());
	if (UPaperZDAnimationComponent* PaperZDAnimComp = PaperCharacter->GetComponentByClass<UPaperZDAnimationComponent>())
	{
		UPaperZDAnimInstance* AnimInstance = PaperZDAnimComp->GetAnimInstance();
		AnimInstance->PlayAnimationOverride(AnimSequence, SlotName, PlayRate, 0.0f, AnimEnd);
	}
}

void UGA_MontageAbility::AnimEndd(bool End)
{
	EndAbility(CurrentSpecHandle, GetCurrentActorInfo(), GetCurrentActivationInfo(), false, false);
}
