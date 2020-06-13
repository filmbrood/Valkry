#include "keyevent.h"
#include "../app/logging.h"

namespace Valkry {

	KeyEvent::KeyEvent(int keycode)
	{
		this->keycode_ = keycode;
	}

	bool KeyEvent::Pressed(Window& win)
	{
		if (glfwGetKey(win.GetWindow(), keycode_) == GLFW_PRESS)
		{
			LogInfo("Key Pressed", keycode_);
			return true;
		}
		else
			return false;
	}

	bool KeyEvent::Released(Window& win)
	{
		if (glfwGetKey(win.GetWindow(), keycode_) == GLFW_RELEASE)
		{
			LogInfo("Key Released", keycode_);
			return true;
		}
		else
			return false;
	}

	bool KeyEvent::Repeated(Window& win)
	{
		if (glfwGetKey(win.GetWindow(), keycode_) == GLFW_REPEAT)
		{
			LogInfo("Key Repeated", keycode_);
			return true;
		}
		else
			return false;
	}
}