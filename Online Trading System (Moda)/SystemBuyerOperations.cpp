#include "SystemBuyerOperations.h"
#include "System.h"

void SystemBuyerOperations::listProducts(const System& system) const
{
	if (system.products.size() == DEFAULT_VALUE) {
		cout << "There are no products in the system yet!" << endl;
	}

	for (size_t i = 0; i < system.products.size(); i++) {
		cout << (i + 1);
		system.products[i].displayProduct();
		cout << endl;
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

void SystemBuyerOperations::removeRating(System& system, int productID, const String& buyerEGN)
{
	int productIndex = system.findIndexOfProductByID(productID);

	if (productIndex == NOT_FOUND) {
		cout << "This product does not exist!" << endl;
		return;
	}

	system.products[productIndex].removeRating(buyerEGN);
}

void SystemBuyerOperations::sendOrder(System& system, Order& newOrder)
{
	system.seller.receiveOrder(newOrder);
}

void SystemBuyerOperations::sendConfirmation(System& system, int orderNumber) const
{
	system.seller.receiveConfirmation(orderNumber);
}

const String& SystemBuyerOperations::getProductNameByID(const System& system, int productID) const
{
	return system.products[system.findIndexOfProductByID(productID)].getProductName();
}

const double SystemBuyerOperations::getProductPriceByID(const System& system, int productID) const
{
	return system.products[system.findIndexOfProductByID(productID)].getProductPrice();
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

void SystemBuyerOperations::requestRefund(System& system, Order& order)
{
	system.seller.receiveRefundRequest(order);
}

