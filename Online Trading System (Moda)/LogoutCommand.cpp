#include "LogoutCommand.h"

void LogoutCommand::execute(System* system)
{
	system->logout(*system);
}
