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
	Vector<Order> deliveredOrders;
	Vector<Order> rejectedOrders;
	Vector<Order> ordersWaitingForRefund;

	double totalProfit;

public:
	Seller() = default;
	Seller(const String& _name, const String& _EGN, const String& _password);

	static void help();

	//System connected
	void addItem(System& system, const Product newProduct);
	void removeItem(System& system, const String& name);

	void listBestSellingProducts(System& system) const;

	void receiveOrder(Order& newOrder);
	void approveOrder(System& system, int index);
	void rejectOrder(System& system, int index, const String& rejectionReason);
	void receiveConfirmation(int orderNumber);

	//Not system connected
	void listOrders(const System& system) const;
	void listPendingOrders(const System& system) const;

	void receiveRefundRequest(const Order& order);
	void listRefunds(const System& system) const;
	void approveRefund(System& system, int orderIndex);
	void rejectRefund(System& system, int orderIndex, const String& rejectionReason);

	void viewRevenue() const;
};

