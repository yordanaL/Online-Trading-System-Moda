#include "ViewProductCommand.h"
#include "Buyer.h"

void ViewProductCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	int productID = NOT_FOUND;
	cout << "Product ID: ";
	cin >> productID;
	if (checkInput() == UNSUCCESSFUL)
		return;

	buyer->viewProduct(*system, productID);
	buyer = nullptr;
}
