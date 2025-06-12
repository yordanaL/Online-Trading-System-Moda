#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
#include "FrequentlyUsedFunctions.h"
#include "String.h"
class Command;
class RunSystemAsAdministratorCommand;
class RunSystemAsSellerCommand;
class RunSystemAsBuyerCommand;
class Administrator;
class Seller;
class Buyer;
class System;

class SystemOperations
{
public:
	void login(System& system);
	void logout(System& system);
	void signUp();

	const int getCurrentUserType(System& system) const;

	Administrator* getAdmin(System& system);
	Seller* getSeller(System& system);
	Buyer* getBuyer(System& system);

	void saveToFile();
	void loadFromFile();
};

