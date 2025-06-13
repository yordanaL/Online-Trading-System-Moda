#include "RejectOrderCommand.h"
#include "Seller.h"

void RejectOrderCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	int orderIndex = NOT_FOUND;
	cout << "Order index: ";
	cin >> orderIndex;
	if (checkInput() == UNSUCCESSFUL)
		return;
	cin.ignore(INT_MAX, '\n');

	char rejectionReason[BUFF_SIZE]{'\0'};
	cout << "Rejection reason: ";
	cin.getline(rejectionReason, BUFF_SIZE);
	if (checkInput() == UNSUCCESSFUL)
		return;

	seller->rejectOrder(*system, orderIndex, rejectionReason);
	seller = nullptr;
}
