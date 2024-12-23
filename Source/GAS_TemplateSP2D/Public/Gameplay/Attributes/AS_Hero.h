// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "Gameplay/Attributes/AS_Base.h"
#include "AS_Hero.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UAS_Hero : public UAS_Base
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Category = "Hero")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAS_Hero, Mana)
		FOnPropertyValueChanged OnManaChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Hero")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAS_Hero, MaxMana)
		FOnPropertyValueChanged OnMaxManaChanged;

	// Implemented as a percentage value 
	UPROPERTY(BlueprintReadOnly, Category = "Hero")
	FGameplayAttributeData LifeSteal;
	ATTRIBUTE_ACCESSORS(UAS_Hero, LifeSteal)
		FOnPropertyValueChanged OnLifeStealChanged;

	// Implemented as a percentage value 
	UPROPERTY(BlueprintReadOnly, Category = "Hero")
	FGameplayAttributeData CriticalDamage;
	ATTRIBUTE_ACCESSORS(UAS_Hero, CriticalDamage)
		FOnPropertyValueChanged OnCriticalDamageChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Hero")
	FGameplayAttributeData CriticalChance;
	ATTRIBUTE_ACCESSORS(UAS_Hero, CriticalChance)
		FOnPropertyValueChanged OnCriticalChanceChanged;

	virtual bool ClampAttributeValues(const FGameplayEffectModCallbackData& Data)  override;

protected:

	virtual bool BroadcastPropertyChange(const FGameplayEffectModCallbackData& Data) override;
};
