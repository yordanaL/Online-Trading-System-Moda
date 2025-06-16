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

void Buyer::removeProductFromPurchasedProducts(int productID, int quantity)
{
	if (quantity <= DEFAULT_VALUE) {
		cout << "Invalid quantity!" << endl;
		return;
	}

	for (size_t i = 0; i < this->IDsAndQuantityOfPurchasedProducts.size(); i++) {
		if (this->IDsAndQuantityOfPurchasedProducts[i].getKey() == productID) {
			this->IDsAndQuantityOfPurchasedProducts[i].decreaseValue(quantity);
			return;
		}
	}
}

void Buyer::removeRating(System& system, int productID)
{
	system.removeRating(system, productID, this->EGN);
}

void Buyer::checkBoughtProductsQuantity(System& system)
{
	for (size_t i = 0; i < this->IDsAndQuantityOfPurchasedProducts.size(); i++) {
		if (this->IDsAndQuantityOfPurchasedProducts[i].getValue() <= DEFAULT_VALUE) {
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
	cout << " 01) check-balance       - Check your current account balance" << endl;
	cout << " 02) redeem              - Redeem a code" << endl;
	cout << " 03) list-products       - View all available products" << endl;
	cout << " 04) view-product        - View details of a specific product" << endl;
	cout << " 05) add-to-cart         - Add a product to your shopping cart" << endl;
	cout << " 06) remove-from-cart    - Remove a product from your cart" << endl;
	cout << " 07) apply-discount      - Apply a discount code" << endl;
	cout << " 08) remove-discount     - Remove applied discount" << endl;
	cout << " 09) view-cart           - View the contents of your cart" << endl;
	cout << " 10) checkout            - Proceed to payment and order" << endl;
	cout << " 11) list-orders         - View all your orders shipped by the business" << endl;
	cout << " 12) confirm-order       - Mark an order as delivered" << endl;
	cout << " 13) order-history       - View past delivered and completed orders" << endl;
	cout << " 14) rate                - Rate a purchased product" << endl;
	cout << " 15) request-refund      - Request refund for the latest order placed" << endl;
	cout << " 16) refunded-orders     - View refunded orders" << endl;
	cout << " 17) checks              - View all received checks" << endl;
	cout << " 18) list-shipped-orders - See orders that have been shipped" << endl;
	cout << " 19) sort-by-rating      - Sort products by customer rating" << endl;
	cout << " 20) sort-by-asc         - Sort products by price (low to high)" << endl;
	cout << " 21) sort-by-desc        - Sort products by price (high to low)" << endl;
	cout << " 22) sort-by-alph        - Sort products alphabetically (A-Z)" << endl;
	cout << " 23) logout              - Log out from your account" << endl;
	cout << " 24) help                - Show help for available commands" << endl;
	cout << " 25) view-profile        - View your profile information" << endl;
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

		for (size_t i = 0; i < this->rejectedRefunds.size(); i++) {
			cout << "Order #" << this->rejectedRefunds[i].getOrderNumber() << " - ";
			this->rejectedRefunds[i].printOrder(system);
			cout << " ";
			cout << " | Reason: " << this->rejectedRefunds[i].getRejectionReason() << endl;
		}
	}
	this->rejectedRefunds.clear();
}

void Buyer::checkBalance() const
{
	setToCurrencyPrintFormat();
	cout << "Current balance: " << this->balance << " BGN" << endl;
	resetPrintFormat();
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
	setToCurrencyPrintFormat();
	cout << "Successfully redeemed check. " << this->receivedChecks[checkIndex].getAmount() << " BGN added to your balance!" << endl;
	resetPrintFormat();

	this->receivedChecks.erase(checkIndex);
}

void Buyer::receiveCheck(const Check& newCheck)
{
	this->receivedChecks.pushBack(newCheck);
}

void Buyer::printInsights() const
{
	cout << this->name << " - " << this->finalisedOrdersCount << " purchases, ";
	setToCurrencyPrintFormat();
	cout << this->totalMoneySpent << " BGN spent";
	resetPrintFormat();

	if (this->refundedOrdersCount > DEFAULT_VALUE)
		cout << "(" << this->refundedOrdersCount << " refunded orders)" << endl;
	else
		newLine();
}

void Buyer::listProducts(System& system) const
{
	system.listProducts(system);
}

void Buyer::viewProduct(const System& system, int productID) const
{
	system.viewProduct(system, productID);
}

void Buyer::listProductsSortedByRating(System& system) const
{
	system.listProductsSortedByRating(system);
}

void Buyer::listProductsSortedByPriceAsc(System& system) const
{
	system.listProductsSortedByPriceAsc(system);
}

void Buyer::listProductsSortedByPriceDesc(System& system) const
{
	system.listProductsSortedByPriceDesc(system);
}

void Buyer::listProductsSortedByAlphabeticalOrder(System& system) const
{
	system.listProductsSortedByAlphabeticalOrder(system);
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

void Buyer::viewCart(const System& system)
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
	if (system.isSellerSignedUp(system) == false) {
		cout << "There is no registered business in the system you cannot make a purchase!" << endl;
		return;
	}
	if (this->balance < this->cart.getPriceAfterDiscount()) {
		cout << "You do not have enough balance to make this order!" << endl;
		return;
	}
	if (this->cart.isCartEmpty() == true) {
		cout << "Your cart is empty! Order cannot be placed!" << endl;
		return;
	}

	this->cart.updatePrice(system);

	this->balance -= this->cart.getPriceAfterDiscount();
	this->totalMoneySpent += this->cart.getPriceAfterDiscount();
	Order newOrder(this->cart, this->EGN, this->name);
	sendOrder(system, newOrder);
	cout << "Order placed successfully. Awaiting approval from seller!" << endl;

	this->cart.cleanCart();

	String newTransaction = this->name;
	newTransaction += " sent order.";
	system.addTransaction(system, newTransaction);
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

	this->totalMoneySpent -= newRejectedOrder.getTotalPrice();
	if (this->totalMoneySpent < DEFAULT_VALUE)
		this->totalMoneySpent = DEFAULT_VALUE;

	this->rejectedOrders.pushBack(newRejectedOrder);
	//packAndReturnRejectedOrder(newRejectedOrder);
	//checkBoughtProductsQuantity(system);
}

void Buyer::confirmOrder(System& system, int index)
{
	if (index <= DEFAULT_VALUE || index > this->shippedOrders.size()) {
		cout << "Invalid order index!" << endl;
		return;
	}

	this->shippedOrders[index - 1].updateStatus(DELIVERED);
	this->deliveredOrders.pushBack(this->shippedOrders[index - INDEX_FIX]);
	system.sendConfirmation(system, this->shippedOrders[index - INDEX_FIX].getOrderNumber());

	cout << "Order confirmed as delivered. You received " << (int)this->shippedOrders[index - 1].getBonusPoints()
		<< " loyalty points (5% of ";
	setToCurrencyPrintFormat();
	cout << this->shippedOrders[index - INDEX_FIX].getTotalPrice() << " BGN)" << endl;
	resetPrintFormat();

	this->loyaltyPoints += (int)this->shippedOrders[index - INDEX_FIX].getTotalPrice() * LOYALTY_POINTS_INDEX;
	this->finalisedOrdersCount++;
	//this->totalMoneySpent += this->shippedOrders[index - 1].getTotalPrice();

	this->shippedOrders.erase(index - INDEX_FIX);

	unpackOrder();
	String newTransaction = this->name;
	newTransaction += " made a purchase.";
	system.addTransaction(system, newTransaction);
}

void Buyer::unpackOrder()
{
	int orderIndex = this->deliveredOrders.size() - INDEX_FIX;
	Vector<Pair<int, int>> products = this->deliveredOrders[orderIndex].getProducts();

	for (size_t i = 0; i < products.size(); i++) {
		addProductToPurchasedProducts(products[i].getKey(), products[i].getValue());
	}
}

void Buyer::packAndReturnRejectedOrder(const RejectedOrder& newRejectedOrder)
{
	Vector<Pair<int, int>> products = newRejectedOrder.getProducts();

	for (size_t i = 0; i < products.size(); i++) {
		removeProductFromPurchasedProducts(products[i].getKey(), products[i].getValue());
	}
}

void Buyer::listOrders(const System& system) const
{
	if (this->shippedOrders.size() == DEFAULT_VALUE) {
		cout << "No received orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->shippedOrders.size(); i++) {
		cout << (i + INDEX_FIX) << ". ";
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
		cout << (i + INDEX_FIX) << ". ";
		this->deliveredOrders[i].printOrder(system);
		cout << " - Delivered";
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
		cout << (i + INDEX_FIX) << ". ";
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
		cout << (i + INDEX_FIX) << ". ";
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
		return;
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

	String newTransaction = this->name;
	newTransaction += " requested a refund.";
	system.addTransaction(system, newTransaction);
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

	this->finalisedOrdersCount--;
	this->refundedOrdersCount++;
	this->refOrders.pushBack(order);
	this->totalMoneySpent -= order.getTotalPrice();
	this->loyaltyPoints -= order.getBonusPoints();
	if (this->loyaltyPoints < DEFAULT_VALUE)
		this->loyaltyPoints = DEFAULT_VALUE;
	this->balance += order.getTotalPrice();
	this->loyaltyPoints += order.getLoyaltyPointsUsed();

	//this->refOrders.pushBack(order);
	this->deliveredOrders.erase(orderIndex);
	packAndReturnRefundedOrder(order);
	checkBoughtProductsQuantity(system);
}

void Buyer::packAndReturnRefundedOrder(const Order& newRefund)
{
	Vector<Pair<int, int>> products = newRefund.getProducts();

	for (size_t i = 0; i < products.size(); i++) {
		removeProductFromPurchasedProducts(products[i].getKey(), products[i].getValue());
	}
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
