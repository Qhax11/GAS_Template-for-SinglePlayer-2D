// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_SequenceAbility.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "PaperZDAnimationComponent.h"
#include "PaperZDAnimInstance.h"
#include "Animations/Notifys/AN_EventReceived.h"


void UGA_SequenceAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
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
		OnOverrideEnd.BindUObject(this, &UGA_SequenceAbility::OnOverrideEnd);
		AnimInstance->PlayAnimationOverride(AnimSequence, SlotName, PlayRate, 0.0f, OnOverrideEnd);
	}
}

void UGA_SequenceAbility::OnCompleted()
{
	EndAbility(CurrentSpecHandle, GetCurrentActorInfo(), GetCurrentActivationInfo(), false, false);
}

void UGA_SequenceAbility::OnCancelled()
{
	EndAbility(CurrentSpecHandle, GetCurrentActorInfo(), GetCurrentActivationInfo(), false, true);
}

void UGA_SequenceAbility::OnOverrideEnd(bool OverrideEnd)
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

void UGA_SequenceAbility::OnEventRecieved()
{
	/* Will be implemented in child classes */
}

void UGA_SequenceAbility::BindEventRecievedInAnimSequence()
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
					EventReceived->OnEventReceived.AddDynamic(this, &UGA_SequenceAbility::OnEventRecieved);
				}
			}
		}
	}
}
