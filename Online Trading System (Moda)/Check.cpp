#include "Check.h"

Check::Check() :amount(DEFAULT_VALUE), code(), buyerIndex(NOT_FOUND)
{ 
}

Check::Check(double _amount, const String& _code, int _buyerIndex)
	: amount(_amount), code(_code), buyerIndex(_buyerIndex)
{
}

const double Check::getAmount() const
{
	return this->amount;
}

const String& Check::getCode() const
{
	return this->code;
}

const int Check::getBuyerIndex() const
{
	return this->buyerIndex;
}

void Check::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	file << this->amount << endl;
	this->code.save(file);
	file << this->buyerIndex << endl;
}

void Check::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	file >> this->amount;
	this->code.load(file);
	file >> this->buyerIndex;
}
