// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Targeting/GAS_TraceLine.h"

void UGAS_TraceLine::TraceLogic(const UWorld* World, const FVector& Location, const FRotator& Direction, const FCollisionQueryParams& QueryParams, const FCollisionResponseParams& ResponseParams, TArray<FHitResult>& OutHitResults)
{
	World->LineTraceMultiByChannel(
		OutHitResults,
		Location,
		Location + Direction.Vector() * TraceDistance,
		TraceChannel,
		QueryParams,
		ResponseParams
	);
}

void UGAS_TraceLine::DrawDebugShape(const UWorld* World, const FVector& Location) const
{
	DrawDebugLine(
		World,
		Location,
		Location + TraceDirection.Vector() * TraceDistance,
		DrawColor,
		false,
		DebugShapeDrawDuration,
		0,
		2.0f
	);
}
