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
	Vector< Pair<Product, int> > products;
	double totalPrice;
	bool discountUsed;

public:
	const Vector< Pair<Product, int> > getProducts() const;
	const double getTotalPrice() const;
	bool getDiscountUsed() const;
};

