// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Gameplay/UI/AbilityData/W_AbilitySlot.h"
#include "DS_HUD.generated.h"

/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "HUD")) // Give it a better looking name in UI
class GAS_TEMPLATESP2D_API UDS_HUD : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Config, EditDefaultsOnly, Category = "AbilitySlotPanel")
	TSoftClassPtr<UW_AbilitySlot> WBP_AbilitySlot;

	UPROPERTY(Config, EditDefaultsOnly, Category = "AbilitySlotPanel")
	FGameplayTagContainer DisplayedAbilitiesTags;

	UPROPERTY(Config, EditDefaultsOnly, Category = "AbilitySlotPanel")
	FVector2D SpacerSizeBetweenAbilitySlots = FVector2D(10, 0);
};
