// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/AbilityData/W_AbilitySlotPanel.h"
#include "Gameplay/Components/AC_AbilitySet.h"
#include "AbilitySystemGlobals.h"
#include "Components/Image.h"
#include "Gameplay/Abilities/GA_SequenceAbility.h"
#include "Gameplay/UI/AbilityData/W_AbilitySlot.h"
#include "Gameplay/UI/DS_HUD.h"


void UW_AbilitySlotPanel::NativeConstruct()
{
	Super::NativeConstruct();


	// BeginPlay is running before AbilitySet Initialize, so we need wait
	if (UAC_AbilitySet* PlayerAbiltySetComp = GetOwningPlayerPawn()->GetComponentByClass<UAC_AbilitySet>())
	{
		PlayerAbiltySetComp->OnAbilitySetGiven.AddDynamic(this, &UW_AbilitySlotPanel::OnAbilitySetGiven);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilitySet doesen't exist in %s, so we can't bind attribute to widget"), *GetOwningPlayerPawn()->GetName());
	}
}

void UW_AbilitySlotPanel::OnAbilitySetGiven(const AActor* OwnerActor)
{
	UAbilitySystemComponent* PlayerASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OwnerActor);
	if (!PlayerASC)
	{
		return;
	}
	TArray<FGameplayAbilitySpec>& ActivatableAbilities = PlayerASC->GetActivatableAbilities();

	for (const FGameplayAbilitySpec& AbilitySpec : ActivatableAbilities)
	{
		if (UGA_SequenceAbility* SeqAbility = Cast<UGA_SequenceAbility>(AbilitySpec.Ability))
		{
			if (SeqAbility->AbilityIcon) 
			{
				const UDS_HUD* HUDSettings = GetDefault<UDS_HUD>();
				UW_AbilitySlot* AbilitySlot = Cast<UW_AbilitySlot>(CreateWidget<UW_AbilitySlot>(this, HUDSettings->BP_AbilitySlot.LoadSynchronous()));
				if (AbilitySlot) 
				{
					HorizontalAbilities->AddChildToHorizontalBox(AbilitySlot);
					UMaterialInstanceDynamic* ImageMaterial = AbilitySlot->IMG_AbilityImage->GetDynamicMaterial();
					ImageMaterial->SetTextureParameterValue(FName("IconParam"), SeqAbility->AbilityIcon);
				}
			}
		}
	}
}
