#include "RedeemCommand.h"
#include "Buyer.h"

void RedeemCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;


}
