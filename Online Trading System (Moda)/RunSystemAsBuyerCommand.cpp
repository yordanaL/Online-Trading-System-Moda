#include "RunSystemAsBuyerCommand.h"
#include "CheckBalanceCommand.h"
#include "RedeemCommand.h"
#include "ListProductsCommand.h"
#include "ViewProductCommand.h"
#include "AddToCartCommand.h"
#include "RemoveFromCartCommand.h"
#include "ApplyDiscountCommand.h"
#include "RemoveDiscountCommand.h"
#include "ViewCartCommand.h"
#include "CheckoutCommand.h"
#include "ListOrdersSellerCommand.h"
#include "ConfirmOrderCommand.h"
#include "OrderHistoryCommand.h"
#include "RateCommand.h"
#include "RequestRefundCommand.h"
#include "RefundedOrdersCommand.h"
#include "LogoutCommand.h"
#include "HelpCommand.h"
#include "ViewProfileCommand.h"

void RunSystemAsBuyerCommand::execute(System* system)
{
	CheckBalanceCommand checkBalance;
	RedeemCommand redeem;
	ListProductsCommand listProducts;
	ViewProductCommand viewProduct;
	AddToCartCommand addToCart;
	RemoveFromCartCommand removeFromCart;
	ApplyDiscountCommand applyDiscount;
	RemoveDiscountCommand removeDiscount;
	ViewCartCommand viewCart;
	CheckoutCommand checkout;
	ListOrdersSellerCommand listOrders;
	ConfirmOrderCommand confirmOrder;
	OrderHistoryCommand orderHistory;
	RateCommand rate;
	RequestRefundCommand requestRefund;
	RefundedOrdersCommand refundedOrders;
	LogoutCommand logout;
	HelpCommand help;
	ViewProfileCommand viewProfile;

	while (true) {
		String command;
		awaitingCommand();
		cin >> command;
		if (checkInput() == UNSUCCESSFUL)
			continue;

		if (command == "check-balance") {
			clearBuffer();
			checkBalance.execute(system);
		}
		else if (command == "redeem") {
			clearBuffer();
			redeem.execute(system);
		}
		else if (command == "list-products") {
			clearBuffer();
			listProducts.execute(system);
		}
		else if (command == "view-product") {
			clearBuffer();
			viewProduct.execute(system);
		}
		else if (command == "add-to-cart") {
			clearBuffer();
			addToCart.execute(system);
		}
		else if (command == "remove") {
			clearBuffer();
			removeFromCart.execute(system);
		}
		else if (command == "apply-discount") {
			clearBuffer();
			applyDiscount.execute(system);
		}
		else if (command == "remove-discount") {
			clearBuffer();
			removeDiscount.execute(system);
		}
		else if (command == "view-cart") {
			clearBuffer();
			viewCart.execute(system);
		}
		else if (command == "checkout") {
			clearBuffer();
			checkout.execute(system);
		}
		else if (command == "list-orders") {
			clearBuffer();
			listOrders.execute(system);
		}
		else if (command == "confirm-order") {
			clearBuffer();
			confirmOrder.execute(system);
		}
		else if (command == "order-history") {
			clearBuffer();
			orderHistory.execute(system);
		}
		else if (command == "rate") {
			clearBuffer();
			rate.execute(system);
		}
		else if (command == "request-refund") {
			clearBuffer();
			requestRefund.execute(system);
		}
		else if (command == "refunded-orders") {
			clearBuffer();
			refundedOrders.execute(system);
		}
		else if (command == "logout") {
			clearBuffer();
			logout.execute(system);
		}
		else if (command == "help") {
			clearBuffer();
			help.execute(system);
		}
		else if (command == "view-profile") {
			clearBuffer();
			viewProfile.execute(system);
		}
		else {
			clearBuffer();
			cout << "Invalid command!" << endl;
		}
	}
}
