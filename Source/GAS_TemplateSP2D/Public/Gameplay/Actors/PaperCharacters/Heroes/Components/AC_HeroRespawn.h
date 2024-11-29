// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Gameplay/Components/AC_RespawnBase.h"
#include "AC_HeroRespawn.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_HeroRespawn : public UAC_RespawnBase
{
	GENERATED_BODY()

protected:
	virtual void BindCharacterDeSpawn() override;

	virtual void OnCharacterRespawn(AGAS_PaperCharacterBase* CharacterBase) override;

	void SetHeroLocation(AGAS_PaperCharacterBase* Hero);

};
