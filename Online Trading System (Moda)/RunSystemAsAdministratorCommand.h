#pragma once
#include <iostream>
using namespace std;
#include "Command.h"
class Administartor;
class SendCheckCommand;
class CustomerInsightsCommand;
class ViewTransactionsCommand;
class LogoutCommand;
class HelpCommand;
class ViewProfileCommand;

class RunSystemAsAdministratorCommand : public Command {
public:
	void execute(System* system) override;
};

