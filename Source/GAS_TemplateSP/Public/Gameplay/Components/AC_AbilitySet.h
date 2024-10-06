// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GAS_AbilitySystemComponent.h"
#include "AC_AbilitySet.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP_API UAC_AbilitySet : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_AbilitySet();

	void Initialize(UGAS_AbilitySystemComponent* ASC);

	UPROPERTY(EditDefaultsOnly)
	UGAS_GameplayAbilitySet* AbilitySet;
};
