#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
public:
	void run()
	{
		valkry::LogWarn("Warning Test");
		valkry::LogError("Error Test");
		valkry::LogFatal("Fatal Test");

		valkry::window testWindow(1280, 720, "Valkry");

		while (true)
			testWindow.refresh();
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}