#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
public:
	Sandbox() {}
	~Sandbox() {}

	void Run()
	{
		std::cout << "Sandbox creation successful\n";
		while (true);
	}
};

valkry::app* valkry::MakeApp()
{
	return new sandbox;
}