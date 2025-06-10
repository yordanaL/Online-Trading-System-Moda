#include "RunSystemCommand.h"

void RunSystemCommand::execute(System* system)
{
	//system load

	RegisterCommand regist;
	LoginCommand login;
	ExitCommand exit;

	/*Administrator* admin = nullptr;
	Seller* seller = nullptr;
	Buyer* buyer = nullptr;*/

	while (true) {
		String command;
		awaitingCommand();
		cin >> command;
		if (checkInput() == UNSUCCESSFUL)
			continue;

		if (command == "register") {
			regist.execute(system);
		}
		else if (command == "login") {
			login.execute(system);
		}
		else if (command == "exit") {
			exit.execute(system);
		}
		else {
			cout << "Invalid command!" << endl;
		}
	}
}
