// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AbilitySystemComponent.h"
#include "W_PropertyBar.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_PropertyBar : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void InitializePropertyBar(AActor* Owner);

protected:
	
	virtual void SetPercantage(float Value1, float Value2);
	
	virtual void BindAttributesAndSetDefaultValues(UAbilitySystemComponent* OwnerASC);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UProgressBar* ProgressBar;
};
