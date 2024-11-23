// Qhax's GAS Template for SinglePlayer


#include "Gameplay/UI/W_AttachedEffectTextParent.h"
#include "Components/CanvasPanelSlot.h"

void UW_AttachedEffectTextParent::AddChildText(UUserWidget* Child)
{
	if (!Child) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Child widget is null in %s"), *this->GetName());
		return;
	}
	UCanvasPanelSlot* CanvasPanelSlot = Canvas->AddChildToCanvas(Child);
	CanvasPanelSlot->SetAnchors(FAnchors(0.5, 0.5, 0.5, 0.5));
	CanvasPanelSlot->SetAlignment(FVector2D(0.5, 0.5));
}
