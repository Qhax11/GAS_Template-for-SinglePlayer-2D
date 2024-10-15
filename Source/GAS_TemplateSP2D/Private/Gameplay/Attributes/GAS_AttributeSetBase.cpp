// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Attributes/GAS_AttributeSetBase.h"
#include "GameplayEffectExtension.h"


UGAS_AttributeSetBase::UGAS_AttributeSetBase()
{
}

void UGAS_AttributeSetBase::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
}

void UGAS_AttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    BroadcastPropertyChange(Data);
}

bool UGAS_AttributeSetBase::BroadcastPropertyChange(const FGameplayEffectModCallbackData& Data)
{
	bool bIsBroadcasted = false;

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UGAS_AttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UGAS_AttributeSetBase, Health)))
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
