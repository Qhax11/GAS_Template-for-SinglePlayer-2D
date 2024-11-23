// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/AbilityData/W_AbilitySlot.h"
#include "Gameplay/Abilities/Tasks/AsyncTask_AbilityCooldownChanged.h"
#include "Components/Image.h"


void UW_AbilitySlot::CustomInitialize(UAbilitySystemComponent* ASC, UGAS_GameplayAbilityBase* AbilityBase)
{
	if (!IMG_AbilityImage)
	{
		UE_LOG(LogTemp, Warning, TEXT("IMG_AbilityImage is null in %s, cannot initialize ability slots."), *this->GetName());
		return;
	}

	ImageMaterial = IMG_AbilityImage->GetDynamicMaterial();
	if (ImageMaterial)
	{
		// Setting image of ability as param to Ability Slot Image Material
		ImageMaterial->SetTextureParameterValue(FName("IconParam"), AbilityBase->AbilityIcon);
	}

	if (AbilityBase->GetCooldownTags()->GetByIndex(0).IsValid()) 
	{
		InitialListenCooldown(ASC, AbilityBase->GetCooldownTags()->GetByIndex(0));
	}

 	BP_CustomInitialize(ASC, AbilityBase);
}

void UW_AbilitySlot::InitialListenCooldown(UAbilitySystemComponent* AbilitySystemComponent, FGameplayTag CooldownTag)
{
	UAsyncTask_AbilityCooldownChanged* CooldownChanged = UAsyncTask_AbilityCooldownChanged::ListenForCooldownChange(AbilitySystemComponent, FGameplayTagContainer(CooldownTag), false);
	CooldownChanged->OnCooldownBegin.AddDynamic(this, &UW_AbilitySlot::OnCooldownBegin);
}

void UW_AbilitySlot::OnCooldownBegin(FGameplayTag CooldownTag, float TimeRemaining, float Duration)
{
	CooldownEndTime = TimeRemaining + GetWorld()->TimeSeconds;
	CooldownDuration = Duration;

	// CooldownTimeCounter's tick is 0.1f
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_CooldownTimeCounter, this, &UW_AbilitySlot::CooldownTimeCounter, 0.1f, true, 0);

	BP_OnCoolDownBegin();
}

void UW_AbilitySlot::CooldownTimeCounter()
{
	CooldownTimeRemaining = CooldownEndTime - GetWorld()->TimeSeconds;

	// Clamping
	CooldownTimeRemaining = FMath::Max(0, CooldownTimeRemaining);

	// This percent value is for material param of image
	float Percent = 1 - (CooldownTimeRemaining / CooldownDuration);

	BP_OnCoolDownUpdated(CooldownTimeRemaining, Percent);

	if (CooldownTimeRemaining <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle_CooldownTimeCounter);
		BP_OnCoolDownFinished();
	}
}

