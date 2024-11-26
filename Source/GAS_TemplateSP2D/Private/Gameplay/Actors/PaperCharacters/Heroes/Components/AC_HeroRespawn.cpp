// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroRespawn.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/GAS_PaperHeroBase.h"
#include "Gameplay/Effects/GAS_EffectBlueprintFunctionLibary.h"
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
        SpawnDelegatesSubsystem->OnHeroDeSpawn.AddDynamic(this, &UAC_HeroRespawn::StartHeroReSpawnCountdown);
    }
}

void UAC_HeroRespawn::StartHeroReSpawnCountdown(AGAS_PaperHeroBase* Hero)
{
    GetWorld()->GetTimerManager().SetTimer(HeroDeSpawnCountDownTimerHandle, [this, Hero]()
        {
            HeroRespawn(Hero);
        }, ReSpawnDelay, false);
}

void UAC_HeroRespawn::HeroRespawn(AGAS_PaperHeroBase* Hero)
{
    ApplyHeroReSpawnEffect(Hero);

    SetHeroLocation(Hero);

    Hero->EnableMovement();

    if (US_SpawnDelegates* SpawnDelegatesSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<US_SpawnDelegates>())
    {
        SpawnDelegatesSubsystem->OnHeroReSpawn.Broadcast(Hero);
    }
}

void UAC_HeroRespawn::ApplyHeroReSpawnEffect(AGAS_PaperHeroBase* Hero)
{
    if (!ReSpawnEffectClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("ReSpawnEffectClass is null in: %s"), *GetName());
        return;
    }

    UGameplayEffect* ReSpawnEffect = UGAS_EffectBlueprintFunctionLibary::CreateEffectWithTSubclass(ReSpawnEffectClass);
    Hero->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(ReSpawnEffect, 1, FGameplayEffectContextHandle());
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



