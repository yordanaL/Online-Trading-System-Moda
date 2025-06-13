#pragma once
#include <fstream>
#include "Constants.h"
#include "String.h"

class Check {
private: 
	double amount;
	String code;
	int buyerIndex;

public:
	Check();
	Check(double _amount, const String& _code, int _clientEGN);

	const double getAmount() const;
	const String& getCode() const;
	const int getBuyerIndex() const;

	void save(ofstream& file);
	void load(ifstream& file);
};

