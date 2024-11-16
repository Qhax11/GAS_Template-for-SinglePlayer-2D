// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/AbilityData/W_AbilitySlotPanel.h"
#include "Gameplay/Components/AC_AbilitySet.h"
#include "AbilitySystemGlobals.h"
#include "Gameplay/Abilities/GAS_GameplayAbilityBase.h"
#include "Gameplay/UI/AbilityData/W_AbilitySlot.h"
#include "Gameplay/UI/DS_HUD.h"
#include "Components/Spacer.h"
#include "Blueprint/WidgetTree.h"
#include "Gameplay/Components/GAS_AbilitySystemComponent.h"


void UW_AbilitySlotPanel::NativeConstruct()
{
	Super::NativeConstruct();

	// We need to wait init abilities for init of Abilitiy Slots
	if (UAC_AbilitySet* PlayerAbiltySetComp = GetOwningPlayerPawn()->GetComponentByClass<UAC_AbilitySet>())
	{
		PlayerAbiltySetComp->OnAbilitySetGiven.AddDynamic(this, &UW_AbilitySlotPanel::OnAbilitySetGiven);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerAbiltySetComp is null in %s, cannot initialize ability slots."), *this->GetName());
	}
}

void UW_AbilitySlotPanel::OnAbilitySetGiven(const AActor* OwnerActor)
{
	UGAS_AbilitySystemComponent* PlayerASC = Cast<UGAS_AbilitySystemComponent>(UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OwnerActor));
	if (!PlayerASC)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerASC is null in %s, cannot initialize ability slots."), *this->GetName());
		return;
	}

	// Bind delegate for granted abilities in runtime
	PlayerASC->OnAbilityGranted.AddDynamic(this, &UW_AbilitySlotPanel::OnAbilityGranted);

	HUDSettings = GetDefault<UDS_HUD>();
	if (!HUDSettings)
	{
		UE_LOG(LogTemp, Warning, TEXT("HUDSettings is null in %s, cannot initialize ability slots."), *this->GetName());
		return;
	}

	TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;
	PlayerASC->FindAllAbilitiesWithTags(AbilitySpecHandles, HUDSettings->DisplayedAbilitiesTags, false);
	for (FGameplayAbilitySpecHandle& AbilitySpecHandle : AbilitySpecHandles)
	{
		FGameplayAbilitySpec* AbilitySpec = PlayerASC->FindAbilitySpecFromHandle(AbilitySpecHandle);
		AddAbilitySlotToAbilityPanel(PlayerASC, Cast<UGAS_GameplayAbilityBase>(AbilitySpec->Ability));
	}
}

void UW_AbilitySlotPanel::AddAbilitySlotToAbilityPanel(UAbilitySystemComponent* ASC, UGAS_GameplayAbilityBase* AbilityBase)
{
	if (!AbilityBase || !AbilityBase->AbilityIcon || !AbilityBase->GetCooldownGameplayEffect())
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilityBase is null or missing required assets (Icon or Cooldown Gameplay Effect) in %s"), *this->GetName());
		return;
	}

	UW_AbilitySlot* AbilitySlot = Cast<UW_AbilitySlot>(CreateWidget<UW_AbilitySlot>(this, HUDSettings->WBP_AbilitySlot.LoadSynchronous(), FName(AbilityBase->GetName())));
	if (!AbilitySlot)
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilitySlot is couldn't created in %s, cannot initialize ability slots."), *this->GetName());
		return;
	}

	AbilitySlot->CustomInitialize(ASC, AbilityBase);

	HB_Abilities->AddChild(AbilitySlot);
	
	// Adding spacer for better UI
	USpacer* Spacer = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
	if (Spacer)
	{
		Spacer->SetSize(HUDSettings->SpacerSizeBetweenAbilitySlots);
		HB_Abilities->AddChild(Spacer);
	}
}

void UW_AbilitySlotPanel::OnAbilityGranted(UAbilitySystemComponent* ASC, FGameplayAbilitySpec& AbilitySpec)
{
	AddAbilitySlotToAbilityPanel(ASC, Cast<UGAS_GameplayAbilityBase>(AbilitySpec.Ability.Get()));
}
