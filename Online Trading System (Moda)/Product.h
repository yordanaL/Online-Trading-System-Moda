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
	double price;
	int quantity;
	String description;
	double rating;
	bool availability;

	Vector< Pair<String, int> > allRatings;
	int totalSales;

	static int IDGenerator;

public:
	const String& getProductName() const;
	const int getProductID() const;
	const int getTotalSales() const;

	void updateRating(const Pair<String, int>& newRating);

	void displayProduct() const;
	void printProductDetails() const;
};

