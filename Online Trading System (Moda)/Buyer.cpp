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
	if (quantity <= DEFAULT_VALUE) {
		cout << "Invalid quantity!" << endl;
		return;
	}

	for (size_t i = 0; i < this->IDsAndQuantityOfPurchasedProducts.size(); i++) {
		if (this->IDsAndQuantityOfPurchasedProducts[i].getKey() == productID) {
			this->IDsAndQuantityOfPurchasedProducts[i].increaseValue(quantity);
			return;
		}
	}

	Pair<int, int> newPurchasedProduct(productID, quantity);
	this->IDsAndQuantityOfPurchasedProducts.pushBack(newPurchasedProduct);
}

void Buyer::removeRating(System& system, int productID)
{
	system.removeRating(system, productID, this->EGN);
}

void Buyer::checkBoughtProductsQuantity(System& system)
{
	for (size_t i = 0; i < this->IDsAndQuantityOfPurchasedProducts.size(); i++) {
		if (this->IDsAndQuantityOfPurchasedProducts[i].getValue() == DEFAULT_VALUE) {
			removeRating(system, this->IDsAndQuantityOfPurchasedProducts[i].getKey());
		}
	}
}

Buyer::Buyer(const String& _name, const String& _EGN, const String& _password) :User(_name, _EGN, _password)
{
}

void Buyer::help()
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
	cout << "17) checks" << endl;
	cout << "18) list-shipped-orders" << endl;
	cout << "19) logout" << endl;
	cout << "20) help" << endl;
	cout << "21) view-profile" << endl;
}

void Buyer::loginInfo(const System& system)
{
	if (this->rejectedOrders.size() > DEFAULT_VALUE) {
		cout << "You have a rejected order/s: " << endl;

		for (size_t i = 0; i < this->rejectedOrders.size(); i++)	{
			cout << "Order #" << this->rejectedOrders[i].getOrderNumber() << " - ";
			this->rejectedOrders[i].printOrder(system);
			cout << " ";
			cout << " | Reason: " << this->rejectedOrders[i].getRejectionReason() << endl;

			this->balance += this->rejectedOrders[i].getTotalPrice();
			this->loyaltyPoints += this->rejectedOrders[i].getLoyaltyPointsUsed();
		}
	}
	this->rejectedOrders.clear();

	if (this->rejectedRefunds.size() > DEFAULT_VALUE) {
		cout << "You have a rejected refund/s: " << endl;

		for (size_t i = 0; i < this->rejectedOrders.size(); i++) {
			cout << "Order #" << this->rejectedOrders[i].getOrderNumber() << " - ";
			this->rejectedOrders[i].printOrder(system); 
			cout << " ";
			cout << " | Reason: " << this->rejectedOrders[i].getRejectionReason() << endl;
		}
	}
	this->rejectedOrders.clear();
}

void Buyer::checkBalance() const
{
	cout << "Current balance: " << this->balance << " BGN" << endl;
	cout << "Loyalty points: " << this->loyaltyPoints << endl;
}

void Buyer::checks() const
{
	if (this->receivedChecks.size() == DEFAULT_VALUE) {
		cout << "You have not received any checks yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->receivedChecks.size(); i++) {
		cout << (i + INDEX_FIX) << ". ";
		cout << this->receivedChecks[i].getCode();
		newLine();
	}
}

void Buyer::redeemCheck(const String& code)
{
	int checkIndex = findIndexOfCheck(code);

	if (checkIndex == NOT_FOUND) {
		cout << "Invalid code!" << endl;
		return;
	}

	this->balance += this->receivedChecks[checkIndex].getAmount();
	cout << "Successfully redeemed check. " << this->receivedChecks[checkIndex].getAmount() << " BGN added to your balance!" << endl;

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
		newLine();
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
	if (quantity <= DEFAULT_VALUE) {
		cout << "Invalid quantity!" << endl;
		return UNSUCCESSFUL;
	}

	return system.takeProduct(system, productID, quantity);
}

