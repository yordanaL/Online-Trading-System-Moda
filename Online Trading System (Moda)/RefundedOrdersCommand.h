#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class Buyer;

class RefundedOrdersCommand : public Command {
public:
	void execute(System* system) override;
};

