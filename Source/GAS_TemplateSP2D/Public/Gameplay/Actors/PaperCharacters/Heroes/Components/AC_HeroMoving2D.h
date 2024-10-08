// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperHeroBase.h"
#include "AC_HeroMoving2D.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_HeroMoving2D : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_HeroMoving2D();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	AGAS_PaperHeroBase* PaperHero;

	UPROPERTY(EditAnywhere)
	const UInputAction* LeftInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* RightInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* ForwardInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* BackwardInputAction;

	void MoveLeft(const FInputActionValue& Value);
		
	void MoveRight(const FInputActionValue& Value);

	void MoveForward(const FInputActionValue& Value);

	void MoveBackward(const FInputActionValue& Value);

};
