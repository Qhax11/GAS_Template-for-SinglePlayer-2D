// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/Characters/GAS_HeroBase.h"
#include "Gameplay/Actors/Characters/Heroes/Components/AC_HeroMoving.h"
#include "Gameplay/Actors/Characters/Heroes/Components/AC_AbilityInputBinding.h"
#include "EnhancedInputSubsystems.h"


AGAS_HeroBase::AGAS_HeroBase()
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

    HeroMovingComp = CreateDefaultSubobject<UAC_HeroMoving>(TEXT("HeroMovingComp"));

    AbilityInputBindingComp = CreateDefaultSubobject<UAC_AbilityInputBinding>(TEXT("AbilityInputBindingComp"));
}

void AGAS_HeroBase::BeginPlay()
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



