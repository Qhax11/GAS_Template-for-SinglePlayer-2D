// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GA_DeathBase.h"
#include "GA_HeroDeath.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_HeroDeath : public UGA_DeathBase
{
	GENERATED_BODY()
	
public:

	virtual void OnCompleted();

};
