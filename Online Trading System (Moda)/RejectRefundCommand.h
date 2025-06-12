#pragma once
#include <iostream>
using namespace std;
#include "Command.h"

class RejectRefundCommand : public Command {
public:
	void execute(System* system) override;
};

