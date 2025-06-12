#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
#include "RunSystemCommand.h"

class LogoutCommand : public Command {
public:
	void execute(System* system) override;
};

