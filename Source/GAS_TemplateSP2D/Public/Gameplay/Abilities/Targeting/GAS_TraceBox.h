// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/Targeting/GAS_TraceBase.h"
#include "GAS_TraceBox.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGAS_TraceBox : public UGAS_TraceBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TraceBox", meta = (ExposeOnSpawn = true))
	float HalfLength = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TraceBox", meta = (ExposeOnSpawn = true))
	float HalfWidth = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TraceBox", meta = (ExposeOnSpawn = true))
	float HalfHeight = 50.0f;
	
protected:

	FCollisionShape GetCollisionShape() const override;

#if WITH_EDITOR
	virtual void DrawDebugShape(const UWorld* World, const FVector& Location) const override;
#endif // WITH_EDITOR

};
