// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GA_SequenceAbility.h"
#include "GA_HeroDash.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_HeroDash : public UGA_SequenceAbility
{
	GENERATED_BODY()
	

protected:

	virtual void OnEventRecieved() override;

	UPROPERTY(EditDefaultsOnly, Category = "RootMotionTaskParams")
	float Strenght = 500.0f;

	UPROPERTY(EditDefaultsOnly, Category = "RootMotionTaskParams")
	float Duration = 1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "RootMotionTaskParams")
	UCurveFloat* DashCurve;

	UPROPERTY(EditDefaultsOnly, Category = "RootMotionTaskParams")
	bool bEnableGravity;

};
