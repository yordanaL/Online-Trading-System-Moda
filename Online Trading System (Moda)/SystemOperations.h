#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
#include "FrequentlyUsedFunctions.h"
#include "String.h"
class System;

class SystemOperations
{
public:
	void login(System& system);
	void signUp();

	void saveToFile();
	void loadFromFile();
};

