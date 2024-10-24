// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AS_Base.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


#define INVALID_ATTRIBUTE_VALUE -1.0f

USTRUCT(BlueprintType)
struct FAttributeChangeCallbackData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "Attribute Change Data")
	UAbilitySystemComponent* AbilitySystemComponent = nullptr;

	UPROPERTY()
	FGameplayAttributeData AttributeData;

	UPROPERTY(BlueprintReadWrite, Category = "Attribute Change Data")
	float CurrentValue = INVALID_ATTRIBUTE_VALUE;

	UPROPERTY(BlueprintReadWrite, Category = "Attribute Change Data")
	float BaseValue = INVALID_ATTRIBUTE_VALUE;

	UPROPERTY(BlueprintReadWrite, Category = "Attribute Change Data")
	float MaxValue = INVALID_ATTRIBUTE_VALUE;

public:

	FAttributeChangeCallbackData() = default;

	FAttributeChangeCallbackData(UAbilitySystemComponent* NewAbilitySystemComponent, FGameplayAttributeData NewAttributeData) :
		FAttributeChangeCallbackData(NewAbilitySystemComponent, NewAttributeData, NewAttributeData.GetCurrentValue(), INVALID_ATTRIBUTE_VALUE)
	{
	}

	FAttributeChangeCallbackData(UAbilitySystemComponent* NewAbilitySystemComponent, FGameplayAttributeData NewAttributeData, float NewCurrentValue, float NewMaxValue) :
		AbilitySystemComponent(NewAbilitySystemComponent),
		AttributeData(NewAttributeData),
		CurrentValue(NewCurrentValue),
		MaxValue(NewMaxValue)
	{
		BaseValue = AttributeData.GetBaseValue();
	}

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPropertyValueChanged, const FAttributeChangeCallbackData&, Data);

// Doesent used because brodcast doesent work with this way
/*
#define AttributeDelegateSetup(AttributeName)\
	FOnPropertyValueChanged On##AttributeName##Changed;\
	*/

UCLASS()
class GAS_TEMPLATESP2D_API UAS_Base : public UAttributeSet
{
	GENERATED_BODY()

public:

	UAS_Base();

	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	// Current Health, when 0 we expect owner to die unless prevented by an ability. Capped by MaxHealth.
	// Positive changes can directly use this.
	// Negative changes to Health should go through Damage meta attribute.

	    UPROPERTY(BlueprintReadOnly, Category = "Endurance")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAS_Base, Health)
		FOnPropertyValueChanged OnHealthChanged;

		// MaxHealth is its own attribute since GameplayEffects may modify it
		UPROPERTY(BlueprintReadOnly, Category = "Endurance")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAS_Base, MaxHealth)
		FOnPropertyValueChanged OnMaxHealthChanged;

		UPROPERTY(BlueprintReadOnly, Category = "Endurance")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAS_Base, Armor)
		FOnPropertyValueChanged OnArmorChanged;

		UPROPERTY(BlueprintReadOnly, Category = "Attack")
	FGameplayAttributeData PhysicalDamage;
	ATTRIBUTE_ACCESSORS(UAS_Base, PhysicalDamage)
		FOnPropertyValueChanged OnPhysicalDamageChanged;

		UPROPERTY(BlueprintReadOnly, Category = "Util")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UAS_Base, MovementSpeed)
		FOnPropertyValueChanged OnMovementSpeedChanged;

	
protected:

	virtual bool BroadcastPropertyChange(const FGameplayEffectModCallbackData& Data);

};
