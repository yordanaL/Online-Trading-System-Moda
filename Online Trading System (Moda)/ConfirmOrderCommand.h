#pragma once
#include <iostream>
using namespace std;
#include "Command.h"

class ConfirmOrderCommand : public Command {
public:
	void execute(System* system) override;
};

