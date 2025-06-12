#include "ApproveOrderCommand.h"
#include "Seller.h"

void ApproveOrderCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	cout << endl;

	int orderIndex = NOT_FOUND;
	cout << "Order index: ";
	cin >> orderIndex;
	if (checkInput() == UNSUCCESSFUL)
		return;

	seller->approveOrder(*system, orderIndex);
	seller = nullptr;
}
