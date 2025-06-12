#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class Seller;

class ViewRevenueCommand : public Command {
public:
	void execute(System* system) override;
};

