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
			checkBalance.execute(system);
		}
		else if (command == "redeem") {
			redeem.execute(system);
		}
		else if (command == "list-products") {
			listProducts.execute(system);
		}
		else if (command == "view-product") {
			viewProduct.execute(system);
		}
		else if (command == "add-to-cart") {
			addToCart.execute(system);
		}
		else if (command == "remove-from-cart") {
			removeFromCart.execute(system);
		}
		else if (command == "apply-discount") {
			applyDiscount.execute(system);
		}
		else if (command == "remove-discount") {
			removeDiscount.execute(system);
		}
		else if (command == "view-cart") {
			viewCart.execute(system);
		}
		else if (command == "checkout") {
			checkout.execute(system);
		}
		else if (command == "list-orders") {
			listOrders.execute(system);
		}
		else if (command == "confirm-order") {
			confirmOrder.execute(system);
		}
		else if (command == "order-history") {
			orderHistory.execute(system);
		}
		else if (command == "rate") {
			rate.execute(system);
		}
		else if (command == "request-refund") {
			requestRefund.execute(system);
		}
		else if (command == "refunded-orders") {
			refundedOrders.execute(system);
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
