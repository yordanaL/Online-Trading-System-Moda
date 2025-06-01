#include "Product.h"

const String& Product::getProductName() const
{
	return this->name;
}

const int Product::getTotalSales() const
{
	return this->totalSales;
}

void Product::displayProduct() const
{
	cout << " | " << this->name << " | " << this->price << " BGN" 
		<< " | " << this->rating << " stars" << " | " << this->quantity << " pcs";
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
