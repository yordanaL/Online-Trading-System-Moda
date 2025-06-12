#include "Transaction.h"

Transaction::Transaction(const String& _operation) : operation(_operation)
{
}

void Transaction::printTransaction() const
{
	cout << this->operation << endl;
}
