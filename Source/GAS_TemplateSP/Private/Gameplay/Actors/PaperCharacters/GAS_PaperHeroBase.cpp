// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Actors/PaperCharacters/GAS_PaperHeroBase.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroMoving2D.h"
#include "Gameplay/Actors/Characters/Heroes/Components/AC_AbilityInputBinding.h"
#include "EnhancedInputSubsystems.h"


AGAS_PaperHeroBase::AGAS_PaperHeroBase()
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

    HeroMoving2DComp = CreateDefaultSubobject<UAC_HeroMoving2D>(TEXT("HeroMoving2DComp"));

    AbilityInputBindingComp = CreateDefaultSubobject<UAC_AbilityInputBinding>(TEXT("AbilityInputBindingComp"));
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




