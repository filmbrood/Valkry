#include <Valkry.h>

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

Valkry::KeyEvent LEFT_KEY(GLFW_KEY_LEFT);
Valkry::KeyEvent RIGHT_KEY(GLFW_KEY_RIGHT);
Valkry::KeyEvent UP_KEY(GLFW_KEY_UP);
Valkry::KeyEvent DOWN_KEY(GLFW_KEY_DOWN);

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

class sandbox : public Valkry::App
{
private:
	Valkry::Window windowtest;
	Valkry::Shader shadertest;
	Valkry::Renderer2D renderer2D;

	player player;

public:
	void OnInit()
	{
		windowtest.SetDimensions(SCREENWIDTH, SCREENHEIGHT);
		windowtest.SetTitle("Valkry Renderer 0.0.0");
		windowtest.Create(3, 3);
		windowtest.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		shadertest.SetSource("shaders/test_shader.glsl");
	}

	void OnUpdate()
	{
		renderer2D.SetProjectionMatrix(SCREENWIDTH, SCREENHEIGHT);
		renderer2D.SetViewMatrix(0.0f, 0.0f);

		windowtest.BeginFrame();
		
		shadertest.SetVec3("color", 0.1f, 0.5f, 0.2f);
		renderer2D.DrawQuad(shadertest, 1500, 1500, 0.0f, 0.0f);

		shadertest.SetVec3("color", sin(4 * glfwGetTime()), 0.0f, 1.0f);
		renderer2D.DrawQuad(shadertest, 100.0f, 100.0f, player.getPosX(), player.getPosY());

		windowtest.EndFrame();
	}

	void OnEvent()
	{
		if (windowtest.CheckIfClosed())
			this->CloseApp();

		if (RIGHT_KEY.Pressed(windowtest))
			player.moveRight();

		if (LEFT_KEY.Pressed(windowtest))
			player.moveLeft();

		if (UP_KEY.Pressed(windowtest))
			player.moveUp();

		if (DOWN_KEY.Pressed(windowtest))
			player.moveDown();
	}
};

Valkry::App* Valkry::CreateApp()
{
	return new sandbox;
}