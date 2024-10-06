// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "GAS_AbilitySystemComponent.generated.h"

USTRUCT(BlueprintType)
struct FAbilityData
{
	GENERATED_USTRUCT_BODY()
public:
	// TODO: remove "class" ?
	UPROPERTY(EditAnywhere, Category = "AbilityData")
	class TSubclassOf<class UGameplayAbility> Ability;

	UPROPERTY(EditAnywhere, Category = "AbilityData")
	class UInputAction* AbilityInput;

};

USTRUCT(BlueprintType)
struct FAttributeSetData
{
	GENERATED_BODY()
public:

	/** Attribute Set to grant */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes)
	TSoftClassPtr<UAttributeSet> AttributeSet;

	/** Data table referent to initialize the attributes with, if any (can be left unset) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes, meta = (RequiredAssetDataTags = "RowStructure=/Script/GameplayAbilities.AttributeMetaData"))
	TSoftObjectPtr<UDataTable> InitializationData;

};

UCLASS()
class GAS_TEMPLATESP_API UGAS_GameplayAbilitySet : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, Category = "AbilitySet")
	TArray<FAbilityData> Abilities;

	UPROPERTY(EditAnywhere, Category = "AbilitySet")
	TArray<TSubclassOf<class UGameplayEffect>> StartupEffects;

	UPROPERTY(EditAnywhere, Category = "AbilitySet")
	FAttributeSetData AttributeData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilitySet")
	FGameplayTagContainer PermenantTags;

};

UCLASS()
class GAS_TEMPLATESP_API UGAS_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:

	UGAS_AbilitySystemComponent();

	void GiveAbilitySet(const UGAS_GameplayAbilitySet* AbilitySet);
	
	void GiveAbilities(const UGAS_GameplayAbilitySet* AbilitySet);

	void TryAbilityInputBind(UInputAction* AbilityInput, const FGameplayAbilitySpecHandle& AbilitySpecHandle);

	void GiveAttributes(const UGAS_GameplayAbilitySet* AbilitySet);

	void GivePermenantTags(FGameplayTagContainer PermenantTags);
};
