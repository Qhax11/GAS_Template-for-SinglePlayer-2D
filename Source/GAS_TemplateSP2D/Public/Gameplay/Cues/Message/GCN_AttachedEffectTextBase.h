// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Gameplay/Cues/Message/GCN_MessageBase.h"
#include "Gameplay/UI/Components/WC_AttachedEffectTextHandle.h"
#include "GCN_AttachedEffectTextBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API AGCN_AttachedEffectTextBase : public AGCN_MessageBase
{
	GENERATED_BODY()
public:
	AGCN_AttachedEffectTextBase();

	// For instant effects or periodic ticks
	virtual void OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) override;

	/**
     * This function checks if a Critical hit occurred within the Damage GameplayCue.
     * If a Critical hit is detected, it triggers the Critical GameplayCue instead of the Damage GameplayCue.
     */
	bool CheckAndExecuteGameplay(AActor* Target, FGameplayCueParameters Parameters);

	void PrepareText(float RawMagnitudeValue);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWC_AttachedEffectTextHandle* WC_AttachedEffectText;

	UPROPERTY(EditDefaultsOnly, Category = "MessageConfig", meta = (EditCondition = "!bOverrideText"))
	FString PrefixText;

	UPROPERTY(EditDefaultsOnly, Category = "MessageConfig", meta = (EditCondition = "!bOverrideText"))
	FString SuffixText;
	
	UPROPERTY(EditDefaultsOnly, Category = "MessageConfig|OverrideText")
	bool bOverrideText;

	UPROPERTY(EditDefaultsOnly, Category = "MessageConfig|OverrideText", meta = (EditCondition = "bOverrideText"))
	FString OverridedText;
};
