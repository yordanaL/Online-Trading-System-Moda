#include <iostream>
#include "System.h"
#include "Command.h"
#include "RunSystemCommand.h"

int main() {
	System* system = &System::getInstance();
	RunSystemCommand runSystem;
	runSystem.execute(system);
}