// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GA_SequenceAbility.h"
#include "GA_HealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_HealthPotion : public UGA_SequenceAbility
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "HealthPotion")
	TSubclassOf<UGameplayEffect> HealEffectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthPotion")
	FScalableFloat HealValue;

protected:

	virtual void OnEventRecieved();

};
