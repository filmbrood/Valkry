#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
private:
	valkry::window windowtest;
	valkry::shader* shadertest;
public:

	void setup()
	{
		shadertest = new valkry::shader("shaders/test_shader.glsl");
	}

	void update()
	{
		windowtest.refresh();
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}