#include "testlayer.h"

void TestLayer::OnInit()
{
	SetName("Valkry Sandbox");

	sandbox_window.SetDimensions(1280, 720);
	sandbox_window.SetTitle(GetName());
	sandbox_window.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	sandbox_window.SetVerticalSync(true);
	sandbox_window.SetFullscreen(false);
	sandbox_window.Create(3, 3);

	flat_shader.SetSource("shaders/flat_color.glsl");
	textured_shader.SetSource("shaders/textured_color.glsl");

	texture1.LoadFromPath("res/concrete_diffuse.png");

	renderer.SetResolution(1280, 720);
}

void TestLayer::OnUpdate()
{
	renderer.SetCameraPosition(player1.getPosX() - 640, player1.getPosY() - 360);
	renderer.Update();

	sandbox_window.BeginFrame();

	renderer.DrawTexturedQuad(textured_shader, texture1, 750, 750, 0.0f, 0.0f);

	flat_shader.SetVec4("color", 0.8f, 0.1f, 0.1f, 0.5f);
	renderer.DrawQuad(flat_shader, 100.0f, 100.0f, player1.getPosX(), player1.getPosY());

	sandbox_window.EndFrame();
}

void TestLayer::OnEvent()
{
	if (Valkry::Keys::ESC.Pressed(sandbox_window))
	{
		CloseProgram();
	}

	if (Valkry::Keys::W.Pressed(sandbox_window))
	{
		player1.moveUp();
	}

	if (Valkry::Keys::A.Pressed(sandbox_window))
	{
		player1.moveLeft();
	}

	if (Valkry::Keys::S.Pressed(sandbox_window))
	{
		player1.moveDown();
	}

	if (Valkry::Keys::D.Pressed(sandbox_window))
	{
		player1.moveRight();
	}

}

