#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
public:
	valkry::window windowtest;

	void update()
	{
		windowtest.refresh();
		valkry::LogInfo("Update!");
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}