// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/AC_Team.h"

// Sets default values for this component's properties
UAC_Team::UAC_Team()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UAC_Team::SetTeamID(TEnumAsByte<EGAS_PredefinedTeamId> NewTeamID)
{
	AssignedTeamID = FGenericTeamId(NewTeamID);
}

FGenericTeamId UAC_Team::GetGenericTeamId() const
{
	return AssignedTeamID;
}

// Called when the game starts
void UAC_Team::BeginPlay()
{
	Super::BeginPlay();

	SetTeamID(TeamID);
}

