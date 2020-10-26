#include "valkry.h"
#include "player.h"

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

class TestLayer : public Valkry::Layer
{
public:
	void OnInit();
	void OnUpdate();
	void OnImGuiRender();
	void OnEvent();

private:
	Valkry::Shader flat_shader;
	Valkry::Shader textured_shader;
	Valkry::Texture texture1;

	player player1;
	float playerSpeed = 5;

	float cameraZoom = 1;

	bool showImGuiDemoWindow = true;
	bool showImGuiPlayerInfo = true;
	bool showImGuiSettings = true;

	int quadCount = 1;

	bool drawCursorQuad = false;
};
