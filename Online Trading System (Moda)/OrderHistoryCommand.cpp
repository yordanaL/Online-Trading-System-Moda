#include "OrderHistoryCommand.h"
#include "Buyer.h"

void OrderHistoryCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->orderHistory();
	buyer = nullptr;
}
