// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_AbilitySlot.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_AbilitySlot : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* IMG_AbilityImage;

	UPROPERTY(BlueprintReadWrite)
	UMaterialInstanceDynamic* UMI;
};
