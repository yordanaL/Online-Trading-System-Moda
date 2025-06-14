#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class Buyer;

class SortByAlphCommand : public Command {
public:
	void execute(System* system) override;
};

