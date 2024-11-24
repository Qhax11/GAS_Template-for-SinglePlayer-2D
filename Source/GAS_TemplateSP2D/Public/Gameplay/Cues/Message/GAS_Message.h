// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Cues/GCN_ActorBase.h"
#include "Styling/SlateColor.h"
#include "GAS_Message.generated.h"


UENUM(BlueprintType)
enum EMessageTextAnim : uint8
{
	SlideUpFadeOut,
	FadeInAndFadeOut,
	ZoomOut,
	BounceIn,
};


UCLASS()
class GAS_TEMPLATESP2D_API AGAS_Message : public AGCN_ActorBase
{
	GENERATED_BODY()

public:

	virtual void OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) override;

protected:

	void Initialize();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_TriggerWidget(const FSlateColor FinalColor, const FString& FinalString, EMessageTextAnim MessageTextAnim);

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	FSlateColor WidgetTextColor;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	TEnumAsByte<EMessageTextAnim> WidgetTextAnim = EMessageTextAnim::SlideUpFadeOut;

protected:
	FSlateColor FinalTextColor;
	FString FinalTextString;
	TEnumAsByte<EMessageTextAnim> FinalShowTextType;
};
