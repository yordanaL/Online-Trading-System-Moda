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

const int Product::getQuantity() const
{
	return this->quantity;
}

void Product::increaseQuantity(int quantity)
{
	this->quantity += quantity;
}

void Product::decreaseQuantity(int quantity)
{
	this->quantity -= quantity;
}

void Product::updateRating(const Pair<String, int>& newRating)
{
	for (size_t i = 0; i < this->allRatings.size(); i++) {
		if (this->allRatings[i].getKey() == newRating.getKey()) {
			return;
			cout << "You have already rated product with ID: " << this->ID << endl;
		}
	}

	this->rating *= this->allRatings.size();
	this->allRatings.pushBack(newRating);
	this->rating += newRating.getValue();
	this->rating /= this->allRatings.size();

	cout << "Rated product with ID: " << this->ID << endl;

	/*this->rating = DEFAULT_VALUE;
	for (size_t i = 0; i < this->allRatings.size(); i++) {
		this->rating += allRatings[i].getValue();
	}
	this->rating /= this->allRatings.size();*/
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
