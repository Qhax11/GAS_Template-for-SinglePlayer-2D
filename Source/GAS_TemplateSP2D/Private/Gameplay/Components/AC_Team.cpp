// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/AC_Team.h"

UAC_Team::UAC_Team()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_Team::SetTeamID(TEnumAsByte<EGAS_PredefinedTeamId> NewTeamID)
{
	AssignedTeamID = FGenericTeamId(NewTeamID);
}

FGenericTeamId UAC_Team::GetGenericTeamId() const
{
	return AssignedTeamID;
}

void UAC_Team::BeginPlay()
{
	Super::BeginPlay();

	SetTeamID(TeamID);
}

