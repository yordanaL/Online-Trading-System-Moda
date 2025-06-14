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
#include "ChecksCommand.h"
#include "ListShippedOrdersCommand.h"
#include "LogoutCommand.h"
#include "HelpCommand.h"
#include "ViewProfileCommand.h"
#include "Buyer.h"

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
	ChecksCommand checks;
	ListShippedOrdersCommand listShippedOrders;
	LogoutCommand logout;
	HelpCommand help;
	ViewProfileCommand viewProfile;

	Buyer* buyer = system->getBuyer(*system);
	buyer->loginInfo(*system);
	buyer = nullptr;

	newLine();

	while (true) {
		String command;
		awaitingCommand();
		cin >> command;
		if (checkInput() == UNSUCCESSFUL)
			continue;

		if (command == "check-balance") {
			clearBuffer();
			checkBalance.execute(system);
			newLine();
		}
		else if (command == "redeem") {
			clearBuffer();
			redeem.execute(system);
			newLine();
		}
		else if (command == "list-products") {
			clearBuffer();
			listProducts.execute(system);
			newLine();
		}
		else if (command == "view-product") {
			clearBuffer();
			viewProduct.execute(system);
			newLine();
		}
		else if (command == "add-to-cart") {
			clearBuffer();
			addToCart.execute(system);
			newLine();
		}
		else if (command == "remove-from-cart") {
			clearBuffer();
			removeFromCart.execute(system);
			newLine();
		}
		else if (command == "apply-discount") {
			clearBuffer();
			applyDiscount.execute(system);
			newLine();
		}
		else if (command == "remove-discount") {
			clearBuffer();
			removeDiscount.execute(system);
			newLine();
		}
		else if (command == "view-cart") {
			clearBuffer();
			viewCart.execute(system);
			newLine();
		}
		else if (command == "checkout") {
			clearBuffer();
			checkout.execute(system);
			newLine();
		}
		else if (command == "list-orders") {
			clearBuffer();
			listOrders.execute(system);
			newLine();
		}
		else if (command == "confirm-order") {
			clearBuffer();
			confirmOrder.execute(system);
			newLine();
		}
		else if (command == "order-history") {
			clearBuffer();
			orderHistory.execute(system);
			newLine();
		}
		else if (command == "rate") {
			clearBuffer();
			rate.execute(system);
			newLine();
		}
		else if (command == "request-refund") {
			clearBuffer();
			requestRefund.execute(system);
			newLine();
		}
		else if (command == "refunded-orders") {
			clearBuffer();
			refundedOrders.execute(system);
			newLine();
		}
		else if (command == "checks") {
			clearBuffer();
			checks.execute(system);
			newLine();
		}
		else if (command == "list-shipped-orders") {
			clearBuffer();
			listShippedOrders.execute(system);
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
