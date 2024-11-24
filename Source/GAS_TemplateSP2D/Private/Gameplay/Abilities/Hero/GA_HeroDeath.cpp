// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Hero/GA_HeroDeath.h"
#include "Gameplay/StaticDelegates/S_SpawnDelegates.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperHeroBase.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroRespawn.h"


void UGA_HeroDeath::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>()) 
	{
		SpawnDelegatesSubsystem->OnHeroDeSpawn.Broadcast(Cast<AGAS_PaperHeroBase>(GetAvatarActorFromActorInfo()));
	}

	GetAbilitySystemComponentFromActorInfo()->ExecuteGameplayCue(GAS_Tags::TAG_GameplayCue_PlayerMessageHUD_Died, FGameplayCueParameters());
}


