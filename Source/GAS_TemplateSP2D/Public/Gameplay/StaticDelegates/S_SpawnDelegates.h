// Qhax's GAS Template for SinglePlayer

#pragma once

#include "Subsystems/GameInstanceSubsystem.h"
#include "Gameplay/Actors/PaperCharacters/GAS_PaperCharacterBase.h"
#include "S_SpawnDelegates.generated.h"

// Spawn refers to the first initialization, 
// ReSpawn refers to subsequent initializations after death
// DeSpawn means the character's death.

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroSpawn, AGAS_PaperCharacterBase*, Hero);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroReSpawn, AGAS_PaperCharacterBase*, Hero);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroDeSpawn, AGAS_PaperCharacterBase*, Hero);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemySpawn, AGAS_PaperCharacterBase*, Enemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyReSpawn, AGAS_PaperCharacterBase*, Enemy);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDeSpawn, AGAS_PaperCharacterBase*, Enemy);


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

	UPROPERTY(BlueprintAssignable)
	FOnEnemySpawn OnEnemySpawn;

	UPROPERTY(BlueprintAssignable)
	FOnEnemyReSpawn OnEnemyReSpawn;

	UPROPERTY(BlueprintAssignable)
	FOnEnemyDeSpawn OnEnemyDeSpawn;
};
