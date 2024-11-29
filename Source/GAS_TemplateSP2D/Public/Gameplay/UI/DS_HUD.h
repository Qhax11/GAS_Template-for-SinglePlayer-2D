// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Engine/DeveloperSettings.h"
#include "Gameplay/UI/AbilityData/W_AbilitySlot.h"
#include "DS_HUD.generated.h"

/**
 *  This class is used for retrieving Blueprint classes and configuring HUD settings.
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "HUD")) 
class GAS_TEMPLATESP2D_API UDS_HUD : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Config, EditDefaultsOnly, Category = "DynamicAbilitySlotPanel")
	TSoftClassPtr<UW_AbilitySlot> WBP_AbilitySlot;

	UPROPERTY(Config, EditDefaultsOnly, Category = "DynamicAbilitySlotPanel")
	FGameplayTagContainer DisplayedAbilitiesTags;

	UPROPERTY(Config, EditDefaultsOnly, Category = "DynamicAbilitySlotPanel")
	FVector2D SpacerSizeBetweenAbilitySlots = FVector2D(10, 0);
};
