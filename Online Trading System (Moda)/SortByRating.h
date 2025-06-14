#pragma once
#include "SortStrategy.h"

class SortByRating : public SortStrategy {
public:
	void sort(Vector<Product>& products) override;
};

