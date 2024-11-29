// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Hero/GA_HeroDeath.h"
#include "Gameplay/StaticDelegates/S_SpawnDelegates.h"


void UGA_HeroDeath::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	GetAbilitySystemComponentFromActorInfo()->ExecuteGameplayCue(GAS_Tags::TAG_GameplayCue_HeroMessageHUD_Died, FGameplayCueParameters());
}

void UGA_HeroDeath::BroadcastDeSpawn()
{
	if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>())
	{
		SpawnDelegatesSubsystem->OnHeroDeSpawn.Broadcast(Cast<AGAS_PaperCharacterBase>(GetAvatarActorFromActorInfo()));
	}
}


