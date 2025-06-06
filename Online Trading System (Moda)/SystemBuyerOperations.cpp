#include "SystemBuyerOperations.h"
#include "System.h"

void SystemBuyerOperations::listProducts(const System& system) const
{
	for (size_t i = 0; i < system.products.size(); i++) {
		cout << (i + 1);
		system.products[i].displayProduct();
	}
}

void SystemBuyerOperations::viewProduct(const System& system, int productID) const
{
	int productIndex = system.findIndexOfProductByID(productID);

	if (productIndex == NOT_FOUND) {
		cout << "This product does not exist!" << endl;
		return;
	}
	else
		system.products[productIndex].printProductDetails();
}

void SystemBuyerOperations::rate(System& system, int productID, const Pair<String, int>& newRating)
{
	int productIndex = system.findIndexOfProductByID(productID);

	if (productIndex == NOT_FOUND) {
		cout << "This product does not exist!" << endl;
		return;
	}
	else {
		system.products[productIndex].updateRating(newRating);
	}
}

void SystemBuyerOperations::sendConfirmation(System& system, int orderNumber) const
{
	system.seller.receiveConfirmation(orderNumber);
}
