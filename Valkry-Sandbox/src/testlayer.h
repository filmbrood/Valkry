#include "valkry.h"
#include "player.h"

class TestLayer : public Valkry::Layer
{
public:
	void OnInit();
	void OnUpdate();
	void OnImGuiRender();
	void OnEvent();

private:
	Valkry::Window sandbox_window;
	Valkry::Renderer2D renderer;

	Valkry::Shader flat_shader;
	Valkry::Shader textured_shader;
	Valkry::Texture texture1;

	player player1;

	bool showImGuiDemoWindow = true;
	bool showImGuiTestWindow = true;
	bool showImGuiViewport = true;
};