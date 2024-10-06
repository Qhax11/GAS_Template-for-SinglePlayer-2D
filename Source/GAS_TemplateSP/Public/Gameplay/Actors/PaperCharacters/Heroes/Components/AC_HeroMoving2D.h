// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperHeroBase.h"
#include "AC_HeroMoving2D.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP_API UAC_HeroMoving2D : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_HeroMoving2D();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	AGAS_PaperHeroBase* PaperHero;

	UPROPERTY(EditAnywhere)
	const UInputAction* LeftInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* RightInputAction;

	UPROPERTY(EditAnywhere)
	const UInputAction* JumpInputAction;

	void MoveLeft(const FInputActionValue& Value);
		
	void MoveRight(const FInputActionValue& Value);

	void Jump(const FInputActionValue& Value);

};
