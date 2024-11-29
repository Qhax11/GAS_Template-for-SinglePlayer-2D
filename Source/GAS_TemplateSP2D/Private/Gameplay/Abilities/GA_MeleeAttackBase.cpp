// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_MeleeAttackBase.h"
#include <AbilitySystemGlobals.h>

void UGA_MeleeAttackBase::OnEventRecieved()
{
	TArray<AActor*> OutResultActors;
	CreateTraceFromTargetingDataWithTeamFilter(OutResultActors, ETeamAttitude::Hostile);

	FGameplayEffectSpec DamageSpec;
	bool bIsDamageSpecValid = UGAS_EffectBlueprintFunctionLibary::CreateInstantEffectSpecWithSetByCallerValue(
		DamageSpec,
		GetAbilitySystemComponentFromActorInfo(),
		GEPhysicalDamage,
		GAS_Tags::TAG_Gameplay_EffectData_SetByCaller_DamageAmount,
		Damage.GetValueAtLevel(GetAbilityLevel())
		);

	if (!bIsDamageSpecValid)
	{
		UE_LOG(LogTemp, Warning, TEXT("DamageSpec is null in %s, cannot damage apply"), *GetName());
		return;
	}

	UGAS_EffectBlueprintFunctionLibary::AddTagsToEffectSpecWithContain(DamageSpec, TagsToAddToPhysicalDamageEffect);

	for (AActor* CollectedActor : OutResultActors)
	{
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(CollectedActor))
		{
			GetAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget(DamageSpec, TargetASC);
		}
	}
}
