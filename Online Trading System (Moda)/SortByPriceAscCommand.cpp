#include "SortByPriceAscCommand.h"

void SortByPriceAscCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->listProductsSortedByPriceAsc(*system);
	buyer = nullptr;
}
