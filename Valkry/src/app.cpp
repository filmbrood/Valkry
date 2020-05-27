#include "app.h"

namespace valkry{

	app::app() : appwindow(valkry::window(1280, 720, "Valkry"))
	{
		
	}

	app::~app()
	{

	}

	void app::run()
	{
		while (!appwindow.isClosed())
		{
			appwindow.refresh();
			update();
		}

		appwindow.close();
	}

}