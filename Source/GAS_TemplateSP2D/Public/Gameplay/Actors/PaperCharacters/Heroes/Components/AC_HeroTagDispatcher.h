// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Components/ActorComponent.h"
#include "AbilitySystemComponent.h"
#include "AC_HeroTagDispatcher.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameplayTagTriggered, const UAbilitySystemComponent*, AbilitySystemComponent, const FGameplayTag&, Tag);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_HeroTagDispatcher : public UActorComponent
{
	GENERATED_BODY()

public:	

	UAC_HeroTagDispatcher();

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTagAdded(const UAbilitySystemComponent* AbilitySystemComponent, const FGameplayTag& Tag);

	UFUNCTION()
	void OnTagRemoved(const UAbilitySystemComponent* AbilitySystemComponent, const FGameplayTag& Tag);

	UPROPERTY(BlueprintAssignable)
	FOnGameplayTagTriggered OnGameplayTagAdded;

	UPROPERTY(BlueprintAssignable)
	FOnGameplayTagTriggered OnGameplayTagRemoved;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer ListeningTags;
};
