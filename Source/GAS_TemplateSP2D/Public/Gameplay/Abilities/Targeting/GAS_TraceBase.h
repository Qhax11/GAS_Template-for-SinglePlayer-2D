// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScalableFloat.h"
#include "GAS_TraceBase.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInLineNew)
class GAS_TEMPLATESP2D_API UGAS_TraceBase : public UObject
{
	GENERATED_BODY()
	
protected:

	const AActor* OwnerActor = nullptr;
	float TraceDistanceInternal;
	FRotator TraceDirectionInternal;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (ExposeOnSpawn = true))
	bool bIgnoreSelf = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (ExposeOnSpawn = true))
	TEnumAsByte<ECollisionChannel> TraceChannel = ECollisionChannel::ECC_Pawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (ExposeOnSpawn = true))
	float TraceDistance = .0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (ExposeOnSpawn = true))
	TEnumAsByte<ECollisionResponse> CollisionResponse = ECollisionResponse::ECR_Overlap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	bool bOverrideDrawDuration = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace", meta = (EditCondition = "bOverrideDrawDuration"))
	float DebugShapeDrawDuration = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	bool bSingleTarget = false;

	void Trace(const UWorld* World, const FVector& Location, const FRotator& Direction, TArray<AActor*>& OutActors);

protected:

	virtual void TraceLogic(const UWorld* World, const FVector& Location, const FRotator& Direction, const FCollisionQueryParams& QueryParams, const FCollisionResponseParams& ResponseParams, TArray<FHitResult>& OutHitResults);

	virtual FCollisionShape GetCollisionShape() const;


#if WITH_EDITOR

protected:

	FColor DrawColor = FColor::White;

	virtual void DrawDebugShape(const UWorld* World, const FVector& Location) const;

#endif // WITH_EDITOR

};