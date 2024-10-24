// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/GA_MeleeAttackBase.h"

void UGA_MeleeAttackBase::OnEventRecieved()
{
	TArray<AActor*> OutResultActors;
	CreateTraceFromTargetingData(OutResultActors);

	for (AActor* CollectedActor : OutResultActors)
	{
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(CollectedActor))
		{
			FGameplayEffectSpecHandle NewHandle = GetAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(GEPhysicalDamage, 1, FGameplayEffectContextHandle());
			TargetASC->ApplyGameplayEffectSpecToSelf(*(NewHandle.Data.Get()));
		}
	}
}
