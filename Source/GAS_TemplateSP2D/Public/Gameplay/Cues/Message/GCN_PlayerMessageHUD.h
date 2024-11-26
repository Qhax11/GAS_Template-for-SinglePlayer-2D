// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Cues/Message/GCN_MessageBase.h"
#include "GCN_PlayerMessageHUD.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API AGCN_PlayerMessageHUD : public AGCN_MessageBase
{
	GENERATED_BODY()

public:

	virtual void OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) override;

	UPROPERTY(EditDefaultsOnly, Category = "MessageConfig")
	FString PlayerMessage;
};
