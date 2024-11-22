// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Abilities/GAS_GameplayAbilityBase.h"
#include "Kismet\KismetSystemLibrary.h"


void UGAS_GameplayAbilityBase::CreateTraceFromTargetingData(TArray<AActor*>& OutActors)
{
	FVector StartLocation = GetAvatarActorFromActorInfo()->GetActorLocation();
	FRotator TraceDirection = GetAvatarActorFromActorInfo()->GetActorForwardVector().Rotation();

	TargetingData->Trace->MakeTrace(GetAvatarActorFromActorInfo(), GetWorld(), StartLocation, TraceDirection, OutActors);
}

void UGAS_GameplayAbilityBase::CreateTraceFromTargetingDataWithTeamFilter(TArray<AActor*>& OutActors, ETeamAttitude::Type TeamAttidue)
{
	CreateTraceFromTargetingData(OutActors);

	const AActor& Owner = *GetAvatarActorFromActorInfo();
	for (AActor* CollectedActor : OutActors)
	{
		if (UAC_Team* TeamComp = CollectedActor->GetComponentByClass<UAC_Team>())
		{
			if (TeamComp->GetTeamAttitudeTowards(Owner) != TeamAttidue)
			{
				OutActors.Remove(CollectedActor);
			}
		}
	}
}

bool UGAS_GameplayAbilityBase::CreateEffectWithMagnitude(FGameplayEffectSpec& Spec, UAbilitySystemComponent* SourceAbilitySystemComponent, TSubclassOf<UGameplayEffect> GameplayEffectClass, const FGameplayTag SetByCallerTag, float SetByCallerValue)
{
	FGameplayEffectContextHandle EffectContext = SourceAbilitySystemComponent->MakeEffectContext();
	FGameplayEffectSpecHandle NewHandle = SourceAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass, 1, EffectContext);
	if (NewHandle.IsValid())
	{
		FGameplayEffectSpec* EffectSpec = NewHandle.Data.Get();
		if (EffectSpec)
		{
			if (SetByCallerTag.IsValid() && SetByCallerValue != 0)
			{
				EffectSpec->SetSetByCallerMagnitude(SetByCallerTag, SetByCallerValue);
			}
			Spec = *EffectSpec;
			return true;
		}
	}
	return false;
}

float UGAS_GameplayAbilityBase::GetCost(int32 AbilityLevel) const
{
	UGameplayEffect* CostGameplayEffect = GetCostGameplayEffect();
	float CostValue = 0;

	if (CostGameplayEffect && !CostGameplayEffect->Modifiers.IsEmpty())
	{
		// Getting cost value from CostGameplayEffect
		CostGameplayEffect->Modifiers[0].ModifierMagnitude.GetStaticMagnitudeIfPossible(AbilityLevel, CostValue);
	}

	return CostValue;
}

float UGAS_GameplayAbilityBase::GetCoolDown(int32 AbilityLevel) const
{
	UGameplayEffect* CooldownGameplayEffect = GetCooldownGameplayEffect();
	float CooldownDuration = 0;

	if (CooldownGameplayEffect && CooldownGameplayEffect->DurationPolicy == EGameplayEffectDurationType::HasDuration)
	{
		// Getting cooldown duration from CooldownGameplayEffect
		CooldownGameplayEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(AbilityLevel, CooldownDuration);
	}

	return CooldownDuration;
}

void UGAS_GameplayAbilityBase::IncreaseLevel(UAbilitySystemComponent* AbilitySystemComp)
{
	if (!AbilitySystemComp) 
	{
		return;
	}

	FGameplayAbilitySpec* AbilitySpec = AbilitySystemComp->FindAbilitySpecFromClass(this->GetClass());
	if (!AbilitySpec)
	{
		return;
	}

	int CurrentAbilityLevel = AbilitySpec->Level;
	CurrentAbilityLevel++;

	// This is actual setting.
	AbilitySpec->Level = CurrentAbilityLevel;

	int32 NewAbilityLevel = AbilitySpec->Level;
	OnAbilityLevelChanged.Broadcast(this, NewAbilityLevel);

	float NewCost = GetCost(NewAbilityLevel);
	OnAbilityCostChanged.Broadcast(this, NewCost);

	float NewCooldown = GetCoolDown(NewAbilityLevel);
	OnAbilityCooldownChanged.Broadcast(this, NewCooldown);

	AbilitySystemComp->MarkAbilitySpecDirty(*AbilitySpec);
}



