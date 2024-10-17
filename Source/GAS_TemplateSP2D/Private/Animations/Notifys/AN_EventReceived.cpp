// Qhax's GAS Template for SinglePlayer


#include "Animations/Notifys/AN_EventReceived.h"


void UAN_EventReceived::OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance) const
{
	if (OnEventReceived.IsBound()) 
	{
		OnEventReceived.Broadcast();
	}
}
