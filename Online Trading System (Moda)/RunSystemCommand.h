#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
#include "FrequentlyUsedFunctions.h"
#include "ExitCommand.h"
#include "LoginCommand.h"
#include "RegisterCommand.h"

class RunSystemCommand : public Command {
public:
	void execute(System* system) override;
};

