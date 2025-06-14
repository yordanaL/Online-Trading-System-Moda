#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
#include "FrequentlyUsedFunctions.h"
class CheckBalanceCommand;
class RedeemCommand;
class ListProductsCommand;
class ViewProductCommand;
class AddToCartCommand;
class RemoveFromCartCommand;
class ApplyDiscountCommand;
class RemoveDiscountCommand;
class ViewCartCommand;
class CheckoutCommand;
class ListOrdersBuyerCommand;
class ConfirmOrderCommand;
class OrderHistoryCommand;
class RateCommand;
class RequestRefundCommand;
class RefundedOrdersCommand;
class ChecksCommand;
class ListShippedOrdersCommand;
class LogoutCommand;
class HelpCommand;
class ViewProfileCommand;
class Buyer;

class RunSystemAsBuyerCommand : public Command {
public:
	void execute(System* system) override;
};

