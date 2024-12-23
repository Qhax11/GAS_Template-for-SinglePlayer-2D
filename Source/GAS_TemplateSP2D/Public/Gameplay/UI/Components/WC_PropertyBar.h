// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Components/WidgetComponent.h"
#include "Gameplay/UI/Bars/W_HealthBar.h"
#include "WC_PropertyBar.generated.h"

/**
 *  
 */
UCLASS()
class GAS_TEMPLATESP2D_API UWC_PropertyBar : public UWidgetComponent
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

protected:

	UFUNCTION()
	void OnAbilitySetGiven(const AActor* OwnerActor);

	TObjectPtr<UW_HealthBar> HealthBar;
};
