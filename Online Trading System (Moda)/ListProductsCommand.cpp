#include "ListProductsCommand.h"
#include "Buyer.h"

void ListProductsCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->listProducts(*system);
	buyer = nullptr;
}
