#pragma once
#include "SortStrategy.h"

class SortByAlphabeticalOrder : public SortStrategy {
public:
	void sort(Vector<Product>& products) override;
};
