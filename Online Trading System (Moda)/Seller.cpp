#include "Seller.h"
#include "System.h"

int Seller::findOrderByOrderNumber(int orderNumber)
{
	for (size_t i = 0; i < this->deliveredOrders.size(); i++) {
		if (this->deliveredOrders[i].getOrderNumber() == orderNumber)
			return i;
	}

	return NOT_FOUND;
}

Seller::Seller(const String& _name, const String& _EGN, const String& _password) :User(_name, _EGN, _password)
{
}

void Seller::help()
{
	cout << "Business Commands: " << endl;
	cout << " 01) add-item                   - Add a new product to your store" << endl;
	cout << " 02) remove-item                - Remove an existing product" << endl;
	cout << " 03) list-pending-orders        - View orders awaiting approval" << endl;
	cout << " 04) approve-order              - Approve a customer's pending order" << endl;
	cout << " 05) reject-order               - Reject a customer's pending order" << endl;
	cout << " 06) list-orders                - View all orders" << endl;
	cout << " 07) list-best-selling-products - View your top-selling products" << endl;
	cout << " 08) view-revenue               - See your total generated revenue" << endl;
	cout << " 09) list-refunds               - View all refund requests" << endl;
	cout << " 10) approve-refund             - Approve a refund request" << endl;
	cout << " 11) reject-refund              - Reject a refund request" << endl;
	cout << " 12) logout                     - Log out of your business account" << endl;
	cout << " 13) help                       - Show help for available commands" << endl;
	cout << " 14) view-profile               - View your business profile" << endl;
}

void Seller::addItem(System& system, const Product newProduct)
{
	system.addItem(system, newProduct);
}

void Seller::removeItem(System& system, const String& name)
{
	system.removeItem(system, name);
}

void Seller::listBestSellingProducts(System& system) const
{
	system.listBestSellingProducts(system);
}

void Seller::receiveOrder(Order& newOrder)
{
	newOrder.updateStatus(PENDING);
	this->pendingOrders.pushBack(newOrder);
}

void Seller::approveOrder(System& system, int index)
{
	if (index <= DEFAULT_VALUE || index > this->pendingOrders.size()) {
		cout << "Invalid order index!" << endl;
		return;
	}

	this->pendingOrders[index - INDEX_FIX].updateStatus(SHIPPED);
	this->shippedOrders.pushBack(this->pendingOrders[index - INDEX_FIX]);
	system.shipOrder(system, this->pendingOrders[index - INDEX_FIX]);
	this->pendingOrders.erase(index - INDEX_FIX);

	cout << "Order #" << index << " approved and shipped!" << endl;

	String newTransaction = "Business approved order.";
	system.addTransaction(system, newTransaction);
}

void Seller::rejectOrder(System& system, int index, const String& rejectionReason)
{
	if (index <= DEFAULT_VALUE || index > this->pendingOrders.size()) {
		cout << "Invalid order index!" << endl;
		return;
	}

	this->pendingOrders[index - 1].updateStatus(REJECTED);
	this->rejectedOrders.pushBack(this->pendingOrders[index - 1]);

	RejectedOrder newRejectedOrder(this->pendingOrders[index - 1], rejectionReason);

	system.sendRejectedOrder(system, newRejectedOrder);
	this->pendingOrders.erase(index - 1);
	cout << "Order #" << index << " rejected with reason: " << rejectionReason << endl;

	String newTransaction = "Business rejected order with reason: ";
	newTransaction += rejectionReason;
	newTransaction += ".";
	system.addTransaction(system, newTransaction);
}

void Seller::receiveConfirmation(int orderNumber)
{
	for (int i = 0; i < this->shippedOrders.size(); i++) {
		if (this->shippedOrders[i].getOrderNumber() == orderNumber) {
			this->shippedOrders[i].updateStatus(DELIVERED);
			this->deliveredOrders.pushBack(this->shippedOrders[i]);

			this->totalProfit += shippedOrders[i].getTotalPrice();
			this->shippedOrders.erase(i);

			break;
		}
	}
}

