// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Targeting/GAS_TraceSphere.h"

FCollisionShape UGAS_TraceSphere::GetCollisionShape() const
{
    return FCollisionShape::MakeSphere(Radius);
}

void UGAS_TraceSphere::DrawDebugShape(const UWorld* World, const FVector& Location) const
{
	DrawDebugCapsule(
		World,
		Location + TraceDirectionInternal.Vector() * (TraceDistance / 2.0f),
		TraceDistance / 2.0f + Radius,
		Radius,
		FQuat::MakeFromEuler(FVector(.0f, 90.0f + TraceDirectionInternal.Euler().Y, TraceDirectionInternal.Euler().Z)),
		DrawColor,
		false,
		DebugShapeDrawDuration,
		0,
		2.0f
	);
}
