#pragma once
#include "Constants.h"
#include "String.h"
#include "Vector.hpp"
#include "Pair.hpp"
class Product;

class Order {
private:
	String buyerEGN;
	Vector< Pair<Product, int> > products;
	double totalPrice;
	unsigned int bonusPoints;
	int status;
	bool discountUsed;
	long orderNumber;

	static long orderNumberGenerator;

public:
	const int getOrderStatus() const;
	const String& getBuyerEGN() const;

	void printOrder() const;

	void cleanOrder();
	void createNewOrder();
};

