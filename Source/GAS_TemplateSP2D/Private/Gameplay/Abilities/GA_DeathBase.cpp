// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_DeathBase.h"
#include "Gameplay/Effects/GAS_EffectBlueprintFunctionLibary.h"

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

	BroadcastDeSpawn();

	if (AGAS_PaperCharacterBase* CharacterBase = Cast<AGAS_PaperCharacterBase>(GetAvatarActorFromActorInfo()))
	{
		CharacterBase->DisableMovement();
		CharacterBase->DisableCollision();

		if (DeathEffectClass)
		{
			UGameplayEffect* ReSpawnEffect = UGAS_EffectBlueprintFunctionLibary::CreateEffectWithTSubclass(DeathEffectClass);
			CharacterBase->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(ReSpawnEffect, 1, FGameplayEffectContextHandle());
		}
	}
}

	

void UGA_DeathBase::BroadcastDeSpawn()
{
	// The logic will be implemented in the subclasses.
}




