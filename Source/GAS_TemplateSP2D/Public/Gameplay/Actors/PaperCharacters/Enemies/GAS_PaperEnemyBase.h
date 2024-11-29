// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "GAS_PaperEnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API AGAS_PaperEnemyBase : public AGAS_PaperCharacterBase
{
	GENERATED_BODY()

public:
	AGAS_PaperEnemyBase(const class FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;

protected:

	//* Components *//
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Enemy|Components")
	class UAC_EnemyRespawn* EnemyRespawnComponent;

};
