// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperHeroBase.h"
#include "AC_HeroMoving.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_HeroMoving : public UActorComponent
{
	GENERATED_BODY()

public:	

	UAC_HeroMoving();

protected:

	virtual void BeginPlay() override;

public:	
	void MoveLeft(const FInputActionValue& Value);

	void MoveRight(const FInputActionValue& Value);

	void MoveForward(const FInputActionValue& Value);

	void MoveBackward(const FInputActionValue& Value);

	AGAS_PaperHeroBase* PaperHero;

	UPROPERTY(EditAnywhere)
	const UInputAction* LeftInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* RightInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* ForwardInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* BackwardInputAction;

};