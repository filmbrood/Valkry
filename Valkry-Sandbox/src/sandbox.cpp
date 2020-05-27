#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
private:
	valkry::window windowtest;

	valkry::shader* shadertest;
	valkry::vertexbuffer buffertest;
	valkry::attribarray testattribarray;
public:

	void setup()
	{
		float testverts[] = {
			-1.0f, -1.0f, 0.0f,
			 1.0f, -1.0f, 0.0f,
			 0.0f, 1.0f, 0.0f
		};

		shadertest = new valkry::shader("shaders/test_shader.glsl");
		buffertest.setData(testverts, sizeof(testverts));
		testattribarray.setData(0, 3, 12, 0);
		testattribarray.enable();

		windowtest.setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	void update()
	{
		shadertest->bind();
		buffertest.bind();

		// Render command to go here
		windowtest.refresh();
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}