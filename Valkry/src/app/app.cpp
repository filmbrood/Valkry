#include "valkrypch.h"
#include "app.h"

namespace Valkry{

	App App::s_Instance;

	void App::CloseApp()
	{
		exitCode_ = 0;
		running_ = false;
		Logger::Get().LogInfo("Closing program with exit code " + std::to_string(exitCode_));
		Logger::Get().DumpLogToFile();
	}

	void App::CrashApp()
	{
		exitCode_ = 1;
		running_ = false;
		Logger::Get().LogFatal("Crashing app with exit code " + std::to_string(exitCode_));
		Logger::Get().DumpLogToFile();
	}

	void App::Run()
	{
		stats_.frames++;
		stats_.runtime = glfwGetTime();

		std::string platformString = VALKRY_PLATFORM_STRING;
		Logger::Get().LogInfo("Starting Valkry Application");
		Logger::Get().LogInfo("Platform: " + platformString);
		stack_.InitLayers();

		while (running_)
		{
			if (window_.CheckForFailure())
				this->CrashApp();

			exitCode_ = -1;
			stack_.RunLayers();

			if (stack_.CheckForClosingFlags())
				this->CloseApp();

			UpdateDeltaTime();
			CalculateFPS();
		}


	}

	void App::PushLayer(Layer* layer)
	{
		stack_.PushLayer(layer);
	}

	void App::PopLayer()
	{
		stack_.PopLayer();
	}

	Window& App::GetWindow()
	{
		return window_;
	}

	Renderer2D& App::GetRenderer2D()
	{
		return renderer2D_;
	}

	AppStats App::GetStats()
	{
		return stats_;
	}

	void App::UpdateDeltaTime()
	{
		float currentFrame = glfwGetTime();
		stats_.deltaTime = currentFrame - stats_.lastFrame;
		stats_.lastFrame = currentFrame;
	}

	void App::CalculateFPS()
	{
		fpsMeasures++;
		if (fpsMeasures >= 20)
		{
			stats_.fps = 1 / stats_.deltaTime;
			fpsMeasures = 0;
		}
	}

	App& App::Get()
	{
		return s_Instance;
	}
}
