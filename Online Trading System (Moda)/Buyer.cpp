#include "Buyer.h"
#include "System.h"

int Buyer::findIndexOfCheck(const String& code) const
{
	for (size_t i = 0; i < this->receivedChecks.size(); i++) {
		if (this->receivedChecks[i].getCode() == code)
			return i;
	}

	return NOT_FOUND;
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

void Buyer::receiveOrder(const Order& newOrder)
{
	this->shippedOrders.pushBack(newOrder);
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
