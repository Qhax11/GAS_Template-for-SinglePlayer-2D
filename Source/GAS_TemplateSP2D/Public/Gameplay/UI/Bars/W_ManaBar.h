// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/UI/Bars/W_PropertyBarBase.h"
#include "Gameplay/Attributes/AS_Hero.h"
#include "W_ManaBar.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_ManaBar : public UW_PropertyBarBase
{
	GENERATED_BODY()
	
protected:

	virtual void SetDefaultValues(UAbilitySystemComponent* OwnerASC) override;

	virtual void BindAttributes(UAbilitySystemComponent* OwnerASC) override;

	UFUNCTION()
	void ManaChanged(const FAttributeChangeCallbackData& Data);

	UFUNCTION()
	void MaxManaChanged(const FAttributeChangeCallbackData& Data);
};
