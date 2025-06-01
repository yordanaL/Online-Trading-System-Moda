#include "SystemBuyerOperations.h"
#include "System.h"

void SystemBuyerOperations::listProducts(const System& system) const
{
	for (size_t i = 0; i < system.products.size(); i++) {
		cout << (i + 1);
		system.products[i].displayProduct();
	}
}

void SystemBuyerOperations::viewProduct(const System& system, int productIndex) const
{
	if (system.isProductIndexValid(productIndex) == false) {
		cout << "This product does not exist!" << endl;
	}
	else
		system.products[productIndex].printProductDetails();
}
