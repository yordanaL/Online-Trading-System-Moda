#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
#include "String.h"
class System;
class Check;
class Transaction;

class SystemAdministratorOperations
{
public:
	void sendCheck(System& system, const Check& newCheck);
	void customerInsights(System& system);

	void addTransaction(System& system, const String& operation) const;
	void viewTransactions(const System& system) const;
};

