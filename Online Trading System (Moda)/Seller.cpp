#include "Seller.h"
#include "System.h"

void Seller::help()
{
	cout << "Business Commands: " << endl;
	cout << " 1) add-item" << endl;
	cout << " 2) remove-item" << endl;
	cout << " 3) list-pending-orders" << endl;
	cout << " 4) approve-order" << endl;
	cout << " 5) reject-order" << endl;
	cout << " 6) list-orders" << endl;
	cout << " 7) list-best-selling-products" << endl;
	cout << " 8) view-revenue" << endl;
	cout << " 9) list-refunds" << endl;
	cout << "10) approve-refund" << endl;
	cout << "11) reject-refund" << endl;
	cout << "12) logout" << endl;
	cout << "13) help" << endl;
	cout << "14) view-profile" << endl;
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

	this->pendingOrders[index - 1].updateStatus(SHIPPED);
	this->shippedOrders.pushBack(this->pendingOrders[index - 1]);
	system.shipOrder(system, this->pendingOrders[index - 1]);
	this->pendingOrders.erase(index - 1);

	cout << "Order #" << index << " approved and shipped!" << endl;
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

void Seller::listOrders() const
{
	int index = DEFAULT_VALUE;
	for (size_t i = 0; i < this->pendingOrders.size(); i++) {
		index++;
		cout << index << ". " << this->pendingOrders[i].getBuyerName() << " ";
		this->pendingOrders[i].printOrder();
		cout << index << " - Pending" << endl;
	}

	for (size_t i = 0; i < this->shippedOrders.size(); i++) {
		index++;
		cout << index << ". ";
		this->shippedOrders[i].printOrder();
		cout << index << " - Shipped" << endl;
	}

	for (size_t i = 0; i < this->deliveredOrders.size(); i++) {
		index++;
		cout << index << ". ";
		this->deliveredOrders[i].printOrder();
		cout << index << " - Delivered" << endl;
	}

	for (size_t i = 0; i < this->rejectedOrders.size(); i++) {
		index++;
		cout << index << ". ";
		this->rejectedOrders[i].printOrder();
		cout << index << " - Rejected" << endl;
	}
}

void Seller::listPendingOrders() const
{
	if (this->pendingOrders.empty()) {
		cout << "No orders yet!" << endl;
		return;
	}

	for (size_t i = 0; i < pendingOrders.size(); i++) {
		if (pendingOrders[i].getOrderStatus() == PENDING) {
			cout << (i + INDEX_FIX) << ". ";
			pendingOrders[i].printOrder();
			cout << endl;
		}
	}
}

void Seller::viewRevenue() const
{
	cout << "Total revenue: " << this->totalProfit << " BGN" << endl;
}
