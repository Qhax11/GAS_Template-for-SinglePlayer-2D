// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/AC_AbilitySet.h"

UAC_AbilitySet::UAC_AbilitySet()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_AbilitySet::Initialize(UGAS_AbilitySystemComponent* ASC)
{
	if (ASC)
	{
		if (ASC->GiveAbilitySet(AbilitySet)) 
		{
			OnAbilitySetGiven.Broadcast(GetOwner());
		}
	}
}






