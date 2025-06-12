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

void clearBuffer()
{
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void newLine()
{
	cout << endl;	
}

bool isNumber(char ch)
{
	return (ch >= '0' && ch <= '9');
}
