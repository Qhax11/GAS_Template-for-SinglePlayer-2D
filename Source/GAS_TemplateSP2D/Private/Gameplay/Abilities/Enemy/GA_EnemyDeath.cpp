// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Enemy/GA_EnemyDeath.h"
#include "Gameplay/StaticDelegates/S_SpawnDelegates.h"


void UGA_EnemyDeath::BroadcastDeSpawn()
{
	if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>())
	{
		SpawnDelegatesSubsystem->OnEnemyDeSpawn.Broadcast(Cast<AGAS_PaperCharacterBase>(GetAvatarActorFromActorInfo()));
	}
}
