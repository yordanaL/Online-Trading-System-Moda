#include "ListOrdersSellerCommand.h"
#include "Seller.h"

void ListOrdersSellerCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	seller->listOrders(*system);
	seller = nullptr;
}
