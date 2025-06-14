#include "RunSystemCommand.h"

void RunSystemCommand::execute(System* system)
{
	LoadCommand load;
	load.execute(system);

	RegisterCommand regist;
	LoginCommand login;
	ExitCommand exit;

	cout << "Welcome to < MODA >" << endl << endl;
	while (true) {
		String command;
		awaitingCommand();
		cin >> command;
		if (checkInput() == UNSUCCESSFUL)
			continue;

		if (command == "register") {
			clearBuffer();
			regist.execute(system);
			newLine();
		}
		else if (command == "login") {
			clearBuffer();
			login.execute(system);
			newLine();
		}
		else if (command == "exit") {
			clearBuffer();
			exit.execute(system);
			newLine();
			break;
		}
		else {
			clearBuffer();
			cout << "Invalid command!" << endl;
			newLine();
		}
	}
}
