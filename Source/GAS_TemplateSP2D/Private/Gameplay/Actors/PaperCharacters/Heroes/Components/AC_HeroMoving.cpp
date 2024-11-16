// Qhax's GAS Template for SinglePlayer

#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroMoving.h"
#include "GameFramework/PlayerController.h"


UAC_HeroMoving::UAC_HeroMoving()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_HeroMoving::BeginPlay()
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
		EnhancedInputComponent->BindAction(LeftInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::MoveLeft);
		EnhancedInputComponent->BindAction(RightInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::MoveRight);
		EnhancedInputComponent->BindAction(ForwardInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::MoveForward);
		EnhancedInputComponent->BindAction(BackwardInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::MoveBackward);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Input actions are null! (This message comes from %s)"), *this->GetName());
	}
}

void UAC_HeroMoving::MoveLeft(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(0, -1, 0));
}

void UAC_HeroMoving::MoveRight(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(0, 1, 0));
}

void UAC_HeroMoving::MoveForward(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(1, 0, 0));
}

void UAC_HeroMoving::MoveBackward(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(-1, 0, 0));
}

