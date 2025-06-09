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

void SystemBuyerOperations::sendOrder(System& system, Order& newOrder)
{
	system.seller.receiveOrder(newOrder);
}

void SystemBuyerOperations::sendConfirmation(System& system, int orderNumber) const
{
	system.seller.receiveConfirmation(orderNumber);
}

bool SystemBuyerOperations::takeProduct(System& system, int productID, int quantity)
{
	int productIndex = system.findIndexOfProductByID(productID);
	if (productIndex == NOT_FOUND) {
		cout << "This product does not exist!" << endl;
		return UNSUCCESSFUL;
	}

	if (system.products[productIndex].getQuantity() < quantity) {
		cout << "Not enough pcs in stock!" << endl;
		return UNSUCCESSFUL;
	}

	system.products[productIndex].decreaseQuantity(quantity);
	return SUCCESSFUL;
}

bool SystemBuyerOperations::returnProduct(System& system, int productID, int quantity)
{
	int productIndex = system.findIndexOfProductByID(productID);
	if (productIndex == NOT_FOUND) {
		cout << "This product does not exist!" << endl;
		return UNSUCCESSFUL;
	}

	system.products[productIndex].increaseQuantity(quantity);
	return SUCCESSFUL;
}
