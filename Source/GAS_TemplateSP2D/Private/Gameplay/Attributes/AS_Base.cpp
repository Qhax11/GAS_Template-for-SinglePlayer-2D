// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Attributes/AS_Base.h"


UAS_Base::UAS_Base()
{
}

void UAS_Base::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
}

void UAS_Base::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	ClampingAttributeValues(Data);

    BroadcastPropertyChange(Data);
}

void UAS_Base::ClampingAttributeValues(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0, MaxHealth.GetCurrentValue()));
		Health.SetBaseValue(FMath::Clamp(Health.GetBaseValue(), 0, MaxHealth.GetCurrentValue()));
	}
}

bool UAS_Base::BroadcastPropertyChange(const FGameplayEffectModCallbackData& Data)
{
	bool bIsBroadcasted = false;

	FAttributeChangeCallbackData PropertyCallbackData = FAttributeChangeCallbackData(GetOwningAbilitySystemComponent(), *Data.EvaluatedData.Attribute.GetGameplayAttributeData(this));

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Base::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Base, Health)))
	{
		bIsBroadcasted = true;
		PropertyCallbackData.CurrentValue = Health.GetCurrentValue();
		PropertyCallbackData.MaxValue = MaxHealth.GetCurrentValue();
		OnHealthChanged.Broadcast(PropertyCallbackData);
	}
	else if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Base::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Base, MaxHealth)))
	{
		bIsBroadcasted = true;
		PropertyCallbackData.CurrentValue = MaxHealth.GetCurrentValue();
		OnMaxHealthChanged.Broadcast(PropertyCallbackData);
	}

	return bIsBroadcasted;
}

float UAS_Base::MakeClampManuel(float ClampedValue, float Min, float Max)
{
	if (ClampedValue > Max) 
	{
		UE_LOG(LogTemp, Warning, TEXT("A"));

		return Max;
	}

	else if (ClampedValue < Min)
	{
		UE_LOG(LogTemp, Warning, TEXT("B"));

		return Min;
	}

	UE_LOG(LogTemp, Warning, TEXT("C"));
	return ClampedValue;
}
