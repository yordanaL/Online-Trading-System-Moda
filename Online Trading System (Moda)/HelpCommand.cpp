#include "HelpCommand.h"
#include "Administrator.h"
#include "Seller.h"
#include "Buyer.h"

void HelpCommand::execute(System* system)
{
	switch (system->getCurrentUserType(*system))
	{
	case ADMINISTRATOR: 
		Administrator::help();
		break;
	case SELLER:
		Seller::help();
		break;
	case BUYER:
		Buyer::help();
		break;
	default:
		cout << "No user is logged in!" << endl;
		break;
	}
}
