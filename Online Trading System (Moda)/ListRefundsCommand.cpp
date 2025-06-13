#include "ListRefundsCommand.h"
#include "Seller.h"

void ListRefundsCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	seller->listRefunds(*system);
	seller = nullptr;
}
