#include "RejectRefundCommand.h"
#include "Seller.h"

void RejectRefundCommand::execute(System* system)
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
	clearBuffer();

	char rejectionReason[BUFF_SIZE]{ '\0' };
	cout << "Rejection reason: ";
	cin.getline(rejectionReason, BUFF_SIZE);
	if (checkInput() == UNSUCCESSFUL)
		return;

	seller->rejectRefund(*system, orderIndex, rejectionReason);

	seller = nullptr;
}
