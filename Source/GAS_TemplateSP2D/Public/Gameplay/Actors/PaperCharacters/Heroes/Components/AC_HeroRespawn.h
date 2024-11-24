// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_HeroRespawn.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_HeroRespawn : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAC_HeroRespawn();

protected:
	virtual void BeginPlay() override;

	void Initialize();

	UFUNCTION()
	void OnHeroDeSpawn(AGAS_PaperHeroBase* Hero);

	void StartHeroDeSpawnCountdown(AGAS_PaperHeroBase* Hero);

	void HeroRespawn(AGAS_PaperHeroBase* Hero);

	void SetHeroLocation(AGAS_PaperHeroBase* Hero);

	FTimerHandle HeroDeSpawnCountDownTimerHandle;
		
	UPROPERTY(EditDefaultsOnly, Category = "HeroRespawn|Params")
	float ReSpawnDelay = 2.0f;

	UPROPERTY(EditDefaultsOnly, Category = "HeroRespawn|Params")
	TSubclassOf<UGameplayEffect> ReSpawnEffectClass;
};
