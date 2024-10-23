// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Abilities/GAS_GameplayAbilityBase.h"
#include "Kismet\KismetSystemLibrary.h"


void UGAS_GameplayAbilityBase::CreateTraceFromTargetingData(TArray<AActor*> OutActors)
{

	FVector start = GetAvatarActorFromActorInfo()->GetActorLocation();
	FVector end = GetAvatarActorFromActorInfo()->GetActorLocation() + GetAvatarActorFromActorInfo()->GetActorForwardVector() * 100;

	TargetingData->Trace->Trace(GetWorld(), start, FRotator(), OutActors);

#if WITH_EDITOR
	//DrawDebugShape(World, Location);
#endif // WITH_EDITOR




}

