#include "RemoveDiscountCommand.h"
#include "Buyer.h"

void RemoveDiscountCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->removeDiscount();
	buyer = nullptr;
}
