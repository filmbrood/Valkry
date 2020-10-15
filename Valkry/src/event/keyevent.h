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

	namespace Keys {
		extern KeyEvent ESC;

		extern KeyEvent A;
		extern KeyEvent B;
		extern KeyEvent C;
		extern KeyEvent D;
		extern KeyEvent E;
		extern KeyEvent F;
		extern KeyEvent G;
		extern KeyEvent H;
		extern KeyEvent I;
		extern KeyEvent J;
		extern KeyEvent K;
		extern KeyEvent L;
		extern KeyEvent M;
		extern KeyEvent N;
		extern KeyEvent O;
		extern KeyEvent P;
		extern KeyEvent Q;
		extern KeyEvent R;
		extern KeyEvent S;
		extern KeyEvent T;
		extern KeyEvent U;
		extern KeyEvent V;
		extern KeyEvent W;
		extern KeyEvent X;
		extern KeyEvent Y;
		extern KeyEvent Z;

		extern KeyEvent ZERO;
		extern KeyEvent ONE;
		extern KeyEvent TWO;
		extern KeyEvent THREE;
		extern KeyEvent FOUR;
		extern KeyEvent FIVE;
		extern KeyEvent SIX;
		extern KeyEvent SEVEN;
		extern KeyEvent EIGHT;
		extern KeyEvent NINE;
	}
}