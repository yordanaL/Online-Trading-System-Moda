#include "RemoveItemCommand.h"
#include "Seller.h"

void RemoveItemCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	char productName[BUFF_SIZE]{ '\0' };
	cout << "Product name: ";
	cin.getline(productName, BUFF_SIZE);
	if (checkInput() == UNSUCCESSFUL)
		return;

	seller->removeItem(*system, productName);
	seller = nullptr;
}
