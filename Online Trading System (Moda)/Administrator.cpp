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
	cout << " 01) send-check        - Send a check to a client" << endl;
	cout << " 02) customer-insights - View clients' data" << endl;
	cout << " 03) view-transactions - View all system-wide transactions" << endl;
	cout << " 04) logout            - Log out of your administrator account" << endl;
	cout << " 05) help              - Show help for available commands" << endl;
	cout << " 06) view-profile      - View your administrator profile" << endl;
}

void Administrator::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->sentChecksCodes.save(file);
}

void Administrator::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->sentChecksCodes.load(file);
}
