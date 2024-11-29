// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Components/ActorComponent.h"
#include "GAS_AbilitySystemComponent.h"
#include "AC_AbilitySet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilitySetGiven, const AActor*, OwnerActor);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_AbilitySet : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAC_AbilitySet();

	void Initialize(UGAS_AbilitySystemComponent* ASC);

	UPROPERTY(EditDefaultsOnly)
	UGAS_GameplayAbilitySet* AbilitySet;

	UPROPERTY(BlueprintAssignable)
	FOnAbilitySetGiven OnAbilitySetGiven;
};
