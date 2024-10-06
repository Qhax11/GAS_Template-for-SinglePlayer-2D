// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/Characters/Heroes/Components/AC_HeroMoving.h"
#include "EnhancedInputComponent.h"

// Sets default values for this component's properties
UAC_HeroMoving::UAC_HeroMoving()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UAC_HeroMoving::BeginPlay()
{
	Super::BeginPlay();

	HeroBase = Cast<AGAS_HeroBase>(GetOwner());
	if (!HeroBase)
	{
		UE_LOG(LogTemp, Warning, TEXT("HeroBase is null! (This message comes from %s)"), *this->GetName());
		return;
	}

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(HeroBase->InputComponent);
	if (!EnhancedInputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnhancedInputComponent is null! (This message comes from %s)"), *this->GetName());
		return;
	}

	if (MoveForwardInputAction && MoveForwardInputAction && MoveLeftInputAction && MoveRightInputAction)
	{
		EnhancedInputComponent->BindAction(MoveForwardInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::MoveForward);
		EnhancedInputComponent->BindAction(MoveBackwardInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::MoveBackward);
		EnhancedInputComponent->BindAction(MoveRightInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::MoveRight);
		EnhancedInputComponent->BindAction(MoveLeftInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::MoveLeft);
		EnhancedInputComponent->BindAction(LookMouseInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::LookMouse);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving::Jump);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Input actions are null! (This message comes from %s)"), *this->GetName());
	}
}

void UAC_HeroMoving::MoveForward(const FInputActionValue& Value)
{
	const FRotator MovementRotation(0.0f, HeroBase->GetControlRotation().Yaw, 0.0f);
	const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
	HeroBase->AddMovementInput(MovementDirection, AddMovementValue);
}

void UAC_HeroMoving::MoveBackward(const FInputActionValue& Value)
{
	const FRotator MovementRotation(0.0f, HeroBase->GetControlRotation().Yaw, 0.0f);
	const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
	HeroBase->AddMovementInput(MovementDirection, -AddMovementValue);
}

void UAC_HeroMoving::MoveRight(const FInputActionValue& Value)
{
	const FRotator MovementRotation(0.0f, HeroBase->GetControlRotation().Yaw, 0.0f);
	const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
	HeroBase->AddMovementInput(MovementDirection, AddMovementValue);
}

void UAC_HeroMoving::MoveLeft(const FInputActionValue& Value)
{
	const FRotator MovementRotation(0.0f, HeroBase->GetControlRotation().Yaw, 0.0f);
	const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
	HeroBase->AddMovementInput(MovementDirection, -AddMovementValue);
}

void UAC_HeroMoving::LookMouse(const FInputActionValue& Value)
{
	// input is a Vector2D
	const FVector2D Value2D = Value.Get<FVector2D>();

	if (Value2D.X != 0.0f)
	{
		HeroBase->AddControllerYawInput(Value2D.X);
	}

	if (Value2D.Y != 0.0f)
	{
		HeroBase->AddControllerPitchInput(-Value2D.Y);
	}
}

void UAC_HeroMoving::Jump(const FInputActionValue& Value)
{
	HeroBase->Jump();
}

