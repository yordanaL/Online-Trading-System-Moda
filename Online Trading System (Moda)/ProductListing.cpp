#include "ProductListing.h"

void ProductListing::setStrategy(SortStrategy* _strategy)
{
	this->strategy = _strategy;
}

void ProductListing::list(Vector<Product>& products)
{
	if (strategy != nullptr) {
		strategy->sort(products);
	}

	if (products.size() == DEFAULT_VALUE) {
		cout << "There are no products in the system yet!" << endl;
	}

	for (size_t i = 0; i < products.size(); i++) {
		cout << (i + 1);
		products[i].displayProduct();
		cout << endl;
	}
}
