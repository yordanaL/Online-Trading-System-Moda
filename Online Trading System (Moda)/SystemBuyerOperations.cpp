#include "SystemBuyerOperations.h"
#include "System.h"

bool SystemBuyerOperations::isSellerSignedUp(const System& system)
{
	return system.sellerSignedUp;
}

void SystemBuyerOperations::listProducts(System& system) const
{
	if (system.products.size() == DEFAULT_VALUE) {
		cout << "There are no products in the system yet!" << endl;
	}

	/*for (size_t i = 0; i < system.products.size(); i++) {
		cout << (i + 1);
		system.products[i].displayProduct();
		cout << endl;
	}*/

	SortByID IDSort;
	ProductListing listing;

	listing.setStrategy(&IDSort);
	listing.list(system.products);
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

void SystemBuyerOperations::listProductsSortedByRating(System& system) const
{
	if (system.products.size() == DEFAULT_VALUE) {
		cout << "There are no products in the system yet!" << endl;
	}

	SortByRating ratingSort;
	ProductListing listing;

	listing.setStrategy(&ratingSort);
	listing.list(system.products);
}

void SystemBuyerOperations::listProductsSortedByPriceAsc(System& system) const
{
	if (system.products.size() == DEFAULT_VALUE) {
		cout << "There are no products in the system yet!" << endl;
	}

	SortByPriceAsc priceAscSort;
	ProductListing listing;

	listing.setStrategy(&priceAscSort);
	listing.list(system.products);
}

void SystemBuyerOperations::listProductsSortedByPriceDesc(System& system) const
{
	if (system.products.size() == DEFAULT_VALUE) {
		cout << "There are no products in the system yet!" << endl;
	}

	SortByPriceDesc priceDescSort;
	ProductListing listing;

	listing.setStrategy(&priceDescSort);
	listing.list(system.products);
}

void SystemBuyerOperations::listProductsSortedByAlphabeticalOrder(System& system) const
{
	if (system.products.size() == DEFAULT_VALUE) {
		cout << "There are no products in the system yet!" << endl;
	}

	SortByAlphabeticalOrder alphabeticalOrderSort;
	ProductListing listing;

	listing.setStrategy(&alphabeticalOrderSort);
	listing.list(system.products);
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

const String SystemBuyerOperations::getProductNameByID(const System& system, int productID) const
{
	int productIndex = system.findIndexOfProductByID(productID);
	if (productIndex == NOT_FOUND) {
		String removedItem("Removed Item");
		return removedItem;
	}

	return system.products[productIndex].getProductName();
}

const double SystemBuyerOperations::getProductPriceByID(const System& system, int productID) const
{
	int productIndex = system.findIndexOfProductByID(productID);
	if (productIndex == NOT_FOUND) {
		return DEFAULT_VALUE;
	}

	return system.products[productIndex].getProductPrice();
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

