// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/Components/WC_PropertyBar.h"
#include "Gameplay/Components/AC_AbilitySet.h"


void UWC_PropertyBar::BeginPlay()
{
	Super::BeginPlay();

	// BeginPlay is running before AbilitySet Initialize, so we need wait
	if (UAC_AbilitySet* AbiltySetComp = GetOwner()->GetComponentByClass<UAC_AbilitySet>()) 
	{
		AbiltySetComp->OnAbilitySetGiven.AddDynamic(this, &UWC_PropertyBar::OnAbilitySetGiven);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilitySet doesen't exist in %s, so we can't bind attribute to widget"), *GetOwner()->GetName());
	}
}

void UWC_PropertyBar::OnAbilitySetGiven(const AActor* OwnerActor)
{
	PropertyBar = Cast<UW_HealthBar>(GetUserWidgetObject());
	if (PropertyBar && OwnerActor)
	{
		PropertyBar->Initialize(GetOwner());
	}
}
