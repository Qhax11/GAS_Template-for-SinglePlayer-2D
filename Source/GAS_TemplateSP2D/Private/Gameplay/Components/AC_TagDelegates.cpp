// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/AC_TagDelegates.h"
#include "AbilitySystemGlobals.h"


UAC_TagDelegates::UAC_TagDelegates()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_TagDelegates::BeginPlay()
{
	Super::BeginPlay();

	Initialize(GetOwner());
}

bool UAC_TagDelegates::Initialize(AActor* OwnerActor)
{
	OwnerASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OwnerActor);
	if (!OwnerASC)
	{
		return false;
	}

	OwnerASC->RegisterGenericGameplayTagEvent().AddUObject(this, &UAC_TagDelegates::OnGameplayTagChanged);

	return true;
}

void UAC_TagDelegates::OnGameplayTagChanged(const FGameplayTag Tag, const int32 TagCount) const
{
	for (int32 i = 0; i < TagDelegates.Num(); ++i)
	{
		TagDelegates[i].TryExecute(OwnerASC, Tag, TagCount);
	}
}

FOnGameplayTagChangeReceived& UAC_TagDelegates::RegisterDelegateForTag(const FGameplayTag& Tag, const EListenMode ListenMode)
{
	return RegisterDelegateForTags(FGameplayTagContainer(Tag), ListenMode);
}

FOnGameplayTagChangeReceived& UAC_TagDelegates::RegisterDelegateForTags(const FGameplayTagContainer& TagContainer, const EListenMode ListenMode)
{
	TagDelegates.Add(FTagDelegate(TagContainer));

	// Return the new delegate pair's target function so each added tag gets executed with the same function.
	if (ListenMode == EListenMode::OnAdded)
	{
		return TagDelegates[TagDelegates.Num() - 1].OnAddedTargetFunction;
	}
	else
	{
		return TagDelegates[TagDelegates.Num() - 1].OnRemovedTargetFunction;
	}
}





