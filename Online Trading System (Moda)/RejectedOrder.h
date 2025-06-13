#pragma once
#include "Constants.h"
#include "String.h"
#include "Vector.hpp"
#include "Pair.hpp"
#include "Product.h"
#include "Order.h"
class Buyer;

class RejectedOrder : public Order {
	friend class Buyer;
private:
	String rejectionReason;

public:
	RejectedOrder() = default;
	RejectedOrder(const Order& _order, const String& _rejectionReason = REASON_UNKNOWN);

	const String& getRejectionReason() const;

	void save(ofstream& file);
	void load(ifstream& file);
};

