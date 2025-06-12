#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
#include "String.h"
class Order;
class RejectedOrder;
class System;
class Product;

class SystemSellerOperations
{
public:
	void addItem(System& system, const Product newProduct);
	void removeItem(System& system, const String& productName);

	void listBestSellingProducts(System& system);

	//void sendCheck(System& system, const String& productName);

	void shipOrder(System& system, Order& newOrder);
	void sendRejectedOrder(System& system, const RejectedOrder& newRejectedOrder);

	void sendRefund(System& system, const Order& order);
};

