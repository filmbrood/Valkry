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

	flat_shader.SetSeparateSource("shaders/flat_color_vertex.glsl", "shaders/flat_color_fragment.glsl");
	textured_shader.SetSeparateSource("shaders/textured_color_vertex.glsl", "shaders/textured_color_fragment.glsl");

	texture1.LoadFromPath("res/concrete_diffuse.png");

	renderer.SetResolution(16, 9);
	this->InitImGui(sandbox_window);

	renderer.InitQuadBatch(textured_shader, texture1);
}

void TestLayer::OnUpdate()
{
	renderer.SetCameraPosition(player1.getPosX(), player1.getPosY());
	renderer.Update();

	float xpos = -5, ypos = 5;
	for (int i = 0; i < quadCount; i++)
	{
		ypos = 0;
		renderer.AddQuadToBatch(1, 1, xpos, 0.0f);
		xpos++;
		for (int j = 0; j < quadCount; j++)
		{
			renderer.AddQuadToBatch(1, 1, xpos, ypos);
			ypos++;
		}
	}

	sandbox_window.BeginFrame();

	renderer.DrawQuadBatch();
	renderer.ClearQuadBatch();

	renderer.DrawQuad(flat_shader, 1, 1, player1.getPosX(), player1.getPosY());

	this->OnImGuiRender();

	sandbox_window.EndFrame();

	this->UpdateDeltaTime();
	player1.setDelta(deltaTime);

	runtime = glfwGetTime();
	frameCount++;
	currentFPSMeasure += deltaTime;
	if (currentFPSMeasure > 0.3)
	{
		FPS = 1 / deltaTime;
		currentFPSMeasure = 0;
		FPSmeasurecount++;

		if (FPS > maxFPS)
			maxFPS = FPS;

		if (FPS < minFPS)
			minFPS = FPS;

		avgFPS = frameCount / runtime;
	}

	if (minFPS == 0)
		minFPS = FPS;
}

void TestLayer::OnImGuiRender()
{
	this->BeginImGuiFrame();

	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("ImGui Panels"))
	{
		if (ImGui::MenuItem("Info")) { showImGuiPlayerInfo = true; }
		if (ImGui::MenuItem("Settings")) { showImGuiSettings = true; }
		ImGui::EndMenu();
	}
	ImGui::EndMainMenuBar();
	if (showImGuiPlayerInfo)
	{
		ImGui::Begin("Info", &showImGuiPlayerInfo);
		ImGui::Text("Runtime");
		ImGui::Text(std::to_string(glfwGetTime()).c_str());
		ImGui::Text("Player X");
		ImGui::Text(std::to_string(player1.getPosX()).c_str());
		ImGui::Text("Player Y");
		ImGui::Text(std::to_string(player1.getPosY()).c_str());
		ImGui::Text("Camera X");
		ImGui::Text(std::to_string(renderer.GetCameraPositionX()).c_str());
		ImGui::Text("Camera Y");
		ImGui::Text(std::to_string(renderer.GetCameraPositionY()).c_str());
		ImGui::Text("");
		ImGui::Text("Draw Calls per Frame");
		ImGui::Text(std::to_string(renderer.GetStats().DrawCallsInFrame).c_str());
		ImGui::Text("Draw Skips per Frame");
		ImGui::Text(std::to_string(renderer.GetStats().DrawSkipsInFrame).c_str());
		ImGui::Text("Batch Quads per Frame");
		ImGui::Text(std::to_string(renderer.GetStats().BatchDrawsInFrame).c_str());
		ImGui::Text("Batch Skips per Frame");
		ImGui::Text(std::to_string(renderer.GetStats().BatchSkipsInFrame).c_str());
		ImGui::Text("Delta Time (ms)");
		ImGui::Text(std::to_string(deltaTime * 1000).c_str());
		ImGui::Text("FPS");
		ImGui::Text(std::to_string(FPS).c_str());
		ImGui::Text("Max FPS");
		ImGui::Text(std::to_string(maxFPS).c_str());
		ImGui::Text("Avg FPS");
		ImGui::Text(std::to_string(avgFPS).c_str());
		ImGui::Text("Min FPS");
		ImGui::Text(std::to_string(minFPS).c_str());
		ImGui::Text("FPS Measure Count");
		ImGui::Text(std::to_string(FPSmeasurecount).c_str());
		ImGui::Text("Frame Count");
		ImGui::Text(std::to_string(frameCount).c_str());
		ImGui::End();
	}

	if (showImGuiSettings)
	{
		ImGui::Begin("Settings", &showImGuiSettings);
		if (ImGui::Button("Set Vsync On")) { sandbox_window.SetVerticalSync(true); }
		if (ImGui::Button("Set Vsync Off")) { sandbox_window.SetVerticalSync(false); }
		if (ImGui::Button("Reset FPS Counters")) { maxFPS = 0; minFPS = 0; avgFPS = 0; FPSmeasurecount = 0; frameCount = 0;}
		float rdoffset = renderer.GetRenderDistanceOffset();
		if (ImGui::SliderFloat("Render Distance Offset", &rdoffset, -3.0f, 3.0f)) { renderer.SetRenderDistanceOffset(rdoffset); }
		ImGui::InputInt("Quad Count (will be squared!)", &quadCount);
		if (ImGui::Button("Set quad skipping on")) { renderer.SetQuadDrawSkipping(true); }
		if (ImGui::Button("Set quad skipping off")) { renderer.SetQuadDrawSkipping(false); }
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
