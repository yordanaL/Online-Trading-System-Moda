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
#include "RejectedOrder.h"
#include "Check.h"
class System;

class Buyer : public User {
private:
	Cart cart;
	double balance = DEFAULT_VALUE;
	int loyaltyPoints = DEFAULT_VALUE;

	Vector<Order> shippedOrders;
	Vector<RejectedOrder> rejectedOrders;
	Vector<Order> deliveredOrders;
	Vector<Order> refOrders;

	Vector<Check> receivedChecks;

	Vector<Pair<int, int>> IDsAndQuantityOfPurchasedProducts;

	int finalisedOrdersCount;
	int refundedOrdersCount;
	double totalMoneySpent;

	int findIndexOfCheck(const String& code) const;
	void addProductToPurchasedProducts(int productID, int quantity);

	void removeRating(System& system, int productID);
	void checkBoughtProductsQuantity(System& system);
public:
	Buyer() = default;
	Buyer(const String& _name, const String& _EGN, const String& _password);

	static void help();
	void loginInfo();

	//finance operations
	void checkBalance() const;
	void redeemCheck(const String& code);
	void receiveCheck(const Check& newCheck);
	void printInsights() const;

	//products and sorting operations
	void listProducts(const System& system) const;
	void viewProduct(const System& system, int productID) const;

	void listOrders() const;
	void orderHistory() const;
	void refundedOrders() const;

	//cart and purchases operations
	bool takeProduct(System& system, int productID, int quantity);
	bool returnProduct(System& system, int productID, int quantity);

	void viewCart(const System& system) const;

	void addToCart(System& system, int productID, int quantity);
	void removeFromCart(System& system, int productID, int quantity);

	void applyDiscount();
	void removeDiscount();

	void checkout(System& system);

	void sendOrder(System& system, Order& newOrder);

	void receiveOrder(Order& newOrder);
	void receiveRejectedOrder(const RejectedOrder& newRejectedOrder);

	void confirmOrder(System& system, int index);
	//void sendConfirmation(System& system, int orderNumber) const;
	
	//system connected operations
	void rate(System& system, int productID, int rating) const;
	void requestRefund(System& system);
	void receiveRefund(const Order& order);
};

