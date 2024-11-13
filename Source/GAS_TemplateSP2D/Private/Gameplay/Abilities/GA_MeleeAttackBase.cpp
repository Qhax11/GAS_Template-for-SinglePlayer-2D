// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_MeleeAttackBase.h"

void UGA_MeleeAttackBase::OnEventRecieved()
{
	TArray<AActor*> OutResultActors;
	CreateTraceFromTargetingDataWithTeamFilter(OutResultActors, ETeamAttitude::Hostile);

	FGameplayEffectSpec DamageSpec;
	CreateEffectWithMagnitude(DamageSpec,
		GetAbilitySystemComponentFromActorInfo(), 
		GEPhysicalDamage, 
		GAS_Tags::TAG_Gameplay_EffectData_SetByCaller_DamageAmount,
		Damage.GetValueAtLevel(GetAbilityLevel())
	);

	DamageSpec.AppendDynamicAssetTags(ToBeAddedTagsInPhysicalDamageEffect);

	for (AActor* CollectedActor : OutResultActors)
	{
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(CollectedActor))
		{
			GetAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget(DamageSpec, TargetASC);
		}
	}
}
