#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class Buyer;

class RedeemCommand : public Command {
public:
	void execute(System* system) override;
};

