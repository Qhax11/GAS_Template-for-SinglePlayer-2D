// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GenericTeamAgentInterface.h"
#include "GAS_GenericTeamAgentInterface.generated.h"

UENUM(BlueprintType)
enum EGAS_PredefinedTeamId : uint8
{
	TeamId0 = 0,
	TeamId1 = 1,
	TeamId2 = 2,
	TeamId3 = 3,
	TeamId4 = 4,
	TeamId5 = 5,
	TeamId6 = 6,
	TeamId7 = 7,
	TeamId8 = 8,
	TeamId9 = 9,
	NoTeamId = 255,
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGAS_GenericTeamAgentInterface : public UGenericTeamAgentInterface
{
	GENERATED_BODY()
};


class GAS_TEMPLATESP2D_API IGAS_GenericTeamAgentInterface : public IGenericTeamAgentInterface
{
	GENERATED_IINTERFACE_BODY()

public:

	virtual FGenericTeamId GetGenericTeamId() const override { return FGenericTeamId::NoTeam; }

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

};
