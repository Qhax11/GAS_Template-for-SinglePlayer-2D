// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Components/ActorComponent.h"
#include "AC_GameplayData.generated.h"

class UDA_ActorSounds;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAS_TEMPLATESP2D_API UAC_GameplayData : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAC_GameplayData();
	
	UFUNCTION(BlueprintCallable)
	UDA_ActorSounds* GetActorSoundsData();
	
private:

	UPROPERTY(EditDefaultsOnly, Category = "ActorSounds")
	TObjectPtr<UDA_ActorSounds> DA_ActorSounds;

};
