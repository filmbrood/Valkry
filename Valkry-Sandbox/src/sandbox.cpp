#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
private:
	valkry::window windowtest;
	valkry::shader shadertest;
	valkry::renderer renderer;

public:
	void setup()
	{
		shadertest.setSource("shaders/test_shader.glsl");
	}

	void update()
	{
		windowtest.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		windowtest.beginFrame();
		
		renderer.DrawQuad(shadertest, 0.5f, 1.0f);

		windowtest.endFrame();
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}