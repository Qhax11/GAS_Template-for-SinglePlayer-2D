// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Interface/GAS_GenericTeamAgentInterface.h"
#include "Gameplay/Components/AC_Team.h"

ETeamAttitude::Type IGAS_GenericTeamAgentInterface::GetTeamAttitudeTowards(const AActor& Other) const
{
	UAC_Team* OtherTeam = Other.GetComponentByClass<UAC_Team>();
	uint8 OtherTeamId = OtherTeam ? OtherTeam->GetGenericTeamId().GetId() : NoTeamId;
	uint8 OwnerTeamId = this->GetGenericTeamId().GetId();

	if (OtherTeamId == NoTeamId || OwnerTeamId == NoTeamId)
	{
		return ETeamAttitude::Neutral;
	}

	if (OtherTeamId == OwnerTeamId)
	{
		return ETeamAttitude::Friendly;
	}

	return ETeamAttitude::Hostile;
}
