#include "ChecksCommand.h"
#include "Buyer.h"

void ChecksCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->checks();
	buyer = nullptr;
}
