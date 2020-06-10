#include <valkry.h>

valkry::keyevent LEFT_KEY(GLFW_KEY_LEFT);
valkry::keyevent RIGHT_KEY(GLFW_KEY_RIGHT);
valkry::keyevent UP_KEY(GLFW_KEY_UP);
valkry::keyevent DOWN_KEY(GLFW_KEY_DOWN);

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

		if (RIGHT_KEY.isPressed(windowtest))
			player.moveRight();

		if (LEFT_KEY.isPressed(windowtest))
			player.moveLeft();

		if (UP_KEY.isPressed(windowtest))
			player.moveUp();

		if (DOWN_KEY.isPressed(windowtest))
			player.moveDown();
	}
};

valkry::app* valkry::createapp()
{
	return new sandbox;
}