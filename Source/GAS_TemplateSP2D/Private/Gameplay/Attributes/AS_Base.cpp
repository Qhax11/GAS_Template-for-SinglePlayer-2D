// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Attributes/AS_Base.h"
#include "GameplayEffectExtension.h"


UAS_Base::UAS_Base()
{
}

void UAS_Base::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
}

void UAS_Base::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    BroadcastPropertyChange(Data);
}

bool UAS_Base::BroadcastPropertyChange(const FGameplayEffectModCallbackData& Data)
{
	bool bIsBroadcasted = false;

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Base::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Base, Health)))
	{
		bIsBroadcasted = true;

		OnHealthChanged.Broadcast(FAttributeChangeCallbackData(
			GetOwningAbilitySystemComponent(),
			*Data.EvaluatedData.Attribute.GetGameplayAttributeData(this),
			Health.GetCurrentValue(),
			MaxHealth.GetCurrentValue())
		);
	}

	return bIsBroadcasted;
}
