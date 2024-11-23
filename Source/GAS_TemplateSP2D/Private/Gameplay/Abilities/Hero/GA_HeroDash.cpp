// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Hero/GA_HeroDash.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionConstantForce.h"
#include "GameFramework/RootMotionSource.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionMoveToForce.h"

void UGA_HeroDash::OnEventRecieved()
{
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
			

	RootMotionTask->ReadyForActivation();
	RootMotionTask->OnFinish.AddDynamic(this, &UGA_HeroDash::OnTaskFinished);
	*/
}

