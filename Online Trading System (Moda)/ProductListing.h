#pragma once
#include "SortStrategy.h"
#include "Vector.hpp"
#include "Product.h"

class ProductListing {
private:
	SortStrategy* strategy;

public:
	void setStrategy(SortStrategy* _strategy);
	void list(Vector<Product>& products);
};

