// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilitySystemComponent.h"
#include "C_TagDelegates.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGameplayTagChangeReceived, const UAbilitySystemComponent*, AbilitySystemComponent, const FGameplayTag&, Tag);


UENUM(BlueprintType)
enum EListenMode : uint8
{
	OnAdded,
	OnRemoved,
};

USTRUCT(BlueprintType)
struct FTagDelegate
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tag Delegate")
	TArray<FGameplayTag> ListeningTags;

	UPROPERTY(BlueprintReadOnly, Category = "Tag Delegate")
	FOnGameplayTagChangeReceived OnAddedTargetFunction;

	UPROPERTY(BlueprintReadOnly, Category = "Tag Delegate")
	FOnGameplayTagChangeReceived OnRemovedTargetFunction;

	FTagDelegate() = default;

	FTagDelegate(const FGameplayTag& ListenTag)
	{
		ListeningTags.Add(ListenTag);
	}

	FTagDelegate(const FGameplayTagContainer& TagContainer)
	{
		AddUniqueTags(TagContainer);
	}

	bool TryExecute(const UAbilitySystemComponent* AbilitySystemComponent, const FGameplayTag& Tag, const int32 TagCount) const
	{
		for (int32 i = 0; i < ListeningTags.Num(); ++i)
		{
			if (Tag == ListeningTags[i])
			{
				if (TagCount > 0)
				{
					return OnAddedTargetFunction.ExecuteIfBound(AbilitySystemComponent, Tag);
				}
				else
				{
					return OnRemovedTargetFunction.ExecuteIfBound(AbilitySystemComponent, Tag);
				}
			}
		}
		return false;
	}

	void AddUniqueTags(const FGameplayTagContainer& TagContainer)
	{
		for (int32 i = 0; i < TagContainer.Num(); ++i)
		{
			ListeningTags.AddUnique(TagContainer.GetByIndex(i));
		}
	}

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UC_TagDelegates : public UActorComponent
{
	GENERATED_BODY()

public:	

	UC_TagDelegates();

protected:

	virtual void BeginPlay() override;

public:	

	virtual bool Initialize(AActor* OwnerActor);

	/**
 * Will be triggered every time a tag change observe in ability system component.
 * @param  Tag - That triggered event.
 * @param  TagCount - The number of this tag added to Owner ability system component.
 */
	UFUNCTION()
	void OnGameplayTagChanged(const FGameplayTag Tag, const int32 TagCount) const;
	
	FOnGameplayTagChangeReceived& RegisterDelegateForTag(const FGameplayTag& Tag, const EListenMode ListenMode);
	
	FOnGameplayTagChangeReceived& RegisterDelegateForTags(const FGameplayTagContainer& TagContainer, const EListenMode ListenMode);

protected:

	UAbilitySystemComponent* OwnerASC;

private:

	TArray<FTagDelegate> TagDelegates;

};
