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
			FGameplayEffectSpec* EffectSpec = NewHandle.Data.Get();
            if (EffectSpec)
            {
            	EffectSpec->SetSetByCallerMagnitude(GAS_Tags::TAG_Gameplay_SetByCaller_DamageAmount, Damage.GetValueAtLevel(GetAbilityLevel()));
            }
			TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpec);
		}
	}
}
