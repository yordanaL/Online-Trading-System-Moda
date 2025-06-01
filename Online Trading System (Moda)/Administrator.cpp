#include "Administrator.h"
#include "System.h"
#include "Check.h"

void Administrator::sendCheck(System& system, double amount, const String& code, const String& clientEGN)
{
	if (amount < DEFAULT_VALUE) {
		cout << "Invalid amount!";
		return;
	}

	for (size_t i = 0; i < this->sentChecksCodes.size(); i++) {
		if (this->sentChecksCodes[i] == code) {
			cout << "Code already used! Please use another one!";
			return;
		}
	}

	int buyerIndex = system.indexOfBuyer(clientEGN);

	if (buyerIndex == NOT_FOUND) {
		cout << "A buyer with such EGN does not exist!" << endl;
		return;
	}

	Check newCheck(amount, code, buyerIndex);


}

void Administrator::customerInsights(System& system)
{
	system.customerInsights(system);
}
