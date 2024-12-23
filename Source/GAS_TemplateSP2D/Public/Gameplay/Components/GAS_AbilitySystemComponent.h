// Qhax's GAS Template for SinglePlayer

#pragma once

#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "GAS_AbilitySystemComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityGiven, UAbilitySystemComponent*, ASC, FGameplayAbilitySpec&, AbilitySpec);


USTRUCT(BlueprintType)
struct FAbilityData
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditDefaultsOnly, Category = "AbilityData")
	TSubclassOf<UGameplayAbility> Ability;

	UPROPERTY(EditAnywhere, Category = "AbilityData")
	class UInputAction* AbilityInput;

};

USTRUCT(BlueprintType)
struct FAttributeSetData
{
	GENERATED_BODY()
public:

	/** Attribute Set to grant */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Attributes)
	TSoftClassPtr<UAttributeSet> AttributeSet;

	/** Data table referent to initialize the attributes with, if any (can be left unset) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Attributes, meta = (RequiredAssetDataTags = "RowStructure=/Script/GameplayAbilities.AttributeMetaData"))
	TSoftObjectPtr<UDataTable> InitializationData;
};

UCLASS()
class GAS_TEMPLATESP2D_API UGAS_GameplayAbilitySet : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, Category = "AbilitySet")
	TArray<FAbilityData> Abilities;

	UPROPERTY(EditDefaultsOnly, Category = "AbilitySet")
	TArray<TSubclassOf<class UGameplayEffect>> StartupEffects;

	UPROPERTY(EditDefaultsOnly, Category = "AbilitySet")
	FAttributeSetData AttributeData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AbilitySet")
	FGameplayTagContainer PermenantTags;
};

UCLASS()
class GAS_TEMPLATESP2D_API UGAS_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:

	bool GiveAbilitySet(const UGAS_GameplayAbilitySet* AbilitySet);
	
	void GiveAbilities(const UGAS_GameplayAbilitySet* AbilitySet);

	UFUNCTION(BlueprintCallable)
	void GiveAbilityWithInputAction(UInputAction* AbilityInput, const TSubclassOf<UGameplayAbility> Ability);

	bool IsAbilityGivenAlready(const TSubclassOf<UGameplayAbility> Ability);

	void TryAbilityInputBind(UInputAction* AbilityInput, const FGameplayAbilitySpecHandle& AbilitySpecHandle);

	void GiveAttributes(const UGAS_GameplayAbilitySet* AbilitySet);

	void GivePermenantTags(FGameplayTagContainer PermenantTags);

	// Overrided for OnAbilityGiven broadcast
	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityGiven OnAbilityGranted;
};
