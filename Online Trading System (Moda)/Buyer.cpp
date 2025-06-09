#include "Buyer.h"
#include "System.h"

int Buyer::findIndexOfCheck(const String& code) const
{
	for (int i = 0; i < this->receivedChecks.size(); i++) {
		if (this->receivedChecks[i].getCode() == code)
			return i;
	}

	return NOT_FOUND;
}

void Buyer::addProductToPurchasedProducts(int productID, int quantity)
{
	for (size_t i = 0; i < this->IDsAndQuantityOfPurchasedProducts.size(); i++) {
		if (this->IDsAndQuantityOfPurchasedProducts[i].getKey() == productID) {
			this->IDsAndQuantityOfPurchasedProducts[i].increaseValue(quantity);
			return;
		}
	}

	Pair<int, int> newPurchasedProduct(productID, quantity);
}

void Buyer::checkBoughtProductsQuantity(System& system)
{
	for (size_t i = 0; i < this->IDsAndQuantityOfPurchasedProducts.size(); i++) {
		if (this->IDsAndQuantityOfPurchasedProducts[i].getValue() == DEFAULT_VALUE) {
			removeRating(system, this->IDsAndQuantityOfPurchasedProducts[i].getKey(), this->EGN);
		}
	}
}

void Buyer::help() const
{
	cout << "Client Commands: " << endl;
	cout << " 1) check-balance" << endl;
	cout << " 2) redeem" << endl;
	cout << " 3) list-products" << endl;
	cout << " 4) view-product" << endl;
	cout << " 5) add-to-cart" << endl;
	cout << " 6) remove-from-cart" << endl;
	cout << " 7) apply-discount" << endl;
	cout << " 8) remove-discount" << endl;
	cout << " 9) view-cart" << endl;
	cout << "10) checkout" << endl;
	cout << "11) list-orders" << endl;
	cout << "12) confirm-order" << endl;
	cout << "13) order-history" << endl;
	cout << "14) rate" << endl;
	cout << "15) request-refund" << endl;
	cout << "16) refunded-orders" << endl;
	cout << "17) logout" << endl;
	cout << "18) help" << endl;
	cout << "19) view-profile" << endl;
}

void Buyer::loginInfo()
{
	if (this->rejectedOrders.size() > DEFAULT_VALUE) {
		cout << "You have a rejected order/s: " << endl;

		for (size_t i = 0; i < this->rejectedOrders.size(); i++)	{
			cout << "Order #" << this->rejectedOrders[i].getOrderNumber() << " - ";
			this->rejectedOrders[i].printOrder();
			cout << "Reason: " << this->rejectedOrders[i].getRejectionReason() << endl;

			this->balance += this->rejectedOrders[i].getTotalPrice();
			this->loyaltyPoints += this->rejectedOrders[i].getLoyaltyPointsUsed();
		}
	}

	this->rejectedOrders.clear();
}

void Buyer::checkBalance() const
{
	cout << "Current balance: " << this->balance << endl;
	cout << "Loyalty points: " << this->loyaltyPoints << endl;
}

void Buyer::redeemCheck(const String& code)
{
	int checkIndex = findIndexOfCheck(code);

	if (checkIndex == NOT_FOUND) {
		cout << "Invalid code!" << endl;
		return;
	}

	this->balance += this->receivedChecks[checkIndex].getAmount();
	cout << "Successfully redeemed check. " << this->receivedChecks[checkIndex].getAmount() << " BGN added to your balance!";

	this->receivedChecks.erase(checkIndex);
}

void Buyer::receiveCheck(const Check& newCheck)
{
	this->receivedChecks.pushBack(newCheck);
}

void Buyer::printInsights() const
{
	cout << this->name << " - " << this->finalisedOrdersCount << " purchases, " << this->totalMoneySpent << " BGN spent";

	if (this->refundedOrdersCount > DEFAULT_VALUE)
		cout << "(" << this->refundedOrdersCount << " refunded orders)" << endl;
	else
		cout << endl;
}

