// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Actors/PaperCharacters/Heroes/Components/AC_HeroTagDispatcher.h"
#include "Gameplay/Components/AC_TagDelegates.h"


UAC_HeroTagDispatcher::UAC_HeroTagDispatcher()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_HeroTagDispatcher::BeginPlay()
{
	Super::BeginPlay();

	if (UAC_TagDelegates* TagDelegatesComponent = GetOwner()->GetComponentByClass<UAC_TagDelegates>())
	{
		TagDelegatesComponent->RegisterDelegateForTags(ListeningTags, EListenMode::OnAdded).BindDynamic(this, &UAC_HeroTagDispatcher::OnTagAdded);
		TagDelegatesComponent->RegisterDelegateForTags(ListeningTags, EListenMode::OnRemoved).BindDynamic(this, &UAC_HeroTagDispatcher::OnTagRemoved);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TagDelegatesComponent is null in %s, cannot listen tags."), *this->GetName());
	}
}

void UAC_HeroTagDispatcher::OnTagAdded(const UAbilitySystemComponent* AbilitySystemComponent, const FGameplayTag& Tag)
{
	OnGameplayTagAdded.Broadcast(AbilitySystemComponent, Tag);
}

void UAC_HeroTagDispatcher::OnTagRemoved(const UAbilitySystemComponent* AbilitySystemComponent, const FGameplayTag& Tag)
{
	OnGameplayTagRemoved.Broadcast(AbilitySystemComponent, Tag);
}






