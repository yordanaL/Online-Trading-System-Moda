#include "LoginCommand.h"

void LoginCommand::execute(System* system)
{
	system->login(*system);
}
