#include "ViewRevenueCommand.h"
#include "Seller.h"

void ViewRevenueCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	seller->viewRevenue();
	seller = nullptr;
}
