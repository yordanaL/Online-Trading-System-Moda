#include "Product.h"

int Product::IDGenerator = DEFAULT_VALUE;

const String& Product::getProductName() const
{
	return this->name;
}

const int Product::getProductID() const
{
	return this->ID;
}

const int Product::getTotalSales() const
{
	return this->totalSales;
}

void Product::displayProduct() const
{
	cout << " | " << this->name << " | " << this->price << " BGN" << " | " << this->rating <<
		" stars" << " | " << this->quantity << " pcs" << " | product ID: " <<this->ID;
}

void Product::printProductDetails() const
{
	cout << "ID: " << this->ID << endl
		<< "Product Name: " << this->name << endl
		<< "Price: " << this->price << " BGN" << endl
		<< "Stock: " << this->quantity << " pcs" << endl
		<< "Rating: " << this->rating << " stars" << endl
		<< "Description: " << this->description << " pcs" << endl;
}
