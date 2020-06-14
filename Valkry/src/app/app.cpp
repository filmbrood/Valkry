#include "valkrypch.h"

#include "app.h"
#include "logging.h"

namespace Valkry{

	void App::CloseApp()
	{
		running_ = false;
	}

	void App::Run()
	{
		OnInit();

		while (running_)
		{
			OnUpdate();
			OnEvent();
		}
	}

}