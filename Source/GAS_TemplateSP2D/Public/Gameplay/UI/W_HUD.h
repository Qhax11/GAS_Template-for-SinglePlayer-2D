// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Gameplay/UI/W_HealthBar.h"
#include "W_HUD.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_HUD : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativePreConstruct();
	virtual void NativeConstruct();

	UFUNCTION()
	void OnAbilitySetGiven(const AActor* OwnerActor);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UW_HealthBar* HealthBar;
	
};
