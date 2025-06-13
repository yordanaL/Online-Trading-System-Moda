#include "Transaction.h"

Transaction::Transaction(const String& _operation) : operation(_operation)
{
}

void Transaction::printTransaction() const
{
	cout << this->operation << endl;
}

void Transaction::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->operation.save(file);
}

void Transaction::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->operation.load(file);
}
