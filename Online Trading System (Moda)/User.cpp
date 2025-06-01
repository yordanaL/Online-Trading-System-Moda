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
