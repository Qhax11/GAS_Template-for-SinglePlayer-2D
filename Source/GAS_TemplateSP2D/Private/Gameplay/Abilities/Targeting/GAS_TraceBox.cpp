// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Targeting/GAS_TraceBox.h"

FCollisionShape UGAS_TraceBox::GetCollisionShape() const
{
    return FCollisionShape::MakeBox(FVector(HalfLength, HalfWidth, HalfHeight));
}
