// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GA_SequenceAbility.h"
#include "GA_MeleeAttackBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_MeleeAttackBase : public UGA_SequenceAbility
{
	GENERATED_BODY()

public:
	virtual void OnEventRecieved();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Parameters")
	TSubclassOf<UGameplayEffect> GEPhysicalDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Parameters")
	FGameplayTagContainer TagsToAddToPhysicalDamageEffect;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Parameters")
    FScalableFloat Damage;
};
