// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AbilitySystemComponent.h"
#include "Components/TextBlock.h"
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

	virtual void SetDefaultValues(UAbilitySystemComponent* OwnerASC);

	virtual void BindAttributes(UAbilitySystemComponent* OwnerASC);
	
	void SetPercantage(float Value1, float Value2);

	void SetValuesToTexts(float CurrentValue, float MaxValue);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UProgressBar* ProgressBar;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, OptionalWidget = true))
	UTextBlock* T_CurrentValue;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, OptionalWidget = true))
	UTextBlock* T_MaxValue;
};
