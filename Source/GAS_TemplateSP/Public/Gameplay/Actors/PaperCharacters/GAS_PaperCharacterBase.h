// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "AbilitySystemInterface.h"
#include "Gameplay/Components/GAS_AbilitySystemComponent.h"
#include "Gameplay/Components/AC_AbilitySet.h"
#include "GAS_PaperCharacterBase.generated.h"


UCLASS()
class GAS_TEMPLATESP_API AGAS_PaperCharacterBase : public APaperCharacter, public IAbilitySystemInterface 
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AGAS_PaperCharacterBase();

	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	UGAS_AbilitySystemComponent* PaperCharacterASC;

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

public:

	/* Components */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "CharacterBase|Components")
	UAC_AbilitySet* AbilitySetComponent;

};
