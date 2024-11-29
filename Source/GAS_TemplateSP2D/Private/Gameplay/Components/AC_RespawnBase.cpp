// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/AC_RespawnBase.h"
#include "Gameplay/Effects/GAS_EffectBlueprintFunctionLibary.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"


UAC_RespawnBase::UAC_RespawnBase()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_RespawnBase::BeginPlay()
{
	Super::BeginPlay();

	BindCharacterDeSpawn();
}

void UAC_RespawnBase::BindCharacterDeSpawn()
{
	// The logic will be implemented in the subclasses.
}

void UAC_RespawnBase::StartCharacterReSpawnCountdown(AGAS_PaperCharacterBase* CharacterBase)
{
	GetWorld()->GetTimerManager().SetTimer(CharacterDeSpawnCountDownTimerHandle, [this, CharacterBase]()
		{
			OnCharacterRespawn(CharacterBase);
		}, 
		ReSpawnDelay, false);
}

void UAC_RespawnBase::OnCharacterRespawn(AGAS_PaperCharacterBase* CharacterBase)
{
	ApplyCharacterReSpawnEffect(CharacterBase);

	CharacterBase->EnableMovement();
	CharacterBase->EnableCollision();
}

void UAC_RespawnBase::ApplyCharacterReSpawnEffect(AGAS_PaperCharacterBase* CharacterBase)
{
	if (!ReSpawnEffectClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("ReSpawnEffectClass is null in: %s"), *GetName());
		return;
	}

	UGameplayEffect* ReSpawnEffect = UGAS_EffectBlueprintFunctionLibary::CreateEffectWithTSubclass(ReSpawnEffectClass);
	CharacterBase->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(ReSpawnEffect, 1, FGameplayEffectContextHandle());
}






