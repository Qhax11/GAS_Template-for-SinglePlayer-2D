// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Hero/GA_HeroDash.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionConstantForce.h"
#include "GameFramework/RootMotionSource.h"

void UGA_HeroDash::OnEventRecieved()
{
	// I used same params in Blueprint side, still the duration twice as much
	/*
	UAbilityTask_ApplyRootMotionConstantForce* RootMotionTask =
		UAbilityTask_ApplyRootMotionConstantForce::ApplyRootMotionConstantForce(
			this,
			TEXT("None"),
			GetAvatarActorFromActorInfo()->GetActorRotation().Vector(),
			Strenght,
			Duration,
			false,
			DashCurve,
			ERootMotionFinishVelocityMode::MaintainLastRootMotionVelocity,
			FVector(0, 0, 0),
			0.f,
			bEnableGravity);
			*/
}