void Buyer::listProducts(const System& system) const
{
	system.listProducts(system);
}

void Buyer::viewProduct(const System& system, int productID) const
{
	system.viewProduct(system, productID);
}

bool Buyer::takeProduct(System& system, int productID, int quantity)
{
	return system.takeProduct(system, productID, quantity);
}

bool Buyer::returnProduct(System& system, int productID, int quantity)
{
	return system.returnProduct(system, productID, quantity);
}

void Buyer::addToCart(System& system, int productID, int quantity)
{
	bool operationSuccess = takeProduct(system, productID, quantity);
	if (operationSuccess == UNSUCCESSFUL) {
		cout << "Could not add product to cart!" << endl;
		return;
	}

	this->cart.addProduct(productID, quantity);
}

void Buyer::removeFromCart(System& system, int productID, int quantity)
{
	bool operationSuccess = returnProduct(system, productID, quantity);
	if (operationSuccess == UNSUCCESSFUL) {
		cout << "Could not remove product from cart!" << endl;
		return;
	}

	this->cart.removeProduct(productID, quantity);
}

void Buyer::checkout(System& system)
{
	Order newOrder(this->cart);
	sendOrder(system, newOrder);
	cout << "Order placed successfully. Awaiting approval from seller!" << endl;

	this->cart.cleanCart();
}

void Buyer::sendOrder(System& system, Order& newOrder)
{
	system.sendOrder(system, newOrder);
}

void Buyer::receiveOrder(Order& newOrder)
{
	this->shippedOrders.pushBack(newOrder);
}

void Buyer::receiveRejectedOrder(const RejectedOrder& newRejectedOrder)
{
	this->rejectedOrders.pushBack(newRejectedOrder);
}

void Buyer::confirmOrder(System& system, int index)
{
	if (index <= DEFAULT_VALUE || index > this->shippedOrders.size()) {
		cout << "Invalid order index!" << endl;
		return;
	}

	this->shippedOrders[index - 1].updateStatus(DELIVERED);
	this->deliveredOrders.pushBack(this->shippedOrders[index - 1]);
	system.sendConfirmation(system, this->shippedOrders[index - 1].getOrderNumber());

	cout << "Order confirmed as delivered. You received " << this->shippedOrders[index - 1].getTotalPrice() * LOYALTY_POINTS_INDEX
		<< " (5% of " << this->shippedOrders[index - 1].getTotalPrice() << " BGN)";

	this->loyaltyPoints += (int)this->shippedOrders[index - 1].getTotalPrice() * LOYALTY_POINTS_INDEX;
	this->finalisedOrdersCount++;
	this->totalMoneySpent += this->shippedOrders[index - 1].getTotalPrice();

	this->shippedOrders.erase(index - 1);
}

void Buyer::listOrders() const
{
	if (this->shippedOrders.size() == DEFAULT_VALUE) {
		cout << "No received orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->shippedOrders.size(); i++) {
		this->shippedOrders[i].printOrder();
	}
}

void Buyer::orderHistory() const
{
	if (this->deliveredOrders.size() == DEFAULT_VALUE) {
		cout << "No orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->deliveredOrders.size(); i++) {
		this->deliveredOrders[i].printOrder();
	}
}

void Buyer::refundedOrders() const
{
	if (this->refOrders.size() == DEFAULT_VALUE) {
		cout << "No orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->refOrders.size(); i++) {
		this->refOrders[i].printOrder();
	}
}

void Buyer::rate(System& system, int productID, int rating) const
{
	bool found = false;
	for (size_t i = 0; i < this->IDsAndQuantityOfPurchasedProducts.size(); i++) {
		if (this->IDsAndQuantityOfPurchasedProducts[i].getKey() == productID) {
			found = true;
			break;
		}
	}

	if (found == false) {
		cout << "You have not purchased this product yet!" << endl;
	}
	else {
		Pair<String, int> newRating(this->EGN, rating);
		system.rate(system, productID, newRating);
	}
}
