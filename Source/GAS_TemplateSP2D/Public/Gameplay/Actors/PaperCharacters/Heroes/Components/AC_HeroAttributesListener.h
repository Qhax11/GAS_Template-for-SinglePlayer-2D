// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Gameplay/Components/AC_AttributesListenerBase.h"
#include "AC_HeroAttributesListener.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UAC_HeroAttributesListener : public UAC_AttributesListenerBase
{
	GENERATED_BODY()

public:

	virtual bool Initialize(const AActor* OwnerActor) override;

protected:

	UFUNCTION()
	virtual void ManaChanged(const FAttributeChangeCallbackData& Data);
	
};
