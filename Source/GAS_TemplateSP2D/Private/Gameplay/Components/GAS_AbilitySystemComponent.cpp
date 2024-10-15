// Qhax's GAS Template for SinglePlayer

#include "Gameplay/Components/GAS_AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_AbilityInputBinding.h"
#include "Abilities/GameplayAbility.h"


UGAS_AbilitySystemComponent::UGAS_AbilitySystemComponent()
{
}

bool UGAS_AbilitySystemComponent::GiveAbilitySet(const UGAS_GameplayAbilitySet* AbilitySet)
{
	if (AbilitySet) 
	{
		GiveAbilities(AbilitySet);
		GiveAttributes(AbilitySet);
		GivePermenantTags(AbilitySet->PermenantTags);
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilitySet doesen't exist in %s"), *GetOwnerActor()->GetName());
		return false;
	}
}

void UGAS_AbilitySystemComponent::GiveAbilities(const UGAS_GameplayAbilitySet* AbilitySet)
{
	if (AbilitySet->Abilities.IsEmpty()) 
	{
		return;
	}

	for (const FAbilityData& AbilityData : AbilitySet->Abilities)
	{
		FGameplayAbilitySpecHandle GivenAbilitySpecHandle = GiveAbility(FGameplayAbilitySpec(AbilityData.Ability));
		TryAbilityInputBind(AbilityData.AbilityInput, GivenAbilitySpecHandle);
	}
}

void UGAS_AbilitySystemComponent::TryAbilityInputBind(UInputAction* AbilityInput, const FGameplayAbilitySpecHandle& AbilitySpecHandle)
{
	if (UAC_AbilityInputBinding* AbilityInputBinding = Cast<UAC_AbilityInputBinding>(GetAvatarActor()->FindComponentByClass(UAC_AbilityInputBinding::StaticClass())))
	{
		AbilityInputBinding->SetInputBinding(AbilityInput, AbilitySpecHandle);
	}
}

void UGAS_AbilitySystemComponent::GiveAttributes(const UGAS_GameplayAbilitySet* AbilitySet)
{
	if (!IsValid(GetOwnerActor()))
	{
		return;
	}

	const TSubclassOf<UAttributeSet> WillBeGivenAttributeSet = AbilitySet->AttributeData.AttributeSet.LoadSynchronous();
	if (!WillBeGivenAttributeSet)
	{
		return;
	}

	UAttributeSet* OutAttributeSet = NewObject<UAttributeSet>(GetOwnerActor(), WillBeGivenAttributeSet);

	if (!AbilitySet->AttributeData.InitializationData.IsNull())
	{
		const UDataTable* InitData = AbilitySet->AttributeData.InitializationData.LoadSynchronous();
		if (InitData)
		{
			OutAttributeSet->InitFromMetaDataTable(InitData);
		}
	}

	AddAttributeSetSubobject(OutAttributeSet);
}

void UGAS_AbilitySystemComponent::GivePermenantTags(FGameplayTagContainer PermenantTags)
{
	if (!PermenantTags.IsEmpty()) 
	{
		AddLooseGameplayTags(PermenantTags);
	}
}
