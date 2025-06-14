#pragma once
#include "Constants.h"
#include "String.h"
#include "Vector.hpp"
#include "Pair.hpp"
#include "Order.h"
#include "ProductListing.h"
#include "SortStrategy.h"
#include "SortByRating.h"
#include "SortByPriceAsc.h"
#include "SortByPriceDesc.h"
#include "SortByAlphabeticalOrder.h"
#include "SortByID.h"
class System;

class SystemBuyerOperations
{
public:
	bool isSellerSignedUp(const System& system);

	void listProducts(System& system) const;
	void viewProduct(const System& system, int productID) const;

	void listProductsSortedByRating(System& system) const;
	void listProductsSortedByPriceAsc(System& system) const;
	void listProductsSortedByPriceDesc(System& system) const;
	void listProductsSortedByAlphabeticalOrder(System& system) const;

	void rate(System& system, int productID, const Pair<String, int>& newRating);
	void removeRating(System& system, int productID, const String& buyerEGN);

	void sendOrder(System& system, Order& newOrder);
	void sendConfirmation(System& system, int orderNumber) const;

	const String getProductNameByID(const System& system, int productID) const;
	const double getProductPriceByID(const System& system, int productID) const;

	bool takeProduct(System& system, int productID, int quantity);
	bool returnProduct(System& system, int productID, int quantity);

	void requestRefund(System& system, Order& order);
};

