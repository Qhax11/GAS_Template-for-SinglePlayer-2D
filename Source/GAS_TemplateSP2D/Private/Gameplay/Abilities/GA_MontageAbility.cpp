// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_MontageAbility.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "PaperZDAnimationComponent.h"
#include "PaperZDAnimInstance.h"


void UGA_MontageAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	AActor* AvatarActor = GetAvatarActorFromActorInfo();
	if (!AvatarActor)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	AGAS_PaperCharacterBase* PaperCharacter = CastChecked<AGAS_PaperCharacterBase>(AvatarActor);
	if (UPaperZDAnimationComponent* PaperZDAnimComp = PaperCharacter->GetComponentByClass<UPaperZDAnimationComponent>())
	{
		if (UPaperZDAnimInstance* AnimInstance = PaperZDAnimComp->GetAnimInstance()) 
		{
			FZDOnAnimationOverrideEndSignature AnimEnd;
			AnimEnd.BindUObject(this, &UGA_MontageAbility::OnAnimEnd);
			AnimInstance->PlayAnimationOverride(AnimSequence, SlotName, PlayRate, 0.0f, AnimEnd);
		}
	}
}

void UGA_MontageAbility::OnAnimEnd(bool Finished)
{
	if(Finished)
	{
		EndAbility(CurrentSpecHandle, GetCurrentActorInfo(), GetCurrentActivationInfo(), false, false);
	}
	else
	{
		// Cancelled
		EndAbility(CurrentSpecHandle, GetCurrentActorInfo(), GetCurrentActivationInfo(), false, true);
	}
}
