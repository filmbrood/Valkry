#include "valkry.h"
#include "player.h"

class TestLayer : public Valkry::Layer
{
public:
	void OnInit();
	void OnUpdate();
	void OnImGuiRender();
	void OnEvent();

public:
	void UpdateDeltaTime();

private:
	Valkry::Window sandbox_window;
	Valkry::Renderer2D renderer;

	Valkry::Shader flat_shader;
	Valkry::Shader textured_shader;
	Valkry::Texture texture1;

	player player1;

	bool showImGuiDemoWindow = true;
	bool showImGuiPlayerInfo = true;
	bool showImGuiSettings = true;

	float deltaTime = 0.0f, lastFrame = 0.0f;
	float runtime = 0.0f;

	unsigned int frameCount = 0;
	float FPS = 0;
	float maxFPS = 0;
	float minFPS = 0;
	float avgFPS = 0;
	float currentFPSMeasure = 0;
	unsigned int FPSmeasurecount = 0;
	int quadCount = 1;
};
