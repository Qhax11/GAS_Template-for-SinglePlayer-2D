// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/Actors/Characters/GAS_HeroBase.h"
#include "AC_HeroMoving.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP_API UAC_HeroMoving : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_HeroMoving();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	AGAS_HeroBase* HeroBase;

	UPROPERTY(EditAnywhere)
	float AddMovementValue = 100;

	UPROPERTY(EditAnywhere)
	const UInputAction* MoveForwardInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* MoveBackwardInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* MoveRightInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* MoveLeftInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* LookMouseInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* JumpInputAction;

	void MoveForward(const FInputActionValue& Value);

	void MoveBackward(const FInputActionValue& Value);

	void MoveLeft(const FInputActionValue& Value);

	void MoveRight(const FInputActionValue& Value);

	void LookMouse(const FInputActionValue& Value);

	void Jump(const FInputActionValue& Value);
		
};
