#include <valkry.h>
#include <iostream>

class player
{
private:
	float posx = 0.0f, posy = 0.0f;

public:
	float getPosX()
	{
		return posx;
	}

	float getPosY()
	{
		return posy;
	}

	void moveRight()
	{
		posx++;
	}

	void moveDown()
	{
		posy++;
	}

	void moveUp()
	{
		posy--;
	}

	void moveLeft()
	{
		posx--;
	}
};

class sandbox : public valkry::app
{
private:
	valkry::window windowtest;
	valkry::shader shadertest;
	valkry::renderer renderer;

	player player;

public:
	void setup()
	{
		shadertest.setSource("shaders/test_shader.glsl");
		renderer.SetProjectionMatrix(1280.0f, 720.0f);
		windowtest.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	}

	void update()
	{
		renderer.SetViewMatrix(0.0f, 0.0f);

		windowtest.beginFrame();
		
		renderer.DrawQuad(shadertest, 100.0f, 100.0f, player.getPosX(), player.getPosY());

		windowtest.endFrame();
	}

	void events()
	{
		if (windowtest.isClosed())
			this->closeApp();

		if (glfwGetKey(windowtest.getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
			player.moveRight();

		if (glfwGetKey(windowtest.getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
			player.moveLeft();

		if (glfwGetKey(windowtest.getWindow(), GLFW_KEY_UP) == GLFW_PRESS)
			player.moveUp();

		if (glfwGetKey(windowtest.getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS)
			player.moveDown();
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}