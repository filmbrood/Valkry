#include "valkry.h"
#include "player.h"

class TestLayer : public Valkry::Layer
{
public:
	void OnInit();
	void OnUpdate();
	void OnEvent();

private:
	Valkry::Window sandbox_window;
	Valkry::Shader flat_shader;
	Valkry::Renderer2D renderer;

	player player1;
};