#include "ConfirmOrderCommand.h"

void ConfirmOrderCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	int orderIndex = NOT_FOUND;
	cout << "Order index: ";
	cin >> orderIndex;
	if (checkInput() == UNSUCCESSFUL)
		return;

	buyer->confirmOrder(*system, orderIndex);
	buyer = nullptr;
}
