// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/Interface/GAS_GenericTeamAgentInterface.h"
#include "AC_Team.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_Team : public UActorComponent, public IGAS_GenericTeamAgentInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_Team();

	UFUNCTION(BlueprintCallable)
	void SetTeamID(TEnumAsByte<EGAS_PredefinedTeamId> NewTeamID);

	FGenericTeamId GetGenericTeamId() const override;

	FGenericTeamId AssignedTeamID;

	UPROPERTY(EditAnywhere, Category = "Team Properties")
	TEnumAsByte <EGAS_PredefinedTeamId> TeamID;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
