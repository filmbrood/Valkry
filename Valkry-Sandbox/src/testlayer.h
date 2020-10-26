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

public:
	void UpdateDeltaTime();

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
