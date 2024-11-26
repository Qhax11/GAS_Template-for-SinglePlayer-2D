// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Actors/PaperCharacters/Heroes/GAS_PaperHeroBase.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroMoving.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_AbilityInputBinding.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroAttributesListener.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroRespawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"


AGAS_PaperHeroBase::AGAS_PaperHeroBase(const class FObjectInitializer& ObjectInitializer):
    Super(ObjectInitializer.SetDefaultSubobjectClass<UAC_HeroAttributesListener>(TEXT("AttributesListenerBase")))
{
    // Create a camera boom (pulls in towards the player if there is a collision)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character 
    CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

    // Create a follow camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
    FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

    HeroMovingComponent = CreateDefaultSubobject<UAC_HeroMoving>(TEXT("HeroMovingComponent"));

    AbilityInputBindingComponent = CreateDefaultSubobject<UAC_AbilityInputBinding>(TEXT("AbilityInputBindingComponent"));

    HeroTagDispatcherComponent = CreateDefaultSubobject<UAC_HeroTagDispatcher>(TEXT("HeroTagDispatcherComponent"));

    HeroRespawnComponent = CreateDefaultSubobject<UAC_HeroRespawn>(TEXT("HeroRespawnComponent"));
}

void AGAS_PaperHeroBase::BeginPlay()
{
    Super::BeginPlay();

    //Adding Input Mapping Context
    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(HeroInputMappingContext, 0);
        }
    }
}

void AGAS_PaperHeroBase::DisableMovement()
{
    if (UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement())
    {
        CharacterMovementComponent->DisableMovement();
    }
}

void AGAS_PaperHeroBase::EnableMovement()
{
    if (UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement())
    {
        CharacterMovementComponent->SetMovementMode(EMovementMode::MOVE_Walking);  
    }
}











