#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
#include "User.h"
#include "String.h"
#include "Vector.hpp"
#include "Order.h"
#include "Product.h"
class System;

class Seller : public User {
private:
	Vector<Order> pendingOrders;
	Vector<Order> shippedOrders;

	double totalProfit;

public:
	void help() const override;

	//System connected
	void addItem(System& system, const Product newProduct);
	void removeItem(System& system, const String& name);

	void listBestSellingProducts(System& system) const;
	void approveOrder(int index);

	//Not system connected
	void listPendingOrders() const;

	void viewRevenue() const;
};

