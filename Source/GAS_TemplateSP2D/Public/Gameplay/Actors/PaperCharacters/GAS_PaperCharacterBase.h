// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "AbilitySystemInterface.h"
#include "Gameplay/Attributes/AS_Base.h"
#include "Gameplay/Components/GAS_AbilitySystemComponent.h"
#include "Gameplay/Tags/GAS_Tags.h"
#include "GAS_PaperCharacterBase.generated.h"


UCLASS()
class GAS_TEMPLATESP2D_API AGAS_PaperCharacterBase : public APaperZDCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AGAS_PaperCharacterBase(const class FObjectInitializer& ObjectInitializer);

	// Called when the game starts
	virtual void BeginPlay() override;

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	UGAS_AbilitySystemComponent* PaperCharacterASC;

public:

	/* Components */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "CharacterBase|Components")
	class UAC_AbilitySet* AbilitySetComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "CharacterBase|Components")
	class UAC_Team* TeamComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "CharacterBase|Components")
	class UAC_TagDelegates* TagDelegatesComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "CharacterBase|Components")
	class UAC_AttributesListenerBase* AttributesListenerComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "CharacterBase|Components")
	class UAC_GameplayData* GameplayDataComponent;

public:

	void DisableMovement();

	void EnableMovement();

};
