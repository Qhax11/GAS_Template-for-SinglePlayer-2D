// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/AC_AbilitySet.h"

UAC_AbilitySet::UAC_AbilitySet()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_AbilitySet::Initialize(UGAS_AbilitySystemComponent* ASC)
{
	if (!ASC)
	{
		UE_LOG(LogTemp, Warning, TEXT("ASC is null in: %s. AbilitySet cannot be initialized."), *GetName());
		return;
	}
	if (ASC->GiveAbilitySet(AbilitySet))
	{
		OnAbilitySetGiven.Broadcast(GetOwner());
	}
}






