#pragma once
#include <iostream>
using namespace std;
#include "String.h"
#include "Constants.h"
#include "Pair.hpp"
#include "Vector.hpp"
#include "Product.h"

class Cart
{
private:
	//Vector< Pair<Product, int> > products;
	Vector< Pair<int, int> > products;
	//double totalPrice;
	double priceBeforeDiscount = DEFAULT_VALUE;
	double priceAfterDiscount = DEFAULT_VALUE;
	bool discountUsed = false;

public:
	const Vector< Pair<int, int> > getProducts() const;
	const double getPriceBeforeDiscount() const;
	const double getPriceAfterDiscount() const;
	bool getDiscountUsed() const;

	void addProduct(int productID, int quantity);
	void removeProduct(int productID, int quantity);

	void applyDiscount(int loyaltyPoints);

	void cleanCart();
};

