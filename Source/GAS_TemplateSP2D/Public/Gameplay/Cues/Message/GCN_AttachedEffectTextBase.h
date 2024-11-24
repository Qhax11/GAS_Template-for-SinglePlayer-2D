// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Cues/Message/GCN_PlayerMessageHUD.h"
#include "Gameplay/UI/Components/WC_AttachedEffectTextHandle.h"
#include "GCN_AttachedEffectTextBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API AGCN_AttachedEffectTextBase : public AGCN_PlayerMessageHUD
{
	GENERATED_BODY()
public:
	AGCN_AttachedEffectTextBase();

	virtual void OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) override;

	/**
     * This function checks if a Critical hit occurred within the Damage GameplayCue.
     * If a Critical hit is detected, it triggers the Critical GameplayCue instead of the Damage GameplayCue.
     */
	bool CheckAndExecuteGameplay(AActor* Target, FGameplayCueParameters Parameters);

	void PrepareText(float Value);

	FString AddingToString(FString String, FString AddedString, bool EndOfString);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UWC_AttachedEffectTextHandle* WC_AttachedEffectText;

	UPROPERTY(EditDefaultsOnly, Category = "Config", meta = (EditCondition = "!bOverrideText"))
	FString WillBeAddedFrontOfText;

	UPROPERTY(EditDefaultsOnly, Category = "Config", meta = (EditCondition = "!bOverrideText"))
	FString WillBeAddedEndOfText;
	
	UPROPERTY(EditDefaultsOnly, Category = "Config|OverrideText")
	bool bOverrideText;

	UPROPERTY(EditDefaultsOnly, Category = "Config|OverrideText", meta = (EditCondition = "bOverrideText"))
	FString OverridedText;
};
