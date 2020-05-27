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

		virtual void setup() = 0;
		virtual void update() = 0;
	};

	//define in application
	app* createapp();
}