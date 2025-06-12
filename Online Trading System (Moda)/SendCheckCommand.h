#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
#include "FrequentlyUsedFunctions.h"
class Administrator;

class SendCheckCommand : public Command {
public:
	void execute(System* system) override;
};

