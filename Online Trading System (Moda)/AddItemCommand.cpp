#include "AddItemCommand.h"
#include "Seller.h"
#include "Product.h"

void AddItemCommand::execute(System* system)
{
	Seller* seller = system->getSeller(*system);
	if (seller == nullptr)
		return;

	char productName[BUFF_SIZE]{ '\0' };
	cout << "Product name: ";
	cin.getline(productName, BUFF_SIZE);
	if (checkInput() == UNSUCCESSFUL)
		return;

	double price = DEFAULT_VALUE;
	cout << "Price: ";
	cin >> price;
	if (checkInput() == UNSUCCESSFUL)
		return;
	clearBuffer();

	int quantity = DEFAULT_VALUE;
	cout << "Quantity: ";
	cin >> quantity;
	if (checkInput() == UNSUCCESSFUL)
		return;
	clearBuffer();

	char description[BUFF_SIZE]{ '\0' };
	cout << "Description: ";
	cin.getline(description, BUFF_SIZE);
	if (checkInput() == UNSUCCESSFUL)
		return;

	Product newProduct(productName, price, quantity, description);
	seller->addItem(*system, newProduct);

	seller = nullptr;
}
