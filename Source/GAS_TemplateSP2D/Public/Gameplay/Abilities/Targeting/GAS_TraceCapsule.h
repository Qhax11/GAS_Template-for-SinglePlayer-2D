// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/Targeting/GAS_TraceBase.h"
#include "GAS_TraceCapsule.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGAS_TraceCapsule : public UGAS_TraceBase
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (ExposeOnSpawn = true))
	float Radius = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (ExposeOnSpawn = true))
	float HalfHeight = 400.0f;

protected:

	FCollisionShape GetCollisionShape() const override;

#if WITH_EDITOR
	virtual void DrawDebugShape(const UWorld* World, const FVector& Location) const override;
#endif // WITH_EDITOR
};
