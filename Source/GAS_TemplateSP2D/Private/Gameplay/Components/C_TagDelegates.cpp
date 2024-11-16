// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Components/C_TagDelegates.h"
#include "AbilitySystemGlobals.h"


UC_TagDelegates::UC_TagDelegates()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UC_TagDelegates::BeginPlay()
{
	Super::BeginPlay();

	Initialize(GetOwner());
}

bool UC_TagDelegates::Initialize(AActor* OwnerActor)
{
	OwnerASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OwnerActor);
	if (!OwnerASC)
	{
		return false;
	}

	OwnerASC->RegisterGenericGameplayTagEvent().AddUObject(this, &UC_TagDelegates::OnGameplayTagChanged);

	return true;
}

void UC_TagDelegates::OnGameplayTagChanged(const FGameplayTag Tag, const int32 TagCount) const
{
	for (int32 i = 0; i < TagDelegates.Num(); ++i)
	{
		TagDelegates[i].TryExecute(OwnerASC, Tag, TagCount);
	}
}

FOnGameplayTagChangeReceived& UC_TagDelegates::RegisterDelegateForTag(FGameplayTag Tag, EListenMode ListenMode)
{
	TagDelegates.Add(FTagDelegate(Tag));

	if (ListenMode == EListenMode::OnAdded) 
	{
		return TagDelegates[TagDelegates.Num() - 1].OnAddedTargetFunction;
	}
	else
	{
		return TagDelegates[TagDelegates.Num() - 1].OnRemovedTargetFunction;
	}
	// this is much better
	//RegisterDelegateForTags(FGameplayTagContainer(Tag), ListenMode);
}

FOnGameplayTagChangeReceived& UC_TagDelegates::RegisterDelegateForTags(FGameplayTagContainer Tags, EListenMode ListenMode)
{
	for (int32 i = 0; i < Tags.Num(); ++i)
	{
		TagDelegates.Add(FTagDelegate(Tags.GetByIndex(i)));
	}

	if (ListenMode == EListenMode::OnAdded)
	{
		return TagDelegates[TagDelegates.Num() - 1].OnAddedTargetFunction;
	}
	else
	{
		return TagDelegates[TagDelegates.Num() - 1].OnRemovedTargetFunction;
	}
}





