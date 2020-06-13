#include <valkry.h>

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

class player
{
private:
	float posx = 0.0f, posy = 0.0f;

public:
	float getPosX() { return posx; }

	float getPosY(){ return posy; }

	void setPos(float x, float y)
	{
		posx = x;
		posy = y;
	}

	void moveRight() { posx += 5.0f; }

	void moveLeft() { posx -= 5.0f; }

	void moveDown() { posy += 5.0f; }
	
	void moveUp() { posy -= 5.0f; }

};

class Sandbox : public Valkry::App
{
private:
	Valkry::Window sandbox_window;
	Valkry::Shader flat_shader;
	Valkry::Renderer2D renderer;

	player player;

public:
	void OnInit()
	{
		sandbox_window.SetDimensions(SCREENWIDTH, SCREENHEIGHT);
		sandbox_window.SetTitle("Valkry Renderer 0.0.0");
		sandbox_window.Create(3, 3);
		sandbox_window.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		flat_shader.SetSource("shaders/flat_color.glsl");
	}

	void OnUpdate()
	{
		renderer.SetProjectionMatrix(SCREENWIDTH, SCREENHEIGHT);
		renderer.SetViewMatrix(0.0f, 0.0f);

		sandbox_window.BeginFrame();
		
		flat_shader.SetVec3("color", 0.1f, 0.5f, 0.2f);
		renderer.DrawQuad(flat_shader, 1500, 1500, 0.0f, 0.0f);

		flat_shader.SetVec3("color", sin(4 * glfwGetTime()), 0.0f, 1.0f);
		renderer.DrawQuad(flat_shader, 100.0f, 100.0f, player.getPosX(), player.getPosY());

		sandbox_window.EndFrame();
	}

	void OnEvent()
	{
		if (sandbox_window.CheckIfClosed())
			this->CloseApp();

		player.setPos(sandbox_window.GetCursorPositionX(), sandbox_window.GetCursorPositionY());
	}
};

Valkry::App* Valkry::CreateApp()
{
	return new Sandbox;
}