// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "W_AttachedEffectTextParent.generated.h"

/**
 * This class just for add the created show text widgets to the canvas
 * In with that we can add widget to canvas more than one in same time
 */

UCLASS()
class GAS_TEMPLATESP2D_API UW_AttachedEffectTextParent : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void AddChildText(UUserWidget* Child);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCanvasPanel> Canvas;

};
