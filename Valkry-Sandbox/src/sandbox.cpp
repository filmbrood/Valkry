#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
public:
	void update()
	{
		valkry::LogInfo("Update!");
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}