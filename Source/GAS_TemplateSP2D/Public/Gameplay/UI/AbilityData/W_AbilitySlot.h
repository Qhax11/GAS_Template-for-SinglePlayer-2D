// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Gameplay/Abilities/GAS_GameplayAbilityBase.h"
#include "W_AbilitySlot.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UW_AbilitySlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Setting veriables
	virtual void CustomInitialize(UAbilitySystemComponent* ASC, UGAS_GameplayAbilityBase* AbilityBase);

	UFUNCTION(Blueprintcallable)
	void InitialListenCooldown(UAbilitySystemComponent* AbilitySystemComponent, FGameplayTag CooldownTag);

protected:
	//This function starts working when the cooldown of the ability starts and starts a timer.
	UFUNCTION(Blueprintcallable)
	void OnCooldownBegin(FGameplayTag CooldownTag, float TimeRemaining, float Duration);

	void CooldownTimeCounter();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnCoolDownUpdated(const float InRemainingTime, float InPercent);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnCoolDownBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnCoolDownFinished();

	UPROPERTY(BlueprintReadOnly)
	UMaterialInstanceDynamic* ImageMaterial;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* IMG_AbilityImage;

	UPROPERTY(BlueprintReadWrite)
	double CooldownEndTime;

	FTimerHandle TimerHandle_CooldownTimeCounter;

	float CooldownTimeRemaining;
	float CooldownDuration;

};
