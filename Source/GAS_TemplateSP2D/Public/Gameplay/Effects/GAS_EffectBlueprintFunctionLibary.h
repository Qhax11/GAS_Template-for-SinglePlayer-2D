// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GAS_EffectBlueprintFunctionLibary.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGAS_EffectBlueprintFunctionLibary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "GAS_EffectBlueprintFunctionLibary")
	static UGameplayEffect* CreateEffectWithTSubclass(TSubclassOf<UGameplayEffect> EffectClass);

	// This function is for creating effect specs using Calculation classes.
	UFUNCTION(BlueprintCallable, Category = "GAS_EffectBlueprintFunctionLibary")
	static bool CreateInstantEffectSpecWithSetByCallerValue(FGameplayEffectSpec& OutSpec, UAbilitySystemComponent* SourceASC, TSubclassOf<UGameplayEffect> GameplayEffectClass, const FGameplayTag SetByCallerTag, float SetByCallerValue);
	 
	UFUNCTION(BlueprintCallable, Category = "GAS_EffectBlueprintFunctionLibary")
	static UGameplayEffect* CreateInstantEffectWithModifier(FGameplayAttribute ModifierAttribute, TEnumAsByte<EGameplayModOp::Type> ModifierOp, float ModifierValue);

	UFUNCTION(BlueprintCallable, Category = "GAS_EffectBlueprintFunctionLibary")
	static UGameplayEffect* CreateDurationEffectWithModifiers(FGameplayAttribute ModifierAttribute, TEnumAsByte<EGameplayModOp::Type> ModifierOp, float ModifierValue, float Duration);

	UFUNCTION(BlueprintCallable, Category = "GAS_EffectBlueprintFunctionLibary|Effects")
	static UGameplayEffect* CreateDurationEffectWithGrantedTags(TArray<FGameplayTag> TagsToAppend, float Duration);

	UFUNCTION(BlueprintCallable, Category = "GAS_EffectBlueprintFunctionLibary")
	static void AddTagsToEffectSpecWithArray(FGameplayEffectSpec& Spec, TArray<FGameplayTag> TagsToAdd);

	UFUNCTION(BlueprintCallable, Category = "GAS_EffectBlueprintFunctionLibary")
	static void AddTagsToEffectSpecWithContain(FGameplayEffectSpec& Spec, FGameplayTagContainer TagContainer);

	UFUNCTION(BlueprintCallable, Category = "GAS_EffectBlueprintFunctionLibary")
	static bool ApplyEffectArrayToTarget(UAbilitySystemComponent* OwnerASC, UAbilitySystemComponent* TargetASC, TArray<TSubclassOf<UGameplayEffect>> EffectClasses);
};
