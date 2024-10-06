// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayAbilitySpec.h" 
#include "EnhancedInputComponent.h" 
#include "Gameplay/Components/GAS_AbilitySystemComponent.h"
#include "AC_AbilityInputBinding.generated.h"


class UInputAction;

USTRUCT()
struct FAbilityInputBinding
{
	GENERATED_BODY()

	int32  InputID = 0;
	uint32 OnPressedHandle = 0;
	uint32 OnReleasedHandle = 0;
	TArray<FGameplayAbilitySpecHandle> BoundAbilitiesStack;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_AbilityInputBinding : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_AbilityInputBinding();

	virtual void BeginPlay() override;

	UGAS_AbilitySystemComponent* OwnerAbilitySystemComponent;

	/**
	 * Updates the Ability Input Binding Component registered bindings or create a new one for the passed in Ability Handle.
	 *
	 * @param InputAction The Enhanced InputAction to bind to
	 * @param TriggerEvent The trigger type to use for the ability pressed handle. The most common trigger types are likely to be Started for actions that happen once, immediately upon pressing a button.
	 * @param AbilityHandle The Gameplay Ability Spec handle to setup binding for (handle returned when granting abilities manually with GSCAbilitySystemComponent)
	 */

	UFUNCTION(BlueprintCallable, Category = "Enhanced Input Abilities")
	void SetInputBinding(UInputAction* InputAction, const FGameplayAbilitySpecHandle& AbilityHandle);

	void OnAbilityInputPressed(UInputAction* InputAction);

	void OnAbilityInputReleased(UInputAction* InputAction);


	void TryBindAbilityInput(UInputAction* InputAction, FAbilityInputBinding& AbilityInputBinding);

	UPROPERTY(transient)
	TMap<UInputAction*, FAbilityInputBinding> MappedAbilities;

	UPROPERTY(transient)
	UEnhancedInputComponent* InputComponent;

};
