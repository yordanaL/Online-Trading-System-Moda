#include "SortByPriceDesc.h"

void SortByPriceDesc::sort(Vector<Product>& products)
{
	for (int i = 0; i < products.size() - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < products.size(); j++) {
			if (products[j].getProductPrice() > products[minIndex].getProductPrice())
				minIndex = j;
		}

		swap(products[i], products[minIndex]);
	}
}
