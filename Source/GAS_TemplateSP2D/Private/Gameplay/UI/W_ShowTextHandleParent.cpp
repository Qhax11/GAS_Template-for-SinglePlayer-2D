// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/W_ShowTextHandleParent.h"
#include "Components/CanvasPanelSlot.h"

void UW_ShowTextHandleParent::AddChildText(UUserWidget* Child)
{
	if (!Child) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Child is null (This message comes from UW_ShowTextHandleParent)"));
		return;
	}
	UCanvasPanelSlot* CanvasPanelSlot = Canvas->AddChildToCanvas(Child);
	CanvasPanelSlot->SetAnchors(FAnchors(0.5, 0.5, 0.5, 0.5));
	CanvasPanelSlot->SetAlignment(FVector2D(0.5, 0.5));
}
