#include "ExitCommand.h"
#include "SaveCommand.h"

void ExitCommand::execute(System* system)
{
	SaveCommand save;
	save.execute(system);
	cout << "Thank you for shopping with us! See you next time for more awesome finds!" << endl;
}
