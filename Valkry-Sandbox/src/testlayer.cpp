#include "testlayer.h"

#define SCREENWIDTH 1280
#define SCREENHEIGHT 720

void TestLayer::OnInit()
{
	SetName("Valkry Sandbox");

	sandbox_window.SetDimensions(SCREENWIDTH, SCREENHEIGHT);
	sandbox_window.SetTitle(this->GetName());
	sandbox_window.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	sandbox_window.SetFullscreen(false);
	sandbox_window.Create();

	flat_shader.SetSource("shaders/flat_color.glsl");
	textured_shader.SetSource("shaders/textured_color.glsl");

	texture1.LoadFromPath("res/concrete_diffuse.png");

	renderer.SetResolution(16, 9);
	this->InitImGui(sandbox_window);
}

void TestLayer::OnUpdate()
{
	renderer.SetCameraPosition(player1.getPosX(), player1.getPosY());
	renderer.Update();

	sandbox_window.BeginFrame();

	float xpos = 0;
	float ypos = 0;
	for (int i = 0; i < 300; i++)
	{
		ypos = 0;
		renderer.DrawTexturedQuad(textured_shader, texture1, 1, 1, xpos, 0.0f);
		xpos++;
		for (int i = 0; i < 300; i++)
		{
			renderer.DrawTexturedQuad(textured_shader, texture1, 1, 1, xpos, ypos);
			ypos++;
		}
	}

	flat_shader.SetVec4("color", 0.8f, 0.1f, 0.1f, 0.5f);
	renderer.DrawQuad(flat_shader, 1, 1, player1.getPosX(), player1.getPosY());

	this->OnImGuiRender();

	sandbox_window.EndFrame();

	this->UpdateDeltaTime();
	player1.setDelta(deltaTime);

	frameCount++;
	if (frameCount == 10)
	{
		FPS = 1 / deltaTime;
		frameCount = 0;

		if (FPS > maxFPS)
			maxFPS = FPS;

		if (FPS < minFPS)
			minFPS = FPS;
	}

	if (minFPS == 0)
		minFPS = FPS;
}

void TestLayer::OnImGuiRender()
{
	this->BeginImGuiFrame();

	if (showImGuiPlayerInfo)
	{
		ImGui::Begin("Info", &showImGuiPlayerInfo);
		ImGui::Text("Player X");
		ImGui::Text(std::to_string(player1.getPosX()).c_str());
		ImGui::Text("Player Y");
		ImGui::Text(std::to_string(player1.getPosY()).c_str());
		ImGui::Text("");
		ImGui::Text("Draw Calls per Frame");
		ImGui::Text(std::to_string(renderer.GetStats().DrawCallsInFrame).c_str());
		ImGui::Text("Draw Skips per Frame");
		ImGui::Text(std::to_string(renderer.GetStats().DrawSkipsInFrame).c_str());
		ImGui::Text("Delta Time (ms)");
		ImGui::Text(std::to_string(deltaTime * 1000).c_str());
		ImGui::Text("FPS");
		ImGui::Text(std::to_string(FPS).c_str());
		ImGui::Text("Max FPS");
		ImGui::Text(std::to_string(maxFPS).c_str());
		ImGui::Text("Min FPS");
		ImGui::Text(std::to_string(minFPS).c_str());
		ImGui::Text("Camera X");
		ImGui::Text(std::to_string(renderer.GetCameraPositionX()).c_str());
		ImGui::Text("Camera Y");
		ImGui::Text(std::to_string(renderer.GetCameraPositionY()).c_str());
		ImGui::End();
	}

	if (showImGuiSettings)
	{
		ImGui::Begin("Settings", &showImGuiSettings);
		if (ImGui::Button("Toggle Vsync"))
		{
			if (sandbox_window.GetVerticalSync())
			{
				sandbox_window.SetVerticalSync(false);
				vsyncStateString = "Vsync Off";
			}
			else if (!sandbox_window.GetVerticalSync())
			{
				sandbox_window.SetVerticalSync(true);
				vsyncStateString = "Vsync On";
			}
		}
		if (ImGui::Button("Reset Min/Max FPS Counters"))
		{
			maxFPS = 0;
			minFPS = 0;
		}
		float rdoffset = renderer.GetRenderDistanceOffset();
		ImGui::SliderFloat("Render Distance Offset", &rdoffset, -10.0f, 10.0f);
		renderer.SetRenderDistanceOffset(rdoffset);
		ImGui::Text(vsyncStateString.c_str());
		ImGui::End();
	}

	this->EndImGuiFrame();
}

void TestLayer::OnEvent()
{
	if (Valkry::Keys::ESC.Pressed(sandbox_window) || sandbox_window.CheckIfClosed())
	{
		this->CloseProgram();
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
