// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Targeting/GAS_TraceBase.h"

void UGAS_TraceBase::Trace(const UWorld* World, const FVector& Location, const FRotator& Direction, TArray<AActor*>& OutActors)
{
	FCollisionQueryParams QueryParams;
	if (bIgnoreSelf)
	{
		QueryParams.AddIgnoredActor(OwnerActor);
	}

	FCollisionResponseContainer ResponseContainer;
	ResponseContainer.SetAllChannels(CollisionResponse);

	FCollisionResponseParams ResponseParams;
	ResponseParams.CollisionResponse = ResponseContainer;

	TArray<FHitResult> HitResults;
	TraceLogic(World, Location, Direction, QueryParams, ResponseParams, HitResults);

#if WITH_EDITOR
	DrawDebugShape(World, Location);
#endif // WITH_EDITOR

	if (HitResults.IsEmpty())
	{
		return;
	}

	for (int32 i = 0; i < (bSingleTarget ? 1 : HitResults.Num()); ++i)
	{
		OutActors.AddUnique(HitResults[i].GetActor());
	}
}

void UGAS_TraceBase::TraceLogic(const UWorld* World, const FVector& Location, const FRotator& Direction, const FCollisionQueryParams& QueryParams, const FCollisionResponseParams& ResponseParams, TArray<FHitResult>& OutHitResults)
{
	World->SweepMultiByChannel(
		OutHitResults,
		Location,
		Location + Direction.Vector() * TraceDistanceInternal,
		FQuat::Identity,
		TraceChannel,
		GetCollisionShape(),
		QueryParams
	);
}

FCollisionShape UGAS_TraceBase::GetCollisionShape() const
{
    return FCollisionShape();
}

void UGAS_TraceBase::DrawDebugShape(const UWorld* World, const FVector& Location) const
{
	// Logic will be implmeneted in subclasses.
}


