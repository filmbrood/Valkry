#pragma once
#include "window.h"

namespace valkry{

	class app
	{
	private:
		valkry::window appwindow;

	public:
		app();
		~app();

		void run();

		virtual void update() = 0;
	};

	//define in application
	app* createapp();
}