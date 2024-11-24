// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroRespawn.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperHeroBase.h"
#include "Gameplay/StaticDelegates/S_SpawnDelegates.h"
#include "GameFramework/GameMode.h"


UAC_HeroRespawn::UAC_HeroRespawn()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_HeroRespawn::BeginPlay()
{
	Super::BeginPlay();

    Initialize();
}

void UAC_HeroRespawn::Initialize()
{
    if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>()) 
    {
        SpawnDelegatesSubsystem->OnHeroDeSpawn.AddDynamic(this, &UAC_HeroRespawn::OnHeroDeSpawn);
    }
}

void UAC_HeroRespawn::OnHeroDeSpawn(AGAS_PaperHeroBase* Hero)
{
    StartHeroDeSpawnCountdown(Hero);
}

void UAC_HeroRespawn::StartHeroDeSpawnCountdown(AGAS_PaperHeroBase* Hero)
{
    GetWorld()->GetTimerManager().SetTimer(HeroDeSpawnCountDownTimerHandle, [this, Hero]()
        {
            HeroRespawn(Hero);
        }, ReSpawnDelay, false);
}

void UAC_HeroRespawn::HeroRespawn(AGAS_PaperHeroBase* Hero)
{
    SetHeroLocation(Hero);

    // TODO: create helper functions in another place, dont make code repeat
    const UGameplayEffect* ReSpawnEffect = ReSpawnEffectClass->GetDefaultObject<UGameplayEffect>();
    FGameplayEffectContextHandle EffectContextHandle;
    if (ReSpawnEffect) 
    {
        Hero->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(ReSpawnEffect, 1, EffectContextHandle);
    }
}

void UAC_HeroRespawn::SetHeroLocation(AGAS_PaperHeroBase* Hero)
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



