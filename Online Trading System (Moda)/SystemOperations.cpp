#include "SystemOperations.h"
#include "System.h"

void SystemOperations::login(System& system)
{
	String name;
	cout << "Name: ";
	cin >> name;
	if (checkInput() == UNSUCCESSFUL)
		return;

	String password;
	cout << "password: ";
	cin >> password;
	if (checkInput() == UNSUCCESSFUL)
		return;

	for (size_t i = 0; i < system.buyers.size(); i++) {
		if (system.buyers[i].getName() == name) {
			if (system.buyers[i].getPassword() == password) {
				system.currentUserType = BUYER;
				system.currentBuyer = &system.buyers[i];
				return;
			}
		}
	}

	for (size_t i = 0; i < system.admins.size(); i++) {
		if (system.admins[i].getName() == name) {
			if (system.admins[i].getPassword() == password) {
				system.currentUserType = ADMINISTRATOR;
				return;
			}
		}
	}

	for (size_t i = 0; i < system.sellers.size(); i++) {
		if (system.sellers [i] .getName() == name) {
			if (system.sellers[i].getPassword() == password) {
				system.currentUserType = SELLER;
				return;
			}
		}
	}

	cout << "Wrong name or password! Please try again!" << endl;
	system.currentUserType = USER;
}
