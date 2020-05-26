#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
public:
	void Run()
	{
		valkry::LogWarn("Warning Test");
		valkry::LogError("Error Test");
		valkry::LogFatal("Fatal Test");
		while (true);
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}