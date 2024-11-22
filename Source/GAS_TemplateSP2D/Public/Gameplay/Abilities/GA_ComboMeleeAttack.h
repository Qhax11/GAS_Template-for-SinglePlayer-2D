// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Abilities/GA_MeleeAttackBase.h"
#include "GA_ComboMeleeAttack.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGA_ComboMeleeAttack : public UGA_MeleeAttackBase
{
	GENERATED_BODY()

public:

	UGA_ComboMeleeAttack();

protected:

	virtual void OnEventRecieved();

	virtual UPaperZDAnimSequence* SelectSequence() override;
	
	UPaperZDAnimSequence* GetNextComboSequence();

	int32 SequenceIndex = 0;
};
