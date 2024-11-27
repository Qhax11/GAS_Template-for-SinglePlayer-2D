// Qhax's GAS Template for 2D SinglePlayer


#include "Gameplay/Actors/PaperCharacters/Enemies/GAS_PaperEnemyBase.h"
#include "Gameplay/Actors/PaperCharacters/Enemies/Components/AC_EnemyRespawn.h"


AGAS_PaperEnemyBase::AGAS_PaperEnemyBase(const class FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
	EnemyRespawnComponent = CreateDefaultSubobject<UAC_EnemyRespawn>(TEXT("EnemyRespawnComponent"));
}

void AGAS_PaperEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}
