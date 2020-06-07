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
		renderer.SetProjectionMatrix(1280.0f, 720.0f);
	}

	void update()
	{
		renderer.SetViewMatrix(0.0f, 0.0f);
		windowtest.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		windowtest.beginFrame();
		
		renderer.DrawQuad(shadertest, 100.0f, 100.0f, 200 * sin(glfwGetTime()) + 640, 200.0f);
		renderer.DrawQuad(shadertest, 100.0f, 100.0f, 200 * sin(glfwGetTime() - 1) + 640, 400.0f);

		windowtest.endFrame();
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}