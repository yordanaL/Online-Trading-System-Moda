#pragma once
#include "SortStrategy.h"

class SortByPriceDesc : public SortStrategy {
public:
	void sort(Vector<Product>& products) override;
};

