// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Abilities/GAS_GameplayAbilityBase.h"
#include "Kismet\KismetSystemLibrary.h"


void UGAS_GameplayAbilityBase::CreateTraceFromTargetingData(TArray<AActor*>& OutActors)
{
	FVector StartLocation = GetAvatarActorFromActorInfo()->GetActorLocation();
	FRotator TraceDirection = GetAvatarActorFromActorInfo()->GetActorForwardVector().Rotation();

	TargetingData->Trace->MakeTrace(GetAvatarActorFromActorInfo(), GetWorld(), StartLocation, TraceDirection, OutActors);
}

