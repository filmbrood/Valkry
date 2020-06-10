#include "keyevents.h"

namespace valkry {

	keyevent::keyevent(int keycode)
	{
		this->keycode = keycode;
	}

	bool keyevent::isPressed(window& win)
	{
		if (glfwGetKey(win.getWindow(), keycode) == GLFW_PRESS)
			return true;
		else
			return false;
	}

	bool keyevent::isReleased(window& win)
	{
		if (glfwGetKey(win.getWindow(), keycode) == GLFW_RELEASE)
			return true;
		else
			return false;
	}

	bool keyevent::isRepeated(window& win)
	{
		if (glfwGetKey(win.getWindow(), keycode) == GLFW_REPEAT)
			return true;
		else
			return false;
	}
}