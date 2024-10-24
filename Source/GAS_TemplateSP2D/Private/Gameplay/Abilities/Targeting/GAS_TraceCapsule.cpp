// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Targeting/GAS_TraceCapsule.h"

FCollisionShape UGAS_TraceCapsule::GetCollisionShape() const
{
    return FCollisionShape::MakeCapsule(Radius, HalfHeight);
}

void UGAS_TraceCapsule::DrawDebugShape(const UWorld* World, const FVector& Location) const
{
	DrawDebugCapsule(
		World,
		Location + TraceDirection.Vector() * TraceDistance,
		HalfHeight,
		Radius,
		TraceDirection.Quaternion(),
		DrawColor,
		false,
		DebugShapeDrawDuration,
		0,
		2.0f
	);
}
