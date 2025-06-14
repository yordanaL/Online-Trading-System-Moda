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

	newLine();

	while (true) {
		String command;
		awaitingCommand();
		cin >> command;
		if (checkInput() == UNSUCCESSFUL)
			continue;

		if (command == "add-item") {
			clearBuffer();
			addItem.execute(system);
			newLine();
		}
		else if (command == "remove-item") {
			clearBuffer();
			removeItem.execute(system);
			newLine();
		}
		else if (command == "list-pending-orders") {
			clearBuffer();
			listPendingOrders.execute(system);
			newLine();
		}
		else if (command == "approve-order") {
			clearBuffer();
			approveOrder.execute(system);
			newLine();
		}
		else if (command == "reject-order") {
			clearBuffer();
			rejectOrder.execute(system);
			newLine();
		}
		else if (command == "list-orders") {
			clearBuffer();
			listOrdersSeller.execute(system);
			newLine();
		}
		else if (command == "list-best-selling-products") {
			clearBuffer();
			listBestSellingProducts.execute(system);
			newLine();
		}
		else if (command == "view-revenue") {
			clearBuffer();
			viewRevenue.execute(system);
			newLine();
		}
		else if (command == "list-refunds") {
			clearBuffer();
			listRefunds.execute(system);
			newLine();
		}
		else if (command == "approve-refund") {
			clearBuffer();
			approveRefund.execute(system);
			newLine();
		}
		else if (command == "reject-refund") {
			clearBuffer();
			rejectRefund.execute(system);
			newLine();
		}
		else if (command == "logout") {
			clearBuffer();
			logout.execute(system);
			newLine();
			break;
		}
		else if (command == "help") {
			clearBuffer();
			help.execute(system);
			newLine();
		}
		else if (command == "view-profile") {
			clearBuffer();
			viewProfile.execute(system);
			newLine();
		}
		else {
			clearBuffer();
			cout << "Invalid command!" << endl;
			newLine();
		}
	}
}
