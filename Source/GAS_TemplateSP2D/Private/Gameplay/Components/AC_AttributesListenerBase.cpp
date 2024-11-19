// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/AC_AttributesListenerBase.h"
#include "AbilitySystemGlobals.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "Gameplay/Components/AC_AbilitySet.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"


UAC_AttributesListenerBase::UAC_AttributesListenerBase()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_AttributesListenerBase::BeginPlay()
{
	Super::BeginPlay();

	// We need to wait init attributes for init of AttributesListenerBase
	if (UAC_AbilitySet* OwnerAbiltySetComp = GetOwner()->GetComponentByClass<UAC_AbilitySet>())
	{
		OwnerAbiltySetComp->OnAbilitySetGiven.AddDynamic(this, &UAC_AttributesListenerBase::OnAbilitySetGiven);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OwnerAbiltySetComp is null in %s, cannot initialize AttributesListenerBase."), *this->GetName());
	}
}

void UAC_AttributesListenerBase::OnAbilitySetGiven(const AActor* OwnerActor)
{
	Initialize(OwnerActor);
}

bool UAC_AttributesListenerBase::Initialize(const AActor* OwnerActor)
{
	OwnerASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OwnerActor);
	if (!OwnerASC)
	{
		return false;
	}

	if (UAS_Base* BaseAttributes = const_cast<UAS_Base*>(OwnerASC->GetSet<UAS_Base>()))
	{
		BaseAttributes->OnHealthChanged.AddDynamic(this, &UAC_AttributesListenerBase::HealthChanged);
		if (BaseAttributes->GetHealth() == BaseAttributes->GetMaxHealth())
		{
			OwnerASC->AddLooseGameplayTag(GAS_Tags::TAG_Gameplay_Health_Full);
		}

		BaseAttributes->OnMovementSpeedChanged.AddDynamic(this, &UAC_AttributesListenerBase::MovementSpeedChanged);

		return true;
	}

	return false;
}

void UAC_AttributesListenerBase::HealthChanged(const FAttributeChangeCallbackData& Data)
{
	if (Data.CurrentValue >= Data.MaxValue)
	{
		OwnerASC->AddLooseGameplayTag(GAS_Tags::TAG_Gameplay_Health_Full);
	}
	else
	{
		if (OwnerASC->HasMatchingGameplayTag(GAS_Tags::TAG_Gameplay_Health_Full))
		{
			OwnerASC->RemoveLooseGameplayTag(GAS_Tags::TAG_Gameplay_Health_Full, 100);
		}
	}
}

void UAC_AttributesListenerBase::MovementSpeedChanged(const FAttributeChangeCallbackData& Data)
{
	if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
	{
		if (UCharacterMovementComponent* CharacterMoveComp = Character->GetCharacterMovement())
		{
			CharacterMoveComp->MaxWalkSpeed = Data.CurrentValue;
		}
	}
}


