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

	// Checking default stuff like is blind or is it critical? 
	void DefaultTextTypeChecks(const FGameplayTagContainer TextTags);

	FString AddingToString(FString String, FString AddedString, bool EndOfString);

	UPROPERTY(EditDefaultsOnly, Category = "Config|Blind")
	FString BlindString = "Blind!";

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	FString WillBeAddedFrontOfText;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	FString WillBeAddedEndOfText;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	FSlateColor WidgetTextColor;

	UPROPERTY(EditDefaultsOnly, Category = "Config")
	TEnumAsByte<EShowTextAnim> WidgetShowTextType;

	UPROPERTY(EditDefaultsOnly, Category = "Config|Critical")
	FSlateColor CriticalColor;

	UPROPERTY(EditDefaultsOnly, Category = "Config|Critical")
	FString  WillBeAddedEndOfCriticalText;

private:

	FSlateColor FinalTextColor;
	FString FinalTextString;
	TEnumAsByte<EShowTextAnim> FinalShowTextType;
};
