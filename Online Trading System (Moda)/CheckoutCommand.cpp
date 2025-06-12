#include "CheckoutCommand.h"
#include "Buyer.h"

void CheckoutCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->checkout(*system);
	buyer = nullptr;
}
