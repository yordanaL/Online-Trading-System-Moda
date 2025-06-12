#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class Buyer;

class ListOrdersBuyerCommand : public Command {
public:
	void execute(System* system) override;
};

