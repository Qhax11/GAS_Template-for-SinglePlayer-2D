// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/UI/Bars/W_PropertyBar.h"
#include "Gameplay/Attributes/AS_Hero.h"
#include "W_ManaBar.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_ManaBar : public UW_PropertyBar
{
	GENERATED_BODY()
	
protected:

	virtual void BindAttributesAndSetDefaultValues(UAbilitySystemComponent* OwnerASC);

	UFUNCTION()
	void ManaChanged(const FAttributeChangeCallbackData& Data);
};
