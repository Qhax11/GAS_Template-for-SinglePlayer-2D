// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Cues/GCN_ActorBase.h"
#include "Styling/SlateColor.h"
#include "Gameplay/UI/Components/WC_ShowTextHandle.h"
#include "GCN_ShowTextWidgetCompBase.generated.h"


UENUM(BlueprintType)
enum EShowTextAnim : uint8
{
	Default,
	Blind,
	Critical,
	Bleed,
	Heal,
};


UCLASS()
class GAS_TEMPLATESP2D_API AGCN_ShowTextWidgetCompBase : public AGCN_ActorBase
{
	GENERATED_BODY()
	

public:
	AGCN_ShowTextWidgetCompBase();

	virtual void OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UWC_ShowTextHandle* ShowTextHandle;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void TriggerWidget(const FSlateColor FinalColor, const FString& FinalString, EShowTextAnim TextType);

	void DefaultSettings(float Value);

	FString AddingToString(FString String, FString AddedString, bool EndOfString);

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	FSlateColor WidgetTextColor;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	TEnumAsByte<EShowTextAnim> WidgetTextAnim;

	UPROPERTY(EditDefaultsOnly, Category = "Config", meta = (EditCondition = "!bOverrideText"))
	FString WillBeAddedFrontOfText;

	UPROPERTY(EditDefaultsOnly, Category = "Config", meta = (EditCondition = "!bOverrideText"))
	FString WillBeAddedEndOfText;

	UPROPERTY(EditDefaultsOnly, Category = "Config|OverrideText")
	bool bOverrideText;

	UPROPERTY(EditDefaultsOnly, Category = "Config|OverrideText", meta = (EditCondition = "bOverrideText"))
	FString OverridedText;

private:
	// These are sent to the ShowText widget
	FSlateColor FinalTextColor;
	FString FinalTextString;
	TEnumAsByte<EShowTextAnim> FinalShowTextType;
};
