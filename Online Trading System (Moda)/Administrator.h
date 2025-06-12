#pragma once
#include "Vector.hpp"
#include "String.h"
#include "User.h"
class Check;
class System;

class Administrator : public User {
private:
	Vector<String> sentChecksCodes;

public:
	Administrator() = default;
	Administrator(const String& _name, const String& _EGN, const String& _password);

	void sendCheck(System& system, double amount, const String& code, const String& clientEGN);
	void customerInsights(System& system);

	void viewTransactions(const System& system);

	static void help();
};
