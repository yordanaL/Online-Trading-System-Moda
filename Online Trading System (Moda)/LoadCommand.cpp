#include "LoadCommand.h"

void LoadCommand::execute(System* system)
{
	system->load(*system);
}
