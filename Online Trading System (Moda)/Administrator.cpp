#include "Administrator.h"
#include "System.h"
#include "Check.h"

Administrator::Administrator(const String& _name, const String& _EGN, const String& _password) : User(_name, _EGN, _password)
{
}

void Administrator::sendCheck(System& system, double amount, const String& code, const String& clientEGN)
{
	if (amount < DEFAULT_VALUE) {
		cout << "Invalid amount!";
		return;
	}

	for (size_t i = 0; i < this->sentChecksCodes.size(); i++) {
		if (this->sentChecksCodes[i] == code) {
			cout << "Code already used! Please use another one!" << endl;
			return;
		}
	}

	int buyerIndex = system.findIndexOfBuyerByEGN(clientEGN);
	if (buyerIndex == NOT_FOUND) {
		cout << "A buyer with such EGN does not exist!" << endl;
		return;
	}

	this->sentChecksCodes.pushBack(code);

	Check newCheck(amount, code, buyerIndex);
	system.sendCheck(system, newCheck);

	String newTransaction = "Check sent to ";
	newTransaction += system.buyers[buyerIndex].getName();
	system.addTransaction(system, newTransaction);
}

void Administrator::customerInsights(System& system)
{
	system.customerInsights(system);
}

void Administrator::viewTransactions(const System& system)
{
	system.viewTransactions(system);
}

void Administrator::help()
{
	cout << "Administrator Commands: " << endl;
	cout << "1) send-check" << endl;
	cout << "2) customer-insights" << endl;
	cout << "3) view-transactions" << endl;
	cout << "4) logout" << endl;
	cout << "5) help" << endl;
	cout << "6) view-profile" << endl;
}