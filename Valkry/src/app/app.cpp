#include "valkrypch.h"

#include "app.h"

namespace Valkry{

	void App::CloseApp()
	{
		running_ = false;
		Logger::Get().LogInfo("Closing program with exit code ", exitCode);
		Logger::Get().LogInfo("Dumping log to valkry.log");
		Logger::Get().DumpLogToFile();
	}


	void App::Run()
	{
		stack_.InitLayers();

		while (running_)
		{
			stack_.RunLayers();

			if (stack_.CheckForClosingFlags())
				this->CloseApp();
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
