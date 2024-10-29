// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/GCN_ActorBase.h"

bool AGCN_ActorBase::OnExecute_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters)
{
	Super::OnExecute_Implementation(MyTarget, Parameters);

	OnExecuted(Parameters.GetEffectCauser(), MyTarget, Parameters);

	return true;
}

bool AGCN_ActorBase::OnActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters)
{
	Super::OnExecute_Implementation(MyTarget, Parameters);

	OnActivated(Parameters.GetEffectCauser(), MyTarget, Parameters);

	return true;
}

bool AGCN_ActorBase::WhileActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters)
{
	Super::OnExecute_Implementation(MyTarget, Parameters);

	OnWhileActivated(Parameters.GetEffectCauser(), MyTarget, Parameters);

	return true;
}

bool AGCN_ActorBase::OnRemove_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters)
{
	Super::OnExecute_Implementation(MyTarget, Parameters);

	OnRemoved(Parameters.GetEffectCauser(), MyTarget, Parameters);

	return true;
}

void AGCN_ActorBase::OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	// Logic will be implemented in subclasses.
}

void AGCN_ActorBase::OnActivated(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	// Logic will be implemented in subclasses.
}

void AGCN_ActorBase::OnWhileActivated(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	// Logic will be implemented in subclasses.
}

void AGCN_ActorBase::OnRemoved(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	// Logic will be implemented in subclasses.
}
