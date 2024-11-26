// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Cues/GCN_ActorBase.h"
#include "Styling/SlateColor.h"
#include "GCN_MessageBase.generated.h"


UENUM(BlueprintType)
enum EMessageTextAnim : uint8
{
	SlideUpFadeOut,
	FadeInAndFadeOut,
	ZoomOut,
	BounceIn,
};

USTRUCT(BlueprintType)
struct FWidgetMessageData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "WidgetMessageData")
	FString MessageString = TEXT("");

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WidgetMessageData")
	FSlateColor MessageColor = FSlateColor(FLinearColor::White);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WidgetMessageData")
	TEnumAsByte <EMessageTextAnim> MessageTextAnim = EMessageTextAnim::SlideUpFadeOut;


	FWidgetMessageData() = default;

	FWidgetMessageData(FSlateColor InMessageColor, FString InMessageString, EMessageTextAnim InMessageTextAnim)
		: MessageColor(MessageColor),
		MessageString(InMessageString),
		MessageTextAnim(InMessageTextAnim)
	{}

};


UCLASS()
class GAS_TEMPLATESP2D_API AGCN_MessageBase : public AGCN_ActorBase
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void BP_TriggerWidget(const FWidgetMessageData& MessageData);

	UPROPERTY(EditDefaultsOnly, Category = "MessageConfig")
	FWidgetMessageData WidgetMessageData;

};
