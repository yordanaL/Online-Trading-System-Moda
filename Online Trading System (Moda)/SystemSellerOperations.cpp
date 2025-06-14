#include "SystemSellerOperations.h"
#include "Product.h"
#include "System.h"

void SystemSellerOperations::addItem(System& system, const Product newProduct)
{
	system.products.pushBack(newProduct);
	cout << "Product added successfully!" << endl;
}

void SystemSellerOperations::removeItem(System& system, const String& productName)
{
	int productIndex = system.findIndexOfProductByName(productName);

	if (productIndex == NOT_FOUND) {
		cout << "Product not found!" << endl;
		return;
	}
	else {
		try {
			system.products.erase(productIndex);
		}
		catch (invalid_argument& ex) {
			cout << ex.what() << endl;
		}
	}
}

void SystemSellerOperations::listBestSellingProducts(System& system)
{
	Vector<Product> sortedArray = system.products;
	size_t productCount = sortedArray.size();

	for (int i = 0; i < productCount - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < productCount; j++) {
			if (sortedArray[j].getTotalSales() > sortedArray[minIndex].getTotalSales())
				minIndex = j;
		}

		swap(sortedArray[i], sortedArray[minIndex]);
	}

	if (sortedArray.size() < COUNT_OF_BEST_SELLING_PRODUCTS) {
		for (size_t i = 0; i < sortedArray.size(); i++) {
			cout << (i + 1) << ". " << sortedArray[i].getProductName() << " - " 
				<< sortedArray[i].getTotalSales() << " sales" << endl;
		}

		return;
	}

	for (size_t i = 0; i < COUNT_OF_BEST_SELLING_PRODUCTS; i++) {
		cout << (i + 1) << ". " << sortedArray[i].getProductName() << " - "
			<< sortedArray[i].getTotalSales() << " sales" << endl;
	}
}

void SystemSellerOperations::shipOrder(System& system, Order& newOrder)
{
	int buyerIndex = system.findIndexOfBuyerByEGN(newOrder.getBuyerEGN());

	if (buyerIndex == NOT_FOUND) {
		cout << "Order cannot be shipped!" << endl;
		return;
	}

	system.buyers[buyerIndex].receiveOrder(newOrder);
}

void SystemSellerOperations::sendRejectedOrder(System& system, const RejectedOrder& newRejectedOrder)
{
	int buyerIndex = system.findIndexOfBuyerByEGN(newRejectedOrder.getBuyerEGN());

	if (buyerIndex == NOT_FOUND) {
		cout << "Order cannot be rejected!" << endl;
		return;
	}

	system.buyers[buyerIndex].receiveRejectedOrder(system, newRejectedOrder);
}

void SystemSellerOperations::sendRefund(System& system, const Order& order)
{
	int buyerIndex = system.findIndexOfBuyerByEGN(order.getBuyerEGN());
	if (buyerIndex == NOT_FOUND) {
		cout << "Buyer could not be found!" << endl;
		return;
	}

	system.buyers[buyerIndex].receiveRefund(system, order);
}

void SystemSellerOperations::rejectRefund(System& system, const RejectedOrder& newRejectedRefund)
{
	int buyerIndex = system.findIndexOfBuyerByEGN(newRejectedRefund.getBuyerEGN());

	if (buyerIndex == NOT_FOUND) {
		cout << "Refund cannot be rejected!" << endl;
		return;
	}

	system.buyers[buyerIndex].receiveRefundRejection(newRejectedRefund);
}
