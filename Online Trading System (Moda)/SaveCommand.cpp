#include "SaveCommand.h"

void SaveCommand::execute(System* system)
{
	system->save();
}
