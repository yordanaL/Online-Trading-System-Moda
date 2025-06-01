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
