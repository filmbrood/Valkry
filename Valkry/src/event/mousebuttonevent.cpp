#include "valkrypch.h"
#include "mousebuttonevent.h"

namespace Valkry{

  MouseButtonEvent::MouseButtonEvent(int keycode)
  {
    keycode_ = keycode;
  }

  bool MouseButtonEvent::Pressed(Window& win)
  {
    if (glfwGetMouseButton(win.GetWindow(), keycode_) == GLFW_PRESS)
			return true;
		else
			return false;
  }

  bool MouseButtonEvent::Repeated(Window& win)
  {
    if (glfwGetMouseButton(win.GetWindow(), keycode_) == GLFW_REPEAT)
			return true;
		else
			return false;
  }

  bool MouseButtonEvent::Released(Window& win)
  {
    if (glfwGetMouseButton(win.GetWindow(), keycode_) == GLFW_RELEASE)
			return true;
		else
			return false;
  }
}
