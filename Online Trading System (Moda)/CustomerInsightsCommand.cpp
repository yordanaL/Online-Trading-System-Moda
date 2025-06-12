#include "CustomerInsightsCommand.h"
#include "Administrator.h"

void CustomerInsightsCommand::execute(System* system)
{
	Administrator* admin = system->getAdmin(*system);
	if (admin == nullptr)
		return;

	admin->customerInsights(*system);
	admin = nullptr;
}
