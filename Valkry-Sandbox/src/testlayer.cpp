#include "testlayer.h"

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

void TestLayer::OnInit()
{
	SetName("Valkry Sandbox");

	sandbox_window.SetDimensions(SCREENWIDTH, SCREENHEIGHT);
	sandbox_window.SetTitle(GetName());
	sandbox_window.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	sandbox_window.SetVerticalSync(true);
	sandbox_window.SetFullscreen(false);
	sandbox_window.Create();

	flat_shader.SetSource("shaders/flat_color.glsl");
	textured_shader.SetSource("shaders/textured_color.glsl");

	texture1.LoadFromPath("res/concrete_diffuse.png");

	renderer.SetResolution(16, 9);

	InitImGui(sandbox_window);
}

void TestLayer::OnUpdate()
{
	renderer.SetCameraPosition(player1.getPosX() - 8, player1.getPosY() - 4.5);
	renderer.Update();

	sandbox_window.BeginFrame();

	renderer.DrawTexturedQuad(textured_shader, texture1, 10, 10, 0.0f, 0.0f);

	flat_shader.SetVec4("color", 0.8f, 0.1f, 0.1f, 0.5f);
	renderer.DrawQuad(flat_shader, 1, 1, player1.getPosX(), player1.getPosY());

	OnImGuiRender();

	sandbox_window.EndFrame();

	UpdateDeltaTime();
	player1.setDelta(deltaTime);
}

void TestLayer::OnImGuiRender()
{
	BeginImGuiFrame();

	ImGui::Begin("Info", &showImGuiPlayerInfo);
	ImGui::Text("Player X");
	ImGui::Text(std::to_string(player1.getPosX()).c_str());
	ImGui::Text("Player Y");
	ImGui::Text(std::to_string(player1.getPosY()).c_str());
	ImGui::Text("");
	ImGui::Text("Delta Time (ms)");
	ImGui::Text(std::to_string(deltaTime * 1000).c_str());
	ImGui::Text("FPS");
	ImGui::Text(std::to_string((1 / deltaTime)).c_str());
	ImGui::Text("");
	ImGui::Text("Camera X");
	ImGui::Text(std::to_string(renderer.GetCameraPositionX()).c_str());
	ImGui::Text("Camera Y");
	ImGui::Text(std::to_string(renderer.GetCameraPositionY()).c_str());
	ImGui::End();

	EndImGuiFrame();
}

void TestLayer::OnEvent()
{
	if (Valkry::Keys::ESC.Pressed(sandbox_window) || sandbox_window.CheckIfClosed())
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

	if (Valkry::Keys::W.Pressed(sandbox_window) && Valkry::Keys::A.Pressed(sandbox_window)
		|| Valkry::Keys::W.Pressed(sandbox_window) && Valkry::Keys::D.Pressed(sandbox_window)
		|| Valkry::Keys::S.Pressed(sandbox_window) && Valkry::Keys::D.Pressed(sandbox_window)
		|| Valkry::Keys::A.Pressed(sandbox_window) && Valkry::Keys::S.Pressed(sandbox_window))
		player1.SetSpeed(4.0f);
	else
		player1.SetSpeed(5.0f);

}

void TestLayer::UpdateDeltaTime()
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}
