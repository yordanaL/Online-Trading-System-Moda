#include "ListShippedOrdersCommand.h"
#include "Buyer.h"

void ListShippedOrdersCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->listShippedOrders(*system);
	buyer = nullptr;
}
