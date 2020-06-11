#include <valkry.h>

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

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
		posx += 5.0f;
	}

	void moveLeft()
	{
		posx -= 5.0f;
	}

	void moveDown()
	{
		posy += 5.0f;
	}

	void moveUp()
	{
		posy -= 5.0f;
	}

};

class sandbox : public valkry::app
{
private:
	valkry::window windowtest;
	valkry::shader shadertest;
	valkry::renderer2D renderer2D;

	player player;

public:
	void setup()
	{
		windowtest.setDimensions(SCREENWIDTH, SCREENHEIGHT);
		windowtest.setTitle("Valkry Renderer 0.0.0");
		windowtest.create(3, 3);
		windowtest.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		shadertest.setSource("shaders/test_shader.glsl");
	}

	void update()
	{
		renderer2D.SetProjectionMatrix(SCREENWIDTH, SCREENHEIGHT);
		renderer2D.SetViewMatrix(0.0f, 0.0f);

		windowtest.beginFrame();
		
		shadertest.setVec3("color", 0.1f, 0.5f, 0.2f);
		renderer2D.DrawQuad(shadertest, 1500, 1500, 0.0f, 0.0f);

		shadertest.setVec3("color", sin(4 * glfwGetTime()), 0.0f, 1.0f);
		renderer2D.DrawQuad(shadertest, 100.0f, 100.0f, player.getPosX(), player.getPosY());

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