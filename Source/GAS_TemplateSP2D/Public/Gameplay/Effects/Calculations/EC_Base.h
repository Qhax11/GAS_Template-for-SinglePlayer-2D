// Qhax's GAS Template for SinglePlayer

#pragma once

#include "GameplayEffectExecutionCalculation.h"
#include "AbilitySystemComponent.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "Gameplay/Tags/GAS_Tags.h"
#include "EC_Base.generated.h"


USTRUCT()
struct FExecCalculationParameters
{
	GENERATED_BODY()
	FExecCalculationParameters() = default;

	FExecCalculationParameters(
		const FGameplayEffectCustomExecutionParameters& ExecutionParams)
		: ExecutionParams(const_cast<FGameplayEffectCustomExecutionParameters&>(ExecutionParams))
	{
		MutableSpec = ExecutionParams.GetOwningSpecForPreExecuteMod();

		GetSpec().GetAllAssetTags(EffectAssetTags);

		SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();
		SourceActor = SourceASC ? SourceASC->GetAvatarActor() : nullptr;

		TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
		TargetActor = TargetASC ? TargetASC->GetAvatarActor() : nullptr;
		if (ExecutionParams.GetOwningSpec().GetContext().GetHitResult())
			HitResult = *ExecutionParams.GetOwningSpec().GetContext().GetHitResult();
	}

	const UAS_Base* GetSourceAttributeSet() const
	{
		return SourceASC->GetSet<UAS_Base>();
	}
	template <typename T>
	const T* GetSourceAttributeSetTemplate() const
	{
		if (Cast<T>(SourceASC->GetSet<UAS_Base>()))
		{
			return SourceASC->GetSet<T>();
		}
		else
		{
			return nullptr;
		}
	}

	const UAS_Base* GetTargetAttributeSet() const
	{
		return TargetASC->GetSet<UAS_Base>();
	}

	template <typename T>
	const T* GetTargetAttributeSetTemplate() const
	{
		if (Cast<T>(TargetASC->GetSet<UAS_Base>()))
		{
			return TargetASC->GetSet<T>();
		}
		else
		{
			return nullptr;
		}
	}

	template <typename T>
	const T* GetSourceActorTemplate() const
	{
		if (const T* SourceActorCasted = Cast<T>(SourceActor))
		{
			return SourceActorCasted;
		}
		else
		{
			return nullptr;
		}
	}


	template <typename T>
	const T* GetTargetActorTemplate() const
	{
		if (const T* TargetActorCasted = Cast<T>(TargetActor))
		{
			return TargetActorCasted;
		}
		else
		{
			return nullptr;
		}
	}

	const FGameplayEffectCustomExecutionParameters& GetExecutionParams() const
	{
		return ExecutionParams;
	}

	const FGameplayEffectSpec& GetSpec() const
	{
		return ExecutionParams.GetOwningSpec();
	}

	const FHitResult* GetHitResult() const
	{
		return ExecutionParams.GetOwningSpec().GetContext().GetHitResult();
	}

	AActor* SourceActor = nullptr;

	UAbilitySystemComponent* SourceASC = nullptr;

	AActor* TargetActor = nullptr;

	UAbilitySystemComponent* TargetASC = nullptr;

	FGameplayTagContainer EffectAssetTags;

	FGameplayEffectSpec* MutableSpec = nullptr;

	FGameplayEffectCustomExecutionParameters ExecutionParams;

	FHitResult HitResult;
};


UCLASS()
class GAS_TEMPLATESP2D_API UEC_Base : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override final;

	virtual void ExecuteWithParams(FExecCalculationParameters Params, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const;

protected:

	void MakeAggregatorEvaluatedParamsByEffectSpec(const FGameplayEffectSpec& EffectSpec, FAggregatorEvaluateParameters& OutEvaluatedParams) const;

	void MakeAggregatorEvaluatedParamsBySourceTagsAndTargetTags(const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FAggregatorEvaluateParameters& OutEvaluatedParams) const;

	// We take  magnitude value from SetByCaller, it is in EffectSpec.
	float GetSetByCallerMagnitude(const FGameplayEffectSpec& EffectSpec, const FGameplayTag& DataTag, float DefaultIfNotFound = .0f, bool bWarnIfNotFound = false) const;
};
