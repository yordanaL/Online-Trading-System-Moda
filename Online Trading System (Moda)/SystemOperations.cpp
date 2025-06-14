#include "SystemOperations.h"
#include "Command.h"
#include "RunSystemCommand.h"
#include "RunSystemAsAdministratorCommand.h"
#include "RunSystemAsSellerCommand.h"
#include "RunSystemAsBuyerCommand.h"
#include "System.h"
#include "Registration.h"
#include "Transaction.h"
#include "Administrator.h"
#include "Seller.h"
#include "Buyer.h"

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
	cout << "Password: ";
	cin >> password;
	if (checkInput() == UNSUCCESSFUL)
		return;

	for (size_t i = 0; i < system.buyers.size(); i++) {
		if (system.buyers[i].getName() == name) {
			if (system.buyers[i].getPassword() == password) {
				system.currentUserType = BUYER;
				system.currentBuyer = &system.buyers[i];
				cout << "Login successful!" << endl;
				runSystemAsBuyer.execute(&system);
				return;
			}
		}
	}

	for (int i = 0; i < system.adminsRegistrations.size(); i++) {
		if (system.adminsRegistrations[i].getName() == name) {
			if (system.adminsRegistrations[i].getPassword() == password) {
				system.currentUserType = ADMINISTRATOR;
				system.indexOfCurrentAdmin = i;
				cout << "Login successful!" << endl;
				runSystemAsAdministrator.execute(&system);
				return;
			}
		}
	}

	for (int i = 0; i < system.sellersRegistrations.size(); i++) {
		if (system.sellersRegistrations[i] .getName() == name) {
			if (system.sellersRegistrations[i].getPassword() == password) {
				system.currentUserType = SELLER;
				system.indexOfCurrentSeller = i;
				cout << "Login successful!" << endl;
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
	system.indexOfCurrentAdmin = NOT_FOUND;
	system.indexOfCurrentSeller = NOT_FOUND;
	system.currentUserType = USER;
	system.currentBuyer = nullptr;

	cout << "You have logged out!" << endl;
}

void SystemOperations::signUp(System& system, const String& name, const String& EGN, const String& password, const String& role)
{
	RunSystemCommand runSystem;

	if (isEGNValid(EGN) == false) {
		cout << "Registration failed!" << endl;
		return;
	}
	else if (isEGNUnique(system, EGN) == false) {
		cout << "This EGN is already in use! Registration failed!" << endl;
		return;
	}
	else if (isNameUnique(system, name) == false) {
		cout << "This name is already in use! Registration failed!" << endl;
		return;
	}


	if (role == "Client") {
		Buyer newBuyer(name, EGN, password);
		system.buyers.pushBack(newBuyer);
	}
	else if (role == "Business") {
		if (system.sellerSignedUp == false) {
			Seller newSeller(name, EGN, password);
			system.seller = newSeller;

			Registration newRegistration(name, EGN, password);
			system.sellersRegistrations.pushBack(newRegistration);

			system.sellerSignedUp = true;
		}
		else {
			Registration newRegistration(name, EGN, password);
			system.sellersRegistrations.pushBack(newRegistration);
		}
	}
	else if (role == "Administrator") {
		if (system.adminSignedUp == false) {
			Administrator newAdmin(name, EGN, password);
			system.admin = newAdmin;

			Registration newRegistration(name, EGN, password);
			system.adminsRegistrations.pushBack(newRegistration);

			system.adminSignedUp = true;
		}
		else {
			Registration newRegistration(name, EGN, password);
			system.adminsRegistrations.pushBack(newRegistration);
		}
	}
	else {
		cout << "Invalid role!" << endl;
		return;
	}

	system.allNames.pushBack(name);
	system.allEGNs.pushBack(EGN);

	cout << "Registration is successful!" << endl;
}

bool SystemOperations::isEGNValid(const String& EGN) const
{
	if (EGN.length() != EGN_LENGTH) {
		cout << "EGN is too short (it has to be 10 digits long). ";
		return false;
	}

	for (size_t i = 0; i < EGN.length(); i++) {
		if (isNumber(EGN[i]) == false) {
			cout << "EGN must contain only digits. ";
			return false;
		}
	}

	return true;
}

bool SystemOperations::isEGNUnique(const System& system, const String& EGN) const
{
	for (size_t i = 0; i < system.allEGNs.size(); i++) {
		if (system.allEGNs[i] == EGN)
			return false;
	}
	return true;
}

bool SystemOperations::isNameUnique(const System& system, const String& name) const
{
	for (size_t i = 0; i < system.allNames.size(); i++) {
		if (system.allNames[i] == name)
			return false;
	}
	return true;
}

void SystemOperations::viewProfile(System& system)
{
	Buyer* buyer = nullptr;

	if (system.getCurrentUserType(system) == BUYER) {
		buyer = system.getBuyer(system);
		buyer->viewProfile();
	}
	else if (system.getCurrentUserType(system) == SELLER) {
		cout << "Name: " << system.sellersRegistrations[getSellerIndex(system)].getName() << endl;
		cout << "EGN: " << system.sellersRegistrations[getSellerIndex(system)].getEGN() << endl;
	}
	else if (system.getCurrentUserType(system) == ADMINISTRATOR) {
		cout << "Name: " << system.adminsRegistrations[getAdministratorIndex(system)].getName() << endl;
		cout << "EGN: " << system.adminsRegistrations[getAdministratorIndex(system)].getEGN() << endl;
	}
	else {
		cout << "No user is logged in!" << endl;
	}

	buyer = nullptr;
}

const int SystemOperations::getCurrentUserType(System& system) const
{
	return system.currentUserType;
}

Administrator* SystemOperations::getAdmin(System& system)
{
	return &system.admin;
}

const int SystemOperations::getAdministratorIndex(const System& system) const
{
	return system.indexOfCurrentAdmin;
}

Seller* SystemOperations::getSeller(System& system)
{
	return &system.seller;
}

const int SystemOperations::getSellerIndex(const System& system) const
{
	return system.indexOfCurrentSeller;
}

Buyer* SystemOperations::getBuyer(System& system)
{
	return system.currentBuyer;
}
