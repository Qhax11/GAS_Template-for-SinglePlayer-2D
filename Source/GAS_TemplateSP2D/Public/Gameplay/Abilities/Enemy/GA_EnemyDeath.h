// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GA_DeathBase.h"
#include "GA_EnemyDeath.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_EnemyDeath : public UGA_DeathBase
{
	GENERATED_BODY()
	
protected:

	virtual void BroadcastDeSpawn() override;

};
