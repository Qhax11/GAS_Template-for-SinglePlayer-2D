// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/Message/GCN_PlayerMessageHUD.h"


void AGCN_PlayerMessageHUD::OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	Super::OnExecuted(Source, Target, Parameters);

	BP_TriggerWidget(FinalTextColor, PlayerMessage, FinalShowTextType);
}
