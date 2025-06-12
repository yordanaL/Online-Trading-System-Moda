#include "ExitCommand.h"
#include "SaveCommand.h"

void ExitCommand::execute(System* system)
{
	SaveCommand save;
	save.execute(system);
}
