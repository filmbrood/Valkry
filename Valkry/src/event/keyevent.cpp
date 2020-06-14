#include "valkrypch.h"

#include "keyevent.h"

namespace Valkry {

	KeyEvent::KeyEvent(int keycode)
	{
		this->keycode_ = keycode;
	}

	bool KeyEvent::Pressed(Window& win)
	{
		if (glfwGetKey(win.GetWindow(), keycode_) == GLFW_PRESS)
		{
			return true;
		}
		else
			return false;
	}

	bool KeyEvent::Released(Window& win)
	{
		if (glfwGetKey(win.GetWindow(), keycode_) == GLFW_RELEASE)
		{
			return true;
		}
		else
			return false;
	}

	bool KeyEvent::Repeated(Window& win)
	{
		if (glfwGetKey(win.GetWindow(), keycode_) == GLFW_REPEAT)
		{
			return true;
		}
		else
			return false;
	}
}