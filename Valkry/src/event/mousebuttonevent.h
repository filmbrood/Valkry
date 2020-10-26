#pragma once

#include "../app/logging.h"
#include "../app/window.h"

#include "GLFW/glfw3.h"

namespace Valkry{

  class MouseButtonEvent
  {
  public:
    MouseButtonEvent(int keycode);

    bool Pressed(Window& win);
    bool Repeated(Window& win);
    bool Released(Window& win);

  private:
    int keycode_;
  };

}
