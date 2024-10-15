// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/UI/W_PropertyBar.h"
#include "W_HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_HealthBar : public UW_PropertyBar
{
	GENERATED_BODY()

public:

	virtual void Initialize(AActor* Owner);
protected:

	virtual void BindAttributesAndSetDefaultValues(UAbilitySystemComponent* OwnerASC);

	UFUNCTION()
	void HealthChanged(const FAttributeChangeCallbackData& Data);

};
