#include "valkrypch.h"

#include "app.h"

namespace Valkry{

	void App::CloseApp()
	{
		running_ = false;
		Logger::Get().LogInfo("Closing program with exit code ", exitCode_);
		Logger::Get().LogInfo("Dumping log to valkry.log");
		Logger::Get().DumpLogToFile();
	}


	void App::Run()
	{
		stack_.InitLayers();

		while (running_)
		{
			exitCode_ = -1;
			stack_.RunLayers();

			if (stack_.CheckForClosingFlags())
				this->CloseApp();
			exitCode_ = 0;
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

}
