#include "valkrypch.h"

#include "app.h"

namespace Valkry{

	void App::CloseApp()
	{
		running_ = false;
	}

	void App::Run()
	{
		stack_.InitLayers();

		while (running_)
		{
			stack_.RunLayers();

			if (stack_.CheckForClosingFlags())
				running_ = false;
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