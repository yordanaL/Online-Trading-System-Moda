#pragma once
#include "Constants.h"
#include "Vector.hpp"
#include "Administrator.h"
#include "Seller.h"
#include "Buyer.h"
#include "Product.h"
#include "SystemOperations.h"
#include "SystemAdministratorOperations.h"
#include "SystemSellerOperations.h"
#include "SystemBuyerOperations.h"

class System : public SystemOperations, public SystemAdministratorOperations, 
	public SystemSellerOperations, public SystemBuyerOperations {
	friend class Administrator;
	friend class SystemOperations;
	friend class SystemAdministratorOperations;
	friend class SystemSellerOperations;
	friend class SystemBuyerOperations;

private:
	Administrator admin;
	Seller seller;
	Vector<Buyer> buyers;
	Vector<Administrator> administrators;
	Vector<Product> products;

	System() = default;
	~System() = default;

	bool isProductIndexValid(int index) const;
	int findIndexOfProductByName(const String& productName) const;
	int findIndexOfProductByID(int productID) const;
	int findIndexOfBuyerByEGN(const String& buyerEGN) const;
	//int findIndexOfBuyerByID(int buyerID) const;

public:
	static System& getInstance();

	System(const System&) = delete;
	System& operator=(const System&) = delete;
};

