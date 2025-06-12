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
class ListOrdersSellerCommand;
class ConfirmOrderCommand;
class OrderHistoryCommand;
class RateCommand;
class RequestRefundCommand;
class RefundedOrdersCommand;
class LogoutCommand;
class HelpCommand;
class ViewProfileCommand;

class RunSystemAsBuyerCommand : public Command {
public:
	void execute(System* system) override;
};

