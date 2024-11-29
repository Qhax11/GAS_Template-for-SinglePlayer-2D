// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/UI/Bars/W_PropertyBarBase.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "W_HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_HealthBar : public UW_PropertyBarBase
{
	GENERATED_BODY()

protected:

	virtual void SetDefaultValues(UAbilitySystemComponent* OwnerASC) override;

	virtual void BindAttributes(UAbilitySystemComponent* OwnerASC) override;

	UFUNCTION()
	void HealthChanged(const FAttributeChangeCallbackData& Data);

	UFUNCTION()
	void MaxHealthChanged(const FAttributeChangeCallbackData& Data);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnHealthChanged(const FAttributeChangeCallbackData& Data);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<class UProgressBar> BackgroundProgressBar;
};
