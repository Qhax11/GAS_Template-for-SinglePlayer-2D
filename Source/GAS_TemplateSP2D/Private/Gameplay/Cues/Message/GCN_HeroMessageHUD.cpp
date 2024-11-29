// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/Message/GCN_HeroMessageHUD.h"


void AGCN_HeroMessageHUD::OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	Super::OnExecuted(Source, Target, Parameters);

	WidgetMessageData.MessageString = HeroMessage;
	BP_TriggerWidget(WidgetMessageData);
}

void AGCN_HeroMessageHUD::OnActivated(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	Super::OnActivated(Source, Target, Parameters);

	WidgetMessageData.MessageString = HeroMessage;
	BP_TriggerWidget(WidgetMessageData);
}
