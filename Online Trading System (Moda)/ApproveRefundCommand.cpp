#include "ApproveRefundCommand.h"
#include "Seller.h"

void ApproveRefundCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	int orderIndex = NOT_FOUND;
	cout << "Order index: ";
	cin >> orderIndex;
	if (checkInput() == UNSUCCESSFUL)
		return;

	seller->approveRefund(*system, orderIndex);

	seller = nullptr;
}
