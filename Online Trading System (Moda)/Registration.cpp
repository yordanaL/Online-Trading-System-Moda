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
