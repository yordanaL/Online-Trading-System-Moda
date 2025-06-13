#include "ListBestSellingProductsCommand.h"
#include "Seller.h"

void ListBestSellingProductsCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	seller->listBestSellingProducts(*system);
	seller = nullptr;
}
