#pragma once
#include "Constants.h"
#include "Vector.hpp"
class Product;

class Order {
private:
	Vector<Product> products;
	double totalPrice;
	unsigned int bonusPoints;
	OrderStatus status;

public:
	OrderStatus getOrderStatus() const;
	void printOrder() const;
};