bool Buyer::returnProduct(System& system, int productID, int quantity)
{
	if (quantity <= DEFAULT_VALUE) {
		cout << "Invalid quantity!" << endl;
		return UNSUCCESSFUL;
	}

	return system.returnProduct(system, productID, quantity);
}

void Buyer::viewCart(const System& system) const
{
	this->cart.viewCart(system);
}

void Buyer::addToCart(System& system, int productID, int quantity)
{
	if (quantity <= DEFAULT_VALUE) {
		cout << "Invalid quantity!" << endl;
		return;
	}

	bool operationSuccess = takeProduct(system, productID, quantity);
	if (operationSuccess == UNSUCCESSFUL) {
		cout << "Could not add product to cart!" << endl;
		return;
	}

	this->cart.addProduct(system, productID, quantity);
	cout << "Product added to cart successfully!" << endl;
}

void Buyer::removeFromCart(System& system, int productID, int quantity)
{
	if (quantity <= DEFAULT_VALUE) {
		cout << "Invalid quantity!" << endl;
		return;
	}

	if (this->cart.checkProductQuantityInCart(productID) < quantity) {
		cout << "You do not have so many pcs in cart!" << endl;
		return;
	}

	bool operationSuccess = returnProduct(system, productID, quantity);
	if (operationSuccess == UNSUCCESSFUL) {
		cout << "Could not remove product from cart!" << endl;
		return;
	}

	this->cart.removeProduct(system, productID, quantity);
	cout << "Product removed from cart successfully!" << endl;
}

void Buyer::applyDiscount()
{
	if (loyaltyPoints <= DEFAULT_VALUE) {
		cout << "You have no loyalty points!" << endl;
		return;
	}

	if (this->cart.getDiscountUsed() == true) {
		cout << "You have already used a discount for this order!" << endl;
		return;
	}

	if (loyaltyPoints * DISCOUNT_INDEX <= (this->cart.getPriceBeforeDiscount() / 2)) {
		this->cart.applyDiscount(this->loyaltyPoints);
		this->loyaltyPoints = DEFAULT_VALUE;
	}
	else {
		int pointsNeeded = (this->cart.getPriceBeforeDiscount() / 2) / DISCOUNT_INDEX;
		this->cart.applyDiscount(pointsNeeded);
		this->loyaltyPoints -= pointsNeeded;

		if (this->loyaltyPoints <= DEFAULT_VALUE)
			this->loyaltyPoints = DEFAULT_VALUE;
	}
}

void Buyer::removeDiscount()
{
	if (this->cart.getDiscountUsed() == false) {
		cout << "You have not used a discount for this order!" << endl;
		return;
	}

	this->loyaltyPoints += this->cart.getloyaltyPointsUsed();
	this->cart.removeDiscount();
}

