#include "SystemAdministratorOperations.h"
#include "System.h"
#include "Check.h"
#include "Transaction.h"

void SystemAdministratorOperations::sendCheck(System& system, const Check& newCheck)
{
	system.buyers[newCheck.getBuyerIndex()].receiveCheck(newCheck);
	cout << "Check sent successfully!" << endl;
}

void SystemAdministratorOperations::customerInsights(System& system)
{
	if (system.buyers.size() == DEFAULT_VALUE)
		cout << "No clients in the system yet!" << endl;
	else {
		for (size_t i = 0; i < system.buyers.size(); i++) {
			cout << (i + 1);
			system.buyers[i].printInsights();
		}
	}
}

void SystemAdministratorOperations::addTransaction(System& system, const String& operation) const
{
	Transaction newTransaction(operation);
	system.transactions.pushBack(newTransaction);
}

void SystemAdministratorOperations::viewTransactions(const System& system) const
{
	for (size_t i = 0; i < system.transactions.size(); i++) {
		cout << (i + INDEX_FIX) << ". ";
		system.transactions[i].printTransaction();
	}
}
