// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_TakeDamageBase.h"

UGA_TakeDamageBase::UGA_TakeDamageBase()
{
	TEnumAsByte<EGameplayAbilityTriggerSource::Type> TriggerSource = EGameplayAbilityTriggerSource::GameplayEvent;

	FAbilityTriggerData TriggerData = FAbilityTriggerData();
	TriggerData.TriggerSource = TriggerSource;
	TriggerData.TriggerTag = GAS_Tags::TAG_Gameplay_GameplayEvent_TakeDamage;

	AbilityTriggers.Add(TriggerData);

	ActivationBlockedTags.AddTag(GAS_Tags::TAG_Gameplay_State_Dead);
}

void UGA_TakeDamageBase::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	// Play AnimSequence.
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	
}
