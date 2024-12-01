// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/CrowdControls/GA_StunApplyBase.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UGA_StunApplyBase::UGA_StunApplyBase()
{
	TEnumAsByte<EGameplayAbilityTriggerSource::Type> TriggerSource = EGameplayAbilityTriggerSource::OwnedTagPresent;

	FAbilityTriggerData TriggerData = FAbilityTriggerData();
	TriggerData.TriggerSource = TriggerSource;
	TriggerData.TriggerTag = GAS_Tags::TAG_Gameplay_State_Debuff_Stun;

	AbilityTriggers.Add(TriggerData);
}

void UGA_StunApplyBase::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* OwnerInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	//Super::ActivateAbility(Handle, OwnerInfo, ActivationInfo, TriggerEventData);

	Character = Cast<ACharacter>(OwnerInfo->AvatarActor);
	CharacterMoveComp = Character->GetCharacterMovement();

	CharacterMoveComp->MaxAcceleration = 0;
}

void UGA_StunApplyBase::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	CharacterMoveComp->MaxAcceleration = 2024;;

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}
