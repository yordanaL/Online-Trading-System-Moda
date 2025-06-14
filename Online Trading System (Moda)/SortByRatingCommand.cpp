#include "SortByRatingCommand.h"

void SortByRatingCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->listProductsSortedByRating(*system);
	buyer = nullptr;
}
