#include "Seller.h"
#include "System.h"

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

void Seller::receiveOrder(const Order& newOrder)
{
	this->pendingOrders.pushBack(newOrder);
}

void Seller::approveOrder(System& system, int index)
{
	if (index <= DEFAULT_VALUE || index > this->pendingOrders.size()) {
		cout << "Invalid order index!" << endl;
		return;
	}

	this->shippedOrders.pushBack(this->pendingOrders[index - 1]);
	system.shipOrder(system, this->pendingOrders[index - 1]);
	this->pendingOrders.erase(index - 1);

	cout << "Order #" << index << " approved and shipped!" << endl;
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
		}
	}
}

void Seller::viewRevenue() const
{
	cout << "Total revenue: " << this->totalProfit << " BGN" << endl;
}
