#pragma once
#include "../window.h"
#include "GLFW/glfw3.h"

namespace valkry {

	class keyevent
	{
	private:
		int keycode;

	public:
		keyevent(int keycode);

		bool isPressed(window& win);
		bool isReleased(window& win);
		bool isRepeated(window& win);
	};
}