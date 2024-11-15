// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Gameplay/Abilities/Targeting/GAS_AbilityTargetingData.h"
#include "Gameplay/Tags/GAS_Tags.h"
#include "AbilitySystemComponent.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "Gameplay/Components/AC_Team.h"
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

	// Icon of ability that will seen on Gameplay UI
	UPROPERTY(EditAnywhere, Category = "GameplayAbilityBase|UI")
	class UTexture2D* AbilityIcon;

	void CreateTraceFromTargetingData(TArray<AActor*>& OutActors);

	void CreateTraceFromTargetingDataWithTeamFilter(TArray<AActor*>& OutActors, ETeamAttitude::Type TeamAttidue);
	
	void CreateEffectWithMagnitude(FGameplayEffectSpec& Spec, UAbilitySystemComponent* SourceAbilitySystemComponent, TSubclassOf<UGameplayEffect> GameplayEffectClass, const FGameplayTag SetByCallerTag, float SetByCallerValue);

};
