#include "RunSystemCommand.h"

void RunSystemCommand::execute(System* system)
{
	LoadCommand load;
	load.execute(system);

	RegisterCommand regist;
	LoginCommand login;
	ExitCommand exit;

	while (true) {
		String command;
		awaitingCommand();
		cin >> command;
		if (checkInput() == UNSUCCESSFUL)
			continue;

		if (command == "register") {
			clearBuffer();
			regist.execute(system);
		}
		else if (command == "login") {
			clearBuffer();
			login.execute(system);
		}
		else if (command == "exit") {
			clearBuffer();
			exit.execute(system);
			break;
		}
		else {
			clearBuffer();
			cout << "Invalid command!" << endl;
		}
	}
}
