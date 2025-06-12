#include "ViewTransactionsCommand.h"
#include "Administrator.h"

void ViewTransactionsCommand::execute(System* system)
{
	Administrator* admin = system->getAdmin(*system);
	if (admin == nullptr)
		return;

	admin->viewTransactions(*system);
	admin = nullptr;
}
