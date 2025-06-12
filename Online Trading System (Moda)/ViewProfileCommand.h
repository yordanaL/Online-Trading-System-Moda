#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
#include "Constants.h"
class Administrator;
class Seller;
class Buyer;

class ViewProfileCommand : public Command {
public:
	void execute(System* system) override;
};

