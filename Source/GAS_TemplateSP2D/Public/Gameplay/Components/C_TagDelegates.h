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
	FGameplayTag ListeningTag;

	UPROPERTY(BlueprintReadOnly, Category = "Tag Delegate")
	FOnGameplayTagChangeReceived OnAddedTargetFunction;

	UPROPERTY(BlueprintReadOnly, Category = "Tag Delegate")
	FOnGameplayTagChangeReceived OnRemovedTargetFunction;

	FTagDelegate() = default;

	FTagDelegate(FGameplayTag ListenTag) :
		ListeningTag(ListenTag)
	{
		
	}

	bool TryExecute(const UAbilitySystemComponent* AbilitySystemComponent, const FGameplayTag& Tag, const int32 TagCount) const
	{
		if (Tag == ListeningTag)
		{
			if (TagCount > 0)
			{
				OnAddedTargetFunction.ExecuteIfBound(AbilitySystemComponent, Tag);
			}
			else
			{
				OnRemovedTargetFunction.ExecuteIfBound(AbilitySystemComponent, Tag);
			}
		}
		return false;
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
	
	FOnGameplayTagChangeReceived& RegisterDelegateForTag(FGameplayTag Tag, EListenMode ListenMode);
	
	FOnGameplayTagChangeReceived& RegisterDelegateForTags(FGameplayTagContainer Tags, EListenMode ListenMode);

protected:

	UAbilitySystemComponent* OwnerASC;

private:

	TArray<FTagDelegate> TagDelegates;

};
