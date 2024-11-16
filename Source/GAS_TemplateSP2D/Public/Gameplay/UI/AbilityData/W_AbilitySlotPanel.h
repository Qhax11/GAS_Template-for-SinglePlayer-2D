// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Gameplay/UI/AbilityData/W_AbilitySlot.h"
#include "Components/HorizontalBox.h"
#include "Gameplay/UI/DS_HUD.h"
#include "W_AbilitySlotPanel.generated.h"

/*
* This class creates Ability Slots as dynamic.
*/

UCLASS()
class GAS_TEMPLATESP2D_API UW_AbilitySlotPanel : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct();

protected:

	UFUNCTION()
	void OnAbilitySetGiven(const AActor* OwnerActor);

	UFUNCTION(BlueprintCallable)
	void AddAbilitySlotToAbilityPanel(UAbilitySystemComponent* ASC, UGAS_GameplayAbilityBase* AbilityBase);

	UFUNCTION()
	void OnAbilityGranted(UAbilitySystemComponent* ASC, FGameplayAbilitySpec& AbilitySpec);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UHorizontalBox* HB_Abilities;

	const UDS_HUD* HUDSettings;

};
