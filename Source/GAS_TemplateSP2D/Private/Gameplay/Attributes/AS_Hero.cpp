// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Attributes/AS_Hero.h"

bool UAS_Hero::ClampAttributeValues(const FGameplayEffectModCallbackData& Data)
{
	if (!Super::ClampAttributeValues(Data)) 
	{
		return false;
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		Mana.SetBaseValue(FMath::Clamp(Mana.GetBaseValue(), 0, MaxMana.GetCurrentValue()));
		Mana.SetCurrentValue(FMath::Clamp(Mana.GetBaseValue(), 0, MaxMana.GetCurrentValue()));
	}

	return true;
}

bool UAS_Hero::BroadcastPropertyChange(const FGameplayEffectModCallbackData& Data)
{
	if (Super::BroadcastPropertyChange(Data))
	{
		return true;
	}

	bool bIsBroadcasted = false;

	if (!Data.EvaluatedData.IsValid)
	{
		return bIsBroadcasted;
	}

	FGameplayAttributeData AttributeData;
	AttributeData = *Data.EvaluatedData.Attribute.GetGameplayAttributeData(this);
	FAttributeChangeCallbackData PropertyCallbackData = FAttributeChangeCallbackData(GetOwningAbilitySystemComponent(), AttributeData);

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Hero::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Hero, Mana)))
	{
		bIsBroadcasted = true;
		PropertyCallbackData.CurrentValue = Mana.GetCurrentValue();
		PropertyCallbackData.MaxValue = MaxMana.GetCurrentValue();
		OnManaChanged.Broadcast(PropertyCallbackData);
	}
	else if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Hero::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Hero, MaxMana)))
	{
		bIsBroadcasted = true;
		PropertyCallbackData.CurrentValue = MaxMana.GetCurrentValue();
		OnMaxManaChanged.Broadcast(PropertyCallbackData);
	}
	else if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Hero::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Hero, CriticalDamage)))
	{
		bIsBroadcasted = true;
		PropertyCallbackData.CurrentValue = CriticalDamage.GetCurrentValue();
		OnCriticalDamageChanged.Broadcast(PropertyCallbackData);
	}
	else if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Hero::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Hero, CriticalChance)))
	{
		bIsBroadcasted = true;
		PropertyCallbackData.CurrentValue = CriticalChance.GetCurrentValue();
		OnCriticalChanceChanged.Broadcast(PropertyCallbackData);
	}

	return bIsBroadcasted;
}
