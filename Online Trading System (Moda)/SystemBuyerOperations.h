#pragma once
#include "Constants.h"
#include "String.h"
#include "Vector.hpp"
#include "Pair.hpp"
class System;

class SystemBuyerOperations
{
public:
	void listProducts(const System& system) const;
	void viewProduct(const System& system, int productID) const;
	void rate(System& system, int productID, const Pair<String, int>& newRating);
	void sendConfirmation(System& system, int orderNumber) const;
	void requestRefund();
};

