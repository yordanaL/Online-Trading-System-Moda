#include "RequestRefundCommand.h"
#include "Buyer.h"

void RequestRefundCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->requestRefund(*system);
	buyer = nullptr;
}
