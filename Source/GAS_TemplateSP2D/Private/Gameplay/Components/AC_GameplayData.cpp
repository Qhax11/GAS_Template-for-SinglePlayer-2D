// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/AC_GameplayData.h"
#include "Gameplay/Data/DA_ActorSounds.h"


UAC_GameplayData::UAC_GameplayData()
{
	PrimaryComponentTick.bCanEverTick = false;
}

UDA_ActorSounds* UAC_GameplayData::GetActorSoundsData()
{
	if (!DA_ActorSounds) 
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorSounds is null in: %s."), *GetName());
		return nullptr;
	}

	return DA_ActorSounds;
}




