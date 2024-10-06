// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/Characters/Heroes/Components/AC_AbilityInputBinding.h"
#include "AbilitySystemGlobals.h"

namespace EnhancedInputAbilitySystem_Impl
{
	constexpr int32 InvalidInputID = 0;
	int32 IncrementingInputID = InvalidInputID;

	static int32 GetNextInputID()
	{
		return ++IncrementingInputID;
	}
}

// Sets default values for this component's properties
UAC_AbilityInputBinding::UAC_AbilityInputBinding()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UAC_AbilityInputBinding::BeginPlay()
{
	Super::BeginPlay();
	AActor* Owner = GetOwner();
	if (IsValid(Owner) && Owner->InputComponent)
	{
		InputComponent = CastChecked<UEnhancedInputComponent>(Owner->InputComponent);
	}

	OwnerAbilitySystemComponent = Cast<UGAS_AbilitySystemComponent>(UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Owner));
	check(OwnerAbilitySystemComponent);
}

void UAC_AbilityInputBinding::SetInputBinding(UInputAction* InputAction, const FGameplayAbilitySpecHandle& AbilityHandle)
{
	using namespace EnhancedInputAbilitySystem_Impl;

	FGameplayAbilitySpec* BindingAbility = OwnerAbilitySystemComponent->FindAbilitySpecFromHandle(AbilityHandle);

	FAbilityInputBinding* AbilityInputBinding = MappedAbilities.Find(InputAction);
	if (AbilityInputBinding)
	{
		FGameplayAbilitySpec* OldBoundAbility = OwnerAbilitySystemComponent->FindAbilitySpecFromHandle(AbilityInputBinding->BoundAbilitiesStack.Top());
		if (OldBoundAbility && OldBoundAbility->InputID == AbilityInputBinding->InputID)
		{
			OldBoundAbility->InputID = InvalidInputID;
		}
	}
	else
	{
		AbilityInputBinding = &MappedAbilities.Add(InputAction);
		AbilityInputBinding->InputID = GetNextInputID();
	}

	if (BindingAbility)
	{
		BindingAbility->InputID = AbilityInputBinding->InputID;
	}

	AbilityInputBinding->BoundAbilitiesStack.Push(AbilityHandle);
	TryBindAbilityInput(InputAction, *AbilityInputBinding);
}

void UAC_AbilityInputBinding::OnAbilityInputPressed(UInputAction* InputAction)
{
	using namespace EnhancedInputAbilitySystem_Impl;

	FAbilityInputBinding* FoundBinding = MappedAbilities.Find(InputAction);
	if (FoundBinding && ensure(FoundBinding->InputID != InvalidInputID))
	{
		OwnerAbilitySystemComponent->AbilityLocalInputPressed(FoundBinding->InputID);
	}
}

void UAC_AbilityInputBinding::OnAbilityInputReleased(UInputAction* InputAction)
{
	using namespace EnhancedInputAbilitySystem_Impl;

	FAbilityInputBinding* FoundBinding = MappedAbilities.Find(InputAction);
	if (FoundBinding && ensure(FoundBinding->InputID != InvalidInputID))
	{
		OwnerAbilitySystemComponent->AbilityLocalInputReleased(FoundBinding->InputID);
	}
}

void UAC_AbilityInputBinding::TryBindAbilityInput(UInputAction* InputAction, FAbilityInputBinding& AbilityInputBinding)
{
	if (InputComponent)
	{
		// Pressed event
		if (AbilityInputBinding.OnPressedHandle == 0)
		{
			AbilityInputBinding.OnPressedHandle = InputComponent->BindAction(InputAction, ETriggerEvent::Started, this, &UAC_AbilityInputBinding::OnAbilityInputPressed, InputAction).GetHandle();
		}

		// Released event
		if (AbilityInputBinding.OnReleasedHandle == 0)
		{
			AbilityInputBinding.OnReleasedHandle = InputComponent->BindAction(InputAction, ETriggerEvent::Completed, this, &UAC_AbilityInputBinding::OnAbilityInputReleased, InputAction).GetHandle();
		}
	}
}
