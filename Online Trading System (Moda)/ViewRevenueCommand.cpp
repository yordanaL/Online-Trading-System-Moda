#include "ViewRevenueCommand.h"
#include "Seller.h"

void ViewRevenueCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	cout << endl;
	seller->viewRevenue();
	seller = nullptr;
}
