#pragma once
#include "logging.h"

extern Valkry::App* Valkry::CreateApp();

int main()
{
	Valkry::LogInfo("Application Created");

	auto app = Valkry::CreateApp();
	app->Run();
	delete app;
}