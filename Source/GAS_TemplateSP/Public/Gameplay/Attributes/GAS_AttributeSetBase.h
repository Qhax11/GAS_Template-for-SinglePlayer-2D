// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GAS_AttributeSetBase.generated.h"


// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP_API UGAS_AttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:

	UGAS_AttributeSetBase();


	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	// Current Health, when 0 we expect owner to die unless prevented by an ability. Capped by MaxHealth.
	// Positive changes can directly use this.
	// Negative changes to Health should go through Damage meta attribute.

	UPROPERTY(BlueprintReadOnly, Category = "Endurance")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGAS_AttributeSetBase, Health)

		// MaxHealth is its own attribute since GameplayEffects may modify it
		UPROPERTY(BlueprintReadOnly, Category = "Endurance")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGAS_AttributeSetBase, MaxHealth)

		UPROPERTY(BlueprintReadOnly, Category = "Endurance")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UGAS_AttributeSetBase, Armor)

		UPROPERTY(BlueprintReadOnly, Category = "Attack")
	FGameplayAttributeData PhysicalDamage;
	ATTRIBUTE_ACCESSORS(UGAS_AttributeSetBase, PhysicalDamage)

		UPROPERTY(BlueprintReadOnly, Category = "Util")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UGAS_AttributeSetBase, MovementSpeed)

	
};
