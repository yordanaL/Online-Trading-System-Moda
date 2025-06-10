#pragma once
#include <iostream>
using namespace std;
#include "Command.h"

class LoginCommand : public Command {
public:
	void execute(System* system) override;
};

