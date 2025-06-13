#include "User.h"

User::User() : name(), EGN(), password()
{
}

User::User(const String& _name, const String& _EGN, const String& _password)
	:name(_name), EGN(_EGN), password(_password)
{
}

void User::viewProfile() const
{
	cout << "Name: " << this->name << endl;
	cout << "EGN: " << this->EGN << endl;
}

void User::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->name.save(file);
	this->EGN.save(file);
	this->password.save(file);
}

void User::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->name.load(file);
	this->EGN.load(file);
	this->password.load(file);
}

void User::setName(const String& _name)
{
	this->name = _name;
}

void User::setEGN(const String& _EGN)
{
	this->EGN = _EGN;
}

void User::setPassword(const String& _password)
{
	this->password = _password;
}

const String& User::getName() const
{
	return this->name;
}

const String& User::getEGN() const
{
	return this->EGN;
}

const String& User::getPassword() const
{
	return this->password;
}