void Buyer::checkout(System& system)
{
	if (this->balance < this->cart.getPriceAfterDiscount()) {
		cout << "You do not have enough balance to make this order!" << endl;
		return;
	}

	if (this->cart.isCartEmpty() == true) {
		cout << "Your cart is empty! Order cannot be placed!" << endl;
		return;
	}

	this->balance -= this->cart.getPriceAfterDiscount();
	Order newOrder(this->cart, this->EGN, this->name);
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

void Buyer::receiveRejectedOrder(System& system, const RejectedOrder& newRejectedOrder)
{
	for (size_t i = 0; i < newRejectedOrder.getProductsCount(); i++) {
		returnProduct(system, newRejectedOrder.products[i].getKey(), newRejectedOrder.products[i].getValue());
	}

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

	cout << "Order confirmed as delivered. You received " << (int)this->shippedOrders[index - 1].getBonusPoints()
		<< " loyalty points (5% of " << this->shippedOrders[index - 1].getTotalPrice() << " BGN)" << endl;

	this->loyaltyPoints += (int)this->shippedOrders[index - 1].getTotalPrice() * LOYALTY_POINTS_INDEX;
	this->finalisedOrdersCount++;
	this->totalMoneySpent += this->shippedOrders[index - 1].getTotalPrice();

	this->shippedOrders.erase(index - 1);

	String newTransaction = this->name;
	newTransaction += " made purchase";
	system.addTransaction(system, newTransaction);
}

void Buyer::listOrders(const System& system) const
{
	if (this->shippedOrders.size() == DEFAULT_VALUE) {
		cout << "No received orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->shippedOrders.size(); i++) {
		this->shippedOrders[i].printOrder(system);
		newLine();
	}
}

void Buyer::orderHistory(const System& system) const
{
	if (this->deliveredOrders.size() == DEFAULT_VALUE) {
		cout << "No orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->deliveredOrders.size(); i++) {
		this->deliveredOrders[i].printOrder(system);
		newLine();
	}
}

void Buyer::refundedOrders(const System& system) const
{
	if (this->refOrders.size() == DEFAULT_VALUE) {
		cout << "No orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->refOrders.size(); i++) {
		this->refOrders[i].printOrder(system);
		newLine();
	}
}

void Buyer::listShippedOrders(const System& system) const
{
	if (this->refOrders.size() == DEFAULT_VALUE) {
		cout << "No orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->shippedOrders.size(); i++) {
		this->shippedOrders[i].printOrder(system);
		newLine();
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

void Buyer::requestRefund(System& system)
{
	if (this->deliveredOrders.size() <= DEFAULT_VALUE) {
		cout << "You have not made any orders yet!" << endl;
		return;
	}

	if (this->deliveredOrders[this->deliveredOrders.size() - INDEX_FIX].getDiscountUsed() == true)
		this->loyaltyPoints = DEFAULT_VALUE;

	cout << "Request refund is sent! Waiting for approval from business!" << endl;
	system.requestRefund(system, this->deliveredOrders[this->deliveredOrders.size() - INDEX_FIX]);
}

void Buyer::receiveRefund(System& system, const Order& order)
{
	int orderIndex = NOT_FOUND;
	for (int i = 0; i < this->deliveredOrders.size(); i++) {
		if (this->deliveredOrders[i].getOrderNumber() == order.getOrderNumber())
			orderIndex = i;
	}

	if (orderIndex == NOT_FOUND) {
		cout << "Order cannot be found!" << endl;
		return;
	}

	for (size_t i = 0; i < order.getProductsCount(); i++) {
		returnProduct(system, order.products[i].getKey(), order.products[i].getValue());
	}

	this->balance += order.getTotalPrice();
	this->loyaltyPoints += order.getLoyaltyPointsUsed();
	this->deliveredOrders.erase(orderIndex);
}

void Buyer::receiveRefundRejection(const RejectedOrder& newRejectedRefund)
{
	this->rejectedRefunds.pushBack(newRejectedRefund);
}

void Buyer::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	User::save(file);

	this->cart.save(file);
	file << this->balance << endl;
	file << this->loyaltyPoints << endl;

	this->shippedOrders.save(file);
	this->deliveredOrders.save(file);
	this->refOrders.save(file);

	this->rejectedOrders.save(file);
	this->rejectedRefunds.save(file);

	this->receivedChecks.save(file);

	this->IDsAndQuantityOfPurchasedProducts.save(file);

	file << this->finalisedOrdersCount << endl;
	file << this->refundedOrdersCount << endl;
	file << this->totalMoneySpent << endl;
}

void Buyer::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	User::load(file);

	this->cart.load(file);
	file >> this->balance;
	file >> this->loyaltyPoints;

	this->shippedOrders.load(file);
	this->deliveredOrders.load(file);
	this->refOrders.load(file);

	this->rejectedOrders.load(file);
	this->rejectedRefunds.load(file);

	this->receivedChecks.load(file);

	this->IDsAndQuantityOfPurchasedProducts.load(file);

	file >> this->finalisedOrdersCount;
	file >> this->refundedOrdersCount;
	file >> this->totalMoneySpent;
}
