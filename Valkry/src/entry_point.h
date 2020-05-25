#pragma once

extern valkry::app* valkry::MakeApp();

int main()
{
	auto app = valkry::MakeApp();
	app->Run();
	delete app;
}