// Qhax's GAS Template for SinglePlayer

#pragma once

#include "GameplayCueNotify_Static.h"
#include "GCN_StaticBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGCN_StaticBase : public UGameplayCueNotify_Static
{
	GENERATED_BODY()

	// Default function implementations
public:

	bool OnExecute_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const final;

	bool OnActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const final;

	bool WhileActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const final;

	bool OnRemove_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const final;

	// Custom functions with flexibility for further modification
protected:

	virtual void OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const;

	virtual void OnActivated(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const;

	virtual void OnWhileActivated(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const;

	virtual void OnRemoved(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const;
};
