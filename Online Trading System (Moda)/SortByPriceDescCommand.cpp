#include "SortByPriceDescCommand.h"

void SortByPriceDescCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->listProductsSortedByPriceDesc(*system);
	buyer = nullptr;
}
