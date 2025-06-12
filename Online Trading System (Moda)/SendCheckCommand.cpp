#include "SendCheckCommand.h"
#include "Administrator.h"

void SendCheckCommand::execute(System* system)
{
	Administrator* admin = system->getAdmin(*system);
	if (admin == nullptr)
		return;

	double amount = DEFAULT_VALUE;
	cout << "Amount: ";
	cin >> amount;
	if (checkInput() == UNSUCCESSFUL)
		return;

	String code = EMPTY_STR;
	cout << "Code: ";
	cin >> code;
	if (checkInput() == UNSUCCESSFUL)
		return;

	String clientEGN = EMPTY_STR;
	cout << "Client EGN: ";
	cin >> clientEGN;
	if (checkInput() == UNSUCCESSFUL)
		return;

	admin->sendCheck(*system, amount, code, clientEGN);
	admin = nullptr;
}
