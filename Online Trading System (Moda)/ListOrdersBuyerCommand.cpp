#include "ListOrdersBuyerCommand.h"
#include "Buyer.h"

void ListOrdersBuyerCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->listOrders(*system);
	buyer = nullptr;
}
