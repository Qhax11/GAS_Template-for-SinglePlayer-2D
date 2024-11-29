// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "Abilities/GameplayAbility.h"
#include "Gameplay/Abilities/Targeting/GAS_AbilityTargetingData.h"
#include "Gameplay/Tags/GAS_Tags.h"
#include "AbilitySystemComponent.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "Gameplay/Components/AC_Team.h"
#include "GAS_GameplayAbilityBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityLevelChanged, UGameplayAbility*, Ability, int32, NewLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityCostChanged, UGameplayAbility*, Ability, float, NewCost);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityCooldownChanged, UGameplayAbility*, Ability, float, NewCooldown);


UCLASS()
class GAS_TEMPLATESP2D_API UGAS_GameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:

	void CreateTraceFromTargetingData(TArray<AActor*>& OutActors);

	void CreateTraceFromTargetingDataWithTeamFilter(TArray<AActor*>& OutActors, ETeamAttitude::Type TeamAttidue);
	
	UFUNCTION(BlueprintPure, Category = "GameplayAbilityBase")
	float GetCost(int32 AbilityLevel) const;

	UFUNCTION(BlueprintPure, Category = "GameplayAbilityBase")
	float GetCoolDown(int32 AbilityLevel) const;

	UPROPERTY(BlueprintAssignable, Category = "GameplayAbilityBase|Delegates")
	FOnAbilityLevelChanged OnAbilityLevelChanged;

	UPROPERTY(BlueprintAssignable, Category = "GameplayAbilityBase|Delegates")
	FOnAbilityCostChanged OnAbilityCostChanged;

	UPROPERTY(BlueprintAssignable, Category = "GameplayAbilityBase|Delegates")
	FOnAbilityCooldownChanged OnAbilityCooldownChanged;

	UPROPERTY(EditDefaultsOnly, Category = "GameplayAbilityBase|TargetingData")
	UGAS_AbilityTargetingData* TargetingData;

	// Icon of ability that will seen on Gameplay UI
	UPROPERTY(EditAnywhere, Category = "GameplayAbilityBase|UI")
	class UTexture2D* AbilityIcon;

protected:

	/**
	 * For "Instanced Per Actor" abilities:
	 * Normally, broadcasting delegates over the CDO is not required for proper functionality. 
	 * However, since the "FindAbilitySpecFromClass" function is used immediately after granting the ability, 
	 * it returns the CDO instead of the instance object. As a result, we use the CDO here to ensure that
	 * delegates remain connected and can be broadcast over the same object.
	 */
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void IncreaseLevel(UAbilitySystemComponent* AbilitySystemComp);
};
