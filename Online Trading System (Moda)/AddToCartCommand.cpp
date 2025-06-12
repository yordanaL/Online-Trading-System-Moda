#include "AddToCartCommand.h"
#include "Buyer.h"

void AddToCartCommand::execute(System* system)
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

	buyer->addToCart(*system, productID, quantity);
	buyer = nullptr;
}
