// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Gameplay/UI/W_HealthBar.h"
#include "Gameplay/UI/Components/WC_PropertyBar.h"

#include "DS_BlueprintWidgets.generated.h"

/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Blueprint Widgets"))
class GAS_TEMPLATESP2D_API UDS_BlueprintWidgets : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly, Category = "HealthBarComp")
	TSoftClassPtr<UWC_PropertyBar> EnemyHealthBarComp;
	
	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly, Category = "PropertyBarConfig")
	int32 HeightOfEnemyHealthBarComp;
};
