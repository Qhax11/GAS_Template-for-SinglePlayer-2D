// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Actors/Characters/GAS_CharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "GAS_HeroBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP_API AGAS_HeroBase : public AGAS_CharacterBase
{
	GENERATED_BODY()

public:
	AGAS_HeroBase();

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
	class UAC_HeroMoving* HeroMovingComp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Hero|Components")
	class UAC_AbilityInputBinding* AbilityInputBindingComp;
};
