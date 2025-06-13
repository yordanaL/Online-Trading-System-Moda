#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class User {
protected:
	String name;
	String EGN;
	String password;

public:
	User();
	User(const String& _name, const String& _EGN, const String& _password);

	void setName(const String& _name);
	void setEGN(const String& _EGN);
	void setPassword(const String& _password);

	const String& getName() const;
	const String& getEGN() const;
	const String& getPassword() const;

	virtual ~User() = default;

	void viewProfile() const;

	void save(ofstream& file);
	void load(ifstream& file);
};

