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
	//Administrator* admin = system->getAdmin(*system);
	//if (admin == nullptr)
	//	return;

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
			sendCheck.execute(system);
		}
		else if (command == "customer-insights") {
			customerInsights.execute(system);
		}
		else if (command == "view-transactions") {
			viewTransactions.execute(system);
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

	//admin = nullptr;
}
