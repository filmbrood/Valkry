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

valkry::app* valkry::MakeApp()
{
	return new sandbox;
}