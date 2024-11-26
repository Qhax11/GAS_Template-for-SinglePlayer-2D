// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Gameplay/Actors/PaperCharacters/Heroes/GAS_PaperHeroBase.h"
#include "S_SpawnDelegates.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroSpawn, AGAS_PaperHeroBase*, Hero);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroReSpawn, AGAS_PaperHeroBase*, Hero);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroDeSpawn, AGAS_PaperHeroBase*, Hero);


UCLASS()
class GAS_TEMPLATESP2D_API US_SpawnDelegates : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable)
	FOnHeroSpawn OnHeroSpawn;

	UPROPERTY(BlueprintAssignable)
	FOnHeroReSpawn OnHeroReSpawn;

	UPROPERTY(BlueprintAssignable)
	FOnHeroDeSpawn OnHeroDeSpawn;
};