#include "Order.h"

long Order::orderNumberGenerator = DEFAULT_VALUE;

const int Order::getOrderStatus() const
{
    return this->status;
}

const String& Order::getBuyerEGN() const
{
	return this->buyerEGN;
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
