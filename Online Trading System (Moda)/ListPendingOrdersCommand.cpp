#include "ListPendingOrdersCommand.h"
#include "Seller.h"

void ListPendingOrdersCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	seller->listPendingOrders(*system);
	seller = nullptr;
}
