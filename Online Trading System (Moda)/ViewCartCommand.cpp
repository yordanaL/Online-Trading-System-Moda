#include "ViewCartCommand.h"
#include "Buyer.h"

void ViewCartCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	buyer->viewCart(*system);
	buyer = nullptr;
}
