// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Hero/GA_HealthPotion.h"

void UGA_HealthPotion::OnEventRecieved()
{
	const FGameplayEffectSpecHandle EffectSpecHandle = GetAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(HealEffectClass, 1, GetAbilitySystemComponentFromActorInfo()->MakeEffectContext());
	FGameplayEffectSpec* EffectSpec = EffectSpecHandle.Data.Get();


	if (EffectSpec)
	{
		EffectSpec->SetSetByCallerMagnitude(GAS_Tags::TAG_Gameplay_EffectData_SetByCaller_HealingAmount, HealValue.GetValueAtLevel(GetAbilityLevel()));
		GetAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToSelf(*EffectSpec);
	}
}
