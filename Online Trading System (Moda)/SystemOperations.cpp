#include "SystemOperations.h"
#include "Command.h"
#include "RunSystemAsAdministratorCommand.h"
#include "RunSystemAsSellerCommand.h"
#include "RunSystemAsBuyerCommand.h"
#include "System.h"

void SystemOperations::login(System& system)
{
	RunSystemAsAdministratorCommand runSystemAsAdministrator;
	RunSystemAsSellerCommand runSystemAsSeller;
	RunSystemAsBuyerCommand runSystemAsBuyer;

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
				runSystemAsBuyer.execute(&system);
				return;
			}
		}
	}

	for (size_t i = 0; i < system.admins.size(); i++) {
		if (system.admins[i].getName() == name) {
			if (system.admins[i].getPassword() == password) {
				system.currentUserType = ADMINISTRATOR;
				system.indexOfCurrentAdmin = i;
				runSystemAsAdministrator.execute(&system);
				return;
			}
		}
	}

	for (size_t i = 0; i < system.sellers.size(); i++) {
		if (system.sellers [i] .getName() == name) {
			if (system.sellers[i].getPassword() == password) {
				system.currentUserType = SELLER;
				system.indexOfCurrentSeller = i;
				runSystemAsSeller.execute(&system);
				return;
			}
		}
	}

	cout << "Wrong name or password! Please try again!" << endl;
	system.currentUserType = USER;
	system.currentBuyer = nullptr;
	system.indexOfCurrentAdmin = NOT_FOUND;
	system.indexOfCurrentSeller = NOT_FOUND;
}

void SystemOperations::logout(System& system)
{
	system.currentUserType = USER;
	system.currentBuyer = nullptr;
}

const int SystemOperations::getCurrentUserType(System& system) const
{
	return system.currentUserType;
}

Administrator* SystemOperations::getAdmin(System& system)
{
	return &system.admin;
}

Seller* SystemOperations::getSeller(System& system)
{
	return &system.seller;
}

Buyer* SystemOperations::getBuyer(System& system)
{
	return system.currentBuyer;
}
