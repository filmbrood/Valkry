#pragma once
#include "window.h"

namespace valkry{

	class app
	{
	private:
		bool running = true;
	public:
		app();
		~app();

		void run();

		virtual void update() = 0;
	};

	//define in application
	app* createapp();
}