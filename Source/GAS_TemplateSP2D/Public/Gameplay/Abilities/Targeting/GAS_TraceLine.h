// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/Targeting/GAS_TraceBase.h"
#include "GAS_TraceLine.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGAS_TraceLine : public UGAS_TraceBase
{
	GENERATED_BODY()
	
protected:

	virtual void TraceLogic(const UWorld* World, const FVector& Location, const FRotator& Direction, const FCollisionQueryParams& QueryParams, const FCollisionResponseParams& ResponseParams, TArray<FHitResult>& OutHitResults) override;

#if WITH_EDITOR
	virtual void DrawDebugShape(const UWorld* World, const FVector& Location) const override;
#endif // WITH_EDITOR
};
