// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/W_HUD.h"
#include "Gameplay/Components/AC_AbilitySet.h"

void UW_HUD::NativePreConstruct()
{
	Super::NativePreConstruct();

}

void UW_HUD::NativeConstruct()
{
	Super::NativeConstruct();

	// BeginPlay is running before AbilitySet Initialize, so we need wait
	if (UAC_AbilitySet* AbiltySetComp = GetOwningPlayerPawn()->GetComponentByClass<UAC_AbilitySet>())
	{
		AbiltySetComp->OnAbilitySetGiven.AddDynamic(this, &UW_HUD::OnAbilitySetGiven);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilitySet doesen't exist in %s, so we can't bind attribute to widget"), *GetOwningPlayerPawn()->GetName());
	}
}

void UW_HUD::OnAbilitySetGiven(const AActor* OwnerActor)
{
	HealthBar->InitializePropertyBar(GetOwningPlayerPawn());
	ManaBar->InitializePropertyBar(GetOwningPlayerPawn());
}
