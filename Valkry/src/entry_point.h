#pragma once
#include "logging.h"

extern valkry::app* valkry::MakeApp();

int main()
{
	valkry::LogInfo("Application Created");

	auto app = valkry::MakeApp();
	app->Run();
	delete app;
}