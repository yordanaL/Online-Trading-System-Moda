#pragma once
#include "Constants.h"
#include "String.h"
#include "Vector.hpp"
#include "Pair.hpp"
#include "Product.h"
class Cart;

class Order {
private:
	String buyerEGN;
	String buyerName;
	Vector< Pair<Product, int> > products;
	double totalPrice = DEFAULT_VALUE;
	unsigned int bonusPoints = DEFAULT_VALUE;
	int status = NO_STATUS;
	bool discountUsed = false;
	int loyaltyPointsUsed = DEFAULT_VALUE;
	long orderNumber = DEFAULT_VALUE;

	static long orderNumberGenerator;

public:
	Order() = default;
	Order(const Cart& cart);

	const int getOrderStatus() const;
	const int getOrderNumber() const;
	const String& getBuyerEGN() const;
	const String& getBuyerName() const;
	const double getTotalPrice() const;
	const double getLoyaltyPointsUsed() const;

	void updateStatus(int newStatus);

	void printOrder() const;

	void cleanOrder();
	void createNewOrder();
};

