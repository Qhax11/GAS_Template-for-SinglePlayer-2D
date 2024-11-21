// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_DeathBase.h"

UGA_DeathBase::UGA_DeathBase()
{
	TEnumAsByte<EGameplayAbilityTriggerSource::Type> TriggerSource = EGameplayAbilityTriggerSource::GameplayEvent;

	FAbilityTriggerData TriggerData = FAbilityTriggerData();
	TriggerData.TriggerSource = TriggerSource;
	TriggerData.TriggerTag = GAS_Tags::TAG_Gameplay_Event_Death;

	AbilityTriggers.Add(TriggerData);

	ActivationOwnedTags.AddTag(GAS_Tags::TAG_Gameplay_State_Dead);
	ActivationBlockedTags.AddTag(GAS_Tags::TAG_Gameplay_State_Dead);
}

void UGA_DeathBase::ActivateAbility(const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	// Play AnimSequence.
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	DisableCollisions();
}

void UGA_DeathBase::DisableCollisions()
{
	if (AGAS_PaperCharacterBase* CharBase = Cast<AGAS_PaperCharacterBase>(GetAvatarActorFromActorInfo()))
	{
		// Dead object collision, you can check ProjectSettings->Engine->Collision->CollisionObject
		CharBase->GetCapsuleComponent()->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	}
}


