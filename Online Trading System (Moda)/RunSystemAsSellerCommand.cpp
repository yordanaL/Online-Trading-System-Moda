#include "RunSystemAsSellerCommand.h"
#include "AddItemCommand.h"
#include "RemoveItemCommand.h"
#include "ListPendingOrdersCommand.h"
#include "ApproveOrderCommand.h"
#include "RejectOrderCommand.h"
#include "ListOrdersSellerCommand.h"
#include "ListBestSellingProductsCommand.h"
#include "ViewRevenueCommand.h"
#include "ListRefundsCommand.h"
#include "ApproveRefundCommand.h"
#include "RejectRefundCommand.h"
#include "LogoutCommand.h"
#include "HelpCommand.h"
#include "ViewProfileCommand.h"

void RunSystemAsSellerCommand::execute(System* system)
{
	AddItemCommand addItem;
	RemoveItemCommand removeItem;
	ListPendingOrdersCommand listPendingOrders;
	ApproveOrderCommand approveOrder;
	RejectOrderCommand rejectOrder;
	ListOrdersSellerCommand listOrdersSeller;
	ListBestSellingProductsCommand listBestSellingProducts;
	ViewRevenueCommand viewRevenue;
	ListRefundsCommand listRefunds;
	ApproveRefundCommand approveRefund;
	RejectRefundCommand rejectRefund;
	LogoutCommand logout;
	HelpCommand help;
	ViewProfileCommand viewProfile;

	while (true) {
		String command;
		awaitingCommand();
		cin >> command;
		if (checkInput() == UNSUCCESSFUL)
			continue;

		if (command == "add-item") {
			addItem.execute(system);
		}
		else if (command == "remove-item") {
			removeItem.execute(system);
		}
		else if (command == "list-pending-orders") {
			listPendingOrders.execute(system);
		}
		else if (command == "approve-order") {
			approveOrder.execute(system);
		}
		else if (command == "reject-order") {
			rejectOrder.execute(system);
		}
		else if (command == "list-orders") {
			listOrdersSeller.execute(system);
		}
		else if (command == "list-best-selling-products") {
			listBestSellingProducts.execute(system);
		}
		else if (command == "view-revenue") {
			viewRevenue.execute(system);
		}
		else if (command == "list-refunds") {
			listRefunds.execute(system);
		}
		else if (command == "approve-refund") {
			approveRefund.execute(system);
		}
		else if (command == "reject-refund") {
			rejectRefund.execute(system);
		}
		else if (command == "logout") {
			logout.execute(system);
		}
		else if (command == "help") {
			help.execute(system);
		}
		else if (command == "view-profile") {
			viewProfile.execute(system);
		}
		else {
			cout << "Invalid command!" << endl;
		}
	}
}
