#include "FrequentlyUsedFunctions.h"

void awaitingCommand()
{
	cout << "> ";
}

bool checkInput()
{
	if (!cin) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << "Unexpected input!" << endl;
		return UNSUCCESSFUL;
	}

	return SUCCESSFUL;
}