void Seller::listOrders(const System& system) const
{
	int index = DEFAULT_VALUE;
	for (size_t i = 0; i < this->pendingOrders.size(); i++) {
		index++;
		cout << index << ". " << this->pendingOrders[i].getBuyerName() << " ";
		this->pendingOrders[i].printOrder(system);
		cout << " - Pending" << endl;
	}

	for (size_t i = 0; i < this->shippedOrders.size(); i++) {
		index++;
		cout << index << ". ";
		this->shippedOrders[i].printOrder(system);
		cout << " - Shipped" << endl;
	}

	for (size_t i = 0; i < this->deliveredOrders.size(); i++) {
		index++;
		cout << index << ". ";
		this->deliveredOrders[i].printOrder(system);
		cout << " - Delivered" << endl;
	}

	for (size_t i = 0; i < this->rejectedOrders.size(); i++) {
		index++;
		cout << index << ". ";
		this->rejectedOrders[i].printOrder(system);
		cout << " - Rejected" << endl;
	}
}

void Seller::listPendingOrders(const System& system) const
{
	if (this->pendingOrders.empty()) {
		cout << "No orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < this->pendingOrders.size(); i++) {
		if (this->pendingOrders[i].getOrderStatus() == PENDING) {
			cout << (i + INDEX_FIX) << ". ";
			this->pendingOrders[i].printOrder(system);

			/*if (i != this->pendingOrders.size() - INDEX_FIX)
				cout << endl;
			if (this->pendingOrders.size() == DEFAULT_VALUE)
				cout << endl;*/

			newLine();
		}
	}
}

void Seller::receiveRefundRequest(const Order& order)
{
	this->ordersWaitingForRefund.pushBack(order);
}

void Seller::listRefunds(const System& system) const
{
	if (ordersWaitingForRefund.size() == DEFAULT_VALUE) {
		cout << "You have not received any refund requeests yet!" << endl;
		return;
	}

	for (size_t i = 0; i < ordersWaitingForRefund.size(); i++) {
		cout << (i + INDEX_FIX) << ". ";
		ordersWaitingForRefund[i].printOrder(system);

		newLine();
	}
}

void Seller::approveRefund(System& system, int orderIndex)
{
	if (orderIndex <= DEFAULT_VALUE || orderIndex > this->ordersWaitingForRefund.size()) {
		cout << "Invalid order index!" << endl;
		return;
	}

	int localOrderIndex = findOrderByOrderNumber(this->ordersWaitingForRefund[orderIndex - INDEX_FIX].getOrderNumber());
	if (localOrderIndex == NOT_FOUND) {
		cout << "You have not received such order! You cannot refund!" << endl;
		return;
	}
	else {
		this->deliveredOrders.erase(localOrderIndex);
	}

	this->totalProfit -= this->ordersWaitingForRefund[orderIndex - INDEX_FIX].getTotalPrice();
	cout << "Refund is approved successfully!" << endl;
	system.sendRefund(system, this->ordersWaitingForRefund[orderIndex - INDEX_FIX]);
	this->ordersWaitingForRefund.erase(orderIndex - INDEX_FIX);

	String newTransaction = "Business approved refund.";
	system.addTransaction(system, newTransaction);
}

void Seller::rejectRefund(System& system, int orderIndex, const String& rejectionReason)
{
	if (orderIndex <= DEFAULT_VALUE || orderIndex > this->ordersWaitingForRefund.size()) {
		cout << "Invalid order index!" << endl;
		return;
	}

	RejectedOrder newRejectedRefund(this->ordersWaitingForRefund[orderIndex - INDEX_FIX], rejectionReason);

	system.rejectRefund(system, newRejectedRefund);
	this->ordersWaitingForRefund.erase(orderIndex - INDEX_FIX);
	cout << "Refund #" << orderIndex << " rejected with reason: " << rejectionReason << endl;

	String newTransaction = "Business rejected refund with reason: ";
	newTransaction += rejectionReason;
	newTransaction += ".";
	system.addTransaction(system, newTransaction);
}

void Seller::viewRevenue() const
{
	setToCurrencyPrintFormat();
	cout << "Total revenue: " << this->totalProfit << " BGN" << endl;
	resetPrintFormat();
}

void Seller::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->pendingOrders.save(file);
	this->shippedOrders.save(file);
	this->deliveredOrders.save(file);
	this->rejectedOrders.save(file);
	this->ordersWaitingForRefund.save(file);
	file << this->totalProfit << endl;
}

void Seller::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->pendingOrders.load(file);
	this->shippedOrders.load(file);
	this->deliveredOrders.load(file);
	this->rejectedOrders.load(file);
	this->ordersWaitingForRefund.load(file);
	file >> this->totalProfit;
}
