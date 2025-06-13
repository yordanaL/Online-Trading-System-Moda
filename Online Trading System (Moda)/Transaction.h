#pragma once
#include <iostream>
using namespace std;
#include "String.h"

class Transaction {
private:
	String operation;

public:
	Transaction() = default;
	Transaction(const String& _operation);

	void printTransaction() const;

	void save(ofstream& file);
	void load(ifstream& file);
};

