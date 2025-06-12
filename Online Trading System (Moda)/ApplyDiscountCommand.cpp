#include "ApplyDiscountCommand.h"
#include "Buyer.h"

void ApplyDiscountCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->applyDiscount();
	buyer = nullptr;
}
