#include <valkry.h>

constexpr auto SCREENWIDTH = 1920;
constexpr auto SCREENHEIGHT = 1080;

Valkry::KeyEvent key_escape(GLFW_KEY_ESCAPE);

class player
{
private:
	float posx = 0.0f, posy = 0.0f;

public:
	float getPosX() { return posx; }

	float getPosY() { return posy; }

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

	float cameraX = 0.0f;

public:
	void OnInit()
	{
		sandbox_window.SetDimensions(SCREENWIDTH, SCREENHEIGHT);
		sandbox_window.SetTitle("Valkry Sandbox");
		sandbox_window.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		sandbox_window.SetVerticalSync(true);
		sandbox_window.SetFullscreen(true);
		sandbox_window.Create(3, 3);

		flat_shader.SetSource("shaders/flat_color.glsl");

		renderer.SetResolution(SCREENWIDTH, SCREENHEIGHT);
	}

	void OnUpdate()
	{
		cameraX += 1.0f;
		renderer.SetCameraPosition(cameraX, 0.0f);
		renderer.Update();

		sandbox_window.BeginFrame();
		
		flat_shader.SetVec3("color", 0.1f, 0.5f, 0.2f);
		renderer.DrawQuad(flat_shader, 1500, 1500, 0.0f, 0.0f);

		flat_shader.SetVec3("color", 0.0f, 0.1f, 0.8f);
		renderer.DrawQuad(flat_shader, 100.0f, 100.0f, player.getPosX(), player.getPosY());

		sandbox_window.EndFrame();
	}

	void OnEvent()
	{
		if (sandbox_window.CheckIfClosed())
			CloseApp();

		if (key_escape.Pressed(sandbox_window))
			sandbox_window.Close();

		player.setPos(sandbox_window.GetCursorPositionX(), sandbox_window.GetCursorPositionY());
	}
};

Valkry::App* Valkry::CreateApp()
{
	return new Sandbox;
}