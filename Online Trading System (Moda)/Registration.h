#pragma once
#include "String.h"

class Registration {
private:
	String name;
	String EGN;
	String password;

public:
	Registration() = default;
	Registration(const String& _name, const String& _EGN, const String& _password);

	const String& getName() const;
	const String& getEGN() const;
	const String& getPassword() const;
};

