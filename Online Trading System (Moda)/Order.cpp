#include "Order.h"

long Order::orderNumberGenerator = DEFAULT_VALUE;

Order::Order(const Cart& cart, const String& _buyerEGN, const String& buyerName)
{
}

const int Order::getOrderStatus() const
{
    return this->status;
}

const int Order::getOrderNumber() const
{
	return this->orderNumber;
}

const String& Order::getBuyerEGN() const
{
	return this->buyerEGN;
}

const String& Order::getBuyerName() const
{
	return this->buyerName;
}

const double Order::getTotalPrice() const
{
	return this->totalPrice;
}

const int Order::getLoyaltyPointsUsed() const
{
	return this->loyaltyPointsUsed;
}

void Order::updateStatus(int newStatus)
{
	this->status = newStatus;
}

void Order::printOrder() const
{
	for (size_t i = 0; i < this->products.size(); i++) {
		cout << this->products[i].getValue() << "x " << this->products[i].getKey().getProductName() << " ";
	}
	cout << "- " << this->totalPrice << " BGN";
}

void Order::cleanOrder()
{
    this->buyerEGN =EMPTY_STR;
	this->products.clear();
	this->totalPrice = DEFAULT_VALUE;
	this->bonusPoints = DEFAULT_VALUE;
	this->status = NO_STATUS;
	this->discountUsed = false;
	this->orderNumber = DEFAULT_VALUE;
}

void Order::createNewOrder()
{
	this->cleanOrder();
	this->orderNumberGenerator++;
	this->orderNumber = orderNumberGenerator;
}
