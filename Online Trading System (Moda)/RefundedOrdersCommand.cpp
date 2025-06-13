#include "RefundedOrdersCommand.h"
#include "Buyer.h"

void RefundedOrdersCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->refundedOrders(*system);
	buyer = nullptr;
}
