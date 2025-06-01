#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
#include "String.h"
#include "Vector.hpp"
#include "User.h"
#include "Buyer.h"
#include "Cart.h"
#include "Order.h"
#include "Check.h"
class System;

class Buyer : public User {
private:
	Vector<Order> orders;
	Cart cart;
	Vector<Order> refOrders;
	int balance = DEFAULT_VALUE;
	int loyaltyPoints = DEFAULT_VALUE;

	Vector<Check> receivedChecks;

	int finalisedOrdersCount;
	int refundedOrdersCount;
	double totalMoneySpent;

	int findIndexOfCheck(const String& code) const;
public:
	void help() const override;

	//finance operations
	void checkBalance() const;
	void redeemCheck(const String& code);
	//admin operations
	void receiveCheck(const Check& newCheck);
	void printInsights() const;

	//products and sorting operations

	////system connected operations
	void listProducts(const System& system) const;
	void viewProduct(const System& system, int productIndex) const;

	//cart and purchases operations

	//history of purchases and rating operations
	void listOrders() const;
	void confirmOrder();
	void orderHistory() const;
	void refundedOrders() const;
	
	////system connected operations
	void rate(int productID, int rating) const;
	void requestRefund();

};

