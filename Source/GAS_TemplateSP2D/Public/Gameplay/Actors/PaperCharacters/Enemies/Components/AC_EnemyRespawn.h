// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Components/AC_RespawnBase.h"
#include "AC_EnemyRespawn.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UAC_EnemyRespawn : public UAC_RespawnBase
{
	GENERATED_BODY()
public:

	virtual void BindCharacterDeSpawn() override;

	virtual void OnCharacterRespawn(AGAS_PaperCharacterBase* CharacterBase) override;


};
