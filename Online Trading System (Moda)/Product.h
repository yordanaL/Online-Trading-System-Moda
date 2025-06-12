#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
#include "String.h"
#include "Pair.hpp"
#include "Vector.hpp"

class Product {
private:
	int ID;
	String name;
	double price = DEFAULT_VALUE;
	int quantity = DEFAULT_VALUE;
	String description;
	double rating = DEFAULT_VALUE;
	bool availability;

	Vector< Pair<String, int> > allRatings;
	int totalSales;

	static int IDGenerator;

public:
	Product() = default;
	Product(const String& _name, double _price, int _quantity, const String& _description);
	const String& getProductName() const;
	const int getProductID() const;
	const int getTotalSales() const;
	const int getQuantity() const;

	void increaseQuantity(int quantity);
	void decreaseQuantity(int quantity);

	void updateRating(const Pair<String, int>& newRating);

	void displayProduct() const;
	void printProductDetails() const;
};

