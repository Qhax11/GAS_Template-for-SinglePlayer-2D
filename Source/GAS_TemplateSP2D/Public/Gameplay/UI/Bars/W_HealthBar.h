// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/UI/Bars/W_PropertyBar.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "W_HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_HealthBar : public UW_PropertyBar
{
	GENERATED_BODY()

protected:

	virtual void BindAttributes(UAbilitySystemComponent* OwnerASC) override;

	virtual void SetDefaultValues(UAbilitySystemComponent* OwnerASC) override;

	UFUNCTION()
	void HealthChanged(const FAttributeChangeCallbackData& Data);

	UFUNCTION()
	void MaxHealthChanged(const FAttributeChangeCallbackData& Data);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnHealthChanged(const FAttributeChangeCallbackData& Data);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UProgressBar* BackgroundProgressBar;
};
