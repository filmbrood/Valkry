#include "testlayer.h"

Valkry::KeyEvent key_escape(GLFW_KEY_ESCAPE);

void TestLayer::OnInit()
{
	SetName("TestLayer");

	sandbox_window.SetDimensions(1280, 720);
	sandbox_window.SetTitle("Valkry Sandbox");
	sandbox_window.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	sandbox_window.SetVerticalSync(true);
	sandbox_window.SetFullscreen(false);
	sandbox_window.Create(3, 3);

	flat_shader.SetSource("shaders/flat_color.glsl");

	renderer.SetResolution(1280, 720);
}

void TestLayer::OnUpdate()
{
	renderer.SetCameraPosition(0.0f, 0.0f);
	renderer.Update();

	sandbox_window.BeginFrame();

	flat_shader.SetVec3("color", 0.1f, 0.5f, 0.2f);
	renderer.DrawQuad(flat_shader, 1500, 1500, 0.0f, 0.0f);

	flat_shader.SetVec3("color", 0.0f, 0.1f, 0.8f);
	renderer.DrawQuad(flat_shader, 100.0f, 100.0f, player1.getPosX(), player1.getPosY());

	sandbox_window.EndFrame();
}

void TestLayer::OnEvent()
{
	if (key_escape.Pressed(sandbox_window))
	{
		sandbox_window.Close();
		CloseProgram();
	}

	player1.setPos(sandbox_window.GetCursorPositionX(), sandbox_window.GetCursorPositionY());
}