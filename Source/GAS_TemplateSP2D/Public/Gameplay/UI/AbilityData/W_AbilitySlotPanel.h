// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Gameplay/UI/AbilityData/W_AbilitySlot.h"
#include "Components/HorizontalBox.h"
#include "W_AbilitySlotPanel.generated.h"

USTRUCT(BlueprintType)
struct FAbilitySlotData
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, Category = "AbilitySlotData")
	FGameplayTagContainer WhichAbilitiesShowOnHUD;
};

UCLASS()
class GAS_TEMPLATESP2D_API UGAS_AbilitySlotPanel : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, Category = "AbilitySlotPanel")
	TArray<FAbilitySlotData> AbilitySlotDates;


};


UCLASS()
class GAS_TEMPLATESP2D_API UW_AbilitySlotPanel : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct();

	UFUNCTION()
	void OnAbilitySetGiven(const AActor* OwnerActor);

	UPROPERTY(EditDefaultsOnly, Category = "AbilitySlotData")
	FGameplayTagContainer WhichAbilitiesShowOnHUD;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UHorizontalBox* HorizontalAbilities;

};
