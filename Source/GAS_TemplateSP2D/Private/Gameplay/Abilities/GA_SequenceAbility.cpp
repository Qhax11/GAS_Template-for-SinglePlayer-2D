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

	UPaperZDAnimSequence* SelectedSequence = SelectSequence();
	if (!SelectedSequence)
	{
		UE_LOG(LogTemp, Warning, TEXT("SelectSequence function couldn't selcet sequence in: %s"), *this->GetName());
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

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

	if (UPaperZDAnimInstance* AnimInstance = PaperZDAnimComp->GetAnimInstance())
	{
		FZDOnAnimationOverrideEndSignature OnOverrideEnd;
		OnOverrideEnd.BindUObject(this, &UGA_SequenceAbility::OnOverrideEnd);
		AnimInstance->PlayAnimationOverride(SelectedSequence, SlotName, PlayRate, 0.0f, OnOverrideEnd);
		BindEventRecievedInAnimSequence(SelectedSequence);
	}
}

UPaperZDAnimSequence* UGA_SequenceAbility::SelectSequence()
{
	return AnimSequences.IsValidIndex(0) ? AnimSequences[0] : nullptr;
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

void UGA_SequenceAbility::BindEventRecievedInAnimSequence(UPaperZDAnimSequence* SelectedSequence)
{
	if (SelectedSequence)
	{
		TArray<UPaperZDAnimNotify_Base*> AnimNotifies = SelectedSequence->GetAnimNotifies();
		for (UPaperZDAnimNotify_Base* PaperZDAnimNotify_Base : AnimNotifies)
		{
			if (UAN_EventReceived* EventReceived = Cast<UAN_EventReceived>(PaperZDAnimNotify_Base))
			{
				if (EventReceived->EventTag == EventTag)
				{
					if (!EventReceived->OnEventReceived.IsBound()) 
					{
						EventReceived->OnEventReceived.AddDynamic(this, &UGA_SequenceAbility::OnEventRecieved);
					}
				}
			}
		}
	}
}
