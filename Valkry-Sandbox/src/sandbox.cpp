#include <valkry.h>
#include <iostream>

class sandbox : public valkry::app
{
private:
	float testvertices[9] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f
	};

	valkry::window windowtest;

	valkry::vertexbuffer testbuffer;
public:
	
	void update()
	{
		windowtest.refresh();

		testbuffer.setData(testvertices, sizeof(testvertices));
		testbuffer.bind();
		
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}