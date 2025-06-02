#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
#include "String.h"

class Product {
private:
	int ID;
	String name;
	double price;
	int quantity;
	String description;
	double rating;
	bool availability;

	int totalSales;
	static int IDGenerator;

public:
	const String& getProductName() const;
	const int getProductID() const;
	const int getTotalSales() const;

	void displayProduct() const;
	void printProductDetails() const;
};

