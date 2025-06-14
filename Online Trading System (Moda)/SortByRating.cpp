#include "SortByRating.h"

void SortByRating::sort(Vector<Product>& products) 
{
	for (int i = 0; i < products.size() - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < products.size(); j++) {
			if (products[j].getRating() > products[minIndex].getRating())
				minIndex = j;
		}

		swap(products[i], products[minIndex]);
	}
}
