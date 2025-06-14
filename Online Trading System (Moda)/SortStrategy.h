#pragma once
#include "Vector.hpp"
#include "Product.h"

class SortStrategy {
public:
	virtual void sort(Vector<Product>& products) = 0;
	virtual ~SortStrategy() = default;
};

