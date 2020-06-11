#include "keyevents.h"
#include "../app/logging.h"

namespace valkry {

	keyevent::keyevent(int keycode)
	{
		this->keycode = keycode;
	}

	bool keyevent::isPressed(window& win)
	{
		if (glfwGetKey(win.getWindow(), keycode) == GLFW_PRESS)
		{
			LogInfo("Key Pressed", keycode);
			return true;
		}
		else
			return false;
	}

	bool keyevent::isReleased(window& win)
	{
		if (glfwGetKey(win.getWindow(), keycode) == GLFW_RELEASE)
		{
			LogInfo("Key Released", keycode);
			return true;
		}
		else
			return false;
	}

	bool keyevent::isRepeated(window& win)
	{
		if (glfwGetKey(win.getWindow(), keycode) == GLFW_REPEAT)
		{
			LogInfo("Key Repeated", keycode);
			return true;
		}
		else
			return false;
	}
}