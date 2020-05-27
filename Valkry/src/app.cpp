#include "app.h"

namespace valkry{

	app::app()
	{
		
	}

	app::~app()
	{

	}

	void app::run()
	{
		while (running)
			update();
	}

}