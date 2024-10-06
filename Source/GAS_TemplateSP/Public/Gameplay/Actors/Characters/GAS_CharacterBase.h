// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Gameplay/Components/GAS_AbilitySystemComponent.h"
#include "Gameplay/Components/AC_AbilitySet.h"
#include "GAS_CharacterBase.generated.h"

UCLASS()
class GAS_TEMPLATESP_API AGAS_CharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGAS_CharacterBase();

	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	UGAS_AbilitySystemComponent* CharacterBaseASC;

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

public:

	/* Components */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "CharacterBase|Components")
	UAC_AbilitySet* AbilitySetComponent;
};
