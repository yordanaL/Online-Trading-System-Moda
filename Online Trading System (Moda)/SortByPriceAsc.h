#pragma once
#include "SortStrategy.h"

class SortByPriceAsc : public SortStrategy {
public:
	void sort(Vector<Product>& products) override;
};

