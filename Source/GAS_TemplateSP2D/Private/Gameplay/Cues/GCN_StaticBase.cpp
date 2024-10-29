// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/GCN_StaticBase.h"

bool UGCN_StaticBase::OnExecute_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const
{
	Super::OnExecute_Implementation(MyTarget, Parameters);

	OnExecuted(Parameters.GetEffectCauser(), MyTarget, Parameters);

	return true;
}

bool UGCN_StaticBase::OnActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const
{
	Super::OnExecute_Implementation(MyTarget, Parameters);

	OnActivated(Parameters.GetEffectCauser(), MyTarget, Parameters);

	return true;
}

bool UGCN_StaticBase::WhileActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const
{
	Super::OnExecute_Implementation(MyTarget, Parameters);

	OnWhileActivated(Parameters.GetEffectCauser(), MyTarget, Parameters);

	return true;
}

bool UGCN_StaticBase::OnRemove_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const
{
	Super::OnExecute_Implementation(MyTarget, Parameters);

	OnRemoved(Parameters.GetEffectCauser(), MyTarget, Parameters);

	return true;
}

void UGCN_StaticBase::OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const
{
	// Logic will be implemented in subclasses.
}

void UGCN_StaticBase::OnActivated(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const
{
	// Logic will be implemented in subclasses.
}

void UGCN_StaticBase::OnWhileActivated(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const
{
	// Logic will be implemented in subclasses.
}

void UGCN_StaticBase::OnRemoved(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const
{
	// Logic will be implemented in subclasses.
}
