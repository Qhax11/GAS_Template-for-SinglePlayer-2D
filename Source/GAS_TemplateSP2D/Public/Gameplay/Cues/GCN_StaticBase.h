// Qhax's GAS Template for SinglePlayer

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_Static.h"
#include "GCN_StaticBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEMPLATESP2D_API UGCN_StaticBase : public UGameplayCueNotify_Static
{
	GENERATED_BODY()

	// Default functions
public:

	bool OnExecute_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const final;

	bool OnActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const final;

	bool WhileActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const final;

	bool OnRemove_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) const final;

	// Our functions with flex
protected:

	virtual void OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const;

	virtual void OnActivated(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const;

	virtual void OnWhileActivated(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const;

	virtual void OnRemoved(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters) const;
};
