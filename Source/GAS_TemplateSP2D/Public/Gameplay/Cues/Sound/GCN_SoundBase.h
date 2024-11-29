// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Gameplay/Cues/GCN_ActorBase.h"
#include "GCN_SoundBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API AGCN_SoundBase : public AGCN_ActorBase
{
	GENERATED_BODY()

public:

	virtual void OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters);

};
