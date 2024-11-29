// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Gameplay/Abilities/Targeting/GAS_TraceBase.h"
#include "GAS_TraceSphere.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGAS_TraceSphere : public UGAS_TraceBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TraceSphere", meta = (ExposeOnSpawn = true))
	float Radius = 100.0f;

protected:

	virtual FCollisionShape GetCollisionShape() const override;

protected:

#if WITH_EDITOR
	virtual void DrawDebugShape(const UWorld* World, const FVector& Location) const override;
#endif // WITH_EDITOR
};
