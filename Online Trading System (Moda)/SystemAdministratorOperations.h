#pragma once
#include <iostream>
using namespace std;
#include "Constants.h"
class System;
class Check;

class SystemAdministratorOperations
{
public:
	void sendCheck(System& system, const Check& newCheck);
	void customerInsights(System& system);
};

