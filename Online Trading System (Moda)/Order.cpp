#include "Order.h"
#include "System.h"

long Order::orderNumberGenerator = DEFAULT_VALUE;

Order::Order(const Cart& cart, const String& _buyerEGN, const String& _buyerName)
{
	this->buyerEGN = _buyerEGN;
	this->buyerName = _buyerName;
	this->products = cart.getProducts();
	this->totalPrice = cart.getPriceAfterDiscount();
	this->bonusPoints = this->totalPrice * LOYALTY_POINTS_INDEX;
	this->status = PENDING;
	this->discountUsed = cart.getDiscountUsed();
	this->loyaltyPointsUsed = cart.getloyaltyPointsUsed();
	orderNumberGenerator++;
	this->orderNumber = orderNumberGenerator;
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

const int Order::getBonusPoints() const
{
	return this->bonusPoints;
}

const int Order::getProductsCount() const
{
	return this->products.size();
}

const bool Order::getDiscountUsed() const
{
	return this->discountUsed;
}

void Order::updateStatus(int newStatus)
{
	this->status = newStatus;
}

void Order::printOrder(const System& system) const
{
	for (size_t i = 0; i < this->products.size(); i++) {
		cout << this->products[i].getValue() << "x ";
		cout << system.getProductNameByID(system, this->products[i].getKey());
		cout << " ";
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

void Order::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->buyerEGN.save(file);
	this->buyerName.save(file);
	this->products.save(file);
	file << this->totalPrice << endl;
	file << this->bonusPoints << endl;
	file << this->status << endl; 
	file << this->discountUsed << endl;
	file << this->loyaltyPointsUsed << endl;
	file << this->orderNumber << endl;

	file << orderNumberGenerator << endl;
}

void Order::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->buyerEGN.load(file);
	this->buyerName.load(file);
	this->products.load(file);
	file >> this->totalPrice;
	file >> this->bonusPoints;
	file >> this->status;
	file >> this->discountUsed;
	file >> this->loyaltyPointsUsed;
	file >> this->orderNumber;

	file >> orderNumberGenerator;
}

