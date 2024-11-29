// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Notifies/PaperZDAnimNotify.h"
#include "GameplayTagContainer.h"
#include "AN_EventReceived.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventReceived);

UCLASS()
class GAS_TEMPLATESP2D_API UAN_EventReceived : public UPaperZDAnimNotify
{
	GENERATED_BODY()
	
public:
	void OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance = nullptr) const override;

	FEventReceived OnEventReceived;

	UPROPERTY(EditAnywhere, Category = "AnimNotify")
	FGameplayTag EventTag;

};
