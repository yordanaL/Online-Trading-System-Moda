#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class AddItemCommand;
class RemoveItemCommand;
class ListPendingOrdersCommand;
class ApproveOrderCommand;
class RejectOrderCommand;
class ListOrdersSellerCommand;
class ListBestSellingProductsCommand;
class ViewRevenueCommand;
class ListRefundsCommand;
class ApproveRefundCommand;
class RejectRefundCommand;
class LogoutCommand;
class HelpCommand;
class ViewProfileCommand;

class RunSystemAsSellerCommand : public Command {
public:
	void execute(System* system) override;
};

