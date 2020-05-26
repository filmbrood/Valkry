#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
public:
	void Run()
	{
		while (true);
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}