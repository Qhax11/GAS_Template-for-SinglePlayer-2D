// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/PaperCharacters/Enemies/Components/AC_EnemyRespawn.h"

void UAC_EnemyRespawn::BindCharacterDeSpawn()
{
    if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>())
    {
        SpawnDelegatesSubsystem->OnEnemyDeSpawn.AddDynamic(this, &UAC_RespawnBase::StartCharacterReSpawnCountdown);
    }
}

void UAC_EnemyRespawn::OnCharacterRespawn(AGAS_PaperCharacterBase* CharacterBase)
{
    Super::OnCharacterRespawn(CharacterBase);

    if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>())
    {
        SpawnDelegatesSubsystem->OnEnemyReSpawn.Broadcast(CharacterBase);
    }
}



