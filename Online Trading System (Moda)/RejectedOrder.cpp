#include "RejectedOrder.h"

RejectedOrder::RejectedOrder(const Order& _order, const String& _rejectionReason) : Order(_order), rejectionReason(_rejectionReason)
{
}

const String& RejectedOrder::getRejectionReason() const
{
	return this->rejectionReason;
}

void RejectedOrder::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->rejectionReason.save(file);
}

void RejectedOrder::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	this->rejectionReason.load(file);
}
