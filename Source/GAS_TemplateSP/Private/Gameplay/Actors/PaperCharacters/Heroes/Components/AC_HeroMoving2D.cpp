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

	if (LeftInputAction && RightInputAction)
	{
		EnhancedInputComponent->BindAction(LeftInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving2D::MoveLeft);
		EnhancedInputComponent->BindAction(RightInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving2D::MoveRight);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &UAC_HeroMoving2D::Jump);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Input actions are null! (This message comes from %s)"), *this->GetName());
	}
}

// Called every frame
void UAC_HeroMoving2D::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAC_HeroMoving2D::MoveLeft(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(0, -100, 0));
}

void UAC_HeroMoving2D::MoveRight(const FInputActionValue& Value)
{
	PaperHero->AddMovementInput(FVector(0, 100, 0));
}

void UAC_HeroMoving2D::Jump(const FInputActionValue& Value)
{
	PaperHero->Jump();
}

