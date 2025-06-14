#include "SortByAlphCommand.h"

void SortByAlphCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->listProductsSortedByAlphabeticalOrder(*system);
	buyer = nullptr;
}
