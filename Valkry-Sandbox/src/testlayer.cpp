#include "testlayer.h"

void TestLayer::OnInit()
{
	this->SetName("Valkry Sandbox");

	flat_shader.SetSeparateSource("shaders/flat_color_vertex.glsl", "shaders/flat_color_fragment.glsl");
	textured_shader.SetSeparateSource("shaders/textured_color_vertex.glsl", "shaders/textured_color_fragment.glsl");

	texture1.LoadFromPath("res/concrete_diffuse.png");

	Valkry::App::Get().GetRenderer2D().InitQuadBatch(textured_shader, texture1);

	this->InitImGui(Valkry::App::Get().GetWindow());
}

void TestLayer::OnUpdate()
{
	Valkry::App::Get().GetRenderer2D().SetProjectionMatrix(Valkry::App::Get().GetWindow().GetWidth(), Valkry::App::Get().GetWindow().GetHeight());
	Valkry::App::Get().GetRenderer2D().SetCameraPosition(player1.getPosX(), player1.getPosY());
	Valkry::App::Get().GetRenderer2D().Update();

	float xpos = -5, ypos = 5;
	for (int i = 0; i < quadCount; i++)
	{
		ypos = 0;
		Valkry::App::Get().GetRenderer2D().AddQuadToBatch(1, 1, xpos, 0.0f);
		xpos++;
		for (int j = 0; j < quadCount; j++)
		{
			Valkry::App::Get().GetRenderer2D().AddQuadToBatch(1, 1, xpos, ypos);
			ypos++;
		}
	}

	Valkry::App::Get().GetWindow().BeginFrame();

	Valkry::App::Get().GetRenderer2D().DrawQuadBatch();
	Valkry::App::Get().GetRenderer2D().ClearQuadBatch();

	Valkry::App::Get().GetRenderer2D().DrawQuad(flat_shader, 1, 1, player1.getPosX(), player1.getPosY());

	this->OnImGuiRender();

	Valkry::App::Get().GetWindow().EndFrame();

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

		avgFPS = frameCount / FPSmeasurecount;
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
		ImGui::Text(std::to_string(Valkry::App::Get().GetRenderer2D().GetCameraPositionX()).c_str());
		ImGui::Text("Camera Y");
		ImGui::Text(std::to_string(Valkry::App::Get().GetRenderer2D().GetCameraPositionY()).c_str());
		ImGui::Text("");
		ImGui::Text("Draw Calls per Frame");
		ImGui::Text(std::to_string(Valkry::App::Get().GetRenderer2D().GetStats().DrawCallsInFrame).c_str());
		ImGui::Text("Draw Skips per Frame");
		ImGui::Text(std::to_string(Valkry::App::Get().GetRenderer2D().GetStats().DrawSkipsInFrame).c_str());
		ImGui::Text("Batch Quads per Frame");
		ImGui::Text(std::to_string(Valkry::App::Get().GetRenderer2D().GetStats().BatchDrawsInFrame).c_str());
		ImGui::Text("Batch Skips per Frame");
		ImGui::Text(std::to_string(Valkry::App::Get().GetRenderer2D().GetStats().BatchSkipsInFrame).c_str());
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
		if (ImGui::Button("Set Vsync On")) { Valkry::App::Get().GetWindow().SetVerticalSync(true); }
		if (ImGui::Button("Set Vsync Off")) { Valkry::App::Get().GetWindow().SetVerticalSync(false); }
		if (ImGui::Button("Reset FPS Counters")) { maxFPS = 0; minFPS = 0; avgFPS = 0; FPSmeasurecount = 0; frameCount = 0;}
		float rdoffset = Valkry::App::Get().GetRenderer2D().GetRenderDistanceOffset();
		if (ImGui::SliderFloat("Render Distance Offset", &rdoffset, -3.0f, 3.0f)) { Valkry::App::Get().GetRenderer2D().SetRenderDistanceOffset(rdoffset); }
		ImGui::InputInt("Quad Count (will be squared!)", &quadCount);
		if (ImGui::Button("Set quad skipping on")) { Valkry::App::Get().GetRenderer2D().SetQuadDrawSkipping(true); }
		if (ImGui::Button("Set quad skipping off")) { Valkry::App::Get().GetRenderer2D().SetQuadDrawSkipping(false); }
		ImGui::SliderFloat("Player Speed", &playerSpeed, 0.1f, 100.0f);
		if (ImGui::SliderFloat("Camera Zoom", &cameraZoom, 0.01f, 10.0f)) { Valkry::App::Get().GetRenderer2D().SetCameraZoom(cameraZoom); }
		ImGui::End();
	}

	this->EndImGuiFrame();
}

void TestLayer::OnEvent()
{
	if (Valkry::Keys::ESC.Pressed(Valkry::App::Get().GetWindow()) || Valkry::App::Get().GetWindow().CheckIfClosed())
	{
		this->CloseProgram();
	}

	if (Valkry::Keys::W.Pressed(Valkry::App::Get().GetWindow()))
	{
		player1.moveUp();
	}

	if (Valkry::Keys::A.Pressed(Valkry::App::Get().GetWindow()))
	{
		player1.moveLeft();
	}

	if (Valkry::Keys::S.Pressed(Valkry::App::Get().GetWindow()))
	{
		player1.moveDown();
	}

	if (Valkry::Keys::D.Pressed(Valkry::App::Get().GetWindow()))
	{
		player1.moveRight();
	}

	if (Valkry::Keys::W.Pressed(Valkry::App::Get().GetWindow()) && Valkry::Keys::A.Pressed(Valkry::App::Get().GetWindow())
		|| Valkry::Keys::W.Pressed(Valkry::App::Get().GetWindow()) && Valkry::Keys::D.Pressed(Valkry::App::Get().GetWindow())
		|| Valkry::Keys::S.Pressed(Valkry::App::Get().GetWindow()) && Valkry::Keys::D.Pressed(Valkry::App::Get().GetWindow())
		|| Valkry::Keys::A.Pressed(Valkry::App::Get().GetWindow()) && Valkry::Keys::S.Pressed(Valkry::App::Get().GetWindow()))
		player1.SetSpeed(playerSpeed * 0.8f);
	else
		player1.SetSpeed(playerSpeed);

}

void TestLayer::UpdateDeltaTime()
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}
