#include "Registration.h"

Registration::Registration(const String& _name, const String& _EGN, const String& _password)
	:name(_name), EGN(_EGN), password(_password) {}

const String& Registration::getName() const
{
	return this->name;
}

const String& Registration::getEGN() const
{
	return this->EGN;
}

const String& Registration::getPassword() const
{
	return this->password;
}

void Registration::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->name.save(file);
	this->EGN.save(file);
	this->password.save(file);
}

void Registration::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->name.load(file);
	this->EGN.load(file);
	this->password.load(file);
}
