#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
#include "FrequentlyUsedFunctions.h"
#include "String.h"
class Command;
class RunSystem;
class RunSystemAsAdministratorCommand;
class RunSystemAsSellerCommand;
class RunSystemAsBuyerCommand;
class Registration;
class Transaction;
class Administrator;
class Seller;
class Buyer;
class System;

class SystemOperations
{
public:
	void login(System& system);
	void logout(System& system);
	void signUp(System& system, const String& name, const String& EGN, const String& password, const String& role);
	bool isEGNValid(const String& EGN) const;
	bool isEGNUnique(const System& system, const String& EGN) const;
	bool isNameUnique(const System& system, const String& name) const;
	void viewProfile(System& system);

	const int getCurrentUserType(System& system) const;

	Administrator* getAdmin(System& system);
	const int getAdministratorIndex(const System& system) const;
	Seller* getSeller(System& system);
	const int getSellerIndex(const System& system) const;
	Buyer* getBuyer(System& system);
};

