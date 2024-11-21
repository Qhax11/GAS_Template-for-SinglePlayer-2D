// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Abilities/Enemy/GA_EnemyDeath.h"


void UGA_EnemyDeath::DisableCollisions()
{
	Super::DisableCollisions();
}

void UGA_EnemyDeath::OnCompleted()
{
	Super::OnCompleted();
	GetAvatarActorFromActorInfo()->Destroy();
}
