#include "RunSystemAsAdministratorCommand.h"
#include "Administrator.h"
#include "SendCheckCommand.h"
#include "CustomerInsightsCommand.h"
#include "ViewTransactionsCommand.h"
#include "LogoutCommand.h"
#include "HelpCommand.h"
#include "ViewProfileCommand.h"

void RunSystemAsAdministratorCommand::execute(System* system)
{
	SendCheckCommand sendCheck;
	CustomerInsightsCommand customerInsights;
	ViewTransactionsCommand	viewTransactions;
	LogoutCommand logout;
	HelpCommand help;
	ViewProfileCommand viewProfile;

	while (true) {
		String command;
		awaitingCommand();
		cin >> command;
		if (checkInput() == UNSUCCESSFUL)
			continue;

		if (command == "send-check") {
			clearBuffer();
			sendCheck.execute(system);
		}
		else if (command == "customer-insights") {
			clearBuffer();
			customerInsights.execute(system);
		}
		else if (command == "view-transactions") {
			clearBuffer();
			viewTransactions.execute(system);
		}
		else if (command == "logout") {
			clearBuffer();
			logout.execute(system);
			break;
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
