// Qhax's GAS Template for 2D SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "GAS_PaperHeroBase.generated.h"


UCLASS()
class GAS_TEMPLATESP_API AGAS_PaperHeroBase : public AGAS_PaperCharacterBase
{
	GENERATED_BODY()

public:
	AGAS_PaperHeroBase();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UInputMappingContext* HeroInputMappingContext;

protected:

	//* Components *//
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Hero|Components|Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Hero|Components|Camera")
	class UCameraComponent* FollowCamera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Hero|Components")
	class UAC_HeroMoving2D* HeroMoving2DComp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Hero|Components")
	class UAC_AbilityInputBinding* AbilityInputBindingComp;
	
};
