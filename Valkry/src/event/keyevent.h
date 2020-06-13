#pragma once

#include "../app/logging.h"
#include "../app/window.h"

#include "GLFW/glfw3.h"

namespace Valkry {

	class KeyEvent
	{
	private:
		int keycode_;

	public:
		KeyEvent(int keycode);

		bool Pressed(Window& window);
		bool Released(Window& window);
		bool Repeated(Window& window);
	};
}