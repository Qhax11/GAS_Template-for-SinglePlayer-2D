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

void UGAS_GameplayAbilityBase::CreateEffectWithMagnitude(FGameplayEffectSpec& Spec, UAbilitySystemComponent* SourceAbilitySystemComponent, TSubclassOf<UGameplayEffect> GameplayEffectClass, const FGameplayTag SetByCallerTag, float SetByCallerValue)
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
		}
	}
}

