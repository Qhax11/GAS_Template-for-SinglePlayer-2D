// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_MontageAbility.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "PaperZDAnimationComponent.h"
#include "PaperZDAnimInstance.h"
#include "Animations/Notifys/AN_EventReceived.h"


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

	AGAS_PaperCharacterBase* PaperCharacter = CastChecked<AGAS_PaperCharacterBase>(GetAvatarActorFromActorInfo());
	if (!PaperCharacter) 
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	UPaperZDAnimationComponent* PaperZDAnimComp = PaperCharacter->GetComponentByClass<UPaperZDAnimationComponent>();
	if (!PaperZDAnimComp)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	BindEventRecievedInAnimSequence();

	if (UPaperZDAnimInstance* AnimInstance = PaperZDAnimComp->GetAnimInstance())
	{
		FZDOnAnimationOverrideEndSignature OnOverrideEnd;
		OnOverrideEnd.BindUObject(this, &UGA_MontageAbility::OnOverrideEnd);
		AnimInstance->PlayAnimationOverride(AnimSequence, SlotName, PlayRate, 0.0f, OnOverrideEnd);
	}
}

void UGA_MontageAbility::OnCompleted()
{
	EndAbility(CurrentSpecHandle, GetCurrentActorInfo(), GetCurrentActivationInfo(), false, false);
}

void UGA_MontageAbility::OnCancelled()
{
	EndAbility(CurrentSpecHandle, GetCurrentActorInfo(), GetCurrentActivationInfo(), false, true);
}

void UGA_MontageAbility::OnOverrideEnd(bool OverrideEnd)
{
	if (OverrideEnd)
	{
		OnCompleted();
	}
	else
	{
		OnCancelled();
	}
}

void UGA_MontageAbility::OnEventRecieved()
{
	/* Will be implemented in child classes */
}

void UGA_MontageAbility::BindEventRecievedInAnimSequence()
{
	if (AnimSequence) 
	{
		TArray<UPaperZDAnimNotify_Base*> AnimNotifies = AnimSequence->GetAnimNotifies();
		for (UPaperZDAnimNotify_Base* PaperZDAnimNotify_Base : AnimNotifies)
		{
			if (UAN_EventReceived* EventReceived = Cast<UAN_EventReceived>(PaperZDAnimNotify_Base))
			{
				if (EventReceived->EventTag == EventTag)
				{
					EventReceived->OnEventReceived.AddDynamic(this, &UGA_MontageAbility::OnEventRecieved);
				}
			}
		}
	}
}
