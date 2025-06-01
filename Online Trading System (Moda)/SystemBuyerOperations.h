#pragma once
class System;

class SystemBuyerOperations
{
public:
	void listProducts(const System& system) const;
	void viewProduct(const System& system, int productIndex) const;
	void rate(int productID, int rating);
	void requestRefund();
};

