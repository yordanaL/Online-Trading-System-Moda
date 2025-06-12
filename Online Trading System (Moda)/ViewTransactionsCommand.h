#pragma once
#include <iostream>
using namespace std;
#include "Command.h"

class ViewTransactionsCommand : public Command {
public:
	void execute(System* system) override;
};

