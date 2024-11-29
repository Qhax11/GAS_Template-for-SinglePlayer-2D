// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Blueprint/UserWidget.h"
#include "W_HUD.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_HUD : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct();

	UFUNCTION()
	void OnAbilitySetGiven(const AActor* OwnerActor);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<class UW_HealthBar> HealthBar;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<class UW_ManaBar> ManaBar;
};
