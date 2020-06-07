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
		
		renderer.SetProjectionMatrix(1280.0f, 720.0f);
		renderer.SetViewMatrix(sin(glfwGetTime()), 0.0f);
		renderer.DrawQuad(shadertest, 1.0f, 1.0f, 0.0f, 0.0f);

		windowtest.endFrame();
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}