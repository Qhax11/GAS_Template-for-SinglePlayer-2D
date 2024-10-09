// Qhax's GAS Template for SinglePlayer

#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroMoving2D.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UAC_HeroMoving2D::UAC_HeroMoving2D()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UAC_HeroMoving2D::BeginPlay()
{
	Super::BeginPlay();

	PaperHero = Cast<AGAS_PaperHeroBase>(GetOwner());
	if (!PaperHero)
	{
		UE_LOG(LogTemp, Warning, TEXT("PaperCharacter is null! (This message comes from %s)"), *this->GetName());
		return;
	}

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PaperHero->InputComponent);
	if (!EnhancedInputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnhancedInputComponent is null! (This message comes from %s)"), *this->GetName());
		return;
	}

	if (LeftInputAction && RightInputAction && ForwardInputAction && BackwardInputAction)
	{
		EnhancedInputComponent->BindAction(LeftInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving2D::MoveLeft);
		EnhancedInputComponent->BindAction(RightInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving2D::MoveRight);
		EnhancedInputComponent->BindAction(ForwardInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving2D::MoveForward);
		EnhancedInputComponent->BindAction(BackwardInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving2D::MoveBackward);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Input actions are null! (This message comes from %s)"), *this->GetName());
	}
}

void UAC_HeroMoving2D::MoveLeft(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(0, -1, 0));
}

void UAC_HeroMoving2D::MoveRight(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(0, 1, 0));
}

void UAC_HeroMoving2D::MoveForward(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(1, 0, 0));
}

void UAC_HeroMoving2D::MoveBackward(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(-1, 0, 0));
}

