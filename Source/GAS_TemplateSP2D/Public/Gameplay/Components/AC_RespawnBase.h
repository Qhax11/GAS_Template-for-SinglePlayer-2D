// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Components/ActorComponent.h"
#include "Gameplay/StaticDelegates/S_SpawnDelegates.h"
#include "AC_RespawnBase.generated.h"

class AGAS_PaperCharacterBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_RespawnBase : public UActorComponent
{
	GENERATED_BODY()

public:
	UAC_RespawnBase();

	UFUNCTION()
	void StartCharacterReSpawnCountdown(AGAS_PaperCharacterBase* CharacterBase);

protected:
	virtual void BeginPlay() override;

	virtual void BindCharacterDeSpawn();

	virtual void OnCharacterRespawn(AGAS_PaperCharacterBase* CharacterBase);

	void ApplyCharacterReSpawnEffect(AGAS_PaperCharacterBase* CharacterBase);

	FTimerHandle CharacterDeSpawnCountDownTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category = "RespawnBase|Params")
	float ReSpawnDelay = 2.0f;

	UPROPERTY(EditDefaultsOnly, Category = "RespawnBase|Params")
	TSubclassOf<class UGameplayEffect> ReSpawnEffectClass;
};
