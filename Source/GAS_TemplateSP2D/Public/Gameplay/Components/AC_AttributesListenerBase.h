// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/Tags/GAS_Tags.h"
#include "AC_AttributesListenerBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_AttributesListenerBase : public UActorComponent
{
	GENERATED_BODY()

public:	

	UAC_AttributesListenerBase();

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnAbilitySetGiven(const AActor* OwnerActor);

	UAbilitySystemComponent* OwnerASC;

public:

	virtual bool Initialize(const AActor* OwnerActor);

protected:
	// For update full health state
	UFUNCTION()
	virtual void HealthChanged(const FAttributeChangeCallbackData& Data);

	UFUNCTION()
	virtual void MovementSpeedChanged(const FAttributeChangeCallbackData& Data);

};
