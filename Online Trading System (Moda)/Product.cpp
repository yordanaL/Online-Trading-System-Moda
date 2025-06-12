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

const double Product::getProductPrice() const
{
	return this->price;
}

Product::Product(const String& _name, double _price, int _quantity, const String& _description)
	: name(_name), price(_price), quantity(_quantity), description(_description)
{
	if (_quantity > DEFAULT_VALUE)
		this->availability = true;
	else
		this->availability = false;

	IDGenerator++;
	this->ID = IDGenerator;
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
			cout << "You have already rated product with ID: " << this->ID << endl;
			return;
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

void Product::removeRating(const String& buyerEGN)
{
	int index = NOT_FOUND;
	for (size_t i = 0; i < this->allRatings.size(); i++) {
		if (this->allRatings[i].getKey() == buyerEGN) {
			index = i;
			break;
		}
	}

	this->allRatings.erase(index);

	this->rating = DEFAULT_VALUE;
	for (size_t i = 0; i < this->allRatings.size(); i++) {
		this->rating += this->allRatings[i].getValue();
	}

	this->rating /= this->allRatings.size();
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
		<< "Description: " << this->description << endl;
}
