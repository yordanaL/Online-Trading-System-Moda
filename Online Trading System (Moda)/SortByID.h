#pragma once
#include "SortStrategy.h"

class SortByID : public SortStrategy {
public:
	void sort(Vector<Product>& products) override;
};

