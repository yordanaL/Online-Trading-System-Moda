#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class Seller;

class RejectRefundCommand : public Command {
public:
	void execute(System* system) override;
};

