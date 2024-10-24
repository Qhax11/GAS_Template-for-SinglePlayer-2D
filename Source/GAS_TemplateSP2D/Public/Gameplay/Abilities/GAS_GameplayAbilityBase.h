// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Gameplay/Abilities/Targeting/GAS_AbilityTargetingData.h"
#include "Gameplay/Tags/GAS_Tags.h"
#include "AbilitySystemComponent.h"
#include "GAS_GameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGAS_GameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "GameplayAbilityBase|TargetingData")
	UGAS_AbilityTargetingData* TargetingData;

	void CreateTraceFromTargetingData(TArray<AActor*>& OutActors);
	

};
