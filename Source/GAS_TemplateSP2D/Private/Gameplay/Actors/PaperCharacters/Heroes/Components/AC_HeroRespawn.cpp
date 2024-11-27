// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroRespawn.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/GAS_PaperHeroBase.h"
#include "Gameplay/Effects/GAS_EffectBlueprintFunctionLibary.h"
#include "GameFramework/GameMode.h"


void UAC_HeroRespawn::BindCharacterDeSpawn()
{
    if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>())
    {
        SpawnDelegatesSubsystem->OnHeroDeSpawn.AddDynamic(this, &UAC_RespawnBase::StartCharacterReSpawnCountdown);
    }
}

void UAC_HeroRespawn::OnCharacterRespawn(AGAS_PaperCharacterBase* CharacterBase)
{
    Super::OnCharacterRespawn(CharacterBase);

    SetHeroLocation(CharacterBase);

    if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>())
    {
        SpawnDelegatesSubsystem->OnHeroReSpawn.Broadcast(CharacterBase);
    }
}

void UAC_HeroRespawn::SetHeroLocation(AGAS_PaperCharacterBase* Hero)
{
    if (!Hero)
    {
        return;
    }

    if (UWorld* World = this->GetWorld())
    {
        if (AGameModeBase* AuthGameMode = World->GetAuthGameMode())
        {
            if (AActor* StartPoint = AuthGameMode->FindPlayerStart(Hero->GetController()))
            {
                Hero->SetActorLocation(StartPoint->GetActorLocation());
                Hero->SetActorRotation(StartPoint->GetActorRotation());
            }
        }
    }
}



