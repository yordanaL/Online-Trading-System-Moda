#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class Seller;

class ListPendingOrdersCommand : public Command {
public:
	void execute(System* system) override;
};

