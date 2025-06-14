#include "RateCommand.h"
#include "Buyer.h"

void RateCommand::execute(System* system)
{
	Buyer* buyer = system->getBuyer(*system);
	if (buyer == nullptr)
		return;

	int productID = NOT_FOUND;
	cout << "Product ID: ";
	cin >> productID;
	if (checkInput() == UNSUCCESSFUL)
		return;

	int rating = NOT_FOUND;
	cout << "Rating: ";
	cin >> rating;
	if (checkInput() == UNSUCCESSFUL)
		return;

	if (rating < MIN_RATING || rating > MAX_RATING) {
		cout << "Invalid rating!" << endl;
		buyer = nullptr;
		return;
	}

	buyer->rate(*system, productID, rating);
	buyer = nullptr;
}
