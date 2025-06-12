#include "RemoveFromCartCommand.h"
#include "Buyer.h"

void RemoveFromCartCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	int productID = NOT_FOUND;
	cout << "Product ID: ";
	cin >> productID;
	if (checkInput() == UNSUCCESSFUL)
		return;

	int quantity = NOT_FOUND;
	cout << "Quantity: ";
	cin >> quantity;
	if (checkInput() == UNSUCCESSFUL)
		return;

	buyer->removeFromCart(*system, productID, quantity);
	buyer = nullptr;
}
