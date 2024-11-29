// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Attributes/AS_Base.h"


UAS_Base::UAS_Base()
{
	if (AActor* Owner = Cast<AActor>(this->GetOuter()))
	{
		if (UAbilitySystemComponent* OwnerASC = Owner->GetComponentByClass<UAbilitySystemComponent>())
		{
			if (!OwnerASC->OnGameplayEffectAppliedDelegateToSelf.IsBoundToObject(this))
			{
				OwnerASC->OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAS_Base::ActiveGameplayEffectAdded);
			}
			if (!OwnerASC->OnAnyGameplayEffectRemovedDelegate().IsBoundToObject(this))
			{
				OwnerASC->OnAnyGameplayEffectRemovedDelegate().AddUObject(this, &UAS_Base::ActiveGameplayEffectRemoved);
			}
		}
	}
}

void UAS_Base::ActiveGameplayEffectAdded(UAbilitySystemComponent* OwnerASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle)
{
	for (int32 i = 0; i < EffectSpec.ModifiedAttributes.Num(); i++)
	{
		const FGameplayAttribute& GameplayAttribute = EffectSpec.ModifiedAttributes[i].Attribute;

		float EvaluatedMagnitude = 0;
		if (EffectSpec.Modifiers.IsValidIndex(i))
		{
			EvaluatedMagnitude = EffectSpec.Modifiers[i].GetEvaluatedMagnitude();
		}

		FGameplayModifierEvaluatedData EvaluatedData = FGameplayModifierEvaluatedData(GameplayAttribute, EGameplayModOp::Max, EvaluatedMagnitude, EffectHandle);
		FGameplayEffectModCallbackData Data = FGameplayEffectModCallbackData(EffectSpec, EvaluatedData, *EffectHandle.GetOwningAbilitySystemComponent());

		ClampAttributeValues(Data);
		BroadcastPropertyChange(Data);
	}
}

void UAS_Base::ActiveGameplayEffectRemoved(const FActiveGameplayEffect& ActiveGameplayEffect)
{
	for (int32 i = 0; i < ActiveGameplayEffect.Spec.ModifiedAttributes.Num(); i++)
	{
		const FGameplayAttribute& GameplayAttribute = ActiveGameplayEffect.Spec.ModifiedAttributes[i].Attribute;

		float EvaluatedMagnitude = 0;
		if (ActiveGameplayEffect.Spec.Modifiers.IsValidIndex(i))
		{
			EvaluatedMagnitude = ActiveGameplayEffect.Spec.Modifiers[i].GetEvaluatedMagnitude();
		}

		FGameplayModifierEvaluatedData EvaluatedData = FGameplayModifierEvaluatedData(GameplayAttribute, EGameplayModOp::Max, EvaluatedMagnitude, ActiveGameplayEffect.Handle);
		FGameplayEffectModCallbackData Data = FGameplayEffectModCallbackData(ActiveGameplayEffect.Spec, EvaluatedData, *ActiveGameplayEffect.Handle.GetOwningAbilitySystemComponent());

		ClampAttributeValues(Data);
		BroadcastPropertyChange(Data);
	}
}

void UAS_Base::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EffectSpec.Def->DurationPolicy != EGameplayEffectDurationType::Instant && !Data.EffectSpec.Def->Executions.IsEmpty())
	{
		for (int32 i = 0; i < Data.EffectSpec.ModifiedAttributes.Num(); i++)
		{
			const FGameplayAttribute& GameplayAttribute = Data.EffectSpec.ModifiedAttributes[i].Attribute;

			float EvaluatedMagnitude = 0;
			if (Data.EffectSpec.Def->Modifiers.IsValidIndex(i))
			{
				EvaluatedMagnitude = Data.EffectSpec.Modifiers[i].GetEvaluatedMagnitude();
			}

			FGameplayModifierEvaluatedData EvaluatedData = FGameplayModifierEvaluatedData(GameplayAttribute, EGameplayModOp::Max, EvaluatedMagnitude);
			FGameplayEffectModCallbackData EffectModCallbackData = FGameplayEffectModCallbackData(Data.EffectSpec, EvaluatedData, *GetOwningAbilitySystemComponent());

			ClampAttributeValues(EffectModCallbackData);
			BroadcastPropertyChange(EffectModCallbackData);
		}
	}
}

bool UAS_Base::ClampAttributeValues(const FGameplayEffectModCallbackData& Data)
{
	if (!Data.EvaluatedData.IsValid || !Data.EvaluatedData.Attribute.IsValid())
	{
		return false;
	}

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		Health.SetBaseValue(FMath::Clamp(Health.GetBaseValue(), 0, MaxHealth.GetCurrentValue()));
		Health.SetCurrentValue(FMath::Clamp(Health.GetBaseValue(), 0, MaxHealth.GetCurrentValue()));
	}

	// Clamping MovementSpeed between 0 and 1000.
	else if (Data.EvaluatedData.Attribute == GetMovementSpeedAttribute())
	{
		MovementSpeed.SetBaseValue(FMath::Clamp(MovementSpeed.GetCurrentValue(), 0, 1000));
		MovementSpeed.SetCurrentValue(FMath::Clamp(MovementSpeed.GetCurrentValue(), 0, 1000));
	}

	else if (Data.EvaluatedData.Attribute == GetPhysicalArmorAttribute())
	{
		PhysicalArmor.SetBaseValue(FMath::Clamp(PhysicalArmor.GetCurrentValue(), 0, 10000));
		PhysicalArmor.SetCurrentValue(FMath::Clamp(PhysicalArmor.GetCurrentValue(), 0, 10000));
	}

	return true;
}

bool UAS_Base::BroadcastPropertyChange(const FGameplayEffectModCallbackData& Data)
{
	bool bIsBroadcasted = false;

	if (!Data.EvaluatedData.IsValid)
	{
		return bIsBroadcasted;
	}

	FGameplayAttributeData AttributeData;
	if (!Data.EvaluatedData.Attribute.GetGameplayAttributeData(this)) 
	{
		return bIsBroadcasted;
	}
	AttributeData = *Data.EvaluatedData.Attribute.GetGameplayAttributeData(this);

	FAttributeChangeCallbackData PropertyCallbackData = FAttributeChangeCallbackData(GetOwningAbilitySystemComponent(), AttributeData);

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
	else if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Base::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Base, PhysicalArmor)))
	{
		bIsBroadcasted = true;
		PropertyCallbackData.CurrentValue = PhysicalArmor.GetCurrentValue();
		OnPhysicalArmorChanged.Broadcast(PropertyCallbackData);
	}
	else if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Base::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Base, PhysicalDamage)))
	{
		bIsBroadcasted = true;
		PropertyCallbackData.CurrentValue = PhysicalDamage.GetCurrentValue();
		OnPhysicalDamageChanged.Broadcast(PropertyCallbackData);
	}
	else if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAS_Base::StaticClass(), GET_MEMBER_NAME_CHECKED(UAS_Base, MovementSpeed)))
	{
		bIsBroadcasted = true;
		PropertyCallbackData.CurrentValue = MovementSpeed.GetCurrentValue();
		OnMovementSpeedChanged.Broadcast(PropertyCallbackData);
	}

	return bIsBroadcasted;
}


