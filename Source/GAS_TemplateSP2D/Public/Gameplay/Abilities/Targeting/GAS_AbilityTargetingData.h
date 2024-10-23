// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CollisionShape.h"
#include "Gameplay/Abilities/Targeting/GAS_TraceBase.h"
#include "GAS_AbilityTargetingData.generated.h"


UCLASS(Blueprintable)
class GAS_TEMPLATESP2D_API UGAS_AbilityTargetingData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Targeting")
	TObjectPtr <UGAS_TraceBase> Trace;

};