#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class Administrator;

class CustomerInsightsCommand : public Command {
public:
	void execute(System* system) override;
};

