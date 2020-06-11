#include "app.h"
#include "logging.h"

namespace valkry{

	app::app()
	{
		
	}

	app::~app()
	{

	}

	void app::closeApp()
	{
		running = false;
	}

	void app::setup()
	{

	}

	void app::run()
	{
		setup();

		while (running)
		{
			update();
			events();
		}
	}

}