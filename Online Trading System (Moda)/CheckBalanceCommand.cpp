#include "CheckBalanceCommand.h"
#include "Buyer.h"

void CheckBalanceCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->checkBalance();
	buyer = nullptr;
}
