#pragma once
#include "Constants.h"
#include "String.h"
#include "Vector.hpp"
#include "Pair.hpp"
#include "Product.h"
class Buyer;
class System;
class Cart;

class Order {
	friend class Buyer;
protected:
	String buyerEGN;
	String buyerName;
	Vector< Pair<int, int> > products; // product ID and quantity
	double totalPrice = DEFAULT_VALUE;
	unsigned int bonusPoints = DEFAULT_VALUE;
	int status = NO_STATUS;
	bool discountUsed = false;
	int loyaltyPointsUsed = DEFAULT_VALUE;
	long orderNumber = DEFAULT_VALUE;

	static long orderNumberGenerator;
public:
	Order() = default;
	Order(const Cart& cart, const String& _buyerEGN, const String& buyerName);

	const int getOrderStatus() const;
	const int getOrderNumber() const;
	const String& getBuyerEGN() const;
	const String& getBuyerName() const;
	const double getTotalPrice() const;
	const int getLoyaltyPointsUsed() const;
	const int getBonusPoints() const;
	const int getProductsCount() const;

	void updateStatus(int newStatus);

	void printOrder(const System& system) const;

	void cleanOrder();
	void createNewOrder();
};

