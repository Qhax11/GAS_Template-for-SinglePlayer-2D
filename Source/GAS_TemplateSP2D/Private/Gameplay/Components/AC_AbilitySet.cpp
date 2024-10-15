// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/AC_AbilitySet.h"

// Sets default values for this component's properties
UAC_AbilitySet::UAC_AbilitySet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
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






