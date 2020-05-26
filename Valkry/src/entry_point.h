#pragma once
#include "logging.h"

extern valkry::app* valkry::createapp();

int main()
{
	valkry::LogInfo("Application Created");

	auto app = valkry::createapp();
	app->run();
	delete app;
}