// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_MeleeAttackBase.h"

void UGA_MeleeAttackBase::OnEventRecieved()
{
	TArray<AActor*> OutResultActors;
	CreateTraceFromTargetingDataWithTeamFilter(OutResultActors, ETeamAttitude::Hostile);

	FGameplayEffectSpec DamageSpec;
	bool IsDamageSpecValid = CreateEffectWithMagnitude(DamageSpec,
		GetAbilitySystemComponentFromActorInfo(), 
		GEPhysicalDamage, 
		GAS_Tags::TAG_Gameplay_EffectData_SetByCaller_DamageAmount,
		Damage.GetValueAtLevel(GetAbilityLevel())
	);

	if (!IsDamageSpecValid)
	{
		UE_LOG(LogTemp, Warning, TEXT("DamageSpec is null in %s, cannot damage apply"), *this->GetName());
		return;
	}

	DamageSpec.AppendDynamicAssetTags(TagsToAddToPhysicalDamageEffect);

	for (AActor* CollectedActor : OutResultActors)
	{
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(CollectedActor))
		{
			GetAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget(DamageSpec, TargetASC);
		}
	}
}
