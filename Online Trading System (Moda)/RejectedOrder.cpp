#include "RejectedOrder.h"

RejectedOrder::RejectedOrder(const Order& _order, const String& _rejectionReason) : Order(_order), rejectionReason(_rejectionReason)
{
}

const String& RejectedOrder::getRejectionReason() const
{
	return this->rejectionReason;
}
