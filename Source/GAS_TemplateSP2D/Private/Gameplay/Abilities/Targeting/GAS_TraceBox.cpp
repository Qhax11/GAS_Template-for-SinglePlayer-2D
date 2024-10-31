// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Targeting/GAS_TraceBox.h"

FCollisionShape UGAS_TraceBox::GetCollisionShape() const
{
    return FCollisionShape::MakeBox(FVector(HalfLength, HalfWidth, HalfHeight));
}

#if WITH_EDITOR
void UGAS_TraceBox::DrawDebugShape(const UWorld* World, const FVector& Location) const
{
	DrawDebugBox(
		World,
		Location + TraceDirection.Vector() * HalfLength,
		FVector(HalfLength, HalfWidth, HalfHeight),
		TraceDirection.Quaternion(),
		DrawColor,
		false,
		DebugShapeDrawDuration,
		0,
		2.0f
	);
}
#endif // WITH_EDITOR
