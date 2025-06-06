#pragma once
#pragma once
#include "Constants.h"
#include "String.h"
#include "Vector.hpp"
#include "Pair.hpp"
#include "Product.h"
#include "Order.h"

class RejectedOrder : public Order {
private:
	String rejectionReason;

public:
	RejectedOrder() = default;
	RejectedOrder(const Order& _order, const String& _rejectionReason = EMPTY_STR);

	const String& getRejectionReason() const;
};

