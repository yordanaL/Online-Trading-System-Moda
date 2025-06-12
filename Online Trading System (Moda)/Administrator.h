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
	void sendCheck(System& system, double amount, const String& code, const String& clientEGN);

	void customerInsights(System& system);

	static void help();
};
