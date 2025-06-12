#include "RegisterCommand.h"

void RegisterCommand::execute(System* system)
{
	String name;
	cout << "Name: ";
	cin >> name;
	if (checkInput() == UNSUCCESSFUL)
		return;

	String EGN;
	cout << "EGN: ";
	cin >> EGN;
	if (checkInput() == UNSUCCESSFUL)
		return;

	String password;
	cout << "Password: ";
	cin >> password;
	if (checkInput() == UNSUCCESSFUL)
		return;

	String role;
	cout << "Select Role(Client, Business, Administrator): ";
	cin >> role;
	if (checkInput() == UNSUCCESSFUL)
		return;

	system->signUp(*system, name, EGN, password, role);
}
