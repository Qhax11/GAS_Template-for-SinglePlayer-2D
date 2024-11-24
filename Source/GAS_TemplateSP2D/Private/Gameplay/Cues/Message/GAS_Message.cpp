// Qhax's GAS Template for SinglePlayer


#include "Gameplay/Cues/Message/GAS_Message.h"


void AGAS_Message::OnExecuted(AActor* Source, AActor* Target, const FGameplayCueParameters& Parameters)
{
	Initialize();
}

void AGAS_Message::Initialize()
{
	// Setting default values
	FinalTextColor = WidgetTextColor;
	FinalShowTextType = WidgetTextAnim;
}


