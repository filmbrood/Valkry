#pragma once

#include "../app/logging.h"
#include "../app/window.h"

#include "GLFW/glfw3.h"

namespace Valkry {

	// Handler class for key events. Stores a keycode and contains functions to check that key's state.
	class KeyEvent
	{
	public:
		KeyEvent(int keycode);
		bool Pressed(Window& win);
		bool Released(Window& win);
		bool Repeated(Window& win);

	private:
		int keycode_;
	};

	// Global key events that can be polled anywhere by calling Valkry::Keys::[key].
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
