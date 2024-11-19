// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GA_SequenceAbility.h"
#include "GA_RangeAttackBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_RangeAttackBase : public UGA_SequenceAbility
{
	GENERATED_BODY()

protected:

	virtual void OnEventRecieved();
	
};
